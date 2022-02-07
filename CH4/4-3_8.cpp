// 생각해보기 문제

class string {
  char *str;
  int len;

 public:
  string(char c, int n);  // 문자 c n개 문자열
  string(const char *s);
  string(const string &s);
  ~string();

  void add_string(const string &s);   // str 뒤에 s
  void copy_string(const string &s);  // str 에 s 를 복사
  int strlen();                       // 길이 리턴
};

string::string(char c, int n){
  *str = c * n;
}

string::string(const char *s) {

}

string::string(const string &s) {

}

string::~string() {
  // delete
}

void string::add_string(const string &s) {

}

void string::copy_string(const string &s) {

}

int string::strlen() { return len; }