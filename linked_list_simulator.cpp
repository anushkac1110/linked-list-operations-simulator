#include <iostream>
using namespace std;

// ---------- NODE STRUCTURE ----------
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// ---------- FUNCTION DECLARATIONS ----------
void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromPosition();
void searchElement();
void displayList();

// ---------- INSERT AT BEGINNING ----------
void insertAtBeginning() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout << "Node inserted at beginning.\n";
}

// ---------- INSERT AT END ----------
void insertAtEnd() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        cout << "Node inserted as first element.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    cout << "Node inserted at end.\n";
}

// ---------- INSERT AT POSITION ----------
void insertAtPosition() {
    int value, pos;
    cout << "Enter value: ";
    cin >> value;
    cout << "Enter position: ";
    cin >> pos;

    if (pos <= 0) {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1) {
        insertAtBeginning();
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range.\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted at position " << pos << ".\n";
}

// ---------- DELETE FROM BEGINNING ----------
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "Node deleted from beginning.\n";
}

// ---------- DELETE FROM END ----------
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Last node deleted.\n";
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;

    cout << "Node deleted from end.\n";
}

// ---------- DELETE FROM POSITION ----------
void deleteFromPosition() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (head == NULL || pos <= 0) {
        cout << "Invalid operation.\n";
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range.\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;

    cout << "Node deleted from position " << pos << ".\n";
}

// ---------- SEARCH ELEMENT ----------
void searchElement() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    int key, pos = 1;
    cout << "Enter value to search: ";
    cin >> key;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Element not found in the list.\n";
}

// ---------- DISPLAY LIST ----------
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// ---------- MAIN FUNCTION ----------
int main() {
    int choice;

    do {
        cout << "\n----- Linked List Operations -----\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from position\n";
        cout << "7. Search an element\n";
        cout << "8. Display the list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: deleteFromPosition(); break;
            case 7: searchElement(); break;
            case 8: displayList(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
