#include <string>

enum CELL_TYPE {
    STRING,
    INT,
    DOUBLE
};

class Cell {
public:
    Cell();
    Cell(std::string val);
    Cell(int val);
    Cell(double val);

    CELL_TYPE getType() const;
    std::string getStringVal() const;
    int getIntVal() const;
    double getDoubleVal() const;
private:
    CELL_TYPE type;
    std::string stringVal;
    int intVal;
    double doubleVal;
};

// cell.cpp
// #include "053_cell.h"
Cell::Cell(std::string val){
    this->type = STRING;
    this->stringVal = val;
}
Cell::Cell(int val){
    this->type = INT;
    this->intVal = val;
}
Cell::Cell(double val){
    this->type = DOUBLE;
    this->doubleVal = val;
}
CELL_TYPE Cell::getType() const {
    return this->type;
}
std::string Cell::getStringVal() const {
    return this->stringVal;
}
int Cell::getIntVal() const {
    return this->intVal;
}
double Cell::getDoubleVal() const {
    return this->doubleVal;
}
