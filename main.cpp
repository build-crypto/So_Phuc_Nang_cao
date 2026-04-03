
#include "So_Phuc.h"
#include <iostream>
using namespace std;
void foo(int a)
{
    if (a) cout<<"YES";
    else cout<<"NO";
}

int main()
{
    SoPhuc A,B;
    cout<<"Nhap So Phuc A: \n";
    cin>>A;
    cout<<"Nhap So Phuc B: \n";
    cin>>B;
    cout<<"\nA+B= "<<A+B;
    cout<<"\nA-B= "<<A-B;
    cout<<"\nA*B= "<<A*B;
    cout<<"\nA/B= "<<A/B;
    cout<<"\nA=B? ";
    foo(A==B);
    cout<<"\n(Cong So THUC va So PHUC) VD:\nA+2= "<<A+2;
    cout<<"\nA-2= "<<A-2;
    cout<<"\nA*2= "<<A*2;
    cout<<"\nA/2= "<<A/2;
    return 0;
}
