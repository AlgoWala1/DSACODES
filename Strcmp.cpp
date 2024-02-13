#include<iostream>
#include<string.h>
using namespace std;
int stringCmp(string a,string b){
    int i;
    for(i = 0;i < min(a.length(),b.length());i++){
        if(a[i] < b[i]){
            return -1;
        }
        if(a[i] > b[i]){
            return 1;
        }
    }
    if(i == a.length() && i == b.length())return 0;
    if(i == a.length())return -1;
    if(i == b.length())return 1;
}

int main(){
    cout<<"Using self written: "<<stringCmp("cga","agb")<<endl;
    cout<<"Using strcmp(): "<<strcmp("cga","agb");
}
