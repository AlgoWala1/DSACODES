#include<iostream>
using namespace std;
class DoubleLL{
    DoubleLL *next;
    DoubleLL *prev;
    int data;
    public:
    DoubleLL(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
    void insertAtindex(DoubleLL *head,int index,int data)
    {
         int i;
         i = 1;
         DoubleLL *walker = head;
         DoubleLL *newEl = new DoubleLL(data);
         while(i!=index)
         {
             walker = walker->next;
             i++;
         }
         newEl->next = walker->next;
         newEl->prev = walker;
         walker->next = newEl;
    }
    void inserAtHead(DoubleLL* &head,int data)
    {
        DoubleLL *temp;
        temp = new DoubleLL(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    void inserAtTail(DoubleLL *head,int data)
    {
        DoubleLL *walker = head;
        DoubleLL *newElement = new DoubleLL(data);
        while(walker->next!=NULL)
        {
            walker = walker->next;
        }
        //end of list
        walker->next = newElement;
        newElement->prev = walker;
    }
    void deleteAtIndex(DoubleLL *head,int index)
    {
        DoubleLL *walker = head;
        DoubleLL *skip;
        int i = 1;
         while(i!=index)
         {
             walker = walker->next;
             i++;
         }
         skip = walker->next->next;
         skip->prev = walker;
         walker->next = skip;
    }
    void print(DoubleLL *head)
    {
        DoubleLL *walker = head;
        cout<<"List contains:";
        while(walker!=NULL)
        {
            cout<<" "<<walker->data;
            walker = walker->next;
        }
        cout<<endl;
    }
};
int main()
{
    DoubleLL *head = new DoubleLL(10);
    head->inserAtTail(head,5);
    head->print(head);
    head->insertAtindex(head,1,7);
    head->print(head);
    head->inserAtTail(head,9);
    head->print(head);
    head->inserAtTail(head,20);
     head->deleteAtIndex(head,2);
    head->print(head);
}
