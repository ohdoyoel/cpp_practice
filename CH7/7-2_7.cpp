// 파일에 쓰기

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream out("test.txt");
    std::string s;
    if (out.is_open()) {
        out << "이걸 쓰자~~";
    }
    return 0;
}