#include "newtonmethod.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <sstream>

NewtonMethod::NewtonMethod(Equations *eq, unsigned short pr) : RootFindingMethod(eq, pr){}

QString NewtonMethod::show_calculations()const
{
    arma::vec X(2);
    arma::vec X_prev(2);
    arma::vec deltaX(2);
    arma::vec funcs(2);
    arma::vec funcs_prev(2);
    arma::vec modified_f(2);
    arma::vec modified_x(2);

    double epsilon = std::pow(10, -precision);
    double t;
    double norm_deltaX = std::numeric_limits<double>::infinity();

    arma::mat jacobi;

    QString calc_text;
    QString result_text;

    QTextStream stream(&calc_text);

    unsigned short count = 0;

    X = system->get_x();
    funcs = calc_vector(system->get_templates(), X, system->get_coefficients());

    stream << "Розрахунки:\n\n";

    while (norm_deltaX > epsilon)
    {
        count++;
        jacobi = computeJacobian(system->get_templates(), X, system->get_coefficients());

        // СЛАР не можна розв'язати, якщо визначник матриці коефіцієнтів
        // дорівнює нулю або лежить в околі нуля
        if (fabs(arma::det(jacobi)) <= 0.1)
        {
            throw std::exception("Система рівнянь не є збіжною");
        }

        deltaX = arma::solve(jacobi, -funcs);
        X_prev = X;
        funcs_prev = funcs;

        t = 1;

        // Алгоритм лінійного пошуку. Зменшуємо значення коренів, допоки норма вектора функцій
        // для поточного наближення не буде меншою за норму вектора попереднього наближення
        do
        {
            modified_x = X + t * deltaX;
            modified_f = calc_vector(system->get_templates(), modified_x, system->get_coefficients());

            if (arma::norm(modified_f) <= arma::norm(funcs_prev))
            {
                break;
            }
            else
            {
                t *= 0.88;
            }
        } while (true);

        X = modified_x;

        // Припиняємо роботу, якщо система містить логарифмічне рівняння,
        // а корені є некоректними
        if (!check_log_correctness(system->get_templates(), X))
        {
            throw std::exception("Система не має дійсних коренів");
        }

        funcs = modified_f;
        deltaX = X - X_prev;
        norm_deltaX = arma::norm(deltaX);

        stream << "Крок " << count << '\n';
        // Форматуємо корені, щоб вони вивелись з precision знаків після коми
        stream << "x = " << QString::number(X(0), 'f', precision) << '\n';
        stream << "y = " << QString::number(X(1), 'f', precision) << "\n\n";
    }
    
    result_text += "\nКількість кроків розв'язку: " + QString::number(count) + "\n\n";
    result_text += "Результат обчислень:\n";
    result_text += "x = " + QString::number(X(0), 'f', precision) + '\n';
    result_text += "y = " + QString::number(X(1), 'f', precision) + "\n\n";
    result_text += calc_text;

    return result_text;
}

QString NewtonMethod::get_info()const
{
    QString info = "Введена система нелінійних рівнянь:\n\n";
    info += system->show_equations();
    info += "\nМетод розв'язку: метод Ньютона\n\n";
    info += "\nПочаткове наближення:\n";
    info += system->show_x() + '\n';
    return info;
}