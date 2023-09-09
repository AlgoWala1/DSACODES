#include<iostream>
#include<malloc.h>
using namespace std;
int main()
{
    int *k,j;
    cout<<"Enter the number of elements:";
    cin>>j;
    k = (int*) malloc(j*sizeof(int));
}
