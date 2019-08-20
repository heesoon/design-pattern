#include <iostream>
#include <memory>
#include <string>

// factory method design pattern study

class CPizza
{
public:
	// CPizza의 소멸자는 없어야 한다. 여기서는 소멸자 호출을 보기위해서 디버그 용도로 추가한 것이다.
	~CPizza(){std::cout << "~CPizza()" << std::endl;}
};

class CPizzaStore
{
public:
	// 1. 아래 코드는 pizza type이 추가될 경우, 변화는 부분이다.
	// 2. 각 pizza type에 맞는 pizza를 생성해서 최종 return해야 한다.
	
	// -> 아래 변화는 코드는 별도의 class로 분리하고, 각 Pizza Type에 맞는 Pizza를 생성하기 위해서
	//    CPizza를 부모(interface)로 하고 새부 구체적인 Pizza의 형태는 자식 class에서 구체화한다.
	
	std::unique_ptr<CPizza> pizzaOrder(const std::string& str)
	{
		if(str == "spicy")
		{
			// CPizza를 return하지만 실제 CPizza를 받고자하는 것이 아니라 Spicy Pizza를 원한다.
			return std::unique_ptr<CPizza>(new CPizza);
		}
		else if(str == "hawaiian")
		{
			// CPizza를 return하지만 실제 CPizza를 받고자하는 것이 아니라 Hwaiian Pizza를 원한다.
			return std::unique_ptr<CPizza>(new CPizza);
		}
	}
	
};

int main()
{
	CPizzaStore store;
	std::unique_ptr<CPizza> spicyPizza = store.pizzaOrder("spicy");
	std::unique_ptr<CPizza> hwaiianPizza = store.pizzaOrder("hawaiian");
	
	return 0;
}