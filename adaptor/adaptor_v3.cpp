#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ adaptor pattern - version 3
	
	adaptor_v1.cpp에서 CTri는 CShape에서 상속받은 클래스였다.
	만약 CClient가 CShape에서 상속되지 않은 CTri 클래스를 사용한다고 가정하자.
	
	이 경우에 Adaptor 패턴이 필요하다.
	아래 예제는 클래스 상속이 아닌, 객체를 통한 예제임.
	
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
class CAdaptor : public CAdaptorBase, public CShape
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
		tri.show(); // CTri draw function call
	}
private:
	CTri tri; // 객체를 통한 Adaptor 구현을 위해서 추가된 부분
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