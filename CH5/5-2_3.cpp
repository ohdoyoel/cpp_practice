// 첨자 연산자 []

#include <string.h>
#include <iostream>

class MyString {
    char* string_content; // 문자열 주소
    int string_length; // 문자열 길이

    int memory_capacity; // 메모리 할당

    public:
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();

    int length();

    void print() const;
    void println() const;

    char& operator[](const int index);
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() { return string_length; }
void MyString::print() const {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];
    std::cout << std::endl;
}
char& MyString::operator[](const int index) { return string_content[index]; }

int main() {
  MyString str("abcdef");
  str[3] = 'c';
  str.println();
}