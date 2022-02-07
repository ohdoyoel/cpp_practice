// MyString 클래스 만들기

#include <iostream>
#include <string.h>

class MyString {
    char* string_content; // 문자열 데이터 주소
    int string_length; // 문자열 길이
    int memory_capacity;

    public:
    MyString(char c); // 문자 하나로 생성
    MyString(const char* str); // 문자열로 생성
    MyString(const MyString& str); // 복사 생성자
    ~MyString();
    int length() const;
    int capacity() const;
    void reserve(int size);
    void print() const;
    void println() const;
    MyString& assign (const MyString& str);
    MyString& assign (const char* str);
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);
    MyString& erase(int loc, int num);
    char at(int i) const;
    int find(int find_from, MyString& str) const;
    int find(int find_from, const char* str) const;
    int find (int find_from, char c) const;
    int compare(const MyString& str) const;
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
    memory_capacity = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        // 메모리 할당 다시 하기
        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    string_length = str.string_length;
    return *this;
}

MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        // 메모리 할당 다시 하기
        delete[] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }
    string_length = str_length;
    return *this;
}

MyString& MyString::insert(int loc, const MyString& str) {
    // 이는 i의 위치 바로 앞에 문자를 삽입함 예를 들어
    // "abc"에 insert(i, 'd') 하면 "adbc"가 됨
    if (loc < 0 || loc > string_length) return *this;
    if (string_length + str.string_length > memory_capacity) {
        if (memory_capacity * 2 > string_length + str.string_length) {
            memory_capacity *= 2;
        } else {
            memory_capacity = string_length + str.string_length;
        }
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];
        // i 이전 복사
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }
        // 삽입되는 문자열 넣기
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }
        // i 이후 복사
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }
        delete[] prev_string_content;
        string_length = string_length + str.string_length;
        return *this;
    }
    // 초과하지 않음 -> 효율적인 insert를 위해, 밀리는 부분을 먼저 뒤로 밀기
    for (int i = string_length - 1; i >= loc; i--) {
        string_content[i + str.string_length] = string_content[i];
    }
    // 삽입되는 문자열 넣기
    for (int i = 0; i < str.string_length; i++) {
        string_content[i + loc] = str.string_content[i];
    }
    string_length = string_length + str.string_length;
    return *this;
}

MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    // loc부터 num개의 문자를 지움
    if (num < 0 || loc < 0 || loc > string_length || loc + num - 1 > string_length) return *this;
    for (int i = loc + num; i < string_length; i++) {
        string_content[i - num] = string_content[i];
    }
    string_length -= num;
    return *this;
}

int MyString::capacity() const {return memory_capacity; }

void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;
        string_content = new char[size];
        memory_capacity = size;
        for (int i = 0; i != string_length; i++) string_content[i] = prev_string_content[i];
        delete[] prev_string_content;
    }
}

char MyString::at(int i) const {
    if (i >= string_length || i < 0) return NULL;
    else return string_content[i];
}

int MyString::find(int find_from, MyString& str) const {
    int i, j;
    if (str.string_length == 0) return -1;
    for (i = find_from; i <= string_length - str.string_length; i++) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) break;
        }
        if (j == str.string_length) return i;
    }
    return -1;
}
int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find (int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
    // (*this) - (str)을 수행하여 1, 0, -1로 그 결과 return
    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i]) return 1;
        else if (string_content[i] < str.string_content[i]) return -1;
    }
    // 끝나지 않으면, 앞부분 까지가 모두 동일한것!
    if (string_length == str.string_length) return 0;
    else if (string_length > str.string_length) return 1;
    return -1;
}

int main() {
    MyString str1("abcdef");
    MyString str2("abcde");
    std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
}