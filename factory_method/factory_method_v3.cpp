#include <iostream>
#include <memory>
#include <string>

/*
	c++ fatory method design pattern - version 3
	
	static 함수로 변경할 경우, 구현 사항
	refer to https://www.geeksforgeeks.org/design-patterns-set-2-factory-method/
	
	CPizza안에 static 함수를 사용해서 CPizza의 서브클래스 생성까지 모두 포함시키는 구조
	CPizza가 library이라면, 이런 방식도 좋은 방법이라고 판단됨.
	
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

	static std::unique_ptr<CPizza> productPizza(const std::string &pizzaType);

protected:
	CPizza(const std::string& dough, const std::string sauce, const std::string topping) : m_dough(dough), m_sauce(sauce), m_topping(topping){}

private:
	std::string m_dough;
	std::string m_sauce;
	std::string m_topping;
};
// 2) CPizza로부터 상속받은 Concrete class를 통해 객체를 생성한다.
class CSuperSupremePizza : public CPizza
{
public:
	// using을 사용할 경우, CPizza의 생성자를 protected에 놓을 수 없음.
	//using CPizza::CPizza;
	// 위임생성자 사용
	CSuperSupremePizza() : CPizza("pan baked", "mild" , "ham and pineaple"){}
};

class CPotatoPizza : public CPizza
{
public:
	// using을 사용할 경우, CPizza의 생성자를 protected에 놓을 수 없음.
	//using CPizza::CPizza;
	// 위임생성자 사용
	CPotatoPizza() : CPizza("pan baked", "mild" , "potato"){}
};

// 바로 생성자를 호출하는 구조로 바뀌었지만, 빌더 패턴과 같이 사용하면 더 효율적인 방식이 나올 수 있을 것으로 판단됨.
// 예로, factory method로는 객체 생성만하고, 실제 세부 설정은 빌더패턴을 적용한다.
std::unique_ptr<CPizza> CPizza::productPizza(const std::string &pizzaType)
{
	if(pizzaType == "superSupreme")
	{
		//return std::make_unique<CSuperSupremePizza>("pan baked", "mild" , "ham and pineaple");
		return std::make_unique<CSuperSupremePizza>();
	}
	else if(pizzaType == "potato")
	{
		//return std::make_unique<CPotatoPizza>("pan baked", "mild" , "potato");
		return std::make_unique<CPotatoPizza>();
	}
	else
	{
		return nullptr;
	}		
}

int main()
{
	std::unique_ptr<CPizza> superSupremePizza = CPizza::productPizza("superSupreme");
	superSupremePizza->printPizzaInfo();
	
	return 0;
}