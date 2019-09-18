#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ bridge design pattern - version 1
	
	아래 코드는 특징은 아래와 같다.
	1) CShape을 base 클래스로 하여 CRect, CCircle가 파생클래스이다.
	2) CEditor는 CShape의 추상클래스 포인터를 가지고 execute함수를 호출하고 있다.
	
	CEditor는 전적으로 CShape로부터 파생된 클래스만을 처리할 수 있다.

	만약 다음과 같은 요구사항이 추가된다면 어떻게 해야 하는가?
	1) 추상클래스인 CShape에 draw()와 save() 함수 이외에 update()함수가 추가되어야 한다
	2) 이런식의 함수 추가가 빈번하다
	
	이런 경우, bridge 패턴을 고려해 볼 수 있다.
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