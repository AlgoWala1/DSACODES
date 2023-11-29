#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> list)
{
    while(!list.empty())
    {
        cout<<list.front()<<" ";
        list.erase(list.begin());
    }
    cout<<endl;
}
//program for quicksort with last element as pivot
vector<int> merge(vector<int> lef,int mid,vector<int> right)
{
     vector<int> ret;
     while(!lef.empty())
     {
         ret.push_back(lef.front());
         lef.erase(lef.begin());
     }
     ret.push_back(mid);
     while(!right.empty())
     {
         ret.push_back(right.front());
         right.erase(right.begin());
     }
     return ret;
}
vector<int> quicksort(vector<int> list)
{
    int pivot = list.back();
    vector<int> copy = list;
    vector<int> lef,right;
    while(!copy.empty())
    {
        if(copy.front() < pivot)
        {
            lef.push_back(copy.front());
        }
        else if (copy.front() > pivot)
        {
            right.push_back(copy.front());
        }
        else{
            break;//end of list is reached
        }
        copy.erase(copy.begin());
    }
    if(lef.size()>=2){
    lef = quicksort(lef);
    }
    if(right.size()>=2)
    {
    right = quicksort(right);
    } 
    if(lef.size() <= 1 || right.size()  <= 1)
    {
        return merge(lef,pivot,right);//nothing or single entry remains
    }
}
int main()
{
    vector<int> list = {4,5,-3,10,2,9,1,0};
    list = quicksort(list);
    print(list);
}
