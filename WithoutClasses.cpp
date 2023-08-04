#include<iostream>
using namespace std;
int main(){
    float tempFar,tempCel;
    cout<<"Enter temperature in farenheits: ";
    cin>>tempFar;
    tempCel = 5*(tempFar-32)/9;
    cout<<endl<<"Temperature in Celcius: "<<tempCel;
}
