#include <iostream>
#include <memory>
#include <string>

// factory method design pattern study

class CPizza
{
public:
	// CPizza의 소멸자는 없어야 한다. 여기서는 소멸자 호출을 보기위해서 디버그 용도로 추가한 것이다.
	~CPizza(){std::cout << "~CPizza() called" << std::endl;}

protected:
	explicit CPizza(std::string d, std::string s, std::string t) : dough(d), sauce(s), topping(t)
	{
		std::cout << "3 param CPizza() called" << std::endl;
	}

//private:
public:
	std::string dough;
	std::string sauce;
	std::string topping;
};

class CSpicyPizza : public CPizza
{
public:
	//using CPizza::CPizza;
	CSpicyPizza(std::string d, std::string s, std::string t) : CPizza(d, s, t)
	{
		std::cout << "3 param CSpicyPizza() called" << std::endl;
	}
};

class CHwaiianPizza : public CPizza
{
public:
	//using CPizza::CPizza;
	CHwaiianPizza(std::string d, std::string s, std::string t) : CPizza(d, s, t)
	{
		std::cout << "3 param CHwaiianPizza() called" << std::endl;
	}
};

class CPizzaFactoryBase
{
public:
	virtual std::unique_ptr<CPizza> creatPizza(const std::string& str) = 0;
};

class CPizzaFactory : public CPizzaFactoryBase
{
	virtual std::unique_ptr<CPizza> creatPizza(const std::string& str)
	{
		if(str == "spicy")
		{
			return std::unique_ptr<CSpicyPizza>(new CSpicyPizza("pan baked", "hot", "pepperoni and salami"));
		}
		else if(str == "hawaiian")
		{
			return std::unique_ptr<CHwaiianPizza>(new CHwaiianPizza("cross", "mild", "ham and pineaple"));
		}		
	}
};

class CPizzaStore
{
public:

	void setFactory(CPizzaFactoryBase *p)
	{
		factoryBase = p;
	}

	std::unique_ptr<CPizza> pizzaOrder(const std::string& str)
	{
		return factoryBase->creatPizza(str);
	}
private:
	CPizzaFactoryBase *factoryBase = nullptr;
};

int main()
{
	CPizzaFactory factory;
	CPizzaStore store;
	store.setFactory(&factory);
	
	std::unique_ptr<CPizza> spicyPizza = store.pizzaOrder("spicy");
	
	return 0;
}