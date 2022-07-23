#include <iostream>

using namespace std;

const int MAX_STANDARD_SYMBOL_CODE = 32;


size_t str_len(const char *string) {
    size_t length = 0;
    while (string[length] != '\0') {
        ++length;
    }
    return length;
}

size_t size_of_first_word(const char *string) {

    size_t length = 0;
    while (string[length] > MAX_STANDARD_SYMBOL_CODE)
        ++length;
    return length;
}

const char* current_first_word(const char *start) {
    size_t length = size_of_first_word(start);
    char *word = new char[length + 1];
    size_t i = 0;
    while (i < length) {
    //    *(word + i) = *(start + i);
    word[i] = start[i];
        ++i;
    }
    word[length + 1] = '\0';

    return word;
}

void print_backwards(const char *begin, const char *end) {
    if (begin >= end)
        return;

    const char *word = current_first_word(begin);
    size_t offset = str_len(word);
    //искаме да започнем от следващата дума!!!
    while(*(begin+offset) <= MAX_STANDARD_SYMBOL_CODE) {
        begin++;
    }
    print_backwards(begin + offset , end);
    for (size_t i = 0; i < offset; i++) {
        cout << word[i];
    }
    if(begin + offset!= end) {
        std::cout << ' ';
    }

    delete[]word;
    word = NULL;

}

void print_backwards(const char *string) {
    size_t length = str_len(string);
    print_backwards(string, string + length);
}

int main() {
    const char* sentence = "I\tneed a break!";
    //std::cout<<"Hello World!";
    std::cout<< '\n';
    print_backwards(sentence);
    std::cout<< '\n';
    for(int i =0; i< strlen(sentence); i++) {
        std::cout<< sentence[i];
    }
    return 0;
}
