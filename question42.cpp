#include <iostream>
using namespace std;

#define MAX 5

int q[MAX];
int front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % MAX == front)
    {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    q[rear] = x;
    cout << x << " inserted\n";
}