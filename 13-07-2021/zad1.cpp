#include <iostream>
#include <vector>

using namespace std;

const int MAX_MATRIX_SIZE = 1000;

struct area {
    std::string coordinates_of_fst_cell;
    double average_brightness;

    area(std::string coordinates_of_fst_cell, double average_brightness) {
        this->coordinates_of_fst_cell = coordinates_of_fst_cell;
        this->average_brightness = average_brightness;
    }
};

bool is_in_matrix(size_t i, size_t j, size_t maxRows, size_t max_Cols) {
    return i < maxRows && j < max_Cols;
}

void get_avg_area_brightness(size_t i, size_t j, int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], bool **&can_be_visited, size_t mRows, size_t nCols,
                             double &sum, size_t &cell_cnt) {
    if (!is_in_matrix(i, j, mRows, nCols) || !can_be_visited[i][j])
        return;
    ++cell_cnt;
    sum += matrix[i][j];
    can_be_visited[i][j] = 0;
    get_avg_area_brightness(i - 1, j - 1, matrix, can_be_visited, mRows, nCols, sum, cell_cnt);
    get_avg_area_brightness(i - 1, j, matrix, can_be_visited, mRows, nCols, sum, cell_cnt);
    get_avg_area_brightness(i - 1, j + 1, matrix, can_be_visited, mRows, nCols, sum, cell_cnt);
    get_avg_area_brightness(i, j - 1, matrix, can_be_visited, mRows, nCols, sum, cell_cnt);
    get_avg_area_brightness(i, j + 1, matrix, can_be_visited, mRows, nCols, sum, cell_cnt);
    get_avg_area_brightness(i + 1, j - 1, matrix, can_be_visited, mRows, nCols, sum, cell_cnt);
    get_avg_area_brightness(i + 1, j, matrix, can_be_visited, mRows, nCols, sum, cell_cnt);
    get_avg_area_brightness(i + 1, j + 1, matrix, can_be_visited, mRows, nCols, sum, cell_cnt);

}

bool **create_bool_matrix(int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], size_t mRows, size_t nCols) {
    bool **can_be_visited = new bool *[mRows];
    for (size_t i = 0; i < nCols; i++) {
        can_be_visited[i] = new bool[nCols];
    }
    for (size_t i = 0; i < mRows; i++) {
        for (size_t j = 0; j < nCols; j++) {
            (matrix[i][j] != 0) ? can_be_visited[i][j] = 1 : can_be_visited[i][j] = 0;
        }
    }
    return can_be_visited;
}

void free_matrix_memory(bool **&matrix, int mRows) {
    for (size_t i = 0; i < mRows; i++) {
        delete matrix[i];
        matrix[i] = NULL;
    }
    delete matrix;
    matrix = NULL;
}


void get_avg_brightnesses_in_desc_order(int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], size_t mRows, size_t nCols) {
    bool **can_be_visited = create_bool_matrix(matrix, mRows, nCols);
    vector<area> matrixAreas;


    for (size_t i = 0; i < mRows; i++)
        for (size_t j = 0; j < nCols; j++) {
            if (can_be_visited[i][j]) {
                double sum_of_area = 0.0;
                size_t cell_cnt = 0;
                get_avg_area_brightness(i, j, matrix, can_be_visited, mRows, nCols, sum_of_area, cell_cnt);
                std::string fst_cell = "(" + to_string(i) + ", " + to_string(j) + ")";
                matrixAreas.push_back(area(fst_cell, sum_of_area / cell_cnt));
            }
        }

    std::sort(matrixAreas.begin(), matrixAreas.end(),
              [](area a, area b) { return a.average_brightness > b.average_brightness; });

    for (area i: matrixAreas) {
        std::cout << i.coordinates_of_fst_cell << ' ' << i.average_brightness << ' ';
    }


    free_matrix_memory(can_be_visited, mRows);
}


int main() {
    int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE]=  {{170, 0,   0,   255, 221,   0},
                    {68,  0,   17,  0,   0,   68},
                    {221, 0,   238, 136, 0,   255},
                    {0,   0,   85,  0,   136, 238},
                    {238, 17,  0,   68,  0,   255},
                    {85,  170, 0,   221, 17,  0}};

    get_avg_brightnesses_in_desc_order(matrix, 6, 6);
    //  Програмата ще изведе следните области и средни яркости, сортирани в низходящ ред според яркостта:
    //  (0, 0) 153; (0, 3) 151.11

    return 0;
}
