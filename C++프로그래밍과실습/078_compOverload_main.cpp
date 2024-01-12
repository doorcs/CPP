#include "078_compOverload.h"

int main() {
    std::map<int, Student> student_grades;

    // Insert 5 student objects into the map

    student_grades[1] = {1, "Bob", 90}; // key를 이용해 맵에 접근할 때, 맵에 해당 key가 존재하지 않는다면 맵은 자동으로 value의 기본 생성자를 호출하기 때문에
//  student_grades[1] = Student(); 
//  student_grades[1] = {1, "Bob", 90}; 사실은  두 단계로 나누어 실행되는 셈이다. 따라서 클래스의 기본 생성자`Student()`가 정의되어 있지 않다면 에러가 발생한다.

    // student_grades.emplace(1, Student{1, "Bob", 90}); 처럼 사용하면 기본 생성자가 없어도 오류가 발생하지 않는다!
    student_grades[2] = {2, "Alice", 85};
    student_grades[3] = {3, "David", 80};
    student_grades[4] = {4, "Eve", 95};
    student_grades[5] = {5, "Charlie", 88};

    std::cout << "********** In order of their id" << std::endl;
    for (const auto& [id, student] : student_grades) {
        std::cout << student << std::endl;
    }

    std::vector<Student> students;

    // sort(student_grades.begin(), student_grades.end(), compareByGrade);

    // Since std::sort requires random access iterators while std::map's iterators are bidirectional iterators,
    // this leads to an error.

    for (const auto& [id, student] : student_grades) {
        students.push_back(student);
    }

    std::sort(students.begin(), students.end(), compareByGrade); // std::sort(begin, end, func);

    std::cout << "********** In descending order of their grade" << std::endl;
    for (const auto& student : students) {
        std::cout << student << std::endl;
    }

    std::sort(students.begin(), students.end()); // sort()의 세번째 인자가 없을 경우에는 < 연산자를 사용!!

    std::cout << "********** In order of their name" << std::endl; // 이름순으로 정렬될 수 있도록 클래스의 < 연산자를 오버로딩
    for (const auto& student : students) {
        std::cout << student << std::endl;
    }
    return 0;
}
