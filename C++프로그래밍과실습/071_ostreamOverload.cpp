// implement your code
#include "071_ostreamOverload.h"
using namespace std;

ostream& operator << (ostream& os, const Complex& c){
    return os << c.r << '+' << c.i << 'i';
}
