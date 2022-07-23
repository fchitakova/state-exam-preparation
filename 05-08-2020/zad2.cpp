#include <iostream>

using namespace std;

struct Node {
    std::string text;
    Node *next;
};

void read_cyclic_list(Node *&head) {
    std::string str;
    Node *newNode = NULL;
    while (std::getline(std::cin, str) && !str.empty()) {
        //правим нов възел с този стринг
        newNode = new Node();
        newNode->text = str;

        if (!head) {
            head = newNode;
        } else {
            Node *current = head;
            //итерираме докато не намерим последния елемент. current-> next проверява това
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    //правим списъка цикличен
    if (newNode) {
        newNode->next = head;
    }
}

void delete_list(Node *&head) {
    //ако списъкът е празен
    if (!head)
        return;
    //трябва да различаваме началото и края!!!
    Node *end = head;
    Node *start = head->next;

    //извъртаме цикъла като местим само началото и приключваме, когато и началото и края сочат към една и съща памет
    while (start != end) {
        Node *current = start;
        start = start->next;
        delete current;
        current = NULL;
    }
    //трием началото===края
    delete head;
    head = NULL;
}

//намиране лексикографски най-малкия низ и връщаме pointer към Node-a, който го съдържа
Node *get_lexicographically_smallest(Node *head) {
    Node *smallest = head;
    Node *start = head->next;
    while (start != head) {
        if (start->text.compare(smallest->text) < 0) {
            smallest = start;
        }
        start = start->next;
    }
    return smallest;
}

size_t get_list_length(const Node *list) {
    size_t length = 0;
    Node *start = list->next;
    do {
        ++length;
        start = start->next;
    } while (start != list->next);
    return length;
}

void delete_between(Node*start, Node* end) {
    Node*temp = start -> next;
    while(temp != end) {
        Node *del = temp;
        temp = temp->next;
        delete del;
        del = NULL;
    }
}

void unite(Node *head) {
    Node *currentStart = head -> next;
    bool appended;
    int length = get_list_length(head);

    while (length > 0) {
        appended = false;
        --length;
        std::string result = currentStart->text;
        while (currentStart->text.at(currentStart->text.length() - 1) == currentStart->next->text.at(0)) {
            result += "-" + currentStart->next->text;
            currentStart = currentStart->next;
            appended = true;
        }
        currentStart = currentStart->next;
        //ако не сме добавили нищо, единствено трябва да преместим previous
        if (!appended) {
            head = head->next;
            continue;
        }
        //изтрий всичко между previous и старт
        delete_between(head , currentStart);

        //създаваме нов Node с новия стринг
        Node *newNode = new Node();
        newNode->text = result;
        head->next = newNode;
        newNode->next = currentStart;

        head = newNode;
    }
}


void print_list_starting_from_smallest_str(Node*list){
    //принтираме резултата
    Node *smallestStr = get_lexicographically_smallest(list);
    std::cout << smallestStr->text << '\n';
    Node *current = smallestStr->next;
    while (current != smallestStr) {
        std::cout << current->text << '\n';
        current = current->next;
    }
}


int main() {
    Node *list = NULL;
    read_cyclic_list(list);
    if (list) {
        unite(list);
        print_list_starting_from_smallest_str(list);
        delete_list(list);
    }
    return 0;
}
