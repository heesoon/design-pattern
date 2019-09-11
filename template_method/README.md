# template_method pattern
* 여러클래스에서 공통으로 사용하는 메서드를 상위클래스에 정의한다.
* 하위클래스마다 다르게 구현해야 하는 세부적인 사항은 하위클래스로 분리
* 상위클래스에 정의하는 공통 메서드 부분은 템플릿 메서드라 한다.
* 하위클래스마다 다르게 구현해야 하는 부분은 훅(hook)이라 한다.
* 코드 refactoring에 활용할 수 있는 패턴이다.

## template_method category
* Behavioral pattern

![template_method](/docs/images/template_method.png)

## 구현코드 설명
* template_method_v1.cpp
	* 복잡한 예제가 필요없어서 단순한 예제로 대체