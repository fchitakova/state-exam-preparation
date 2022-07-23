#include <iostream>
#include <vector>

const int MAX_ROWS = 20;
const int MAX_COLS = 30;

using namespace std;

bool checkIfSorted(string row[MAX_COLS], size_t rowSize) {
    for (size_t i = 0; i < rowSize; i++) {
        for (size_t j = i + 1; j < rowSize; j++) {
            if (row[i].compare(row[j]) > 0)
                return false;
        }
    }
    return true;
}

void calculatePasswordPartly(string str, vector<unsigned int> *&v) {
    size_t strlen = str.size();
    for (size_t i = 0, wordLength = 0; i < strlen; i++) {
        while (str.at(i) !=' ' && i < strlen) {
            ++wordLength;
            ++i;
        }
        v->push_back(wordLength);
        wordLength = 0;
        while ((int)str.at(i) == ' ' && i < strlen) ++i;
    }
}

void revealPassword(string library[MAX_ROWS][MAX_COLS], size_t m, size_t n) {
    vector<unsigned int> *password = new vector<unsigned int>();
    for (size_t i = 0; i < m; i++) {
        if (checkIfSorted(library[i], n)) {
            int mediumElem = floor(n / 2);
            string bookName = library[i][mediumElem];
            calculatePasswordPartly(bookName, password);
        }
    }
    for (unsigned int i: *password) {
        std::cout << i << ' ';
    }
    delete password;
}

int main() {
    string library[MAX_ROWS][MAX_COLS] = {
            {"Алгебра",               "Аналитична геометрия",             "Математически анализ"},
            {"Увод в програмирането", "Обектно-ориентирано програмиране", "Структури от данни и програмиране"},
            {"Бази от данни",         "Изкуствен интелект",               "Функционално програмиране"}};


    revealPassword(library, 3, 3);



    return 0;
}
