#include <iostream>
#include <memory>
#include <string>

/*
	c++ fatory method design pattern - version 2
	
	1) CPizza로부터 direct 객체 생성을 못하도록 처리한다.
	-> Concrete class에서만 생성자 호출하도록 처리
	2) CPizza로부터 상속받은 Concrete class를 통해 객체를 생성한다.
	3) 객체 생성을 전담하는 클래스를 정의한다. (factory class)
	
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
	
	// 1) CPizza로부터 direct 객체 생성을 못하도록 처리한다.
protected:
	CPizza() = default;
	
private:
	std::string m_dough;
	std::string m_sauce;
	std::string m_topping;
};

// 2) CPizza로부터 상속받은 Concrete class를 통해 객체를 생성한다.
class CSuperSupremePizza : public CPizza
{
public:
	std::unique_ptr<CPizza> operator()()
	{
		std::unique_ptr<CPizza> up = std::make_unique<CSuperSupremePizza>();
		
		up->setDough("pan baked");
		up->setSauce("mild");
		up->setTopping("ham and pineaple");
		
		return up;  // return up; 는 up를 return하면서 up를 실제 받는 변수에 up를 전달하는 것과 같다.
					// std::unique_ptr<CPizza> a = CSuperSupremePizza(); 이라면
					// a.reset(up);
	}
};

class CPotatoPizza : public CPizza
{
public:
	std::unique_ptr<CPizza> operator()()
	{
		std::unique_ptr<CPizza> up = std::make_unique<CPotatoPizza>();
		
		up->setDough("pan baked");
		up->setSauce("mild");
		up->setTopping("potato");
		
		return up;  // return up; 는 up를 return하면서 up를 실제 받는 변수에 up를 전달하는 것과 같다.
					// std::unique_ptr<CPizza> a = CPotatoPizza(); 이라면
					// a.reset(up);
	}
};

// 3) 객체 생성을 전담하는 클래스를 정의한다. (factory class)

class CPizzFactory
{
}

int main()
{
	return 0;
}