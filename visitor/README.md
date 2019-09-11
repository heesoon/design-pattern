# visitor pattern
* 기존 객체의 구조를 변경하지 않고, 새로운 기능을 추가하고자 할 때 사용
* 객체에서 사용하는 알고리즘을 변경하거나 추가하고자 할 때 사용
* visitor 패턴에서는 기존객체는 visitor를 받아들일 accept함수가 필요하다.
* 알고리즘 신규 기능이나 추가는 visitor를 통해서 구현된다.

## visitor category
* Behavioral pattern

![visitor](/docs/images/visitor.png)

## 구현코드 설명
* visitor_v1.cpp
	* visitor를 적용하기 전의 코드
* visitor_v2.cpp
	* visitor 패턴을 적용하여 기존 객체의 기능을 확장한 예제 코드