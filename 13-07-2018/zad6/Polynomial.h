//
// Created by Fatmagyul Chitakova on 7.07.22.
//

#ifndef INC_13_07_2018ZAD6_POLYNOMIAL_H
#define INC_13_07_2018ZAD6_POLYNOMIAL_H

#include <vector>

using namespace std;

template<class T>
class Polynomial {
private:
    size_t degree;
    T *coefs;
public:
    Polynomial(T *coefs, size_t degree);

    ~Polynomial();

    T operator()(const T x) const;

    size_t getDegree() const;

    T *getCoeffs() const;

    T& operator[](const size_t deg) const;

    Polynomial<T>& operator+=(const Polynomial<T>&rhs);
    Polynomial<T>& operator-=(const Polynomial<T>&rhs);
    Polynomial<T>& operator*=(const Polynomial<T>&rhs);
};

template<typename T>
Polynomial<T>::Polynomial(T *coefs, size_t degree) {
    this->degree = degree;
    this->coefs = new T[degree + 1];
    for (size_t i = 0; i < degree + 1; i++) {
        this->coefs[i] = coefs[i];
    }
}

template<typename T>
Polynomial<T>::~Polynomial() {
    delete[] coefs;
}

template<typename T>
T Polynomial<T>::operator()(const T x) const {
    T result = coefs[degree];
    for (size_t i = 0; i < degree; i++) {
        result += coefs[i] * pow(x, degree - i);
    }
    return result;
}

template<typename T>
size_t Polynomial<T>::getDegree() const {
    return degree;
}

template<typename T>
T *Polynomial<T>::getCoeffs() const {
    return coefs;
}

template<typename T>
Polynomial<T>&  Polynomial<T>::operator+=(const Polynomial<T>& p2) {
    size_t p1Deg = this->getDegree(), p2Deg = p2.getDegree();
    T *p1Coeffs = this->getCoeffs(), *p2Coeffs = p2.getCoeffs();

    size_t degreeOfSum = p1Deg > p2Deg ? p1Deg : p2Deg;
    vector<T>* coeffsOfSum = new vector<T> (degreeOfSum + 1);

    int index = 0;
    while (p1Deg - index > p2Deg) {
        coeffsOfSum->at(index) = p1Coeffs[index];
        index++;
    }

    while (p2Deg - index > p1Deg) {
        coeffsOfSum->at(index) = p2Coeffs[index];
        index++;
    }

    int i = 0, j = 0;
    (p1Deg > p2Deg) ? i = index : j = index;

    for (; i < degreeOfSum + 1 && j <degreeOfSum + 1; i++, j++) {
        coeffsOfSum->at(i) = p1Coeffs[i] + p2Coeffs[j];
    }

    //ако някои са се съкратили
    i = 0;
    while(coeffsOfSum->at(i) == 0) {
        coeffsOfSum->erase(coeffsOfSum->begin() + i);
    }

    return *this;
}

template <typename T>
Polynomial<T> operator+(const Polynomial<T>& p1, const Polynomial<T>& p2) {
    return p1+=p2;
}

template<typename T>
Polynomial<T> operator-(const Polynomial<T>& p1, const Polynomial<T>& p2) {
    return p1 + (p2 * (-1));
}

template<typename T>
Polynomial<T> operator*(const Polynomial<T>& p, T elem) {
    T* newCoeffs = new T[p.getDegree() + 1];
    for(size_t i = 0; i < p.getDegree() + 1; i++) {
        newCoeffs[i] = elem * p.getCoeffs()[i];
    }
    return *(new Polynomial<T>(newCoeffs, p.getDegree()));
}


template<typename T>
T& Polynomial<T>::operator[](const size_t deg) const {
    if(deg < 0 || deg > this->getDegree()) {
        return *new T;
    }
    return this->getCoeffs()[this-> getDegree() - deg];
}

#endif //INC_13_07_2018ZAD6_POLYNOMIAL_H
