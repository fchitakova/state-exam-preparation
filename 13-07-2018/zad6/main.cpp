#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    int coeffsP1[4] = {6,12,-15,0};
    int coeffsP2[4] = {0, -4, 12, -8};

    Polynomial<int> p1(coeffsP1, 3);
    Polynomial<int> p2(coeffsP2, 3);

    Polynomial<int> p3 = p1 - p2;
    std::cout << p3.getCoeffs()[0] << ' '<< p3.getCoeffs()[1] << ' ' << p3.getCoeffs()[2] << ' '<< p3.getCoeffs()[3] << ' '<<endl;
//    std::cout <<p3[-1] << endl;

    return 0;
}
