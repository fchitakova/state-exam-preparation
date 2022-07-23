#include <iostream>

const int MAX_SIZE = 100;

int getDigitSize(int n) {
    int digitSize = 0;
    int num = n;
    do {
        ++digitSize;
        num = num / 10;
    } while (num > 0);

    return digitSize;
}

int getNthNumber(int number, int n) {
    int digitSize = getDigitSize(number);

    int num = number;

    for (int i = 0; i < digitSize - n - 1; ++i) {
        num = num / 10;
    }
    return num % 10;
}

bool lessThan(int lhs, int rhs) {
    for (int i = 0; i < lhs && i < rhs; i++) {
        if (getNthNumber(lhs, i) + '0' < getNthNumber(rhs, i) + '0') {
            return true;
        } else if (getNthNumber(lhs, i) + '0' > getNthNumber(rhs, i) + '0') {
            return false;
        }
    }
    return (getDigitSize(lhs) < getDigitSize(rhs));
}

void sortLex(int n, int *&arr) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lessThan(arr[j + 1], arr[j])) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    std::cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
}

int main() {

    int* A = new int[]{13, 14, 7, 2018, 9, 0};
    sortLex(6, A);
    return 0;
}
