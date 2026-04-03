#include "PhanSo.h"
#include <iostream>
using namespace std;
istream& operator >> (istream &is, PhanSo &p)
{
    is >> p.iTu ;
    do
    {
        is>>p.iMau;
    } while (p.iMau==0);
    p.RutGon();
    return is;
}
ostream& operator << (ostream &os,const PhanSo& p)
{
    if (p.iTu == 0) {
        os << 0;
        return os;
    }
    os << p.iTu;
    if (p.iMau != 1)
        os << "/" << p.iMau;

    return os;
}
PhanSo operator+ (PhanSo a,PhanSo b)
{
    PhanSo C;
    C.iTu = a.iTu * b.iMau + b.iTu * a.iMau;
    C.iMau = a.iMau*b.iMau;
    C.RutGon();
    return C;
}
PhanSo operator- (PhanSo a,PhanSo b)
{
    PhanSo C;
    C.iTu = a.iTu * b.iMau - b.iTu * a.iMau;
    C.iMau = a.iMau*b.iMau;
    C.RutGon();
    return C;
}
PhanSo operator* (PhanSo a,PhanSo b)
{
    PhanSo C;
    C.iTu = a.iTu*b.iTu;
    C.iMau = a.iMau*b.iMau;
    C.RutGon();
    return C;
}
bool operator== (PhanSo a,PhanSo b)
{
    return (a.iTu*b.iMau==b.iTu*a.iMau);
}
PhanSo operator/ (PhanSo a,PhanSo b)
{
    if (b.iTu==0)
    {
        cout<<"INVAlID\n";
        return a;
    }
    PhanSo C;
    C.iTu = a.iTu*b.iMau;
    C.iMau = a.iMau*b.iTu;
    C.RutGon();
    return C;
}
void PhanSo::Nhap()
{   cout<<"\nNhap tu:";
    cin>>iTu;
    do
    {
        cout<<"Nhap mau:";
        cin>>iMau;
    } while (iMau==0);
    this->RutGon();
}
void PhanSo::Xuat()
{
    this->RutGon();
    if (this->iMau==0) {
        cout<<"INVALID";
        return;
    }
    cout<<iTu;
    if (iTu!=0&&iMau!=1)
    cout<<"/"<<iMau;
}
int PhanSo::UOC(int a,int b)
{
    a=abs(a);
    b=abs(b);
    if (b==0)
    {
        return a;
    }
    return UOC(b,a%b);
}

void PhanSo::RutGon()
{
    int t = UOC(iTu,iMau);
    iTu/=t;
    iMau/=t;
    if (iMau<0) {
        iTu=-iTu;
        iMau=-iMau;
    }
}
