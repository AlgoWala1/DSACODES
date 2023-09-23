#include<iostream>
#include<string>
using namespace std;
class Polynomial{
    int power;
    int coeff;
    Polynomial *next;
    public:
    void setPolynomial(string s,Polynomial *head)//assuming no spaces present creates a Polynomial from string
    {
        int i = 0;
        int power,num;
        Polynomial *curr = head;
        while(s[i] != ' '){
            Polynomial *temp = new Polynomial;
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
                i += 3;
                power=(int)s[3]-48;
            }
           i++;
           curr->power = power;
           curr->coeff = num;
           curr->next = temp;
           curr=temp;
        }
    }
    void add(Polynomial *p3,Polynomial *p1,Polynomial *p2)
    {
        Polynomial *temp3 = p3;
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->power== p2->power)//if equal
            {
                temp3->power = p1->power;
                temp3->coeff = p1->coeff + p2->coeff;
                temp3->next = new Polynomial;
                temp3 = temp3->next;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if(p1->power > p2->power)
            {
                temp3->power = p1->power;
                temp3->coeff = p1->coeff;
                temp3->next = new Polynomial;
                temp3 = temp3->next;
                p1 = p1->next;
            }
            else
            {
                temp3->power = p2->power;
                temp3->coeff = p2->coeff;
                temp3->next = new Polynomial;
                temp3 = temp3->next;
                p2 = p2->next;
            }
        }
    }
    void print(Polynomial *head)
    {
        if(head==NULL)
        {
            return;
        }
        else{
            if(head->coeff==0){
                return;
            }
            else{
                cout<<" + "<<head->coeff<<"x^"<<head->power;
            }
            print(head->next);
            return;
        }
    }
};
int main()
{
    Polynomial *p1= new Polynomial;
    Polynomial *p2 = new Polynomial;
    Polynomial *sum = new Polynomial;
    p1->setPolynomial("4x^6+5x^4+3x^3+4x^2+3x^1 ",p1);
    p2->setPolynomial("4x^5+4x^3-2x^1 ",p2);
    sum->add(sum,p1,p2);
    cout<<"Sum of Polynomials: 4x^6+5x^4+3x^3+4x^2+3x^1 and 4x^5+4x^3-2x^1"<<endl;
    cout<<"Is ";
    sum->print(sum);
}
