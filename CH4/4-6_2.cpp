// mutable

# include <iostream>

class A {
    mutable int data_; // const 멤버 함수에서 멤버 변수의 값을 바꿀 수 있다.
    public:
    A (int data) : data_(data) {}
    void DoSomething(int x) const {
        data_ = x; // 불가능
    }
    void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}

// const를 없애면 되지 않나? mutable은 왜 필요한가?
// 읽기 함수임에도 불구하고 특정 변수의 값을 바꿔야 편리한 경우 존재