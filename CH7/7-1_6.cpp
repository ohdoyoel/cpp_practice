// streambuf의 조작

#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    char peek = std::cin.rdbuf()->snextc(); // 위치 지정자 한칸 옮기기, 문자 읽기
    if (std::cin.fail()) std::cout << "Failed";
    std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
    std::cin >> s;
    std::cout << "다시 읽으면 : " << s << std::endl;
}