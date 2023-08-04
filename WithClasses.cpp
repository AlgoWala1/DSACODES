#include<iostream>
using namespace std;
class Temp{
   float temp;
   public:void set(float temp)
   {
     this->temp = temp;
   }
   public:void getTemp()
   {
     float cel;
     cel = 5*(temp - 32)/9;
     cout<<endl<<"Temperature in celcius: "<<cel;
   }
};

int main(){
  Temp entry;
  float T;
  cout<<"Enter temperature in farenheits: ";
  cin>>T;
  entry.set(T);
  entry.getTemp();
}
