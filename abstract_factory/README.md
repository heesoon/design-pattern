# abstract factory pattern
* factory method가 단일 객체 생성에 중점을 두었다면, abstract factory는 factory method를 확장한 복합객체 생성에 중점을 두고 있다.
* 실제 객체 생성은 객체생성을 위임받은(factory)에서 수행한다.

## abstract factor pattern category
* Creational pattern

## abstract factory UML
![abstract_factory](/docs/images/abstract_factory.png)

## abstract factor pattern을 고려할 때
* 단순 객체 생성만으로 객체가 온전히 생성되지 않고, 관련 dependent나 관계된 객체가 같이 생성되어야만 온전한 객체 생성이 완료되는 경우 적용 가능
* 보통 설계는 처음에는 팩토리 메소드로 출발한다. 다음에 설계자의 재량에 따라 추상 팩토리 패턴, 빌더 패턴, 프로토타입 패턴으로 바뀔 수 있다

## 구현코드 설명
* abstract factor_v1.cpp
	* factory_method에서 다루었던 예제를 abstract factory pattern으로 확장한 예제
