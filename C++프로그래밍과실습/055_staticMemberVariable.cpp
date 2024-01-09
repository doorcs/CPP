// implement your code

// static 멤버 변수를 "정의" 하고 초기값을 1로 설정합니다.

// 멤버 함수들 구현
#include "055_staticMemberVariable.h"
using namespace std;

int Logger::logLevel = 1;

void Logger::setLogLevel(int level) {
    logLevel = level;
}

void Logger::debug(const string& a, const string& b){
    if(logLevel <= DEBUG) cout << "[DEBUG][" << b << "] " << a << endl;
}

void Logger::info(const string& a, const string& b){
    if(logLevel <= INFO) cout << "[INFO][" << b << "] " << a << endl;
}

void Logger::warning(const string& a, const string& b) {
    if(logLevel <= WARNING) cout << "[WARNING][" << b << "] " << a << endl;
}

void Logger::error(const string& a, const string& b){
    if(logLevel <= ERROR) cout << "[ERROR][" << b << "] " << a << endl;
}
