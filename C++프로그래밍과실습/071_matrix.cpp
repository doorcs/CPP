#include "071_matrix.h"

matrix::matrix(initializer_list<initializer_list<int>> values){
    row = values.size();
    col = values.begin()->size();
    data = new int[row * col];

    int index = 0;
    for(auto list: values){
        for(auto elem: list){
            data[index++] = elem;
        }
    }
}
matrix::matrix(const matrix& other){
    row = other.row;
    col = other.col;
    data = new int[row * col];
    copy(other.data, other.data + row * col, data);
}
matrix::~matrix() noexcept{
    delete[] data;
}

matrix& matrix::operator+(const matrix& other){
    for(int i=0; i<row*col; i++) data[i] += other.data[i];
    return *this;
}
matrix& matrix::operator=(const matrix& other){
    if(this != &other){
        row = other.row;
        col = other.col;
        delete[] data;
        data = new int[row * col];
        copy(other.data, other.data + row * col, data);
    }
    return *this;
}

matrix& matrix::inverse(){
    if(row * col == 0) return *this;

    int det = data[0]*data[3] - data[1]*data[2];

    matrix* inv = new matrix{{data[3]/det, -data[1]/det}, {-data[2]/det, data[0]/det}};

    return *inv;
}
ostream& operator<<(ostream& os, const matrix& m){
    if(m.row * m.col == 0) os << "||" << endl;
    else{
        os << "|" << m.data[0] << ' ' << m.data[1] << "|" << endl;
        os << "|" << m.data[2] << ' ' << m.data[3] << "|" << endl;
    }
    return os;
}
