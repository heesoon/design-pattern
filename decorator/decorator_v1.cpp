#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ decorator pattern - version 1
	
	동적으로 어떤 객체의 기능을 확장하고자 할 때 고려할 수 있다.
	
	concrete component로 생성된 객체에 기능 확장을 위해서 decorator을 이용한다.
*/

// component class
class CCoffie
{
public:
	virtual std::string getIngredient() const = 0;
	virtual ~CCoffie() = default;
};

// concrete component
class CAmericanoCoffie : public CCoffie
{
public:
	virtual std::string getIngredient() const override
	{
		return ingredient;
	}
	
	virtual ~CAmericanoCoffie()
	{
		std::cout << "called ~CAmericanoCoffie() .. " << std::endl;
	}
private:
	std::string ingredient = "coffie";
};

// base decorator for extending concrete component
class CDecorator : public CCoffie
{
public:
    CDecorator() = default;
	CDecorator(std::shared_ptr<CCoffie> c) : coffie(c) {}
	virtual ~CDecorator()
	{
		std::cout << "called ~CDecorator().. " << std::endl;
	}
private:
	std::shared_ptr<CCoffie> coffie;
};

// concrete decorator for extending concrete component
class CSugarCoffie : public CDecorator
{
public:
    CSugarCoffie() = default;
	CSugarCoffie(std::shared_ptr<CCoffie> c) : coffie(c) {}
	
	virtual std::string getIngredient() const override
	{
		return coffie->getIngredient() + " + " + ingredient;
	}
	
	virtual ~CSugarCoffie()
	{
		std::cout << "called ~CSugarCoffie() .. " << std::endl;
	}

private:
	// decorator는 compoent와 연관관계에 있다. 따라서 아래코드가 필요하다.
	std::shared_ptr<CCoffie> coffie;
	std::string ingredient = "sugar";
};

// concrete decorator for extending concrete component
class CMilkCoffie : public CDecorator
{
public:
    CMilkCoffie() = default;
	CMilkCoffie(std::shared_ptr<CCoffie> c) : coffie(c) {}
	
	virtual std::string getIngredient() const override
	{
		return coffie->getIngredient() + " + " + ingredient;
	}
	
	virtual ~CMilkCoffie()
	{
		std::cout << "called ~CMilkCoffie() .. " << std::endl;
	}

private:
	// decorator는 compoent와 연관관계에 있다. 따라서 아래코드가 필요하다.
	std::shared_ptr<CCoffie> coffie;
	std::string ingredient = "milk";
};

int main()
{
	std::shared_ptr<CAmericanoCoffie> americano = std::make_shared<CAmericanoCoffie>();
	std::shared_ptr<CSugarCoffie> sugarCoffie = std::make_shared<CSugarCoffie>(americano);
	std::shared_ptr<CMilkCoffie> milkCoffie = std::make_shared<CMilkCoffie>(sugarCoffie);
	
	std::cout << milkCoffie->getIngredient() << std::endl; // coffie + sugar + milk 출력
	return 0;
}