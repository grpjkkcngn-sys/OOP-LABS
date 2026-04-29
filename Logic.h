#ifndef LOGIC_H
#define LOGIC_H

struct Tovar {
    int grn;
    short int kop;
};

void ROUND(Tovar &t);
void SUMA(Tovar &t1, Tovar &t2, Tovar &result);
void MNNSHT(Tovar &t, int n);
void showTovar(Tovar t);
void readSum(Tovar &sum);
void showRoundedSum();

#endif