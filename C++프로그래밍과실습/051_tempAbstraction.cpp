// implement your code
#include <string>
#include <iomanip>
#include <sstream>
#include "Temperature.h"

std::string Temperature::print() const {
    std::stringstream ss;
    ss << std::fixed;
    ss << std::setprecision(1);
    if (this->scale == FAHRENHEIT) {
        ss << this->temperature << " F\n";
    } else {
        ss << this->temperature << " C\n";
    }
    return ss.str();
}

Temperature::Temperature(double temp, SCALE scale){
    this->temperature = temp;
    this->scale = scale; // this는 자신을 가리키는 포인터!!
}

Temperature Temperature::add(Temperature other){ // 클래스도 일종의 네임스페이스
    if (this->scale != other.scale) {
        if (this->scale == CELSIUS) other.convertToCelsius();
        else other.convertToFahrenheit();
    }
    return Temperature(this->temperature + other.temperature, this->scale);
}

void Temperature::convertToCelsius() {
    this->temperature = (this->temperature - 32) * 5/9;
}
void Temperature::convertToFahrenheit() {
    this->temperature = (this->temperature * 9/5) + 32;
}
