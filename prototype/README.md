# prototype pattern
* 생성할 객체들의 타입이 프로타입인 instance로부터 결정되도록 하며, instance는 새 객체를 만들기 위해 자신을 복재(clone)하게된다.
* run-time으로 객체를 생성하는 것을 원칙으로 하고, 생성된 객체를 사용하고자할 때, 복재(clone)해서 사용한다.
* 자주 사용하는 객체를 prototype으로 구현하고, 이용 시에는 clone해서 사용하면 성능 개선의 효과가 있다.

## prototype pattern category
* Creational pattern

## abstract factory UML
![prototype](/docs/images/prototype.png)

## prototype pattern을 고려할 때
* 자신을 복재해서 사용하기 때문제 복재 생성자 호출이 중요 포인트이다.
* abstract factory는 factory method와 함께 구현되거나, prototype을 이용해서 구현하기도 한다.
* composite 패턴이나 decorate 패턴을 매우 많이 사용한 무거운 설계를 프로토타입을 사용하여 더 좋게 만들 수 있다.

## 구현코드 설명
* prototype_v1.cpp
	* 구현코드
