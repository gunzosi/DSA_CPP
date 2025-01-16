//
// Created by admin on 16/01/2025.
//
#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int value;
        Node* next;

        Node(int value) : value(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void getHead() {
        if (head == nullptr) {
            cout << "Head: null" << endl;
        } else {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail() {
        if (tail == nullptr) {
            cout << "Tail: null" << endl;
        } else {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Value: " << temp->value << endl;
            temp = temp->next;
        }
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    Node* removeLast() {
        if (length == 0) return nullptr;

        Node* temp = head;
        Node* pre = head;

        while (temp->next != nullptr) {
            pre = temp;
            temp = temp->next;
        }

        tail = pre;
        tail->next = nullptr;
        length--;

        if (length == 0) {
            head = nullptr;
            tail = nullptr;
        }

        return temp;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    Node* removeFirst() {
        if (length == 0) return nullptr;

        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        length--;

        if (length == 0) {
            tail = nullptr;
        }

        return temp;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;

        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp != nullptr) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;

        if (index == 0) {
            prepend(value);
            return true;
        }

        if (index == length) {
            append(value);
            return true;
        }

        Node* newNode = new Node(value);
        Node* temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;

        return true;
    }

    Node* remove(int index) {
        if (index < 0 || index >= length) return nullptr;

        if (index == 0) return removeFirst();
        if (index == length - 1) return removeLast();

        Node* prev = get(index - 1);
        Node* temp = prev->next;

        prev->next = temp->next;
        temp->next = nullptr;
        length--;

        return temp;
    }

    void reverse() {
        Node* temp = head;
        head = tail;
        tail = temp;

        Node* after = temp->next;
        Node* before = nullptr;

        for (int i = 0; i < length; i++) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

    Node* findMiddleNode() {
        Node* slowNode = head;
        Node* fastNode = head;

        while (fastNode != nullptr && fastNode->next != nullptr) {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }

        return slowNode;
    }
};

int main() {
    LinkedList list(10); // Create a LinkedList instance
    list.append(20);
    list.printList();

    return 0;
}
