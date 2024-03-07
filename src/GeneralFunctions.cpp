#include "GeneralFunctions.h"

double calc_function(int func_template, const arma::vec& x, const arma::vec& c)
{
    switch (func_template)
    {
    case 0:
        return (c(0) * pow(x(0), 2) + c(1) * pow(x(1), 3) - 3);
    case 1:
        return (c(0) * sin(x(0)) + c(1)*cos(x(1)) + 1);
    case 2: 
        return (c(0) * log(x(0)) + c(1) * log10(x(1)) - 1);
    case 3:
        return (c(0) * (x(0)) - c(1) * cos(x(1)) - 25);
    case 4:
        return (c(0) * pow(x(0), 3) - c(1) * pow(x(1), 2) - 21);
    }
    
    throw std::invalid_argument("calc_function(): невірно заданий шаблон функції");
}

arma::vec calc_vector(const arma::vec& func_templates, const arma::vec& input, const arma::mat& coefs)
{
    arma::vec result(2);
    for (int i = 0; i < 2; i++)
    {
        result(i) = calc_function((int)func_templates[i], input, coefs.row(i).t());
    }
    return result;
}

arma::mat computeJacobian(const arma::vec& func_templates, const arma::vec& input, const arma::mat coefs)
{
    arma::mat J(2, 2);
    arma::vec shifted_x(2), f(2), shifted_f(2), delta_f(2);
    double h = 1e-10;

    // Похідні знаходяться методом диференціального числення
    for (int i = 0; i < 2; i++)
    {
        shifted_x = input;
        shifted_x(i) += h;
        f = calc_vector(func_templates, input, coefs);
        shifted_f = calc_vector(func_templates, shifted_x, coefs);

        delta_f = shifted_f - f;
        J.col(i) = delta_f / h;
    }

    return J;
}

bool check_log_correctness(const arma::vec& funcs, const arma::vec& values)
{
    for (double i : funcs)
    {
        for (double j : values)
        {
            if ((i == 2 && j <= 1e-5))
            {
                return false;
            }
        }
    }
    return true;
}