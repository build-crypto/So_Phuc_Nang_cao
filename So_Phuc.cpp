#include "So_Phuc.h"
#include <iostream>
#include "PhanSo.h"
using namespace std;
istream& operator >> (istream &is, SoPhuc &p)
{
    int x,y;
    is>>x;
    is>>y;
    p = SoPhuc(x,y);
     return is;
}
ostream& operator << (ostream &os, const SoPhuc& p)
{
    if (p.iThuc == 0 && p.iAo == 0)
    {
        os<<0<<endl;
        return os;
    }
    if (!(p.iThuc == 0)) os<<p.iThuc;
    if (p.iAo.GET_iTu() > 0 && p.iThuc.GET_iTu()!=0)
    {
        os<<"+";
        if (p.iAo.GET_iTu() != 1) os<<p.iAo;
        os<<"i";
    }
    else if (p.iAo.GET_iTu()==1)
    {
        os<<"i";
    }
    else if (p.iAo.GET_iTu()!=0)
    {
         if (p.iAo.GET_iTu() != -1) os<<p.iAo;
         else cout<<"-";
        os<<"i";
    }
    os<<endl;
    return os;
}
SoPhuc operator+ (SoPhuc a,SoPhuc b)
{
    SoPhuc C;
    C.iThuc = a.iThuc+b.iThuc;
    C.iAo = a.iAo+b.iAo;
    return C;
}
SoPhuc operator- (SoPhuc a,SoPhuc b)
{
    SoPhuc C;
    C.iThuc= a.iThuc-b.iThuc;
    C.iAo= a.iAo-b.iAo;
    return C;
}

SoPhuc operator* (SoPhuc a,SoPhuc b)
{
    SoPhuc C;
    C.iThuc= a.iThuc*b.iThuc-a.iAo*b.iAo;
    C.iAo= a.iThuc*b.iAo+a.iAo*b.iThuc;
    return C;
}
SoPhuc operator/ (SoPhuc a,SoPhuc b)
{
    if (b.iAo == 0 && b.iThuc == 0)
    {
        cout<<"INVALID\n";
        return a;
    }
    SoPhuc C;
    PhanSo mau = b.iThuc*b.iThuc+b.iAo*b.iAo;
    C.iThuc = (a.iThuc*b.iThuc + a.iAo*b.iAo)/mau;
    C.iAo = (a.iAo*b.iThuc - a.iThuc*b.iAo)/mau;
    return C;
}
bool operator== (SoPhuc a,SoPhuc b)
{
    return (a.iThuc==b.iThuc&&a.iAo==b.iAo);
}
void SoPhuc::Nhap()
{
    int x;
   cout<<"Nhap phan Thuc:";
   cin>>x;
   iThuc = PhanSo(x);
   cout<<"Nhap phan Ao:";
   cin>>x;
   iAo = PhanSo(x);
}
void SoPhuc::Xuat()
{
    if (iThuc.iTu == 0 && iAo.iTu==0)
    {
        cout<<0<<endl;
        return;
    }
    if (iThuc.iTu!=0) iThuc.Xuat();
    if (iAo.iTu>0&&iThuc.iTu!=0)
    {
        cout<<"+";
        iAo.Xuat();
        cout<<"i";
    }
    else if (iAo.iTu!=0)
    {
        iAo.Xuat();
        cout<<"i";
    }
}
