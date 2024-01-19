// main.cpp
int main() {
    {
        Monitor monitor;
    }
    std::cout << "--------------------------" << std::endl;
    {
        Printer printer;
    }
    std::cout << "--------------------------" << std::endl;
    {
        LED_Monitor led_monitor;
        LCD_Monitor lcd_monitor;
    }
}
// // Outputdevice.h
// #include <iostream>
// using namespace std;

// class OutputDevice{
// public:
//     OutputDevice(){ cout << "OutputDevice constructor" << endl; }
//     ~OutputDevice(){ cout << "OutputDevice destructor" << endl; }
// };
// // Monitor.h
// #include "OutputDevice.h"
// class Monitor: public OutputDevice{
// public:
//     Monitor(): OutputDevice() { cout << "Monitor constructor" << endl; }
//     ~Monitor() { cout << "Monitor destructor" << endl; }
// };
// // Printer.h
// #include "OutputDevice.h"
// class Printer: public OutputDevice{
// public:
//     Printer(): OutputDevice() { cout << "Printer constructor" << endl; }
//     ~Printer() { cout << "Printer destructor" << endl; }
// };
// // LCD_Monitor.h
// #include "Monitor.h"
// class LCD_Monitor: public Monitor{
// public:
//     LCD_Monitor(): Monitor() { cout << "LCD_Monitor constructor" << endl; }
//     ~LCD_Monitor() { cout << "LCD_Monitor destructor" << endl; }
// };
// // LED_Monitor.h
// #include "Monitor.h"
// class LED_Monitor: public Monitor{
// public:
//     LED_Monitor(): Monitor() { cout << "LED_Monitor constructor" << endl; }
//     ~LED_Monitor() { cout << "LED_Monitor destructor" << endl; }
// };
