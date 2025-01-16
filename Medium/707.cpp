/****************************************************************
 *
 * LeetCode 707. Design Linked List
 *
 * *************************************************************/

#include <iostream>


struct Node {
    int val;
    Node* prev;
    Node* next;

    Node(int v = 0) : prev(nullptr), val(v), next(nullptr) {}

    ~Node() {
        if (prev != nullptr) prev->next = next;
        if (next != nullptr) next->prev = prev;
    }

    void insertBetween(Node* p, Node* n) {
        if (p) p->next = this;
        if (n) n->prev = this;
        prev = p;
        next = n;
    }
};


class MyLinkedList {
    Node* head;
    Node* tail;
    int size;

public:


    Node* getNode(int index) {
        if (index < 0 || size <= 0 || index >= size) return nullptr;
        Node* node = head;
        while (index--) node = node->next;
        return node;
    }

public:
    MyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    int get(int index) {
        Node* node = getNode(index);
        if (!node) return -1;
        return node->val;
    }

    void addAtHead(int val) {
        Node* newHead = new Node(val);
        newHead->insertBetween(nullptr, head);
        head = newHead;
        size++;

        if (!tail) tail = head;
    }

    void addAtTail(int val) {
        Node* newTail = new Node(val);
        newTail->insertBetween(tail, nullptr);
        tail = newTail;
        size++;

        if (!head) head = tail;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == size) {
            addAtTail(val);
            return;
        }
        else if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* current = getNode(index);
        Node* node = new Node(val);
        node->insertBetween(current->prev, current);
        size++;
    }

    void deleteAtIndex(int index) {
        Node* temp = getNode(index);

        if (temp == nullptr) return;
        if (temp == head) head = temp->next;
        if (temp == tail) tail = temp->prev;

        delete temp;
        size--;
    }
};