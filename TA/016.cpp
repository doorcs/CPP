#include <iostream>
#include <memory>
using namespace std;

void update(int* a, int* b); // 함수의 선언과 정의를 분리. 여기서는 선언만

int main(){
    unique_ptr<int> pa(new int);
    unique_ptr<int> pb(new int);

    cin >> *pa >> *pb;

    update(pa.get(), pb.get()); // `unique_ptr`의 `.get` 메서드는 `unique_ptr` 객체의 메모리 소유권을 유지하면서 객체가 관리하는 원시 포인터(raw pointer)를 반환함
    cout << *pa << '\n' << *pb;
} // main 함수의 scope가 끝나며 `unique_ptr` 객체들이 소멸됨
  // `unique_ptr` 객체는 소멸시에 메모리를 자동으로 해제해주기 때문에, `delete`가 없어도 메모리 누수가 일어나지 않음

void update(int* a, int* b){ // 앞서 선언했던 함수를 정의. 두개의 `int`형 포인터를 파라미터로 받으며 반환값은 없다(void)
    int temp = *a;
    *a = *a + *b;
    *b = temp - *b;
}
