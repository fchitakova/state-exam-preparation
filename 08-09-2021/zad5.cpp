#include <iostream>
using std::cout;

//ПОДУСЛОВИЕ 2А)
// class test {
//public:
//    int var;
//
//    test() {cout << "test()\n"; var = 0;}
//
//    test &operator=(const test&other) {
//        if (this != &other) {
//            cout << "copy\n";
//            var = other.var;
//        } else {
//            cout << "self-assignment\n";
//        }
//        return *this;
//    }
//
//    static test &instance() {
//        static test obj;
//        return obj;
//    }
//
//    test& self() {return *this; }
//    void _oncreate() { cout << "_oncreate()\n"; }
//    void _oncopy() { cout<<"_oncopy()\n";  };
//};
//
//
//int main() {
//    test& r1 = test::instance();
//    test& r2 = test::instance();
//    r1.var = 10;
//    cout << r2.var << "\n";
//    r1.self() = r2;
//    new test[3];
//
//    return 0;
//}

//ПОДУСЛОВИЕ 2Б)

class foo {
public:
    foo(int){}
};

void g(foo) {}
void f(int) {}

int main() {
    g(5);
    //f(foo(5));
    foo('a');
    return 0;
}
