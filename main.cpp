#include "Logic.h"
#include <iostream>
#include <cstdio>

using namespace std;

void ROUND(Tovar &t)
{
    int ost = t.kop % 10;
    int b = 10 - ost;
    if (ost >= 1 && ost <= 3) t.kop -= ost;
    if (ost >= 4 && ost <= 9) t.kop += b;
    while (t.kop >= 100) { t.kop -= 100; t.grn += 1; }
}

void SUMA(Tovar &t1, Tovar &t2, Tovar &result)
{
    result.grn = t1.grn + t2.grn;
    result.kop = t1.kop + t2.kop;
    while (result.kop >= 100) { result.kop -= 100; result.grn += 1; }
}

void MNNSHT(Tovar &t, int n)
{
    t.grn = t.grn * n;
    t.kop = t.kop * n;
    while (t.kop >= 100) { t.kop -= 100; t.grn += 1; }
}

void showTovar(Tovar t)
{
    cout << t.grn << "grn  " << t.kop << "kop" << endl;
}

void readSum(Tovar &sum)
{
    FILE *file = nullptr;
    fopen_s(&file, "Chek.txt", "r");

    if (file == NULL) {
        cout << "Ne vdalos otvoryty fail Chek.txt" << endl;
        return;
    }

    Tovar tovar;
    int sht = 0;
    char nazva[50];
    sum = {0, 0};

    while (fscanf(file, "%49s %d %hi %d", nazva, &tovar.grn, &tovar.kop, &sht) == 4) {
        if (tovar.grn < 0 || tovar.kop < 0 || sht < 0) continue;
        MNNSHT(tovar, sht);
        Tovar temp = sum;
        SUMA(temp, tovar, sum);
    }

    fclose(file);
}

void showRoundedSum()
{
    Tovar sum = {0, 0};
    readSum(sum);

    Tovar rounded = sum;
    ROUND(rounded);

    cout << "Zagalna syma:     ";
    showTovar(sum);
    cout << "Syma do oplaty:   ";
    showTovar(rounded);
}