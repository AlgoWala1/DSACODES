#include<iostream>
using namespace std;
//Circular Queue
// -1 is setting for empty space for element
class myQueue{
    int front = 0;
    int rear = 0;
    int size;
    int *arr;
    public:myQueue(int size)
    {
        this->size = size;
        arr = new int(this->size);
    }
    public:void pop(){
        int c;
        if (isEmpty())
        {
            cout<<"Queue is empty";
        }
        else{
            c = arr[front];
            arr[front] = -1;
            if (front == this->size-1)
            {
                front = 0;
            }
            else{
                front++;
            }
            cout<<"Pop performed -> "<<c<<endl;

        }
        
    }
    public:bool isEmpty()
    {
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }
    public:void push(int entry)
    {
        if((rear == front-1) || (front == 0 && rear == this->size)){
            cout<<"Queue is Full "<<"("<<entry<<")"<<" not allowed "<<endl;
        }
        else{
            if (rear == this->size)
            {
                rear = 0;
                arr[rear] = entry;
            }
            else{
            arr[rear] = entry;
            rear++;
            }
        }
    }
    public:void get()
    {
        cout<<"Queue elements: ";
        for(int k=0;k<this->size;k++)
        {
            if (arr[k] == -1){//Empty
                continue;
            }
            else{
                cout<<" "<<arr[k]<<" ";
            }
        }
        cout<<endl;
    }
};
int main(){
    myQueue q(4);
    q.push(4);
    q.push(20);
    q.push(5);
    q.push(24);
    q.push(30);
    q.get();
    q.pop();
    q.push(3);
    q.pop();
    q.pop();
    q.push(440);
    q.get();
    return 0;
}
