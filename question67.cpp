void insertAtPosition(Node* &head, int pos, int value) {
    if (pos == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}