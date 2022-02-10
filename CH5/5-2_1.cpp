// friend 키워드

#include <iostream>

class A {
    private:
    void private_func() {}
    int private_num;
    friend class B; // B는 A의 친구
    friend void func(); // func는 A의 친구
};

class B {
    public:
    void b() {
        A a;
        a.private_func(); // private이지만 친구니까 접근 가능
        a.private_num = 2; 
    }
};

void func() {
    A a;
    a.private_func(); // 얘도 임 ㅇㅇ
    a. private_num = 2;
}

int main() {}

// 짝사랑 관계! B는 A의 private 정보에 접근할 수 있지만, A는 B를 못한다.
// 이를 이용하면 이항 연산자 오버로딩을 처리할 수 있음