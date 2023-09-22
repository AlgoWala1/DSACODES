
#include<iostream>
#include<string>
using namespace std;

struct Polynomial{
    int coeff;
    int power;
    Polynomial *next;
};
class PolyList{
    public:
    void setPolynomial(string s,Polynomial *head)//assuming no spaces present
    {
        int i = 0;
        int power,num;
        Polynomial *walker = head;
        Polynomial *temp;
        while(s[i] != ' '){
            if(s[i]=='-')
            {
                i++;
                num = -((int)s[i] - 48);
                //go three positions ahead as x^ format
                i+=3;
                power=(int)s[i] -48;
            }
            else if(s[i] == '+')
            {
                i++;
                num = (int)s[i] - 48;
                i += 3;
                power=(int)s[i] -48; 
            }
            else{//if first char is number
                num = (int)s[0] - 48;
                i = 3;
                power=(int)s[3]-48;
            }
            walker->coeff = num;
            walker->power = power;
            i++;
            walker = walker -> next;
            cout<<num<<" "<<power<<endl;
        }
    }
};
struct Polynomial *poly1;
int main()
{
    PolyList p1;
    poly1 = new Polynomial;
    p1.setPolynomial("3x^4+2x^3",poly1);
}
