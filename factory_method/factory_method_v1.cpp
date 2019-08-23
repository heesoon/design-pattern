#include <iostream>
#include <memory>
#include <string>

/*
	c++ fatory method design pattern - version 1
	
	아래 main함수에서 먼저 피자객체를 생성하고, 생성된 피자객체에 대해서 세부설정을 해주어야한다.
	만약 main함수가 피자주문을 받는 waiter라고 가정하면 매우 비생산적인 구조이다.
	
	이 코드를 factory method design pattern과 연계하여 개선해보는 것이 목표이다.
*/

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

private:
	std::string m_dough;
	std::string m_sauce;
	std::string m_topping;
};

int main()
{
	// 1. Super Supreme
	auto superSupreme = std::make_unique<CPizza>();
	superSupreme->setDough("pan baked");
	superSupreme->setSauce("mild");
	superSupreme->setTopping("ham and pineaple");
	superSupreme->printPizzaInfo();
	
	// 2. potato
	auto potato = std::make_unique<CPizza>();
	potato->setDough("pan baked");
	potato->setSauce("mild");
	potato->setTopping("potato");
	potato->printPizzaInfo();

	return 0;
}