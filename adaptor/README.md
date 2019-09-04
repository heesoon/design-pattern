# Adaptor pattern
* 최종 객체를 생성하는 과정은 동일하다. 하지만 생성과정에 투입된 값(representation)에 따라 최종 결과물인 객체는 다르다.

## Adaptor pattern category
* Structural pattern

## 다중상속을 통한 Adaptor Pattern
![adaptor1](/docs/images/adaptor1.png)

## 객체합성을 통한 Adaptor Pattern
![adaptor2](/docs/images/adaptor2.png)

## Adaptor pattern을 고려할 때
* interface가 호환되지 않는 클래스들을 함께 사용해야할 상황이 존재할 때

## 구현코드 설명
* adaptor_v1.cpp
  * 출발하는 예제
  * 예제에서 client는 모두 CShape에서 상속받은 클래스를 이용하고 있다.
* adaptor_v2.cpp
  * client가 CShape에서 상속받지 않았지만, 자신에게 필요한 기능이 타 클래스에 존재하는 상황이다.
  * client에게 interface 호환성을 제공하기 위해서
  * 다중 상속을 통한 Adaptor Pattern을 구현한 예제이다.
* adaptor_v3.cpp
  * adaptor_v2.cpp와 동일한 상황에서 객체 합성을 통한 예제이다.