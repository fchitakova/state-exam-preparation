#include <iostream>

using namespace std;

class Counter {
private:
    static int count;
public:
    Counter() {
        ++count;
        std::cout << "Counter constructor";
    }

    ~Counter() {
        --count;
    }

    Counter(const Counter&other) {
        ++count;
    }

    Counter&operator=(const Counter&other) {
        return *this;
    }
    static int GetObjCount() {
        return count;
    }
};
int Counter::count;

class Derived: public Counter {};

int main() {
    Derived d1;
    std::cout << Derived::GetObjCount() << endl;
    // горният ред ще изведе:

    Counter c;
    std::cout << Counter::GetObjCount() << endl;
//    // горният ред ще изведе:
//
    Counter* p = new Derived;
    std::cout << Counter::GetObjCount() <<endl ;
    // горният ред ще изведе:

    std::cout << Derived::GetObjCount()<< endl;
//    // горният ред ще изведе:

    delete p;
    std::cout << Counter::GetObjCount() << endl;
//    // горният ред ще изведе:
//
    std::cout << Derived::GetObjCount() << endl;
//    // горният ред ще изведе:



    return 0;
}