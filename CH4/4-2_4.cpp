#include <iostream>

class Date{
    int year_;
    int month_;
    int day_;
    
    public:
    void ShowDate();

    Date() {
        std::cout << "기본 생성자 호출!" << std::endl;
        year_ = 2022;
        month_ = 2;
        day_ = 5;
    }

    Date(int year, int month, int day) {
        std::cout << "인자 3개인 생성자 호출!" << std::endl;
        year_ = year;
        month_ = month;
        day_ = day;
    }
};

void Date::ShowDate() {
    std::cout << "오늘은 " << year_ << "년 "
    << month_ << "월 " << day_ << "일 입니다" << std::endl;
}

int main() {
    Date day = Date();
    day.ShowDate();
    Date day2(2022, 2, 5);
    day2.ShowDate();
    
    return 0;
}