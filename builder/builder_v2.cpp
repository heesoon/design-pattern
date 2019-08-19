#include <iostream>
#include <string>
#include <memory>

#define DEBUG_STAUTS 0

class CPizza
{
public:
	void setDough(const std::string& dough)
	{
		m_dough = dough;
	}
	void setSauce(const std::string& sauce)
	{
		m_sauce = sauce;
	}
	void setTopping(const std::string& topping) 
	{
		m_topping = topping;
	}
	void setPizzaName(const std::string& name) 
	{
		m_name = name;
	}	
	void printPizzaInfo()
	{
		std::cout << m_name << " => dough : " << m_dough << " , " << "sauce : " << m_sauce 
		<< " , " << "topping : " << m_topping << std::endl;
	}
	
#if DEBUG_STAUTS
	~CPizza()
	{
		std::cout << "~CPizza() called check" << std::endl;
	}
#endif
	
private:
	std::string m_dough;
	std::string m_sauce;
	std::string m_topping;
	std::string m_name;
};

// Abstract Builder
class CPizzaBuilder
{
public:
	virtual std::unique_ptr<CPizza> constructPizza() = 0;
	virtual ~CPizzaBuilder() = default;
};

// Concrete Builder
class CSpicyPizzaBuilder : public CPizzaBuilder
{
public:
	virtual std::unique_ptr<CPizza> constructPizza() override
	{
		std::unique_ptr<CPizza> pizza = std::make_unique<CPizza>();
		pizza->setPizzaName("SpicyPizza");
		pizza->setDough("pan baked");
		pizza->setSauce("hot");
		pizza->setTopping("pepperoni and salami");

		return pizza;
	}

#if DEBUG_STAUTS
	~CSpicyPizzaBuilder()
	{
		std::cout << "~CSpicyPizzaBuilder() called check" << std::endl;
	}
#endif	
};

// Concrete Builder
class CHawaiianPizzaBuilder : public CPizzaBuilder
{
public:
	virtual std::unique_ptr<CPizza> constructPizza() override
	{
		std::unique_ptr<CPizza> pizza = std::make_unique<CPizza>();
		pizza->setPizzaName("HawaiianPizza");
		pizza->setDough("cross");
		pizza->setSauce("mild");
		pizza->setTopping("ham and pineaple");

		return pizza;
	}
#if DEBUG_STAUTS
	~CHawaiianPizzaBuilder()
	{
		std::cout << "~CHawaiianPizzaBuilder() called check" << std::endl;
	}
#endif	
};

// Director
class CWaiter
{	
public:
	void setPizzaBuilder(CPizzaBuilder* b)
	{
		pizzaBuilder = b;
	}
	std::unique_ptr<CPizza> constructPizza()
	{
		return pizzaBuilder->constructPizza();
	}
private:
	CPizzaBuilder* pizzaBuilder;
};

int main()
{
	CWaiter waiter;
	
	CHawaiianPizzaBuilder hawaiianPizzaBuilder;
	waiter.setPizzaBuilder(&hawaiianPizzaBuilder);
	std::unique_ptr<CPizza> hawaiianPizza = waiter.constructPizza();
	hawaiianPizza->printPizzaInfo();

	CSpicyPizzaBuilder spicyPizzaBuilder;
	waiter.setPizzaBuilder(&spicyPizzaBuilder);
	std::unique_ptr<CPizza> spicyPizza = waiter.constructPizza();
	spicyPizza->printPizzaInfo();
	
	return 0;
}