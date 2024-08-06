#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
    Queue(int size)
    {
        front=rear=-1;
        this->size=size;
        Q=new Node*[this->size];
    }
    void enqueue(Node *x);
    Node * dequeue();
    void display();
    int isEmpty();
};

void Queue::enqueue(Node *x)
{
    if(rear==size-1)
        printf("Queue is full...\n");
    else
    {
        rear++;
        Q[rear]=x;
    }
}

Node * Queue::dequeue()
{
    Node *x=NULL;

    if(front==rear)
        printf("Queue is empty...\n");
    else
    {
        front++;
        x=Q[front];
    }
    return x;
}

int Queue::isEmpty()
{
    return front==rear;
}

#endif // QUEUE_H
