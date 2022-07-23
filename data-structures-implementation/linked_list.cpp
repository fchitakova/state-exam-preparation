#include <iostream>

struct Node {
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        this->next = NULL;
    }

    Node(int value, Node *next) {
        this->value = value;
        this->next = next;
    }
};

class LinkedList {
private:
    Node *head;
    Node *end;
public:
    LinkedList() {
        head = end = NULL;
    }

    ~ LinkedList() {
        deleteLinkedList();
    }

    void insertElemAtBeginning(int value) {
        Node *newNode = new Node(value);
        if (head == NULL) {
            head = end = newNode;
            return;
        }
        Node *snd = head;
        newNode->next = snd;
        head = newNode;
    }

    void insertElemInTheEnd(int value) {
        Node *newNode = new Node(value);
        if (end == NULL) {
            head = end = newNode;
        }
        Node *last = end;
        last->next = newNode;
        end = newNode;
    }

    void insertElemAtPos(int position, int value) {
        int index = 0;
        Node *temp = head;
        while (index < position - 1) {
            temp = temp->next;
            ++index;
        }

        Node *tempNext = temp->next;
        Node *newNode = new Node(value, tempNext);
        temp->next = newNode;
    }

    Node *searchElem(int value) {
        if (head && head->value == value)
            return head;
        Node *temp = head->next;
        while (temp) {
            if (temp->value == value)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void traverseAndPrint() {
        Node *temp = head;
        while (temp) {
            std::cout << temp->value << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }

    void deleteElem(int value) {
        //ако елементът, който трием е в началото
        if (head && head->value == value) {
            Node *toDel = head;
            if (head == end) {
                end = head->next;
            }
            head = head->next;
            delete toDel;
            toDel = NULL;
        }

        Node *temp = head;
        while (temp && temp->next) {
            if (temp->next->value == value) {
                Node *toDel = temp->next;
                temp->next = toDel->next;

                delete toDel;
                toDel = NULL;
            }
            temp = temp->next;
        }
    }

private:
    void deleteLinkedList() {
        Node *temp = head;
        while (temp) {
            Node *p = temp;
            temp = temp -> next;
            delete p;
            p = NULL;
        }
        head = end = NULL;
    }
};

int main() {
    LinkedList *l = new LinkedList();
    l->insertElemAtBeginning(1);
    l->traverseAndPrint();
    l->insertElemInTheEnd(3);
    l->traverseAndPrint();
    l->insertElemAtPos(1, 2);
    l->traverseAndPrint();
    l->insertElemAtBeginning(8);
    l->traverseAndPrint();
    l->insertElemInTheEnd(999);
    l->traverseAndPrint();
    l->insertElemAtPos(2, -6);
    l->traverseAndPrint();

    l->deleteElem(3);
    l->traverseAndPrint();
    l ->deleteElem(8);
    l -> traverseAndPrint();
    l->deleteElem(999);
    l->traverseAndPrint();


    delete l;
    return 0;
}
