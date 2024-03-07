#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <armadillo>
#include <qbuttongroup.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_eq1_template_choice_activated(int index);

    void on_eq2_template_choice_activated(int index);

private:
    Ui::MainWindow *ui;
    QButtonGroup* methods;

    arma::mat get_coefficients()const;
    arma::vec get_approximation()const;
    unsigned short get_precision()const;
    void solve_system();
};
#endif // MAINWINDOW_H
