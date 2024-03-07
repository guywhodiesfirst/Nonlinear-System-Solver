#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLocale>
#include <QRegularExpressionValidator>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <newtonmethod.h>
#include "filewindow.h"
#include <secantmethod.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Створюємо валідатори для користувацьких полей вводу, щоб уникнути вводу зайвих символів.
    // Для валідатора вводу точності накладаємо додаткові обмеження на кількість знаків після коми
    QDoubleValidator* dv = new QDoubleValidator();
    QIntValidator* eps_validator = new QIntValidator(4, 9);

    // Клас QLocale форматує числа в рядки в залежності від того, який формат 
    // запису чисел є найпоширенішим в тій чи іншій локалізації. 
    // Локалізація "C" має спрощене форматування чисел - скажімо, користувач може
    // розділяти цілу та дійсну частину числа як через '.', так і через ','
    QLocale clocale(QLocale::c());
    dv->setLocale(clocale);

    // Використовуємо QButtonGroup для групування кнопок вибору методу розв'язку
    methods = new QButtonGroup(this);
    methods->addButton(ui->secant_check);
    methods->addButton(ui->newton_check);

    ui->eps_input->setValidator(eps_validator);

    ui->x0_input->setValidator(dv);
    ui->y0_input->setValidator(dv);
    ui->c00_input->setValidator(dv);
    ui->c10_input->setValidator(dv);
    ui->c01_input->setValidator(dv);
    ui->c11_input->setValidator(dv);

    // При запуску програми індекси шаблонів рівнянь
    // за замовчуванням будуть стояти на 0
    ui->eq1_template_choice->setCurrentIndex(0);
    ui->eq2_template_choice->setCurrentIndex(0);

    // Встановлюємо зв'язок між сигналом, clicked об'єкта start_button та слотом solve_system
    QObject::connect(ui->start_button, &QPushButton::clicked, this, &MainWindow::solve_system);

    setWindowTitle("NonlinearSystemSolver");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_eq1_template_choice_activated(int index)
{
    if (index==0)
    {
        ui->c00_label->setText("x^2 + ");
        ui->c01_label->setText("y^3 - 3 = 0");
    }

    else if(index==1)
    {
        ui->c00_label->setText("sin(x) + ");
        ui->c01_label->setText("cos(y) + 1 = 0");
    }

    else if(index==2)
    {
        ui->c00_label->setText("ln(x) + ");
        ui->c01_label->setText("lg(y) - 1 = 0");
    }
    else if(index == 3)
    {
        ui->c00_label->setText("x - ");
        ui->c01_label->setText("cos(y) - 25 = 0");
    }
    else if (index == 4)
    {
        ui->c00_label->setText("x^3 - ");
        ui->c01_label->setText("y^2 - 21 = 0");
    }
}

void MainWindow::on_eq2_template_choice_activated(int index)
{
    if (index==0)
    {
        ui->c10_label->setText("x^2 + ");
        ui->c11_label->setText("y^3 - 3 = 0");
    }

    else if(index==1)
    {
        ui->c10_label->setText("sin(x) + ");
        ui->c11_label->setText("cos(y) + 1 = 0");
    }

    else if(index==2)
    {
        ui->c10_label->setText("ln(x) + ");
        ui->c11_label->setText("lg(y) - 1 = 0");
    }
    else if (index == 3)
    {
        ui->c10_label->setText("x - ");
        ui->c11_label->setText("cos(y) - 25 = 0");
    }
    else if (index == 4)
    {
        ui->c10_label->setText("x^3 - ");
        ui->c11_label->setText("y^2 - 21 = 0");
    }
}

