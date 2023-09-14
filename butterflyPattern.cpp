#include<iostream>
using namespace std;
int main()
{
    int i,j,k;
   for (i = 1;i<=5;i++)
    {
        for(j = 1;j<=i;j++)
        {
            cout<<"*";
        }
        k = 2*(5-i);
        for(j = 0;j<k;j++)
        {
            cout<<" ";
        }
        for(j = 1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for (i = 5;i>=1;i--)
    {
        for(j = 1;j<=i;j++)
        {
            cout<<"*";
        }
        k = 2*(5-i);
        for(j = 0;j<k;j++)
        {
            cout<<" ";
        }
        for(j = 1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
