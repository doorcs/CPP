#include "cell.h"
#include <vector>

class Excel {
public:
    Excel(std::vector<std::vector<Cell>> data);
    double average(int fromRow, int fromCol, int toRow, int toCol) const;
private:
    std::vector<std::vector<Cell>> data;
};

// excel.cpp
// #include "053_excel.h"

Excel::Excel(std::vector<std::vector<Cell>> data){
    this->data = data;
}
//
double Excel::average(int fromRow, int fromCol, int toRow, int toCol) const {
    int cnt = (toRow - fromRow + 1) * (toCol - fromCol + 1);
    double avg = 0;

    for(int row = fromRow; row <= toRow; ++row) {
        for(int col = fromCol; col <= toCol; ++col) {
            if(this->data[row][col].getType() == INT) avg += this->data[row][col].getIntVal();
            else if(this->data[row][col].getType() == DOUBLE) avg += this->data[row][col].getDoubleVal();
            else continue; // 값이 int도 double도 아닐 경우 스킵
        }
    }

    return (avg /= cnt); // 괄호를 안 쳐주면 cnt로 나누지 않은 avg가 그냥 출력된다!!
}
