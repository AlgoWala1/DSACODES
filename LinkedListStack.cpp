#include<iostream>
using namespace std;
#define SIZE 5
class LinkedListStack{
    static int top;
    int data;
    LinkedListStack* next;
    public:
    LinkedListStack(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    void push(LinkedListStack* &head,int data)
    {
        if(top == SIZE)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        LinkedListStack *t = new LinkedListStack(data);
        t->next = head;
        head = t;
        top++;
    }
    void pop(LinkedListStack* &head)
    {
        if(top == 0)
        {
            cout<<"Stack underflow"<<endl;
        }
        head=head->next;
        top--;
    }
    void print(LinkedListStack *head)
    {
        LinkedListStack *TEMP = head;
        cout<<"Stacks contains: ";
        while(TEMP!=NULL)
        {
            cout<<" "<<TEMP->data;
            TEMP = TEMP->next;
        }
        cout<<endl;
    }
};
int LinkedListStack::top = 1;
int main()
{
    
    LinkedListStack *head= new LinkedListStack(5);
    head->print(head);
    head->push(head,4);
    head->print(head);
    head->push(head,6);
    head->pop(head);
    head->print(head);
}
