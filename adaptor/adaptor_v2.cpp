#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ adaptor pattern - version 2
	
	adaptor_v1.cpp에서 CTri는 CShape에서 상속받은 클래스였다.
	만약 CClient가 CShape에서 상속되지 않은 CTri 클래스를 사용한다고 가정하자.
	
	이 경우에 Adaptor 패턴이 필요하다.
	해당 예제는 상속을 통한 Adaptor 패턴 구현이다. 상속을 사용 시에는 Multiple 상속은 불가피하다.
	
	reference : https://sourcemaking.com/design_patterns/adapter
	
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

// class not inherited from abstract of CShape
class CTri
{
public:
	void show()
	{
		std::cout << "draw triangle .. " << std::endl;
	}
};

// Adaptor Pattern start
// abstract of adaptor
class CAdaptorBase
{
public:
	virtual void display() = 0;
};

// concrete adaptor
// 예제가 복잡한 부분이 존재하지만 모든 경우의 수를 고려해 보자는 차원에서 조금 복잡한 구조를 가짐
class CAdaptor : public CAdaptorBase, public CShape, public CTri
{
public:
	// CShape virtual function implementation
	virtual void draw() override
	{
		display(); // CAdaptorBase display function call
	}
	
	// CAdaptorBase virtual function implementation
	virtual void display() override
	{
		show(); // CTri draw function call
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
	client.addShape(std::make_shared<CAdaptor>());

	client.showShapes();
	
	return 0;
}