#include <iostream>
#include <string>
#include <memory>

#define DEBUG_STAUTS 1

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
protected:
	std::unique_ptr<CPizza> pizza;
public:
	void createPizzaProduct()
	{
#if 1		
		// c++11
		pizza.reset(new CPizza);
#else		
		// since c++ 14
		pizza = std::make_unique<CPizza>();
#endif		
	}
	
	// getResult() : Product
	std::unique_ptr<CPizza> getPizza() noexcept
	{
		return std::move(pizza);
	}
	
	// buildPart()
	virtual void buildPizzaName() = 0;
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
	
	virtual ~CPizzaBuilder() = default;
};

// Concrete Builder
class CSpicyPizzaBuilder : public CPizzaBuilder
{
public:
	// buildPart()
	virtual void buildPizzaName() override 	{ pizza->setPizzaName("SpicyPizza"); }
    virtual void buildDough() override		{ pizza->setDough("pan baked"); }
    virtual void buildSauce() override		{ pizza->setSauce("hot"); }
    virtual void buildTopping() override	{ pizza->setTopping("pepperoni and salami"); }

	virtual ~CSpicyPizzaBuilder() = default;
};

// Concrete Builder
class CHawaiianPizzaBuilder : public CPizzaBuilder
{
public:
	// buildPart()
	virtual void buildPizzaName() override	{ pizza->setPizzaName("HawaiianPizza"); }
    virtual void buildDough() override		{ pizza->setDough("cross"); }
    virtual void buildSauce() override		{ pizza->setSauce("mild"); }
    virtual void buildTopping() override	{ pizza->setTopping("ham and pineaple"); }

	virtual ~CHawaiianPizzaBuilder() = default;
};

// Director
class CWaiter
{	
public:
	void setPizzaBuilder(CPizzaBuilder* b)
	{
		pizzaBuilder = b;
	}

	void constructPizza()
	{
		pizzaBuilder->createPizzaProduct();
		pizzaBuilder->buildPizzaName();
		pizzaBuilder->buildDough();
		pizzaBuilder->buildSauce();
		pizzaBuilder->buildTopping();
	}
	
	std::unique_ptr<CPizza> getPizza() noexcept { return std::move(pizzaBuilder->getPizza()); }
private:
	CPizzaBuilder* pizzaBuilder;
};

int main()
{
	CWaiter waiter;
	
	CHawaiianPizzaBuilder hawaiianPizzaBuilder;
	waiter.setPizzaBuilder(&hawaiianPizzaBuilder);
	waiter.constructPizza();
	std::unique_ptr<CPizza> hwaiianPizza = waiter.getPizza();
	hwaiianPizza->printPizzaInfo();

	CSpicyPizzaBuilder spicyPizzaBuilder;
	waiter.setPizzaBuilder(&spicyPizzaBuilder);
	waiter.constructPizza();
	std::unique_ptr<CPizza> spicyPizza = waiter.getPizza();
	spicyPizza->printPizzaInfo();
	
	return 0;
}