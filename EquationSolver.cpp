//
// Created by ritokk on 19.03.26.
//

#include "EquationSolver.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
bool areNearlyEqualToZero(double a, double b) {
    double diff = std::fabs(a - b);
    if (diff <= std::numeric_limits<double>::min()) {
        return true;
    }
    return diff <= std::numeric_limits<double>::epsilon() * std::max(std::fabs(a), std::fabs(b)) * 32.0;
}
EquationSolver::EquationSolver() {

}
EquationSolver::~EquationSolver() {

}
// Setters
void EquationSolver::setA(double a) { this->a = a; }
void EquationSolver::setB(double b) { this->b = b; }
void EquationSolver::setEps(double eps) { this->eps = eps; }
void EquationSolver::setResDyhotomia(double res) { this->resDyhotomia = res; }
void EquationSolver::setResNewton(double res) { this->resNewton = res; }
void EquationSolver::setValF(double val) { this->valF = val; }
void EquationSolver::setValDf(double val) { this->valDf = val; }
// Getters
void EquationSolver::getA(double &a) const { a = this->a; }
void EquationSolver::getB(double &b) const { b = this->b; }
void EquationSolver::getEps(double &eps) const { eps = this->eps; }
void EquationSolver::getResDyhotomia(double &res) const { res = this->resDyhotomia; }
void EquationSolver::getResNewton(double &res) const { res = this->resNewton; }
void EquationSolver::getValF(double &val) const { val = this->valF; }
void EquationSolver::getValDf(double &val) const { val = this->valDf; }

void EquationSolver::f(double &x) {
    double result = sin(sqrt(x)) + (0.35 * x) - 3.8;
    setValF(result);
}
void EquationSolver::df(double &x) {
    double h = 1e-7;
    double x_plus_h = x + h;

    f(x);
    double fx;
    getValF(fx);

    f(x_plus_h);
    double fxh;
    getValF(fxh);

    double result = (fxh - fx) / h;
    setValDf(result);
}

void EquationSolver::solveDyhotomia(double a, double b, double epsilon) {
    int max_iteractions = 1000;

    f(a);
    double fa;
    getValF(fa);

    f(b);
    double fb;
    getValF(fb);
    if (std::isnan(fa) || std::isnan(fb)) {
        cout << "Помилка (Дихотомія): Відрізок знаходиться поза областю визначення функції (ОДЗ)!" << endl;
        setResDyhotomia(std::numeric_limits<double>::quiet_NaN());
        return;
    }
    if (areNearlyEqualToZero(fa, 0.0)) {
        setResDyhotomia(a);
        return;
    }
    if (areNearlyEqualToZero(fb, 0.0)) {
        setResDyhotomia(b);
        return;
    }
    if (fa * fb > 0.0) {
        setResDyhotomia(std::numeric_limits<double>::quiet_NaN());
        return;
    }

    double c = a;
    int i = 0;

    while ((b - a) >= epsilon && i <= max_iteractions) {
        c = (a + b) / 2.0;

        f(c);
        double fc;
        getValF(fc);

        if (areNearlyEqualToZero(fc, 0.0)) {
            break;
        }
        if (fc * fa < 0) {
            b = c;
        } else {
            a = c;
        }

        i++;
    }
    setResDyhotomia(c);
}

void EquationSolver::solveNewton(double x0, double epsilon) {
    double x1;
    int max_iterations = 1000;

    for (int i = 0; i < max_iterations; i++) {
        f(x0);
        double fx;
        getValF(fx);
        if (std::isnan(fx)) {
            cout << "Помилка (Ньютон): Алгоритм вийшов за область визначення функції (ОДЗ)!" << endl;
            setResNewton(std::numeric_limits<double>::quiet_NaN());
            return;
        }
        if (areNearlyEqualToZero(fx, 0.0)) {
            setResNewton(x0);
            return;
        }
        df(x0);
        double dfx;
        getValDf(dfx);
        if (areNearlyEqualToZero(dfx, 0.0)) {
            x0 += 1e-6;
            continue;
        }
        x1 = x0 - (fx / dfx);
        if (fabs(x1 - x0) < epsilon) {
            setResNewton(x1);
            return;
        }
        x0 = x1;
    }
    cout << "Попередження: Метод Ньютона не зійшовся за " << max_iterations << " ітерацій." << endl;
    setResNewton(x1);
}

void startingPoint() {
    double a, b, eps ;
    cout << "Введіть початок відрізка a: ";
    cin >> a;
    cout << "Введіть кінець відрізка b: ";
    cin >> b;
    cout << "Введіть точність eps (наприклад, 1e-9): ";
    cin >> eps;
    if (eps <= 0.0) {
        cout << "Помилка: Точність має бути строго більшою за нуль." << endl;
        return;
    }
    if (a > b) {
        cout << "Попередження: Початок відрізка більший за кінець. Міняємо їх місцями." << endl;
        std::swap(a, b);
    }
    EquationSolver *o = new EquationSolver();
    o->setA(a);
    o->setB(b);
    o->setEps(eps);
    o->solveDyhotomia(a, b, eps);
    o->solveNewton(10, eps);
    double resultD, resultN;
    o->getResDyhotomia(resultD);
    o->getResNewton(resultN);
    cout << fixed << setprecision(15);
    cout << "Досліджуваний проміжок: [" << a << ", " << b << "]" << endl;
    if (std::isnan(resultD)) {
        cout << "Результат Дихотомії: Коренів не виявлено." << endl;
    } else {
        cout << "Результат Дихотомії: Знайдено корінь " << resultD << endl;
    }

    cout << "Результат Ньютона: ";
    if (std::isnan(resultN)) {
        cout << "Помилка ОДЗ або розбіжність." << endl;
    } else {
        cout << "Знайдено корінь " << resultN;

        if (resultN < a || resultN > b) {
            cout << " (Зовнішній)" << endl;
        } else {
            cout << " (Внутрішній)" << endl;
        }
    }

    delete o;
}
