#include <iostream>
#include <memory>
#include <string>

/*
	c++ fatory method design pattern - version 1
	
	일반적으로 클래스에서 객체를 생성해서 사용하는 시나리오이다.
	main 함수는 사용자(client)라고 봤을 떄, 사용자는 객체를 생성하기 위해서 모든 내용을 알고 있어야 한다.
	사용자에게 세부 객체 생성 설정은 감추고, 대신 객체를 생성해 주는 대리자를 통해서 간단하게 생성하는 방식이 필요하다.
	factory method는 이 대리자가 동일하고 일관된 interface를 갖도록 구현하는 것이다.
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