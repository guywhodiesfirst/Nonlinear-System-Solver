#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <math.h>
#include "equations.h"
#include <Windows.h>

double calc_function(int func_template, const arma::vec& x, const arma::vec& c);
arma::vec calc_vector(const arma::vec& func_templates, const arma::vec& input, const arma::mat& coefs);
arma::mat computeJacobian(const arma::vec& func_templates, const arma::vec& input, const arma::mat coefs);
bool check_log_correctness(const arma::vec& funcs, const arma::vec& values);

#endif // GENERALFUNCTIONS_H
