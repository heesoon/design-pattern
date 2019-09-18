# factory method pattern
* 객체생성자(client)에게 객체 생성 logic을 노출하지 않는다.
* 객체생성자가 새로운 객체를 생성할 때, 일관되고 동일한 방식의 interface를 제공하는 대리자를 둔다.
* 반드시 객체 생성을 전담하는 대리자가 있어야하는지는 의문이다.(?)

## factory method pattern category
* Creational pattern

## factory method pattern UML
![factory_method](/docs/images/factory_method.png)

## factory_method pattern을 고려할 때
* abstract factory와 같이 보면 이해도가 높다.

## 구현코드 설명
* factory_method_v1.cpp
	* start code
* factory_method_v2.cpp
	* factory method pattern으로 변경
	* GoF의 UML과 가장 유사하게 구현한 코드
* factory_method_v3.cpp
	* 별도의 대리자(creator)를 두지 않고 product내에서 모두 처리하는 예제
	* GoF에서 말하는 factory method pattern에 부합하지는 않지만, 나름 가능한 코드이다.