#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ template_method pattern - version 1
	
	reference :
*/

// 상위 클래스
// 변경되지 않는 모든 알고리즘 및 메세드는 상위 클래스에 정의
class CBase
{
public:
	void template_method1()
	{
		std::cout << "template_method1()" << std::endl;
	}

	void template_method2()
	{
		std::cout << "template_method2()" << std::endl;
	}
	
	// 하위 계층에서 반드시 구현해야 할 메세드 (하위코드마다 다른 부분)
	virtual void hook1() = 0;
	virtual void hook2() = 0;
};

class CSubClassA : public CBase
{
public:
	// 하위 계층에서 반드시 구현해야 할 메세드 (하위코드마다 다른 부분)
	virtual void hook1() override
	{
		std::cout << "CSubClassA hook1()" << std::endl;
	}
	
	virtual void hook2() override
	{
		std::cout << "CSubClassA hook2()" << std::endl;
	}
};

class CSubClassB : public CBase
{
public:
	// 하위 계층에서 반드시 구현해야 할 메세드 (하위코드마다 다른 부분)
	virtual void hook1() override
	{
		std::cout << "CSubClassB hook1()" << std::endl;
	}
	
	virtual void hook2() override
	{
		std::cout << "CSubClassB hook2()" << std::endl;
	}
};

int main()
{
	std::shared_ptr<CBase> base = std::make_shared<CSubClassA>();
	base->template_method1();

	return 0;
}