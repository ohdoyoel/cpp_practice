// 참조자가 아닌 값을 리턴하는 함수(상수 리턴)를 참조자로 받기

#include <iostream>

int function() {
    int a = 5;
    return a;
}

// a 사라짐

int main(){
    const int& c = function(); // const 안쓰면 오류
    std::cout << c << std::endl;
    return 0;
}

// const 레퍼런스는 리턴값의 수명을 연장시킨다!