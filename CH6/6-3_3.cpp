// 순수 가상 함수 & 추상 클래스

#include <iostream>

class Animal { // 추상 클래스 (설계도)
    public:
    Animal() {}
    virtual ~Animal() {}
    virtual void speak() = 0; // 순수 가상 함수, 즉 반드시 오버라이딩 되어 새롭게 정의되어야 함
};

class Dog : public Animal {
    public:
    Dog() : Animal() {}
    void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
    public:
    Cat() : Animal() {}
    void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    dog->speak();
    cat->speak();
}

// 추상 클래스인 Animal의 객체는 생성할 수 없다