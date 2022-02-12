// 레퍼런스를 이용한 기반 클래스에 접근

#include <iostream>

class A {
    public:
    virtual void show() { std::cout << "Parent !" << std::endl; }
};

class B : public A {
    public:
    void show() override { std::cout << "Child!" << std::endl; }
};

void test(A& a) { a.show(); }

int main() {
    A a;
    B b;
    test(a);
    test(b); // 파생 클래스는 타입 변환되어 잘 전달된다!

    return 0;
}