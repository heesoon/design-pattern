# bridge pattern
* implementation에서 abstraction을 분리하여 서로의 변화가 영향을 주지 않도록 설계하는 디자인 패턴이다.

## bridge pattern category
* Structural pattern

![bridge](/docs/images/bridge.png)

## bridge pattern을 고려할 때
* 전형적인 클래스 상속을 이용한 디자인 패턴이다.
* 구현부는 클래스 상속을 통해서 구현된 부분이다. 사용자가 이 구현부를 바로 사용하는 중에
* 사용자가 구현부 클래스에 존재하지 않는 추가적인 기능을 요구할 경우, 구현부를 고쳐야 하는 부담이 존재한다.
* 구현부는 그대로 나두고, 구현부와 사용자간의 중간 역활을 수행할 클래스를 추가하는 방식이다.

## 구현코드 설명
* bridge_v1.cpp
	* 문제가 있는 예제로 이 예제로부터 bridge 패턴을 유도한다.
* bridge_v2.cpp
	* bridge 패턴을 이용한 bridge_v1.cpp의 문제점을 개선