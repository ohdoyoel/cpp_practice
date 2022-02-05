// 함수의 오버로딩 : 애매해서 오류 발생

#include <iostream>

void print (int x) { std::cout << "int: " << x << std::endl; }
void print (char x) { std::cout << "char: " << x << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c); // 일치하는 것 없음 -> float이니까 double인데 없음 -> 숫자형(int or char)인데 두개나 존재 -> 오류!
}