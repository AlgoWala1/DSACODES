#include<iostream>
using namespace std;
bool isfound(int key,int search[],int size)
{
    int start = 0,end = size-1;
    int mid = start+end/2;
    while(start!=end)
    {
    if(key<search[mid])
    {
        end = mid-1;
    }
    else if(key>search[mid])
    {
        start = mid+1;
    }
    else
    {
        return true;
    }
    mid = (start+end)/2;
    }
    return false;
}
int main()
{
    int listSearch[6] = {2,4,10,20,25,29};
    int key;
    cout<<"Enter a number to be searched: ";
    cin>>key;
    if(isfound(key,listSearch,6)){
        cout<<"The element exists in the list";
    }
    else{
        cout<<"The element does not exists in the list";
    }
}
