// implement your code
#include "071_ostreamOverload.h"
using namespace std;

ostream& operator<<(ostream& cout, const Complex& c){
    return cout << c.r << '+' << c.i << 'i';
}
