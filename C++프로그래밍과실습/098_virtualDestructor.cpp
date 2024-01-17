#include "098_virtualDestructor.h"

int main() {
    {
        Monitor monitor;
        //monitor.print();
    }
    std::cout << "--------------------------" << std::endl;
    {
        Monitor* pMonitor = new LED_Monitor(); // Base Class의 포인터로 Derived Class를 가리키고 있는 상황
        if (pMonitor) delete pMonitor; // if문 조건은 항상 만족하고, 그냥 Derived Class의 소멸자가 정상적으로 호출되는지 확인하기 위한 코드
    }
    std::cout << "--------------------------" << std::endl;
    {
        std::unique_ptr<OutputDevice> pMonitor = std::make_unique<LCD_Monitor>();
    }
}
