// cin은 공백을 읽을 수 없다
#include <iostream>
#include <string>

int main() {
    std::string s;
    while (true) {
        std::cin >> s;
        std::cout << "word : " << s << std::endl;
    }
}