// 상수 레퍼런스 하기
#include <iostream>

int main() {
    const int &ref = 4; // 만일 ref를 const로 선언하지 않으면, 값을 고칠 우려가 있어 오류 발생
    std::cout << ref << std::endl;
}