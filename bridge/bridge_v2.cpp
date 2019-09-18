#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ bridge pattern - version 2

	bridge_v1.cpp에서 제기된 문제를 해결하기 위해서 bridge pattern을 적용한 코드이다.
	adaptor pattern과 겹치는 부분이 많기는 하지만, bridge pattern은 클래스 상속이 아닌 객체를 통한 문제해결 방식이다.
	
	CShape를 수정하지 않고, 신규 update() 함수를 추가하는 것은
	abstract class와 concrete class간의 decoupling 방식으로 구현하는 패턴이다.
	abstract class와 concrete class를 변경하지 않겠다는 의미이다.
	
	이를 위해서 신규 bridge class를 추가한다.
	bridge class는 CShape의 객체의 포인터를 가지고 있어서 기존 기능은 CShape를 통해서 지원한다.
	신규 기능인 udpate()는 bridge class에 추가하여 대응한다.
	
	결국 CShape의 상위 클래스를 클래스 상속이 아닌 객체를 통해서 만들어내는 결과가 된다
	update()함수까지 필요하지 않는 사용자는 기존 CShape 상속 계보로 구현된 코드를 사용하면 되고,
	update()까지 필요한 사용자는 bridge 통해서 생성된 객체를 사용하면 된다.
*/

// 구현부
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

// 추상부
// CShape의 기존 기능을 그대로 사용하고, CEditor에 추가된 기능을 추가로 대응하기 위한 다리역활
class CShapeBride
{
public:
	CShapeBride(std::shared_ptr<CShape> sp) : shapeImp(sp){}
	
	void draw()
	{
		shapeImp->draw();
	}
	
	void save()
	{
		shapeImp->save();
	}
	
	// CEditor의 새로운 기능을 대응하기 위해서 추가된 코드
	void upload()
	{
		std::cout << "upload called .." << std::endl;
	}

private:
	// bridge 패턴에서는 구현부를 가르키는 포인터를 하나 소유한다.
	// 이는 기존에 CShape에서 제공한 기능을 그대로 사용하기 위함.
	std::shared_ptr<CShape> shapeImp;
};

// 기존 사용자(Client). CEditor는 바로 CShape을 호출하고 있다.
class CEditor
{
public:
	void execute(std::shared_ptr<CShape> sp)
	{
		sp->draw();
		sp->save();
	}
};

// upload 기능을 원하는 사용자(Client). CEditor는 바로 CShape를 사용하는 대신 CShapeBride를 사용한다.
class CEditorWithUpload
{
public:
	void execute(std::shared_ptr<CShapeBride> sp)
	{
		sp->draw();
		sp->save();
		sp->upload();
	}
};


int main()
{
	std::shared_ptr<CShapeBride> shape = std::make_shared<CShapeBride>(std::make_shared<CCircle>());
	CEditorWithUpload editor;
	editor.execute(shape);

	return 0;
}