#include "equations.h"

Equations::Equations(arma::vec& variables, arma::vec& function_types, arma::mat& coef_matrix)
{
    x_values = variables;
    templates = function_types;
    coefficients = coef_matrix;
}

arma::vec Equations::get_x()const
{
    return x_values;
}

arma::vec Equations::get_templates()const
{
    return templates;
}

arma::mat Equations::get_coefficients()const
{
    return coefficients;
}

QString Equations::show_equations()const
{
    QString str;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (coefficients(i, j) != 0)
            {
                if (coefficients(i, j) !=1)
                {
                    coefficients(i, j) > 0 ? str += QString::number(coefficients(i, j)) : str+='(' + QString::number(coefficients(i, j)) + ')';
                }
                str += equation_templates[(int)templates[i]][j]+ " ";
            }
        }
        str += equation_templates[(int)templates[i]][2] + " = 0\n";
    }

    return str;
}

QString Equations::show_x()const
{
    QString str;

    str += "x0 = " + QString::number(x_values(0)) + '\n';
    str += "y0 = " + QString::number(x_values(1)) + '\n';

    return str;
}