# command pattern
* Encapsulate a request as an object
* invoker, command, receiver의 용어가 등장
* invoker는 receiver에게 어떤 request를 요청하는데, 이 request를 command라는 패턴으로 Encapsulation한 것이다.
* An object-oriented callback
* request가 함수형 언어에서는 단순히 함수라면, 객체형 언어에서는 이 함수를 객체로 갭슐화한 것이다.
* 이 캡슐화를 통해서 함수형 언어에서 하지 못하는 호출간의 상태 저장 및 추적, logging과 같은 작업을 할 수 있다.

## command category
* Behavioral pattern

![command](/docs/images/command.png)

## 구현코드 설명
* command_v1.cpp
	* 구현 코드