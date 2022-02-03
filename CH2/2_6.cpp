// 레퍼런스를 반환하는 함수 (지역 변수)

#include <iostream>

int& function() {
    int a = 2;
    return a; // int& function = a, a를 참조
}

// a 사라짐

int main(){
    int b = function(); // b는 function값, 즉 a 값을 받아야하는데 a는 사라짐
    b = 3;
    return 0;
}

// 오류!
// 교훈: 지역 변수는 레퍼런스로 반환하지 말아야 한다! (Dangling Reference)