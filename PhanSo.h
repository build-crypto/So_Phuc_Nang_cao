#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>

using namespace std;

class PhanSo
{
    public:
        PhanSo(int a=0,int b=1){iTu=a;iMau=b;this->RutGon();};
        void Nhap();
        void Xuat();
        void RutGon();
        int UOC(int,int);
        friend class SoPhuc;
        friend istream& operator >> (istream &is, PhanSo &p);
        friend ostream& operator << (ostream &os, const PhanSo& p);
        friend PhanSo operator+ (PhanSo a,PhanSo b);
        friend PhanSo operator- (PhanSo a,PhanSo b);
        friend PhanSo operator* (PhanSo a,PhanSo b);
        friend PhanSo operator/ (PhanSo a,PhanSo b);
        friend bool operator== (PhanSo a,PhanSo b);
        int GET_iTu ()const
        {
            return this->iTu;
        }
    private:
        int iTu,iMau;

};

#endif // PHANSO_H
