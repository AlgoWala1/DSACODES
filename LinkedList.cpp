#include<iostream>
using namespace std;

class LinkedList{
    public:
    int data;
    LinkedList *next;
    LinkedList(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insertAtHead(LinkedList* &head ,int newdata)
{
    LinkedList *temp = new LinkedList(newdata);
    temp->next = head;
    head = temp;
}
void insertAtTail(LinkedList* &h,int newdata)
{
    LinkedList *temp,*t;
    t = h;
    temp = new LinkedList(newdata);
    while(t!= NULL)
    {
        if(t->next == NULL)
        {
            break;
        }
        t = t->next;
    }
    t->next = temp;
}
void print(LinkedList* h)
{
    LinkedList* ele = h
    cout<<"The list is: ";
    while(ele != NULL)
    {
        cout<<ele->data<<" ";
        ele = ele->next;
    }
    cout<<endl;
}
int main()
{
    LinkedList *L = new LinkedList(5);
    insertAtHead(L,16);
    insertAtHead(L,118);
    insertAtHead(L,10);
    print(L);
    insertAtTail(L,12);
    print(L);
}
