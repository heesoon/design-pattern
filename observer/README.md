# observer pattern
* 특정객체(Subject)의 상태변화를 관찰하는 관찰자(observer)객체들에게 상태를 통지
* 관찰자 등록 절차가 필요
* 등록된 관찰자에게 Subject의 변화를 통지하는 메세드가 필요
* 발행/구독 모델
* 1:N 방식의 broadcast 통지 방식


## observer category
* Behavioral pattern

![observer](/docs/images/observer.png)

## 구현코드 설명
* observer_v1.cpp
	* 구현 코드