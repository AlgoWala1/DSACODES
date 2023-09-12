#include<iostream>
using namespace std;
//Insertion sort
int main()
{
    int toSort[6] = {2,5,8,32,-11,23};
    int swapvar;
    int k = 0,j;
    //before sort
    cout<<"List: ";
    for(k = 0;k<6;k++)
    {
        cout<<toSort[k]<<" ";
    }
    for(k = 1;k < 6;k++)
    {
      j = k - 1;
      while(j>=0)//Traverse through list
      {
          if(toSort[j]>toSort[k])//continue traversing
          {
              j--;
              if(j = -1)
              {
                  j = 0;
                  swapvar = toSort[j];
                  toSort[j] = toSort[k];
                  toSort[k] = swapvar;
                  break;
              }
          }
          else if(toSort[k]>toSort[j])//switch position with one after j
          {
            j++;
            swapvar = toSort[j];
            toSort[j] = toSort[k];
            toSort[k] = swapvar;
            break;
          }
          else
          {
              break;
          }
      }
    }
    cout<<"\nList: ";
    for(k = 0;k<6;k++)
    {
        cout<<toSort[k]<<" ";
    }
}
