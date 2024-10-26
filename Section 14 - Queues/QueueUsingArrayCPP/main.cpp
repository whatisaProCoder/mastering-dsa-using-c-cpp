#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(int size)
    {
        front=rear=-1;
        this->size=size;
        Q=new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if(rear==size-1)
        printf("Queue is full...\n");
    else
    {
        rear++;
        Q[rear]=x;
    }
}

int Queue::dequeue()
{
    int x=-1;

    if(front==rear)
        printf("Queue is empty...\n");
    else
    {
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::display()
{
    int i;

    for(i=front+1;i<=rear;i++)
        printf("%d ",Q[i]);
    printf("\n");
}

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    return 0;
}
