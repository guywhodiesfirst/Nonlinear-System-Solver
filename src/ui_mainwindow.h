/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *save_results;
    QAction *close_program;
    QAction *secret_button;
    QWidget *centralwidget;
    QPushButton *start_button;
    QWidget *formLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QComboBox *eq1_template_choice;
    QSpacerItem *verticalSpacer;
    QGroupBox *equation_1_input;
    QLabel *c00_label;
    QLineEdit *c00_input;
    QLineEdit *c01_input;
    QLabel *c01_label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *secant_check;
    QRadioButton *newton_check;
    QWidget *formLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QComboBox *eq2_template_choice;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *equation_2_input;
    QLabel *c10_label;
    QLabel *c11_label;
    QLineEdit *c11_input;
    QLineEdit *c10_input;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QLabel *x_label;
    QLineEdit *x0_input;
    QLabel *y0_label;
    QLineEdit *y0_input;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout;
    QLabel *eps_label;
    QLineEdit *eps_input;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(763, 451);
        save_results = new QAction(MainWindow);
        save_results->setObjectName("save_results");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(":/res/img/icon_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        save_results->setIcon(icon);
        close_program = new QAction(MainWindow);
        close_program->setObjectName("close_program");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/img/imgonline-com-ua-Resize-4g37bogRtaOsPph.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_program->setIcon(icon1);
        secret_button = new QAction(MainWindow);
        secret_button->setObjectName("secret_button");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/imgonline-com-ua-Resize-yiUvn8BmKoM.png"), QSize(), QIcon::Normal, QIcon::Off);
        secret_button->setIcon(icon2);
        secret_button->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        start_button = new QPushButton(centralwidget);
        start_button->setObjectName("start_button");
        start_button->setGeometry(QRect(350, 380, 80, 24));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(60, 150, 291, 211));
        verticalLayout_2 = new QVBoxLayout(formLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(formLayoutWidget);
        groupBox_2->setObjectName("groupBox_2");
        eq1_template_choice = new QComboBox(groupBox_2);
        eq1_template_choice->addItem(QString());
        eq1_template_choice->addItem(QString());
        eq1_template_choice->addItem(QString());
        eq1_template_choice->addItem(QString());
        eq1_template_choice->addItem(QString());
        eq1_template_choice->setObjectName("eq1_template_choice");
        eq1_template_choice->setGeometry(QRect(10, 40, 261, 24));

        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        equation_1_input = new QGroupBox(formLayoutWidget);
        equation_1_input->setObjectName("equation_1_input");
        c00_label = new QLabel(equation_1_input);
        c00_label->setObjectName("c00_label");
        c00_label->setGeometry(QRect(90, 50, 51, 16));
        QFont font;
        font.setPointSize(9);
        c00_label->setFont(font);
        c00_input = new QLineEdit(equation_1_input);
        c00_input->setObjectName("c00_input");
        c00_input->setGeometry(QRect(10, 40, 71, 31));
        c01_input = new QLineEdit(equation_1_input);
        c01_input->setObjectName("c01_input");
        c01_input->setGeometry(QRect(130, 40, 71, 31));
        c01_label = new QLabel(equation_1_input);
        c01_label->setObjectName("c01_label");
        c01_label->setGeometry(QRect(210, 50, 81, 16));
        c01_label->setFont(font);

        verticalLayout_2->addWidget(equation_1_input);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(60, 40, 171, 93));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        secant_check = new QRadioButton(groupBox);
        secant_check->setObjectName("secant_check");

        verticalLayout->addWidget(secant_check);

        newton_check = new QRadioButton(groupBox);
        newton_check->setObjectName("newton_check");

        verticalLayout->addWidget(newton_check);

        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(430, 150, 291, 211));
        verticalLayout_3 = new QVBoxLayout(formLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(formLayoutWidget_2);
        groupBox_3->setObjectName("groupBox_3");
        eq2_template_choice = new QComboBox(groupBox_3);
        eq2_template_choice->addItem(QString());
        eq2_template_choice->addItem(QString());
        eq2_template_choice->addItem(QString());
        eq2_template_choice->addItem(QString());
        eq2_template_choice->addItem(QString());
        eq2_template_choice->setObjectName("eq2_template_choice");
        eq2_template_choice->setGeometry(QRect(10, 40, 261, 24));

        verticalLayout_3->addWidget(groupBox_3);

        verticalSpacer_2 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        equation_2_input = new QGroupBox(formLayoutWidget_2);
        equation_2_input->setObjectName("equation_2_input");
        c10_label = new QLabel(equation_2_input);
        c10_label->setObjectName("c10_label");
        c10_label->setGeometry(QRect(90, 50, 51, 16));
        c10_label->setFont(font);
        c11_label = new QLabel(equation_2_input);
        c11_label->setObjectName("c11_label");
        c11_label->setGeometry(QRect(210, 50, 81, 16));
        c11_label->setFont(font);
        c11_input = new QLineEdit(equation_2_input);
        c11_input->setObjectName("c11_input");
        c11_input->setGeometry(QRect(130, 40, 71, 31));
        c10_input = new QLineEdit(equation_2_input);
        c10_input->setObjectName("c10_input");
        c10_input->setGeometry(QRect(10, 40, 71, 31));

        verticalLayout_3->addWidget(equation_2_input);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(530, 40, 191, 91));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName("gridLayout");
        x_label = new QLabel(groupBox_4);
        x_label->setObjectName("x_label");

        gridLayout->addWidget(x_label, 0, 0, 1, 1);

        x0_input = new QLineEdit(groupBox_4);
        x0_input->setObjectName("x0_input");

        gridLayout->addWidget(x0_input, 0, 1, 1, 1);

        y0_label = new QLabel(groupBox_4);
        y0_label->setObjectName("y0_label");

        gridLayout->addWidget(y0_label, 1, 0, 1, 1);

        y0_input = new QLineEdit(groupBox_4);
        y0_input->setObjectName("y0_input");

        gridLayout->addWidget(y0_input, 1, 1, 1, 1);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(250, 69, 261, 58));
        horizontalLayout = new QHBoxLayout(groupBox_5);
        horizontalLayout->setObjectName("horizontalLayout");
        eps_label = new QLabel(groupBox_5);
        eps_label->setObjectName("eps_label");

        horizontalLayout->addWidget(eps_label);

        eps_input = new QLineEdit(groupBox_5);
        eps_input->setObjectName("eps_input");

        horizontalLayout->addWidget(eps_input);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(false);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        save_results->setText(QCoreApplication::translate("MainWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\264\320\276 \321\204\320\260\320\271\320\273\321\203", nullptr));
        close_program->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\320\270 \321\200\320\276\320\261\320\276\321\202\321\203", nullptr));
        secret_button->setText(QCoreApplication::translate("MainWindow", "\320\251\320\276 \321\202\320\260\320\274?", nullptr));
