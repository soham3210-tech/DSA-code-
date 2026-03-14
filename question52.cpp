#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at Beginning
void insertBeginning(int value)
{

    Node *newNode = new Node();
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at End
void insertEnd(int value)
{

    Node *newNode = new Node();
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Delete from Beginning
void deleteBeginning()
{

    if (head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    Node *last = head;

    while (last->next != head)
    {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    delete temp;
}

// Delete from End
void deleteEnd()
{

    if (head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != head)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = head;
}

// Display Circular List
void display()
{

    if (head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

int main()
{

    insertBeginning(10);
    insertBeginning(5);
    insertEnd(20);
    insertEnd(30);

    cout << "Circular Linked List:\n";
    display();

    deleteBeginning();
    deleteEnd();

    cout << "After Deletion:\n";
    display();

    return 0;
}