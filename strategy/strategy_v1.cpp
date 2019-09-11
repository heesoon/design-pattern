#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ strategy pattern - version 1
	
	reference : https://www.bogotobogo.com/DesignPatterns/strategy.php
*/

// strategy base class
class CSort
{
public:
	// execute에 해당
	virtual void sort() = 0;
};

// concrete strategy class
class CBubble : public CSort
{
public:
	virtual void sort() override
	{
		std::cout << "bubble sort" << std::endl;
	}
};

// concrete strategy class
class CSelect : public CSort
{
public:
	virtual void sort() override
	{
		std::cout << "select sort" << std::endl;
	}
};

// concrete strategy class
class CInsert : public CSort
{
public:
	virtual void sort() override
	{
		std::cout << "insert sort" << std::endl;
	}
};

// context class
class CTest
{
public:
	void setSort(std::shared_ptr<CSort> s)
	{
		sortAlgo = s;
	}
	
	void execute()
	{
		sortAlgo->sort();
	}

private:
	std::shared_ptr<CSort> sortAlgo;
};

int main()
{
	CTest test;
	
	std::shared_ptr<CBubble> bubble = std::make_shared<CBubble>();
	std::shared_ptr<CSelect> select = std::make_shared<CSelect>();
	std::shared_ptr<CInsert> insert = std::make_shared<CInsert>();
	
	// 알고리즘을 실시간으로 변경 가능하다.
	test.setSort(bubble);
	test.execute();
	
	test.setSort(select);
	test.execute();

	test.setSort(insert);
	test.execute();

	return 0;
}