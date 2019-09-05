# facade pattern
* 서브시스템에 대한 세부 설정은 사용자에게 숨긴다. 사용자가 원하는 기능 목표를 달성하기 위해서 중간에 서브시스템을 조합하여 이를 제공하는 대리자 역활을 수행하는 패턴이다. 
* 서브시스템에 대한 세부 설정은 facede class가 수행하고 사용자는 facede가 제공하는 기능만 관심을 갖는다.

## facade pattern category
* Structural pattern

![facade](/docs/images/facade.png)

## 구현코드 설명
* facade_v1.cpp
	* facade를 구현한 코드