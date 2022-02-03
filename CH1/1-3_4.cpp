// 행운의 숫자 맞추기
#include <iostream>

int main(){
    int lucky_number = 3;
    std::cout << "내 비밀의 수를 맞춰 바" << std::endl;

    int user_input;

    while (1) {
        std::cout << "입력 : ";
        std::cin >> user_input;
        if (lucky_number == user_input) {
            std::cout << "정답~" << std::endl;
            break;
        } else {
            std::cout << "오답~" << std::endl;
        }
    }

    return 0;
}