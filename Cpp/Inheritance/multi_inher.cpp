#include <iostream>
using namespace std;

class animal {
public:
    void sleep();
    void eat();
    animal();
    ~animal();
};

animal::animal() = default;
animal::~animal() = default;
void animal::eat() {
    cout << "eat!" << endl;
}
void animal::sleep() {
    cout << "zzz" << endl;
}

class pet {
public:
    pet();
    void sleep();
    ~pet();
};

pet::pet() {}
pet::~pet() {}
void pet::sleep() {
    cout << "zzzzz" << endl;
}

//多类派生新类cat
class cat : public pet, public animal {
public:
    void mow();
};

void cat::mow() {
    cout << "mooow~" << endl;
}

int main() {
    cat tom;
    tom.animal::sleep();   //在出现名字冲突时需要限定作用域，告诉编译器究竟要使用哪一个
    tom.mow();
    return 0;
}
