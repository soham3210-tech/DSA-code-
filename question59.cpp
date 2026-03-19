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
    newNode->next = head;
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
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at Position
void insertPosition(int value, int pos)
{
    Node *newNode = new Node();
    newNode->data = value;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete from Position
void deletePosition(int pos)
{
    if (head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

// Display List
void display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{

    insertBeginning(10);
    insertBeginning(5);
    insertEnd(20);
    insertPosition(15, 3);

    cout << "Linked List: ";
    display();

    deleteBeginning();
    deleteEnd();
    deletePosition(2);

    cout << "After Deletion: ";
    display();

    return 0;
}