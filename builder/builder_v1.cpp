#include <iostream>
#include <string>
#include <memory>

// Product
class CPizza
{
public:
	void setDough(const std::string& dough) 	{ m_dough = dough; }
	void setSauce(const std::string& sauce) 	{ m_sauce = sauce; }
	void setTopping(const std::string& topping) { m_topping = topping; }
	void setPizzaName(const std::string& name) 	{ m_name = name;	}	
	void printPizzaInfo() const
	{
		std::cout << m_name << " => dough : " << m_dough << " , " << "sauce : " << m_sauce 
		<< " , " << "topping : " << m_topping << std::endl;
	}

private:
	std::string m_dough;
	std::string m_sauce;
	std::string m_topping;
	std::string m_name;
};

class CPizzaBuilder
{
public:
	/*
		builder pattern
		
		Usage : 객체생성과정은 복잡하지만, 객체의 생성과정은 객체를 생성하기 위한 값만 (표헌식 - representation)만 다르고 생성과정은 동일하다.
		Design Pattern은 변화는 것과 변화지 않는 것을 구분하여 어떻게 설계할 것인가에 대한 규칙이다.

		GOF 기반으로 변화는 것 : 객체의 표현식 (object representation)
		          변화지 않는 것 : 객체 생성과정 (object construction process)
				  
		아래 코드에서 변화지 않는 것은 pizza를 생성하는 과정인 set함수들이고, 변화는 것은 set함수에 입력값들이다.
		
		결국 변화지 않는 부부은 abstraction class로 분리하고, 변화는 부분을 처리하 위해서 abstraction class로부터 상속 받아서 변화는 것을 처리한다.
	*/
	void createPizzaProduct()
	{
#if 1
		// c++ 11
		pizza.reset(new CPizza);
#else
		pizza = std::make_unique<CPizza>();
#endif
	}

	void buildPizzaName(const std::string& name) 	{ pizza->setPizzaName(name); }
    void buildDough(const std::string& dough) 		{ pizza->setDough(dough); }
    void buildSauce(const std::string& sauce) 		{ pizza->setSauce(sauce); }
    void buildTopping(const std::string& topping) 	{ pizza->setTopping(topping); }
	
	std::unique_ptr<CPizza> constructPizza(const std::string &str)
	{
		std::unique_ptr<CPizza> pizza = std::make_unique<CPizza>();
		pizza->setPizzaName(str);
		pizza->setDough("pan baked");
		pizza->setSauce("hot");
		pizza->setTopping("pepperoni and salami");
		
		return pizza; // NRVO (Named Return Value Optiomization)
	}
	
#if 1
	// c++ 11
	auto getPizza() noexcept -> std::unique_ptr<CPizza> { return std::move(pizza); }
#else
	// since c++ 14
	auto getPizza() noexcept { return std::move(pizza); }	
#endif	
	
private:
	std::unique_ptr<CPizza> pizza;
};

int main()
{
	// product : spicy pizza
	CPizzaBuilder pizzaBuilder1;
	
	// same pizza production process
	pizzaBuilder1.createPizzaProduct();
	pizzaBuilder1.buildPizzaName("spicy pizza");
	pizzaBuilder1.buildDough("pan baked");
	pizzaBuilder1.buildSauce("hot");
	pizzaBuilder1.buildTopping("pepperoni and salami");
	
	auto spicyPizza = pizzaBuilder1.getPizza();
	spicyPizza->printPizzaInfo();
	
	// product : hwaiian pizza
	CPizzaBuilder pizzaBuilder2;
	
	// same pizza production process
	pizzaBuilder2.createPizzaProduct();
	pizzaBuilder2.buildPizzaName("Hawaiian pizza");
	pizzaBuilder2.buildDough("cross");
	pizzaBuilder2.buildSauce("mild");
	pizzaBuilder2.buildTopping("ham and pineaple");
	
	auto hwaiianPizza = pizzaBuilder2.getPizza();
	hwaiianPizza->printPizzaInfo();	

	return 0;
}