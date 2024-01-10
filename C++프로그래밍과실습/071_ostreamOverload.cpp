// implement your code
#include "Complex.h"
using namespace std;

ostream& operator<<(ostream& cout, const Complex& c){
    return cout << c.r << '+' << c.i << 'i';
}
