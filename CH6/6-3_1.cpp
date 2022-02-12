// virtual 소멸자
#include <iostream>

class Parent {
    public:
    Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
    virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};

class Child : public Parent {
    public:
    Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
    ~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};

int main() {
    std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
    { Child c; }
    std::cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << std::endl;
    {
        Parent *p = new Child();
        delete p;
    }
}

// child의 소멸자는 생성되지 않기에, 메모리 누수가 발생할 수 있다!
// 따라서 parent의 소멸자를 vitual로 만들어 함께 호출되도록 한다!