#if QT_CONFIG(tooltip)
        secret_button->setToolTip(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\261\321\226 \321\202\320\265\320\266 \320\275\320\265 \321\202\320\265\321\200\320\277\320\270\321\202\321\214\321\201\321\217 \320\277\320\276\320\264\320\270\320\262\320\270\321\202\320\270\321\201\321\217?", nullptr));
#endif // QT_CONFIG(tooltip)
        start_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\207\320\260\321\202\320\270", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \321\210\320\260\320\261\320\273\320\276\320\275 \321\200\321\226\320\262\320\275\321\217\320\275\320\275\321\217 1", nullptr));
        eq1_template_choice->setItemText(0, QCoreApplication::translate("MainWindow", "a*x^2 + b*y^3 - 3 = 0", nullptr));
        eq1_template_choice->setItemText(1, QCoreApplication::translate("MainWindow", "a*sin(x) + b*cos(y) + 1 = 0", nullptr));
        eq1_template_choice->setItemText(2, QCoreApplication::translate("MainWindow", "a*ln(x) + b*lg(y) - 1 = 0", nullptr));
        eq1_template_choice->setItemText(3, QCoreApplication::translate("MainWindow", "a*x - b*cos(y) - 25 = 0", nullptr));
        eq1_template_choice->setItemText(4, QCoreApplication::translate("MainWindow", "a*x^3 - b*y^2 - 21 = 0", nullptr));

        equation_1_input->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \320\272\320\276\320\265\321\204\321\226\321\206\321\226\321\224\320\275\321\202\320\270 \321\200\321\226\320\262\320\275\321\217\320\275\320\275\321\217 1:", nullptr));
        c00_label->setText(QCoreApplication::translate("MainWindow", "x^2 + ", nullptr));
        c01_label->setText(QCoreApplication::translate("MainWindow", "y^3 - 3 = 0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \320\274\320\265\321\202\320\276\320\264 \321\200\320\276\320\267\320\262'\321\217\320\267\320\272\321\203", nullptr));
        secant_check->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \321\201\321\226\321\207\320\275\320\270\321\205", nullptr));
        newton_check->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\235\321\214\321\216\321\202\320\276\320\275\320\260", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \321\210\320\260\320\261\320\273\320\276\320\275 \321\200\321\226\320\262\320\275\321\217\320\275\320\275\321\217 2", nullptr));
        eq2_template_choice->setItemText(0, QCoreApplication::translate("MainWindow", "a*x^2 + b*y^3  - 3 = 0", nullptr));
        eq2_template_choice->setItemText(1, QCoreApplication::translate("MainWindow", "a*sin(x) + b*cos(y) + 1 = 0", nullptr));
        eq2_template_choice->setItemText(2, QCoreApplication::translate("MainWindow", "a*ln(x) + b*lg(y)  - 1 = 0", nullptr));
        eq2_template_choice->setItemText(3, QCoreApplication::translate("MainWindow", "a*x - b*cos(y) - 25 = 0", nullptr));
        eq2_template_choice->setItemText(4, QCoreApplication::translate("MainWindow", "a*x^3 - b*y^2 - 21 = 0", nullptr));

        equation_2_input->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \320\272\320\276\320\265\321\204\321\226\321\206\321\226\321\224\320\275\321\202\320\270 \321\200\321\226\320\262\320\275\321\217\320\275\320\275\321\217 2:", nullptr));
        c10_label->setText(QCoreApplication::translate("MainWindow", "x^2 + ", nullptr));
        c11_label->setText(QCoreApplication::translate("MainWindow", "y^3 - 3 = 0", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \320\277\320\276\321\207\320\260\321\202\320\272\320\276\320\262\320\265 \320\275\320\260\320\261\320\273\320\270\320\266\320\265\320\275\320\275\321\217", nullptr));
        x_label->setText(QCoreApplication::translate("MainWindow", "x0 = ", nullptr));
        y0_label->setText(QCoreApplication::translate("MainWindow", "y0 = ", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \321\202\320\276\321\207\320\275\321\226\321\201\321\202\321\214 (\320\272-\321\202\321\214 \320\267\320\275\320\260\320\272\321\226\320\262 \320\277\321\226\321\201\320\273\321\217 \320\272\320\276\320\274\320\270)", nullptr));
        eps_label->setText(QCoreApplication::translate("MainWindow", "eps = ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
