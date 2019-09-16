# state pattern
* 객체의 상태만을 뽑아서 캡슐화한 것
* 상태가 많은 경우에 효과적이다. 상태가 많지 않거나, 상태 추가/삭제에 따른 변경 사항이 크지 않을 경우 기존 방식(switch case or if else접근) 이 더 낫다
* 상태를 캡슈화한 상태객체는 자신의 상태만 관리한다.
* 상태 변화의 추적과 관리는 Context의 몫이다.
* 상태 객체의 생성과 소멸을 최소화하기 위해서는 Flyweight 패턴과 같이 사용할 수 있다.

## state category
* Behavioral pattern

![state](/docs/images/state.png)

## 구현코드 설명
* state_v1.cpp
	* 상태와 동작이 mixing되어 있는 전형적인 예제
* state_v2.cpp
	* 상태를 객체로 캡슐화하여 뽑아내어 분리한 예제