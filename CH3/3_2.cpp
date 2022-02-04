// new로 배열 할당하기

#include <iostream>

int main() {
    int arr_size;
    std::cout << "array size: ";
    std::cin >> arr_size;
    int *list = new int[arr_size]; // int[arr_size] 크기의 메모리 공간을 할당, 주소를 list에 넣음
    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << i << "th element of list: " << list[i] << std::endl;
    }
    delete[] list; // 메모리 할당 해제
    return 0;
}

// 배열 생성: T* pointer = new T[size];
// new - delete는 짝을 이루어야 한다