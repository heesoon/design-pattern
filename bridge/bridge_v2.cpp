#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ bridge pattern - version 2

	Bridge 패턴을 기준으로 CShape는 implementation(구현부)가 된다. 이 부분의 변경을 막고자 한다.
	Client에 해당하는 CEditor가 CShape을 바로 사용하는 대신에
	CEditor와 CShape 사이에 두 클래스간의 변화를 완충해 줄 Bride를 추가한다.
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