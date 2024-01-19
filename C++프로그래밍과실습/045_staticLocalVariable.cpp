#include "045_staticLocalVariable.h"

void inc(std::promise<int> && result) {
    //your implementation
    int COUNTER = 0;
    for(int i=0; i<100000; i++) COUNTER++;
    result.set_value(COUNTER);
}

int getCounter() {
    // your implementation
    static int COUNTER=0; // 함수 내부 변수는 원래 함수 호출시마다 초기화되지만, static 키워드로 선언된 변수는 최초 한 번만 초기화된다! (재호출시 초기화 구문은 무시됨)
    COUNTER++;
    return COUNTER;
}
