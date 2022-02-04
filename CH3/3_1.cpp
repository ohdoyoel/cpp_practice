// new, delete

# include <iostream>

int main() {
    int* p = new int; // int 크기의 메모리 공간을 할당, 주소를 p에 넣음
    *p = 10;

    std::cout << *p << std::endl;
    
    delete p; // p에 할당된 공간이 해제
    return 0;
}

// new의 사용: T* pointer = new T