# builder pattern
* 최종 객체를 생성하는 과정은 동일하다. 하지만 생성과정에 투입된 값(representation)에 따라 최종 결과물인 객체는 다르다.

## builder pattern category
* creational pattern

## builder pattern을 고려할 때
* 객체 생성과정이 복잡하다. 생성자의 입력 파라미터가 너무 많고 복잡하다.
* 객체를 생성하는 과정은 동일하다.
* 동일한 생성과정에 다른 값을 주면 다른 목표물을 얻을 수 있다.

## 구현코드 설명
* builder_v1.cpp
  * 예제에 사용된 CPizza class가 간단하지만, 생성자가 매우 복잡한 class라고 가정하자
  * CPizza의 객체를 생성하고자 하는 사용자는 이에 대해서 상세하게 알아야하고 매우 복잡한 과정이다.
* builder_v2.cpp
  * builder_v1.cpp의 애로사항을 GoF의 builder pattern 기반으로 수정한 코드이다.
