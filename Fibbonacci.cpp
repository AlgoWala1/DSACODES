#include<iostream>
#define Boundary 10
using namespace std;
///recursive call to print first Boundary value fibonacci numbers
///using logic a2 = a1+a0, a3 = a2+a1
void Fibbo(int iter,int a0,int a1)
{
    if(iter == Boundary)
    {
     return;   
    }
    int swap;
    swap = a1;
    cout<<a0<<" ";//print current fibonacci number then the next
    a1 = a1+a0;
    a0 = swap;
    iter++;
    Fibbo(iter,a0,a1);
}
int main()
{
    cout<<"Series: ";
    Fibbo(0,0,1);
}
