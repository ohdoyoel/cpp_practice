// 생각해볼 문제
#include <iostream>

class Date {
    // 멤버 변수들
    int year_;
    int month_; // 1~12
    int day_; // 1~31 단, 2월은 1~29
    
    // 멤버 함수들
    public:
    void SetDate(int year, int month, int date) {
        year_ = year;
        month_ = month;
        day_ = date;
    }
    void AddDay(int inc) {
        day_ += inc;
        if (month_ != 2) {
            if (day_ > 31) {
                day_ %= 31;
                month_++;
            }
        } else {
            if (day_ > 29) {
                day_ %= 29;
                month_++;
            }
        }
    }
    void AddMonth(int inc) {
        month_ += inc;
        if (month_ > 12) {
            month_ %= 12;
            year_++;
        }
    }
    void AddYear(int inc) {
        year_ += inc;
    }

    void ShowDate() {
        std::cout << "오늘 날짜는 " << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
    }
};

int main() {
    Date date; // 객체
    
    // 인스턴스 함수
    date.SetDate(2022, 2, 5); // 오늘
    date.AddDay(40); // 40일 후의 날짜는?
    date.ShowDate(); // 보여줭
}