# factory method pattern
* 객체 생성을 자신이 하지 않고, 객체 생성을 전담하는 객체(factory)에 자신의 객체 생성을 위임한다.
* factory에는 객체를 생성하는 interface(method)를 제공하고, 실제 어떤 클래스가 instantiate될지는 subclass에서 결정한다.

## factory method pattern category
* creational pattern

## factory method pattern UML
![factory_method](/docs/images/factory_method.png)

## factory_method pattern을 고려할 때
* client는 abstract base class는 알지만 (추상적으로 어떤 객체를 만들것인가 추론이 가능), concrete subclass는 알지 못한다.
* run-time 객체 생성
* subclass가 실제 객체를 생성

## 구현코드 설명
* factory_method_v1.cpp
	* start code
* factory_method_v2.cpp
	* factory method pattern으로 변경
* factory_method_v3.cpp
	* factory_method_v2.cpp에서 static 함수로 활용하여 변경