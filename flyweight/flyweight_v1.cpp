#include <iostream>
#include <memory>
#include <map>
#include <string>

/*
	c++ flyweight pattern - version 1
	
	메모리 사용을 최소화하는 방향으로 설계하는 패턴
	즉, 이미 메모리에 Loading된 객체가 존재하면 새로 생성하지 말고, Loading된 객체를 이용하자.
	
	화면에 글자출력을 위한 폰트처리 관점에서 예제를 생각해 볼 수 있다.
*/

// flyweight class
class CFont
{
public:
	virtual void draw() = 0;
};

// font는 간단한 예제를 위해서 C까지만 사용한다.
class CFontA : public CFont
{
public:
	virtual void draw()
	{
		std::cout << "A" << std::endl;
	}
};

class CFontB : public CFont
{
public:
	virtual void draw()
	{
		std::cout << "B" << std::endl;
	}
};

class CFontC : public CFont
{
public:
	virtual void draw()
	{
		std::cout << "C" << std::endl;
	}
};

// flyweight factory class
class CFontFactory
{
public:
	std::shared_ptr<CFont> getFont(char key)
	{
		if(m.find(key) == m.end())
		{
			switch(key)
			{
				case 'A' :
					m[key] =  std::make_shared<CFontA>();
				break;
				case 'B' :
					m[key] =  std::make_shared<CFontB>();
				break;
				case 'C' :
					m[key] =  std::make_shared<CFontC>();
				break;		
			}
		}
		
		return m[key];
	}
private:
	std::map<char, std::shared_ptr<CFont>> m;
};

int main()
{
	// client
	CFontFactory factory;
	std::shared_ptr<CFont> fontA = factory.getFont('A');
	fontA->draw();

	std::shared_ptr<CFont> fontB = factory.getFont('B');
	fontB->draw();

	return 0;
}