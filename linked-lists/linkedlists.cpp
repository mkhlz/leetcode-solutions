#include <bits/stdc++.h>  // includes almost all standard headers
using namespace std;

// Node structure (generic)
template <typename T>
struct Node {
    T data;        // value of the node
    Node* next;    // pointer to next node

    Node(T val) {
        data = val;
        next = nullptr;
    }
};

// Linked List class (generic)
template <typename T>
class LinkedList {
public:
    Node<T>* head;

    LinkedList() {
        head = nullptr;
    }

    // Append a new node
    void append(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Print the linked list
    void printList() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList<int> list;
    int input;

    cout << "Enter integers for the linked list (type -1 to finish):" << endl;
    while (true) {
        cout << "> ";
        cin >> input;
        if (input == -1) break; // sentinel value to stop input
        list.append(input);
    }

    cout << "The linked list is: ";
    list.printList();

    return 0;
}

