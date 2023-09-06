#include <iostream>
using namespace std;
#define SIZE 50
class Queue
{
    int queue[SIZE];
    int front = -1;
    int rear = -1;

public:
    bool isFull()
    {
        if (rear == SIZE)
        {
            cout << "Queue Overflow";
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            cout << "Stack is Empty";
            return true;
        }
        return false;
    }
    void enqueue(int element)
    {
        if (isFull())
        {
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = element;
        Show();
    }
    int dequeue()
    {
        int x = queue[front];
        front = front + 1;
        if (isEmpty())
        {
            cout << "Queue is already empty";
        }
        return x;
    }
    void Size()
    {
        cout << "Size of the queue is:" << (rear - front + 1);
    }
    void Show()
    {
        int f = front;
        int r = rear;
        cout << "\nQueue has : ";
        while (f <= r)
        {
            cout << queue[f] << " ";
            f = f + 1;
        }
    }
};
int main()
{
    Queue myQueue;
    int k=4;
    myQueue.enqueue(8);
    myQueue.enqueue(10);
    myQueue.enqueue(16);
    myQueue.enqueue(118);
    cout << endl<< "Element dequeued: " << myQueue.dequeue() << endl;
    myQueue.Show();
    return 0;
}
