#include<iostream>
#include<chrono>
#include<vector>
using namespace std;
void print(vector<int> list)
{
    cout<<endl;
    while(!list.empty())
    {
       cout<<" "<<list.front();
       list.erase(list.begin());
    }
}
//considering both are initially sorted
vector<int> merge(vector<int>lHalf,vector<int> rHalf)
{
    vector<int> merged;
   while(!lHalf.empty() && !rHalf.empty())
   {
       if(lHalf.front()<rHalf.front())
       {
           merged.push_back(lHalf.front());
           lHalf.erase(lHalf.begin());
       }
       else
      {
           merged.push_back(rHalf.front());
           rHalf.erase(rHalf.begin());
      }
   }
   while(!lHalf.empty())
   {
       merged.push_back(lHalf.front());
       lHalf.erase(lHalf.begin());
   }
      while(!rHalf.empty())
   {
       merged.push_back(rHalf.front());
       rHalf.erase(rHalf.begin());
   }
   return merged;
}
vector<int> mergeSort(vector<int> list)
{
      if(list.size() == 1)return list;
      vector<int> leftHalf(list.begin(),list.begin() + list.size()/2);
      vector<int> rightHalf(list.begin() + list.size()/2,list.begin() + list.size());
      leftHalf = mergeSort(leftHalf);//goes sorting left ways
      rightHalf = mergeSort(rightHalf);//goes sorting rightways
      return merge(leftHalf,rightHalf);//returns the sort of left and right components to calling components
}
int main()
{
    vector<int> list;
    vector<int> copy;
    list = {14,4,7,1,10,20,30,-4};
    auto start_time = chrono::high_resolution_clock::now();
    cout<<"List before sorting";
    list = mergeSort(list);
    auto end_time = chrono::high_resolution_clock ::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "\nTime taken by merge sort: " << duration.count() << " microseconds" << endl;
    //cout<<"\nSorted list:"<<endl;
    print(list);
}
