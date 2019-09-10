# mediate pattern
* 클래스간의 복잡한 상호 작용을 한클래스에 위임(Mediator)해서 처리하는 디자인패턴
* 각 클래스는 다른 클래스와 상호 통신하기 위해서는 중재자(Mediator)를 알고 있어야 한다. 따라서 register가 보통 구현된다.
* Observer 패턴과 유사한 구조이지만, registered들은 메세지를 보낼 자격이 없고 수신만 가능하다.


## mediate category
* Behavioral pattern

![mediate](/docs/images/mediate.png)

## 구현코드 설명
* mediate_v1.cpp
	* 구현 코드