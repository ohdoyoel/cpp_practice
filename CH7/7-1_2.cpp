// cin 사용 시 주의할 점

#include <iostream>
using namespace std;

int main() {
    int t;
    while (true) {
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (t == 0) break;
    }
}

// 형식에 맞지 않으면 이상한거 출력!