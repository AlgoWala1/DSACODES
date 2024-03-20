#include <iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> num = {1,2,0,3,-1};
    int leftSum = 0;
    int rightSum;
    for(auto i:num){
        rightSum+=i;
    }
    for(int i = num.size() -1;i > -1;i--){
        rightSum-=num[i];
        if(leftSum == rightSum){
            cout<<i;
            exit(0);
        }
        leftSum += num[i];
    }
    cout<<"not found";
}
