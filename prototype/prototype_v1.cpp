#include <iostream>
#include <memory>
#include <string>

/*
	c++ prototype design pattern - version 1
	
	Usage : 객체를 새로 생성하는 비용이 큰 경우에 사용한다.
	1) 먼저 객체를 new 연산자를 통해 생성하는 과정은 존재한다.
	2) 객체가 일단 생성되면, 이 후 객체를 새로 생성하지 않고, 기존에 만들어진 객체를 복사해서 생성하는 것이 핵심이다.
	   -> concrete prototype의 clone은 복사생성자를 통해서 객체를 생성하고 있다.
	
	refer to : https://ko.wikipedia.org/wiki/%ED%94%84%EB%A1%9C%ED%86%A0%ED%83%80%EC%9E%85_%ED%8C%A8%ED%84%B4
	
*/

// Prototype
class CPizza
{
public:
	virtual std::unique_ptr<CPizza> clone() const = 0;
	virtual void print() const = 0;
	virtual ~CPizza() = default;
};

// Concrete Prototype : CSuperSupremePizza
class CSuperSupremePizza : public CPizza
{
public:
	CSuperSupremePizza(const std::string& dough, const std::string& sauce, const std::string& topping) : m_dough(dough), m_sauce(sauce), m_topping(topping) {}

	virtual void print() const override
	{
		std::cout << "Pizza Info. "<< "=> dough : " << m_dough << " , " << "sauce : " << m_sauce 
		<< " , " << "topping : " << m_topping << std::endl;
	}

	virtual std::unique_ptr<CPizza> clone() const override
	{
		return std::make_unique<CSuperSupremePizza>(*this);
	}
	
private:
	std::string m_dough;
	std::string m_sauce;
	std::string m_topping;
};

// Concrete Prototype : CPotatoPizza
class CPotatoPizza : public CPizza
{
public:
	CPotatoPizza(const std::string& dough, const std::string& sauce, const std::string& topping) : m_dough(dough), m_sauce(sauce), m_topping(topping) {}

	virtual void print() const override
	{
		std::cout << "Pizza Info. "<< "=> dough : " << m_dough << " , " << "sauce : " << m_sauce 
		<< " , " << "topping : " << m_topping << std::endl;
	}

	virtual std::unique_ptr<CPizza> clone() const override
	{
		return std::make_unique<CPotatoPizza>(*this);
	}
	
private:
	std::string m_dough;
	std::string m_sauce;
	std::string m_topping;
};

int main()
{
	std::unique_ptr<CSuperSupremePizza> up = std::make_unique<CSuperSupremePizza>("pan baked", "mild" , "ham and pineaple");
	std::unique_ptr<CPizza> uPizza = up->clone();
	uPizza->print();

	return 0;
}
