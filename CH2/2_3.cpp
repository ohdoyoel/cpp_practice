// 참조자 이해하기
#include <iostream>

int main() {
    int x;
    int& y = x; // y는 x의 별명
    int& z = y; // z는 y의 별명, 즉, x = y = z

    x = 1;
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
    y = 2;
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
    z = 3;
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
}