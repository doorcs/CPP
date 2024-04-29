- ranges 라이브러리의 적용범위 공부 && 정리하기. 주로 <`algorithm`> 헤더에 있는 알고리즘  
- begin, end로 호출할 수 있는 <`numeric`> 헤더의 accumulate(), reduce()는 ranges 라이브러리를 지원하지 않는다
- std::views, std::views::filter, std::views::transform 공부해보기. string_view 클래스도 같이 공부하기. 엄청 좋은 개념같다!

- C++ 표준에 통합된 기능들:  
https://en.cppreference.com/w/cpp/ranges
- range-v3:  
https://ericniebler.github.io/range-v3/index.html

`views::remove_if()`로 할 수 있는 모든 작업을 `views::filter()`를 반대로 적용하는 방식으로 구현할 수 있지만, remove_if가 들어오면 좋을 것 같다.  
view를 파이프라이닝하는 것 처럼 in-place change도 파이프라이닝할 수 있는 `actions`도 표준에 들어오면 좋을 것 같은데, 이건 우선순위가 밀린다고 한다..  
> vi = std::move(vi) | actions::sort | actions::unique;
