# bridge pattern
* abstract class와 concrete class간의 decoupling을 지향하는 패턴
* 이말은 기존 abstract와 concrete class간의 상속계보를 통해서 신규 기능을 추가하지 않겠다는 의미와 같다.
* 클래스 상속을 통한 방식이 아닌 객체를 통한 문제 해결 방식이다.
* adaptor와 다소 겹치는 부분이 있어 보인다.

## bridge pattern category
* Structural pattern

## bridge pattern UML
![bridge](/docs/images/bridge.png)

## bridge pattern을 고려할 때
* 신규 요구사항 접수로 abstract class에 신규 method을 추가해야 하는 상황이 발생
* 하지만 abstract class의 method 추가는 위험부담이 크다.
* 기본 코드를 변경없이 신규 method를 추가해야 하는 경우

## 구현코드 설명
* bridge_v1.cpp
	* start code로 전형적인 상속 계보를 통해서 구현된 코드이며, 이 코드의 문제점에 대해서 코드상에 기술하였다.
* bridge_v2.cpp
	* bridge pattern을 써야할 상황에 대해서 구현한 코드