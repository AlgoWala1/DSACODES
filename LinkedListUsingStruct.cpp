#include<iostream>
using namespace std;
struct node{
    int value;
    node *next;
};
struct node *head;
class LinkedList{
    public:
    void insertAtHead(node* &head,int value)
    {
        node *temp = new node;
        temp->value = value;
        temp->next = head;
        head = temp;
    }
    void insertAtTail(node* head,int value)
    {
        node *temp = new node;
        node *walker;
        temp->value = value;
        walker = head;
        while(walker->next!=NULL)
        {
            walker = walker->next;
        }
        walker->next = temp;//end of list is reached;
    }
    void printList(node *head)
    {
        node *walker;
        walker = head;
        cout<<"List contains: ";
        while(walker!=NULL)
        {
            cout<<" "<<walker->value;
            walker = walker->next;
        }
        cout<<endl;
    }
    
};
int main()
{
    LinkedList link;
    head = new node;
    head->value = 5;
    link.insertAtHead(head,6);
    link.printList(head);
    link.insertAtTail(head,7);
    link.printList(head);
}
