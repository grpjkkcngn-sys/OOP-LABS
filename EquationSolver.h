//
// Created by ritokk on 19.03.26.
//
#ifndef LAB3_EQUATIONSOLVER_H
#define LAB3_EQUATIONSOLVER_H
bool areNearlyEqualToZero(double a, double b);
class EquationSolver {
private:
    double a, b;
    double eps;
    double resDyhotomia;
    double resNewton;
    double valF;
    double valDf;
public:
    EquationSolver();
    ~EquationSolver();
    void setA(double a);
    void setB(double b);
    void setEps(double eps);
    void setResDyhotomia(double res);
    void setResNewton(double res);
    void setValF(double val);
    void setValDf(double val);
    void getA(double &a) const;
    void getB(double &b) const;
    void getEps(double &eps) const;
    void getResDyhotomia(double &res) const;
    void getResNewton(double &res) const;
    void getValF(double &val) const;
    void getValDf(double &val) const;

    void f(double &x);
    void df(double &x);

    void solveDyhotomia(double a, double b, double epsilon);
    void solveNewton(double x0, double epsilon);
};

void startingPoint();
#endif //LAB3_EQUATIONSOLVER_H