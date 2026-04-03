
#ifndef SOPHUC_H
#define SOPHUC_H
#include "PhanSo.h"
#include <iostream>

class SoPhuc
{
    public:
        void Nhap();
        void Xuat();
        SoPhuc (int a=0,int b=0): iThuc(a), iAo(b){};
        SoPhuc(const SoPhuc &p)
        {
            iThuc = p.iThuc;
            iAo = p.iAo;
        }
        friend SoPhuc operator+ (SoPhuc,SoPhuc);
        friend SoPhuc operator- (SoPhuc,SoPhuc);
        friend SoPhuc operator* (SoPhuc,SoPhuc);
        friend SoPhuc operator/ (SoPhuc,SoPhuc);
        friend bool operator== (SoPhuc a,SoPhuc b);
        friend std::istream& operator >> (std::istream &is, SoPhuc &p);
        friend std::ostream& operator << (std::ostream &os, const SoPhuc& p);
    private:
        PhanSo iThuc, iAo;

};

#endif // SOPHUC_H
