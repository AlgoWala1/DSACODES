#include<iostream>
using namespace std;
#define SIZE 12
//Insertion sort
int main()
{
    int toSort[SIZE] = {2,5,8,23,-11,44,63,32,226,-400,400,4};
    int k = 0,j;
    int pass = 0;
    int swap;
    //before sort
    cout<<"List: ";
    for(k = 0;k<SIZE;k++)
    {
        cout<<toSort[k]<<" ";
    }
     for(k = 1;k < SIZE;k++)
    {
      j = k - 1;
      while(j>=0 && toSort[j]>toSort[j+1])//Traverse through list(with all elements before assumed to be sorted)
      {
          swap = toSort[j];
          toSort[j] = toSort[j+1];
          toSort[j+1] = swap;
          j--;
      }
      pass++;
    }
    cout<<"\nList: ";
    for(k = 0;k<SIZE;k++)
    {
        cout<<toSort[k]<<" ";
    }
    cout<<"\nPasses required: "<<pass;
}
