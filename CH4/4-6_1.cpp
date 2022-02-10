// explicit 사용하기

#include <iostream>
#include <string.h>

class MyString {
    char* string_content; // 문자열 데이터 주소
    int string_length; // 문자열 길이
    int memory_capacity;

    public:
    explicit MyString(int capacity); // 암시적 변환 X & 메모리 할당
    MyString(const char* str); // 문자열로 생성
    MyString(const MyString& str); // 복사 생성자
    ~MyString();
    int length() const;
    int capacity() const;
};

MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char* str) {
    string_length = 0;
    while (str[string_length++]) {
    }
    string_content = new char[string_length];
    memory_capacity = string_length;
    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

void DoSomethingWithString(MyString s) {
    // do something
}

int main() {
    DoSomethingWithString(3); // 오류!
}