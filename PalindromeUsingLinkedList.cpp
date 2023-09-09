#include<iostream>
#include<string>
using namespace std;

class LinkedList{
    char letter;
    LinkedList *next;
    LinkedList *prev;
    public:
    LinkedList(char letter)
    {
        this->letter = toupper(letter);
    }
    void append(LinkedList* &head,char newValue)
    {
        LinkedList *iterate;
        LinkedList *temp = new LinkedList(toupper(newValue));
        iterate = head;
        while(iterate!=NULL)
        {
            if(iterate->next == NULL)
            {
                temp->prev = iterate;
                break;
            }
            iterate = iterate->next;
        }
        iterate->next = temp;
    }
    void isPalindrome(LinkedList *head)
    {
        bool isPalindrome = true;
        LinkedList *start = head;
        LinkedList *tail = head;
        while(tail!=NULL)
        {
            if(tail->next == NULL)//we get to tail
            {
                break;
            }
            tail = tail->next;
        }
        while(tail!=start)
        {
            if(start->letter != tail->letter)
            {
                isPalindrome = false;
                break;
            }
            tail = tail->prev;
            start = start->next;
        }
        if(isPalindrome)
        {
            cout<<"Is a palindrome";
        }
        else{
            cout<<"Is not a palindrome";
        }
    }
    
};
int main()
{
    LinkedList *head = new LinkedList('O');
    head->append(head,'T');
    head->append(head,'T');
    head->append(head,'O');
    head->isPalindrome(head);
}
