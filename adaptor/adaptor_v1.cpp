#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ adaptor pattern - version 1
	
	interface 호환성을 확보하기 위한 패턴
	
	Usage:
	1) abstract class 가 있다.
	2) concrete class of abstract
	3) concrete class는 abstract class에서 순수 가상함수로 상속받은 함수(interface)를
	   구현해야 한다.
	4) 위의 concrete class를 사용하는 class는 이 interface를 사용한다.
	5) 여기서 abstract class에서 상속되지 않은 다른 class의 interface를 사용하고 싶다.
	
	즉, 상속의 계보가 다른 class의 interface를 사용하고자 할 때, 기존 상속 계보에 존재하는 클래스간에는
	호환성이 유지되지만, 다른 class의 interface는 이 방식이 다를 수 있다.
	이 다름을 같게 하는 패턴이 adaptor 패턴이다.
	
	Adaptor 패턴 유도 방식
	1) class 상속 관계를 통해서
	2) 객체를 통해서
	
	이 예제는 상속을 통한 예제이다.
*/

// abstract class
class CShape
{
public:
	virtual void draw() = 0;
};

// concrete class
class CRect : public CShape
{
public:
	virtual void draw() override
	{
		std::cout << "draw rectangle .. " << std::endl;
	}
};

// concrete class
class CTri : public CShape
{
public:
	virtual void draw() override
	{
		std::cout << "draw triangle .. " << std::endl;
	}
};

// client : CShape에서 상속된 클래스들을 사용하는 사용자
class CClient
{
public:
	void showShapes()
	{
		for(auto x : v)
		{
			x->draw();
		}
	}
	
	void addShape(std::shared_ptr<CShape> s)
	{
		v.push_back(s);
	}
private:
	std::vector<std::shared_ptr<CShape>> v;
};

int main()
{
	CClient client;
	client.addShape(std::make_shared<CRect>());
	client.addShape(std::make_shared<CTri>());
	
	client.showShapes();
	
	return 0;
}