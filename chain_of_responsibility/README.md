# chain of responsibility pattern
* Sender의 Request를 처리할 기회를 늘림으로써 Sender와 Receiver 사이의 Coupling을 최소화한다.
* Sender의 Request는 그것이 처리될 때까지 다른 객체로 전달되도록 설계한다.
* Request 처리에 대한 접근성을 넓히는 것으로 이해가 된다

## chain of responsibility pattern category
* Behavioral pattern

![cor](/docs/images/cor.png)

## 구현코드 설명
* chain_of_responsibility_v1.cpp
	* 구현 코드