#include <iostream>
#include <string>
#include <memory>

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
	void print()
	{
		std::cout << m_dough << " : " << m_sauce << " : " << m_topping << std::endl;
	}
    
    ~CPizza()
    {
        std::cout << "~CPizza()" << std::endl;
    }
private:
	std::string m_dough;
	std::string m_sauce;
	std::string m_topping;
};

class CPizzaBuilder
{
public:
	std::unique_ptr<CPizza> constructPizza()
	{
		std::unique_ptr<CPizza> pizza = std::make_unique<CPizza>();
		pizza->setDough("pan baked");
		pizza->setSauce("hot");
		pizza->setTopping("pepperoni and salami");
		
		return pizza;
	}
};

int main()
{
	CPizzaBuilder pizzaBuilder;
	std::unique_ptr<CPizza> pizza = pizzaBuilder.constructPizza();
	pizza->print();
	
	return 0;
}