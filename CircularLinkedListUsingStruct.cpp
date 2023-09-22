#include<iostream>
using namespace std;
struct node{
    int value;
    node *next;
};
struct node *head;
class CircularLinkedList{
    public:
    void insert(node* head,int value)
    {
        node *temp = new node;
        node *walker;
        temp->value = value;
        walker = head;
        //if empty list
        if(head->next == NULL)
        {
            head->next = temp;
            temp->next = head;
            return;
        }
        while(walker->next!=head)
        {
            walker = walker->next;
        }
        temp->next = head;
        walker->next = temp;//end of list is reached;
    }
    void printList(node *head)
    {
        node *walker;
        walker = head;
        cout<<"List contains: ";
        cout<<walker->value;
        walker = walker->next;
        while(walker!=head)
        {
            cout<<" "<<walker->value;
            walker = walker->next;
        }
        cout<<endl;
    }
    //For middle
    void insert(node *head,int pos,int value)
    {
        int walkerpos = 0;
        node *temp = new node;
        node *walker = head;
        node *add = new node;
        add->value = value;
        while(walkerpos!=pos)
        {
            walker = walker->next;
            walkerpos++;
        }
        temp = walker->next;
        walker->next = add;
        add->next = temp;
    }
    //For middle
    void deletePos(node *head,int pos)
    {
        int walkerpos = 0;
        node *nex;
        node *walker = head;
        while(walkerpos!=pos-1)
        {
            walker = walker->next;
            walkerpos++;
        }
        nex = walker->next;
        nex = nex->next;
        walker->next = nex;
    }
};
int main()
{
    CircularLinkedList link;
    head = new node;
    head->value = 5;
    link.insert(head,6);
    link.insert(head,7);
    link.insert(head,11);
    link.printList(head);
    link.insert(head,2,4);
    link.printList(head);
    link.deletePos(head,2);
    link.printList(head);
    
}
