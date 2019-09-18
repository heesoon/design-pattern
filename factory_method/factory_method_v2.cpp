#include <iostream>
#include <memory>
#include <string>

/*
	c++ fatory method design pattern - version 2
	
	1) 객체 생성을 전담하는 클래스를 별도로 둔다.
	2) 어떤 클래스의 객체를 생성할지는 서브클래스에서 결정한다.
	
*/

// product base class에 해당한다.
class CPizza
{
public:
	void setDough(const std::string& dough) 	{ m_dough = dough; }
	void setSauce(const std::string& sauce) 	{ m_sauce = sauce; }
	void setTopping(const std::string& topping) { m_topping = topping; }
	void printPizzaInfo() const
	{
		std::cout << "Pizza Info. "<< "=> dough : " << m_dough << " , " << "sauce : " << m_sauce 
		<< " , " << "topping : " << m_topping << std::endl;
	}
	
	// 서브클래스에서 작성해야할 가상함수
	virtual std::unique_ptr<CPizza> operator()() = 0;
	
private:
	std::string m_dough;
	std::string m_sauce;
	std::string m_topping;
};

// subclass에 해당하는 CPizza(product)의 concrete class이다.
class CSuperSupremePizza : public CPizza
{
public:
	// 서브클래스에서 작성해야할 가상함수
	virtual std::unique_ptr<CPizza> operator()() override
	{
		std::unique_ptr<CSuperSupremePizza> up = std::make_unique<CSuperSupremePizza>();
		
		up->setDough("pan baked");
		up->setSauce("mild");
		up->setTopping("ham and pineaple");
		
		// redundant std::move
		// http://vmpstr.blogspot.com/2015/12/redundant-stdmove.html
		return up;
	}
};

// subclass에 해당하는 CPizza(product)의 concrete class이다.
class CPotatoPizza : public CPizza
{
public:
	virtual std::unique_ptr<CPizza> operator()() override
	{
		std::unique_ptr<CPotatoPizza> up = std::make_unique<CPotatoPizza>();
		
		up->setDough("pan baked");
		up->setSauce("mild");
		up->setTopping("potato");

		// redundant std::move
		// http://vmpstr.blogspot.com/2015/12/redundant-stdmove.html
		return up;
	}
};

// 객체 생성을 전담하는 대리자인 factory class(Creator)를 둔다.
class CPizzFactoryBase
{
public:
	virtual std::unique_ptr<CPizza> productPizza(const std::string &pizzaType) = 0;
};

// Creator의 concrete class
class CPizzFactory : public CPizzFactoryBase
{
public:
	// factory method
	virtual std::unique_ptr<CPizza> productPizza(const std::string &pizzaType) override
	{
		if(pizzaType == "superSupreme")
		{
			return CSuperSupremePizza()();
		}
		else if(pizzaType == "potato")
		{
			return CPotatoPizza()();
		}
		else
		{
			return nullptr;
		}
	}
};

int main()
{
	// CPizza와 CPizza Factory class가 library내에 존재한다고 가정하고
	// main 함수의 구현은 client라고 했을 때, library 변경에 따른 main 함수 변경은 없다.

	std::unique_ptr<CPizzFactoryBase> factory = std::make_unique<CPizzFactory>();
	std::unique_ptr<CPizza> superSupremePizza = factory->productPizza("superSupreme");
	superSupremePizza->printPizzaInfo();
	
	return 0;
}