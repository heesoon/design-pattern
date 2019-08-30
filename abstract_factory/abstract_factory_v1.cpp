#include <iostream>
#include <memory>
#include <string>

/*
	c++ abstract factory pattern - version 1
	factory method에서 다루었던 pizza example을 abstract factory로 변경해 보자.
	
	1) 변경 사항
	기존에 간단하게 dough, sauce, topping을 string type으로 정의하였는데,
	abstract factory로 확장하기 위해서는 이 들을 하나의 product로 봐야한다.
	예제를 간단하게 위해서 topping은 제외한다.
	
	최종 client가 받을 것은 pizza이다.
	pizza를 최종적으로 만들기 위해서는 dough와 sauce가 나와야 한다.
	
*/

// abstract product
class CAbstractDough
{
public:
	virtual void productDough() = 0;
	virtual void getProductInfo() const = 0;
	virtual ~CAbstractDough() = default;
};

// concrete product
class CPanBakedDough : public CAbstractDough
{
public:
	virtual void productDough() override
	{
		dough = "pan baked";
	}

	virtual void getProductInfo() const override
	{
		std::cout << "dough : " << dough << std::endl;
	}
	
	virtual ~CPanBakedDough() = default;

private:
	std::string dough;
};

// concrete product
class CThickDough : public CAbstractDough
{
public:
	virtual void productDough() override
	{
		dough = "Thick";
	}

	virtual void getProductInfo() const override
	{
		std::cout << "dough : " << dough << std::endl;
	}
	
	virtual ~CThickDough() = default;

private:
	std::string dough;
};

// abstract product
class CAbstracSauce
{
public:
	virtual void productSauce() = 0;
	virtual void getProductInfo() const = 0;
	virtual ~CAbstracSauce() = default;
};

// concrete product
class CMildSauce : public CAbstracSauce
{
public:
	virtual void productSauce() override
	{
		sauce = "mild";
	}

	virtual void getProductInfo() const override
	{
		std::cout << "sauce : " << sauce << std::endl;
	}
	
	virtual ~CMildSauce() = default;

private:
	std::string sauce;
};

// concrete product
class CHotSauce : public CAbstracSauce
{
public:
	virtual void productSauce() override
	{
		sauce = "hot";
	}

	virtual void getProductInfo() const override
	{
		std::cout << "sauce : " << sauce << std::endl;
	}
	
	virtual ~CHotSauce() = default;

private:
	std::string sauce;
};

// abstract factory
class CAstractPizzFactory
{
public:
	virtual std::unique_ptr<CAbstractDough> createDough() = 0;
	virtual std::unique_ptr<CAbstracSauce> createSauce() = 0;
	virtual ~CAstractPizzFactory() = default;
};

// concrete factory
class CSuperSupremePizzaFactory : public CAstractPizzFactory
{
public:
	virtual std::unique_ptr<CAbstractDough> createDough()
	{
		std::unique_ptr<CPanBakedDough> up = std::make_unique<CPanBakedDough>();
		up->productDough();
		
		return up;
	}
	
	virtual std::unique_ptr<CAbstracSauce> createSauce()
	{
		std::unique_ptr<CMildSauce> up = std::make_unique<CMildSauce>();
		up->productSauce();
		
		return up;
	}	
	
	virtual ~CSuperSupremePizzaFactory() = default;
};

// concrete factory
class CSpicyPizzaFactory : public CAstractPizzFactory
{
public:
	virtual std::unique_ptr<CAbstractDough> createDough()
	{
		std::unique_ptr<CThickDough> up = std::make_unique<CThickDough>();
		up->productDough();
		
		return up;
	}
	
	virtual std::unique_ptr<CAbstracSauce> createSauce()
	{
		std::unique_ptr<CHotSauce> up = std::make_unique<CHotSauce>();
		up->productSauce();
		
		return up;
	}	
	
	virtual ~CSpicyPizzaFactory() = default;
};

class CPizza
{
public:
	CPizza(const std::string& s) : name(s) {}

	void setDough(std::unique_ptr<CAbstractDough>&& d)
	{
		_dough.reset(d.release());
	}

	void setSauce(std::unique_ptr<CAbstracSauce>&& s)
	{
		_sauce.reset(s.release());
	}
	
	void printPizzaInfo()
	{
		std::cout << name << " pizza ---------------> " << std::endl;
		std::cout << "dough : ";
		_dough->getProductInfo();
		std::cout << "sauce : ";
		_sauce->getProductInfo();
		std::cout << std::endl;
	}
private:
	std::string name;
	std::unique_ptr<CAbstractDough> _dough;
	std::unique_ptr<CAbstracSauce> _sauce;
};

int main()
{
	CPizza pizza("SuperSupreme");
	CSuperSupremePizzaFactory superSupremePizzaFactory;
	std::unique_ptr<CAbstractDough> up1 = superSupremePizzaFactory.createDough();
	std::unique_ptr<CAbstracSauce> up2 = superSupremePizzaFactory.createSauce();
	pizza.setDough(std::move(up1));
	pizza.setSauce(std::move(up2));
	pizza.printPizzaInfo();

	return 0;
}