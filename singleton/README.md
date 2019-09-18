# singleton pattern
* 단 하나의 객체만 생성해야 할 경우 적용

## singleton pattern category
* Creational pattern

## abstract factory UML
![singleton](/docs/images/singleton.png)

## 구현코드 설명
* singleton_v1.cpp
	* morden c++ 도입 전에 일반적으로 instance 동적할당을 통해서 구현한 예제
* singleton_v2.cpp
	* morden c++ 도입 전에 일반적으로 instance 정적 할당 예제
* singleton_v3.cpp
	* morden c++ 도입 후, call_once 기반, thread safty 구현 예제
* singleton_v4.cpp
	* singleton_v3.cpp 예제에 상속까지 추가한 최종 예제
