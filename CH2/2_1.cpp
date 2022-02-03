// 레퍼런스
#include <iostream>

int main() {
    int a = 3;
    int& another_a = a; // 반드시 누구의 별명인지 지정, 불변

    another_a = 5;
    std::cout << "a: " << a << std::endl;
    std::cout << "another_a: " << another_a << std::endl;
}