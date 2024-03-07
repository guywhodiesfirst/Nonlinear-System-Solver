#ifndef EQUATIONS_H
#define EQUATIONS_H
#include <armadillo>
#include <qstring.h>

const QString equation_templates[5][3] =
{
    {"x^2 +", "y^3 +", "(-3)"},
    {"sin(x) +", "cos(y) +", "1"},
    {"ln(x) +", "lg(y) +", "(-1)"},
    {"x +", "(-cos(y)) +", "(-25)"},
    {"x^3 +", "(-y^2) +", "(-21)"}
};

class Equations
{
    arma::vec x_values;
    arma::vec templates;
    arma::mat coefficients;
public:
    Equations(arma::vec& variables, arma::vec& funcion_types, arma::mat& coef_matrix);
    arma::vec get_x()const;
    arma::vec get_templates()const;
    arma::mat get_coefficients()const;
    QString show_equations()const;
    QString show_x()const;
};

#endif // EQUATIONS_H
