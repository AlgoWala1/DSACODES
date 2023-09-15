#include<iostream>
using namespace std;

class LinkedListStack{
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
        LinkedListStack *t = new LinkedListStack(data);
        t->next = head;
        head = t;
    }
    void pop(LinkedListStack *head)
    {
        head=head->next;
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