arma::mat MainWindow::get_coefficients()const
{
    arma::mat matrix(2, 2);
    const QString coefficient_inputs[4] = {"c00_input", "c01_input", "c10_input", "c11_input"}; // масив з назвами об'єктів полей вводу
    QString coefficients[4]; // масив значень, введених в поля для вводу

    // Отримання значень коефіцієнтів з QLineEdit
    for (int i = 0; i < 4; i++)
    {
        // Функція findChild використовується для пошуку об'єктів указаного типу
        // (в даному випадку - QLineEdit) за іменами з масиву coefficient_inputs
        QLineEdit* input_line = findChild<QLineEdit*>(coefficient_inputs[i]);
        coefficients[i] = input_line->text();

        // Щоб переконатись у тому, що користувач ввів коефіцієнти,
        // спершу треба привести дані з поля для вводу до типу QString,
        // а потім перевірити, що рядок не є порожнім. Інакше, згенерувати виняток
        if (coefficients[i].isEmpty())
        {
            throw std::exception("Не введено коефіцієнти рівняння!");
        }
    }

    // Маркер arma::endr використовується для позначення кінця рядка при визначенні матриць
    // arma::mat не можна ввести за допомогою циклу, всі елементи потрібно додавати послідовно
    matrix << coefficients[0].toDouble() << coefficients[1].toDouble() << arma::endr
        << coefficients[2].toDouble() << coefficients[3].toDouble();

    // Обмеження користувацького вводу коефіцієнтів
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (fabs((matrix(i, j) > 99999)) || ((matrix(i,j) != 0) && fabs((matrix(i, j) < 1e-5))))
            {
                throw std::exception("Коефіцієнти завеликі/замалі.\nВведіть інші коефіцієнти");
            }
        }
    }
    return matrix;
}

// Метод для отримання вектору початкового наближення з полів для вводу даних.
// Повертає об'єкт класу vec, що належить до бібліотеки Armadillo і, на відміну від стандартних
// векторів C++, працює з векторами саме в контексті лінійної алгебри:
// дає можливість використовувати їх для арифметичних операцій, 
// містить методи для знаходження норми вектора та інших стандартних дій над векторами
arma::vec MainWindow::get_approximation()const
{
    const QString x0 = ui->x0_input->text();
    const QString y0 = ui->y0_input->text();

    // Перевірка, чи задано початкове наближення
    if (x0.isEmpty() || y0.isEmpty())
    {
        throw std::exception("Не задано початкове наближення!");
    }

    arma::vec approx(2);
    approx << x0.toDouble() << y0.toDouble();
    
    // Обмеження користувацького вводу початкового наближення
    for (int i = 0; i < 2; i++)
    {
        if ((fabs(approx(i)) > 99999) || (approx(i) != 0 && fabs(approx(i)) < 1e-5))
        {
            throw std::exception("Початкове наближення завелике/замале.\nВведіть інше початкове наближення");
        }
    }
    return approx;
}

unsigned short MainWindow::get_precision()const
{
    unsigned short nums_after_comma = ui->eps_input->text().toInt();

    // Валідатор навіть з указаним проміжком пропускає ввід від 0 до 3,
    // тому треба окремо додатково перевірити інпут користувача
    if (nums_after_comma < 4)
    {
        throw std::exception("Точність має лежати в межах від 4 до 9 знаків після коми!");
    }

    return nums_after_comma;
}

void MainWindow::solve_system()
{
    try
    {
        // Метод checkedButton повертає покажчик на обраний елемент 
        // QButtonGroup. Якщо елемент не обрано, повертає nullptr
        if (methods->checkedButton() == nullptr)
        {
            throw std::exception("Не обрано метод розв'язку!");
        }

        // Вхідні дані
        arma::mat coef_matrix = get_coefficients();
        arma::vec initial_approximation = get_approximation();
        unsigned short eps = get_precision();
        arma::vec f_templates(2);

        // Для шаблонів можна не робити перевірки, так як за замовчуванням індекси комбобоксів = 0
        f_templates(0) = ui->eq1_template_choice->currentIndex();
        f_templates(1) = ui->eq2_template_choice->currentIndex();

        Equations* eq_system;
        eq_system = new Equations(initial_approximation, f_templates, coef_matrix);

        RootFindingMethod* solver;
        if (ui->secant_check->isChecked())
        {
            solver = new SecantMethod(eq_system, eps);
        }
        else
        {
            solver = new NewtonMethod(eq_system, eps);
        }

        QString solution;
        solution += solver->get_info();
        solution += solver->show_calculations();

        delete eq_system;
        delete solver;

        FileWindow result_window(solution);
        result_window.show();
        result_window.exec();
    }
    catch (std::exception& ex)
    {
        QMessageBox::warning(this, "Помилка", ex.what());
    }
}