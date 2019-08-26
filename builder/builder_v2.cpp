#include <iostream>
#include <string>
#include <memory>

#define DEBUG_STAUTS 0

// Product
class CPizza
{
	friend class CPizzaBuilder;
public:
	void setDough(const std::string& dough) 	{ m_dough = dough; }
	void setSauce(const std::string& sauce) 	{ m_sauce = sauce; }
	void setTopping(const std::string& topping) { m_topping = topping; }
	void printPizzaInfo() const
	{
		std::cout << "dough : " << m_dough << " , " << "sauce : " << m_sauce
		<< " , " << "topping : " << m_topping << std::endl;
	}

	// CPizza 생성자를 호출하여 직접 객체 생성을 막기위함.
	// CPizza 객체 생성을 전적으로 CPizzaBuilder에 위임
private:
	CPizza() = default;
	
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
#if 1
	// c++ 11
	auto getPizza() noexcept -> std::unique_ptr<CPizza>
#else
	// since c++ 14
	auto getPizza() noexcept
	// if template is used
	//decltype(auto) getPizza() noexcept
#endif
	{
		return std::move(pizza);
	}
	
	// buildPart()
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
	
	virtual ~CPizzaBuilder() = default;
};

// Concrete Builder
class CSuperSupremePizzaBuilder : public CPizzaBuilder
{
public:
	// buildPart()
    virtual void buildDough() override		{ pizza->setDough("pan baked"); }
    virtual void buildSauce() override		{ pizza->setSauce("mild"); }
    virtual void buildTopping() override	{ pizza->setTopping("ham and pineaple"); }

	virtual ~CSuperSupremePizzaBuilder() = default;
};

// Concrete Builder
class CPotatoPizzaBuilder : public CPizzaBuilder
{
public:
	// buildPart()
    virtual void buildDough() override		{ pizza->setDough("pan baked"); }
    virtual void buildSauce() override		{ pizza->setSauce("mild"); }
    virtual void buildTopping() override	{ pizza->setTopping("potato"); }

	virtual ~CPotatoPizzaBuilder() = default;
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
		pizzaBuilder->buildDough();
		pizzaBuilder->buildSauce();
		pizzaBuilder->buildTopping();
	}
	
#if 1
	// c++ 11
	auto getPizza() noexcept -> std::unique_ptr<CPizza> { return std::move(pizzaBuilder->getPizza()); }
#else
	// since c++ 14
	auto getPizza() noexcept { return std::move(pizzaBuilder->getPizza()); }
	// if template is used
	//decltype(auto) getPizza() noexcept { return std::move(pizzaBuilder->getPizza()); }
#endif
private:
	CPizzaBuilder* pizzaBuilder;
};

int main()
{
	CWaiter waiter;
	
	CSuperSupremePizzaBuilder superSupremePizzaBuilder;
	waiter.setPizzaBuilder(&superSupremePizzaBuilder);
	waiter.constructPizza();
	auto superSupremePizza = waiter.getPizza();
	superSupremePizza->printPizzaInfo();

	CPotatoPizzaBuilder potatoPizzaBuilder;
	waiter.setPizzaBuilder(&potatoPizzaBuilder);
	waiter.constructPizza();
	auto potatoPizza = waiter.getPizza();
	potatoPizza->printPizzaInfo();
	
	return 0;
}