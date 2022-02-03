// 레퍼런스를 반환하는 함수 (외부 변수)

#include <iostream>

int& function(int& a) { // int& a = b
    a = 5; // b = 5
    return a; // 레퍼런스 a = b = 5를 반환
}

int main(){
    int b = 2;
    int c = function(b);
    std::cout << c << std::endl;
    return 0;
}