#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ bridge pattern - version 1
	
	구현부에서 추상측을 분리하여 Decoupling을 확보하고 서로의 변화가 영향을 주지 않도록 한다.
	
	아래 코드는 CShape에서 상속받은 자식 클래스를 CEditor에서 이용하는데 전혀 문제가 없어 보인다.
	하지만 이 구조에서 문제는 무엇일까?
	
	현재 CEditor의 execute 함수는 draw와 save만 사용하고 있다.
	만약 CEditor의 execute 함수에 upload 기능이 필요하다고 생각해 보자.
	이럴 경우 문제가 발생한다.
	
	CShape의 abstract함수에 upload함수가 추가되어야 하는데, 이런 변경은 SW 유지 보수에 문제가 발생한다.
	이런 문제를 해결하기 위해서 제안된 패턴이 bridge 패턴이다.
	
	bridge라는 이름에서 알 수 있듯이 CEditor가 CShape을 사용하는 대신 CShape과 CEditor 사이에
	다리 역활을 하는 class를 하나 두는 방식이다.
	
	이를 통해서 CShape을 변경하지 않으면서 CEditor의 요구사항을 만족 시켜주는 패턴이다.
*/

class CShape
{
public:
	virtual void draw() = 0;
	virtual void save() = 0;
	virtual ~CShape() = default;
};

class CRect : public CShape
{
public:
	virtual void draw() override
	{
		std::cout << "draw rectangle.." << std::endl;
	}

	virtual void save()
	{
		std::cout << "save rectangle.." << std::endl;
	}

	virtual ~CRect() = default;
};

class CCircle : public CShape
{
public:
	virtual void draw() override
	{
		std::cout << "draw CCircle.." << std::endl;
	}

	virtual void save()
	{
		std::cout << "save CCircle.." << std::endl;
	}

	virtual ~CCircle() = default;
};

class CEditor
{
public:
	void execute(std::shared_ptr<CShape> sp)
	{
		sp->draw();
		sp->save();
	}
};

int main()
{
	CEditor editor;
	editor.execute(std::make_shared<CCircle>());

	return 0;
}