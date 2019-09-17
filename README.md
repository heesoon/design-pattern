# design-pattern
study of design pattern based on modern c++

## 생성패턴(Creational Patterns)
* abstract factory
	* factory method가 보다 확장되면 abstract factory 패턴으로 발전한다.
* builder
	* 객체 생성(construction)이 생성자 호출로 간단히 생성하기 힘든 구조에 적용
	* construction 과정은 동일하나, representation에 따라 다른 객체를 생성할 때 적용
	* 일차적으로 생성자가 매우 복잡할 경우 일차적으로 고려해 볼 필요가 있다.
* factory method
	* 객체 생성에 focus되어 있다.
	* builder 패턴과 혼합하여 적용 가능하다.
* prototype
	* 객체를 생성하는 시간이 오래 걸리는 경우 고려
	* 먼저 객체를 생성해서 pool에 넣어두고, 필요 시 객체를 복재해서 사용할 때 고려
	* 복재 생성자가 사용된다.
* singleton
	* 객체는 단 하나만 생성되어야 할 경우 적용 가능

## 구조패턴(Structural Patterns)
* adaptor
	* 두 클래스 또는 객체간에 interface가 호환되지 않지만 서로 통신해야 할 경우 적용
* bridge
	* c++ 관점에서 Pimpl(Pointer to Implementation) 관례가 한 예이다.
	* adaptor처럼 두 클래스간의 호환성을 제공한다는 관점에서는 동일하다.
	* bridge는 호환성 제공이 필요한 부분은 추상화(abstract)부분으로 뽑아서 접근한다.
* composite
	* 단일 객체이든, 복합객체이든 두 객체를 모두 통합할 수 있는 구조를 제공이
	* 보통 GUI 프로그램에서 많이 사용된다
* decorate
	* 기존 객체에 새로운 기능을 추가할 경우 (동적으로 기능 추가)
* facade
	* 외부 라이블러리나 객체에 접근할 때, 단순한 interface를 제공을 목표로 한다.
* flyweight
	* 권투의 몸무게를 줄이는 것에서 유래한 것으로 객체간에 유사한 데이터 공유를 최대화하여 메모리 사용량을 최소화하는 것을 목표
* proxy
	* 중앙 집중적인 관리가 필요한 경우에 적용 가능하다
	* 객체간에는 통신할 수 없고, 반드시 proxy를 거쳐야 한다.
	
## 행동패턴(Behavioral Patterns)
* chain of responsibility
	* 책임을 특정 객체에 집중하기 보다는 자신이 책임지지 않는 기능이라도 일단 받고, 관련 객체에 전달하는 방식
* command
	* 어떤 객체를 활용할 떄, 직접 그 객체의 API를 호출하는 대신 작업에 해당하는 명령(command)를 보내는 방식
* interpreter
	* 문법 규칙을 클래스화한 패턴, SQL이나 통신 프로토콜에 적용 가능하다
* iterator
	* c++ iterator와 유사 개념
	* aggregate(배열, 리스트)와 같은 객체에 접근하는 동일 interface 제공
* observer
	* 어떤 객체의 변화를 감지하여 다른 클래스에 통보
* stategy
	* 알고리즘 군을 정의하고 각각 하나의 클래스로 캡슐화한 다음, 필요할 때 서로 교환해서 사용할 수 있게 해준다.
* template method
	* 상위 클래스에서는 추상적으로 표현하고 그 구체적인 내용은 하위 클래스에서 결정되는 디자인 패턴
* visitor
	* 각 클래스의 데이터 구조로부터 처리 기능을 분리하여 별도의 visitor 클래스로 만들어놓고 해당 클래스의 메서드가 각 클래스를 돌아다니며 특정 작업을 수행하도록 하는 것
* mediator
	* 클래스간의 복잡한 상호작용을 캡슐화하여 한 클래스에 위임해서 처리 하는 디자인 패턴
* state
	* 객체에서 상태처리 부분을 분리(상태 추가에 따른 변경사항이 많은 부분), 각 상태를 객체로 캡슐화
* mememto
	* Ctrl + z 와 같은 undo 기능 개발할 때 유용한 디자인패턴. 클래스 설계 관점에서 객체의 정보를 저장
