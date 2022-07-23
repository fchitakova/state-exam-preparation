#include <iostream>
#include <vector>

struct SparseMatrixElem {

    unsigned int row;
    unsigned int col;
    int value;

    SparseMatrixElem(unsigned int row, unsigned int col, int value) {
        this->row = row;
        this->col = col;
        this->value = value;
    }
};

std::vector<SparseMatrixElem*> sum_two_sparse_matrices(std::vector<SparseMatrixElem *> matrixA, std::vector<SparseMatrixElem *> matrixB) {
    std::vector<SparseMatrixElem*> resultMatrix;

    //в този цикъл добавяме елементите, докато не сме добавили всички елементи на матрицата с по-малко ненулеви елементи
    size_t i = 0, j = 0;
    while (i < matrixA.size() && j < matrixB.size()) {
        if (matrixA.at(i)->row == matrixB.at(j)->row &&
            matrixA.at(i)->col == matrixB.at(j)->col) {
            resultMatrix.push_back(new SparseMatrixElem(matrixA.at(i)->row, matrixA.at(i)->col,
                                                        matrixA.at(i)->value + matrixB.at(j)->value));
            ++i, ++j;
        }
        else if (matrixA.at(i)->row < matrixB.at(j)->row ||
            (matrixA.at(i)->row == matrixB.at(j)->row && matrixA.at(i)->col < matrixB.at(j)->col)) {
            resultMatrix.push_back(new SparseMatrixElem(matrixA.at(i)->row, matrixA.at(i)->col,
                                                        matrixA.at(i)->value));
            ++i;
        }
        else if(matrixA.at(i)->row > matrixB.at(j)->row || (matrixA.at(i)->row == matrixB.at(j)->row && matrixA.at(i)->col > matrixB.at(j)->col)){
            resultMatrix.push_back(new SparseMatrixElem(matrixB.at(j)->row, matrixB.at(j)->col,
                                                        matrixB.at(j)->value));
            ++j;
        }
    }

    //проверяваме дали има оставащи елементи
    if(i < matrixA.size() || j < matrixB.size())  {
        size_t remaining_elements_count = abs(int(matrixA.size() - matrixB.size()));

        for (size_t i = 0; i < remaining_elements_count; i++) {
            if (matrixA.size() < matrixB.size()) {
                resultMatrix.push_back(matrixB.at(resultMatrix.size() - 1 + i));
            } else {
                resultMatrix.push_back(matrixA.at(resultMatrix.size() - 1 + i));
            }

        }
    }
    return resultMatrix;
}


int main() {
    /**
     *
     * Matrix A -> { 0 0 5 }   Matrix B -> {4 0 1}  Matrix A + B -> {4 0 6}
     *             { 0 1 0 }               {6 0 0}                  {6 1 0}
     *             { 0 0 4 }               {0 0 1}                  {0 0 5}
     *
     */

    std::vector<SparseMatrixElem *> matrixA, matrixB, resultMatrix;

//Test 1
//    matrixA.push_back(new SparseMatrixElem(0, 2, 5));
//    matrixA.push_back(new SparseMatrixElem(1, 1, 1));
//    matrixA.push_back(new SparseMatrixElem(2, 2, 4));
//
//    matrixB.push_back(new SparseMatrixElem(0, 0, 4));
//    matrixB.push_back(new SparseMatrixElem(0, 2, 1));
//    matrixB.push_back(new SparseMatrixElem(1, 0, 6));
//    matrixB.push_back(new SparseMatrixElem(2, 2, 1));

Test 2
    matrixA.push_back(new SparseMatrixElem(0, 1, 1));

    matrixB.push_back(new SparseMatrixElem(0, 0, 2));
    matrixB.push_back(new SparseMatrixElem(1, 1, 4));

    resultMatrix = sum_two_sparse_matrices(matrixA, matrixB);

    for (size_t i = 0; i < resultMatrix.size(); i++) {
        std::cout << '(' << resultMatrix.at(i)->row << ',' << resultMatrix.at(i)->col << ','
                  << resultMatrix.at(i)->value << ")\n";
    }

    return 0;
}
