#include <iostream>
#include <memory>
using namespace std;

class OutputDevice{
public:
    OutputDevice(){
        cout << "OutputDevice constructor" << endl;
    }
    virtual ~OutputDevice(){ // 소멸자에 virtual 키워드를 붙여줘야 main이 정상적으로 작동!
        cout << "OutputDevice destructor" << endl;
    }
};
////// 다른 파일들은 실습 096에서 변경 X
//////////////////////////////////////////////////////// Monitor.h
// #include "OutputDevice.h"

// class Monitor: public OutputDevice{
// public:
//     Monitor(){
//         cout << "Monitor constructor" << endl;
//     }
//     ~Monitor(){
//         cout << "Monitor destructor" << endl;
//     }
// };
//////////////////////////////////////////////////////// LCD_Monitor.h
// #include "Monitor.h"
// class LCD_Monitor: public Monitor{
// public:
//     LCD_Monitor(){
//         cout << "LCD_Monitor constructor" << endl;
//     }
//     ~LCD_Monitor(){
//         cout << "LCD_Monitor destructor" << endl;
//     }
// };
//////////////////////////////////////////////////////// LED_Monitor.h
// #include "Monitor.h"
// class LED_Monitor: public Monitor{
// public:
//     LED_Monitor(){
//         cout << "LED_Monitor constructor" << endl;
//     }
//     ~LED_Monitor(){
//         cout << "LED_Monitor destructor" << endl;
//     }
// };
