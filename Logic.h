#ifndef LOGIC_H
#define LOGIC_H

struct Tovar {
    int grn;
    short int kop;
};

void MNNSHT( Tovar &tovar, int &sht);
void SUMA( Tovar &tovar, short int &total_kop , int &total_grn);
void KOPTOGRN( short int &total_kop , int &total_grn);
void ROUND(short int &total_kop);  
void readTovar(); 

#endif
