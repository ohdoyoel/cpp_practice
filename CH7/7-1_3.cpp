// 문자가 입력되면 처리하기

#include <iostream>
#include <string>

int main() {
    int t;
    while (true) {
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) { // failbit or badbit
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();            // 플래그 초기화
            std::cin.ignore(100, '\n');  // 개행문자까지 삭제
        }
        if (t == 1) break;
    }
}