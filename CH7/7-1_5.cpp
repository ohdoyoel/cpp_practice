// 조작자

#include <iostream>
#include <string>

int main() {
    int t;
    while (true) {
        std::cin >> std::hex >> t; // 16진수로 값 받기
        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, 'n');
        }
        if (t == 0) break;
    }
}