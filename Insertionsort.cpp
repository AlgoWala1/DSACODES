#include<iostream>
using namespace std;
#define SIZE 8
//Insertion sort
int main()
{
    int toSort[SIZE] = {2,5,8,23,-11,32,226,-400};
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
      while(j>=0)//Traverse through list
      {
          if(toSort[j]>toSort[k])//continue traversing
          {
              j--;
              if(j = -1)//shift from the starting(start of the list is reached)
              {
                  swap = toSort[k];
                  for(j = k;j>0;j--)
                  {
                      toSort[j] = toSort[j-1];
                  }
                  toSort[0] = swap;
              pass++;
              break;
              }

          }
        else if(toSort[k]>toSort[j])//switch position with one after j(if no switch required code wouldnt enter loop)
          { 
            int b = j+1;
            swap = toSort[k];
            for(j = k;j>b;j--)
            {
                toSort[j] = toSort[j-1];
            }
            toSort[b] = swap;
            break;
          }
          else
          {
              break;
          }
      }
    }
    cout<<"\nList: ";
    for(k = 0;k<SIZE;k++)
    {
        cout<<toSort[k]<<" ";
    }
    cout<<"\nPasses required: "<<pass;
}
