# iterator pattern
* c++관점에서는 container로부터 container 요소에 접근하는 알고리즘을 분리시키는 디자인 패턴
* 일부 container의 알고리즘은 성능이슈로 container에 특화되어 분리가 불가능한 경우도 있다.
* GoF의 design pattern과 c++표준에 구현은 다소 차이가 있다.
* Aggregate는 iterator가 접근할 수 있는 통로를 열어주어야 한다.
	* c++ 표준은 begin(), end() 같은 함수를 통해서
	* GoF의 original은 createIterator() 함수를 통해서 
* iterator가 Aggregate와 friend 속성을 같는 것과 같은 효과이다.

## iterator category
* Behavioral pattern

![iterator](/docs/images/iterator.png)

## 구현코드 설명
* iterator_v1.cpp
	* iterator 적용 전 코드
* iterator_v2.cpp
	* iterator 패턴을 적용하여 검색 부분을 분리한 코드