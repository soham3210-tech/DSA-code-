#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

// Insert at Beginning
void insertBeginning(int value)
{

    Node *newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert at End
void insertEnd(int value)
{

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from Beginning
void deleteBeginning()
{

    if (head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

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

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    delete temp;
}

// Display List
void display()
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{

    insertBeginning(10);
    insertBeginning(5);
    insertEnd(20);
    insertEnd(30);

    cout << "Doubly Linked List:\n";
    display();

    deleteBeginning();
    deleteEnd();

    cout << "After Deletion:\n";
    display();

    return 0;
}