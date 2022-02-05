// 함수의 오버로딩

#include <iostream>

void print (int x) { std::cout << "int: " << x << std::endl; }
//void print (char x) { std::cout << "char: " << x << std::endl; }
void print (double x) { std::cout << "double: " << x << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b); // 만약 char을 인수로 받는 함수가 없다면 최대한 근접한 int로 찾아감
    print(c);
}

// 근접하는 오버로딩 형변환
// char, unsigned char, short -> int
// unsigned short, -> int or unsigned int
// float -> double
// enum -> int

// 숫자 -> 숫자 (float -> int)
// enum -> 숫자 (enum -> double)
// 