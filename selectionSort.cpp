#include <iostream>

using namespace std;
int main(){
    //selection sort
    int minIndex = 0;
    int swap;
    vector<int> ele = {1,2,3,-4,2,0,7,2,-2,1};
    for(int i = 0;i < ele.size();i++){
        minIndex = i;
        for(int j = i;j<ele.size();j++){
            if(ele[j]<ele[minIndex]){
                minIndex = j;
            }
        }
        swap = ele[minIndex];
        ele[minIndex] = ele[i];
        ele[i] = swap;
    }
    cout<<"Elements after sorting"<<endl;
    for(auto i:ele){
        cout<<i<<" ";
    }
}
