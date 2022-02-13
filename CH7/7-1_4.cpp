// 형식 플래그

#include <string>
#include <iostream>

int main() {
    int t;
    while (true) {
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield); // basefield 초기화, 입력 16진수
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl; // 출력 10진수
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();  // 플래그 초기화
        }
        if (t == 0) break;
    }
}