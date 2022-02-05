// Date 클래스

#include <iostream>

class Date{
    int year_;
    int month_;
    int day_;

    public:
    void SetDate(int year, int month, int date);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    int GetCurrentMonthTotalDay(int year, int month);

    void ShowDate();

    Date(int year, int month, int day) {
        year_ = year;
        month_ = month;
        day_ = day;
    } // SetDate 역할을 하는 생성자! 쓰레기 값이 들어오는 것을 막는다.

    // 디폴트 생성자
    /*Date(){
        year_ = 2022;
        month_ = 2;
        day_ = 5;
    }*/

}; // 각 멤버 함수들을 밖에서 정의하니 더 보기 깔끔하다!

void Date::SetDate(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDay(int year, int month) {
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && year % 4 == 0 && year % 100 != 0) { // 2월 & 윤년
        return 29;  // 윤년
    } else { // 2월 & ~윤년
        return month_day[month - 1];
  }
}

void Date::AddDay(int inc) {
    while(true) {
        int current_month_total_days = GetCurrentMonthTotalDay(year_, month_);
        if (day_ + inc <= current_month_total_days) {
            day_ += inc;
            return;
        } else {
            inc -= (current_month_total_days - day_ + 1);
            day_ = 1;
            AddMonth(1);
        }
    }
}

void Date::AddMonth(int inc) {
    AddYear((inc + month_ - 1) / 12);
    month_ += inc % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
    std::cout << "오늘은 " << year_ << "년 " << month_ << "월 " << day_ << "일 입니다" << std::endl;
}

int main() {
    Date day(2011, 3, 1); // 생성자를 이용한 초기 값 설정
    // Date day; 로 호출해도 생성자 코드는 호출된다 -> 디폴트 생성자
    // 단, Date day(); 로 쓰지 않도록 주의한다.
    day.ShowDate();
    day.AddDay(30);
    day.ShowDate();
    day.AddDay(2000);
    day.ShowDate();

    day.SetDate(2012, 1, 31);
    day.AddDay(29);
    day.ShowDate();

    day.SetDate(2012, 8, 4);
    day.AddDay(2500);
    day.ShowDate();
    return 0;
}