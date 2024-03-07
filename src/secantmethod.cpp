#include "secantmethod.h"

SecantMethod::SecantMethod(Equations* eq, unsigned short pr) : RootFindingMethod(eq, pr){}

QString SecantMethod::show_calculations()const
{
    arma::vec X(2);
    arma::vec X_prev(2);
    arma::vec funcs(2);
    arma::vec funcs_prev(2);
    arma::vec Y(2);
    arma::vec S(2);
    double epsilon = std::pow(10, -precision);
    double norm_S = std::numeric_limits<double>::infinity();
    double denominator = 0;
    arma::mat A(2, 2), numerator(2, 2);
    QString calc_text, result_text;
    QTextStream stream(&calc_text);
    unsigned short count = 0;

    X = system->get_x();
    funcs = calc_vector(system->get_templates(), X, system->get_coefficients());

    A = computeJacobian(system->get_templates(), X, system->get_coefficients());

    stream << "\nРозрахунки:\n";

    while (norm_S > epsilon)
    {
        count++;

        // Перевірка, чи знаходиться визначник матриці в околі нуля.
        // якщо так, то генеруємо помилку
        if (fabs(arma::det(A)) <= 0.1)
        {
            throw std::exception("Система рівнянь не є збіжною");
        }

        S = arma::solve(A, -funcs);

        X_prev = X;
        funcs_prev = funcs;
        X += S;
        funcs = calc_vector(system->get_templates(), X, system->get_coefficients());

        norm_S = arma::norm(S);

        Y = funcs - funcs_prev;
        numerator = (Y - A * S) * S.t();
        denominator = arma::dot(S.t(), S);
        A = A + (numerator / denominator);

        // Перевірка на коректність логарифмічної функції
        if (!check_log_correctness(system->get_templates(), X))
        {
            throw std::exception("Система не має дійсних коренів");
        }

        stream << "\nКрок " << count << '\n';
        stream << "x = " << QString::number(X(0), 'f', precision) << '\n';
        stream << "y = " << QString::number(X(1), 'f', precision) << "\n\n\n";
    } 

    result_text += "\nКількість кроків розв'язку: " + QString::number(count) + "\n\n";
    result_text += "Результат обчислень:\n";
    result_text += "x = " + QString::number(X(0), 'f', precision) + '\n';
    result_text += "y = " + QString::number(X(1), 'f', precision) + "\n\n";
    result_text += calc_text;

    return result_text;
}

QString SecantMethod::get_info()const
{
    QString info = "Введена система нелінійних рівнянь:\n\n";
    info += system->show_equations();
    info += "\nМетод розв'язку: метод січних\n\n";
    info += "\nПочаткове наближення:\n";
    info += system->show_x() + '\n';
    return info;
}