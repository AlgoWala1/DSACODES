#include<iostream>
#define SIZE 6
using namespace std;
//Bubble sort using decreasing order(settling of bubbles)
int main()
{
    int list[SIZE] = {3,-5,22,11,40,50};
    int i,j,temp;
    for(i = SIZE-1;i>0;i--)
    {
        for(j = i-1;j>=0;j--)
        {
         if(list[j]<list[j-1])
         {
             temp = list[j];
             list[j] = list[j-1];
             list[j-1] = temp;
         }
        }
    }
    cout<<"sorted: ";
    for(i = 0;i<SIZE;i++)
    {
        cout<<list[i]<<" ";
    }
}
