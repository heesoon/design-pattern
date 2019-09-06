# proxy pattern
* 사용자가 원하는 객체에 직접 접근하기보다는 중간에 대리자(proxy)를 통해서 간접 접근하도록 처리한다.

## proxy pattern을 통해서 가능한 동작
* 실제 객체의 동작을 숨길수 있다. (실제 객체의 실제 interface의 노출 여부를 제어할 수 있다)
* proxy가 실제 객체의 access를 제어할 수 있다.
* proxy가 실제 객체의 생성과 소멸 시점을 제어할 수 있다. (예. lazy intialization)
* 실제 객체의 메모리 사용량이 많다면, 실제 객체를 다수 생성하기 보다는 light한 proxy서버를 다수 생성해서 지원하는 flyweigh 패턴 전략과 접목할 수 있다.
* 실제 객체의 변경 사항에 proxy가 중간 bridge 역활을 수행하여 사용자에게 실제객체의 변경사항에 영향을 최소화할 수 있다.
* 보안 강화를 위한 전략으로 고려할 수 있다.

## proxy pattern category
* Structural pattern

![proxy](/docs/images/proxy.png)

## 구현코드 설명
* proxy_v1.cpp
	* 구현 코드