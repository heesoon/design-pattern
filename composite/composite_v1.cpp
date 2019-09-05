#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ composite pattern - version 1
	
	reference : https://www.bogotobogo.com/DesignPatterns/composite.php
*/

// component class
class CNode
{
public:
	virtual void print() const = 0;
	virtual void add(std::shared_ptr<CNode> n) {}
	virtual void getChild(int) {}
	virtual ~CNode() = default;
};

// Leaf class
class CFile : public CNode 
{
public:
	virtual void print() const override 
	{
		std::cout << "file ..\n";
	}
	
	virtual ~CFile()
	{
		std::cout << "called ~CFile() .. " << std::endl;
	}
};

// composite class
class CDirectory : public CNode 
{
public:
	virtual void print() const override 
	{
		std::cout << "directory.. " << std::endl;
		for(auto x : v)
		{
			x->print();
		}
	}

	virtual void add(std::shared_ptr<CNode> n) override
	{
		v.push_back(n);
	}
	
	virtual ~CDirectory()
	{
		std::cout << "called ~CDirectory() .. " << std::endl;
	}

private:
	std::vector<std::shared_ptr<CNode>> v;
};

int main()
{
	CDirectory dir;
	dir.add(std::make_shared<CFile>());
	dir.add(std::make_shared<CFile>());
	dir.add(std::make_shared<CDirectory>());
	dir.add(std::make_shared<CDirectory>());
	dir.add(std::make_shared<CFile>());
	dir.add(std::make_shared<CFile>());
	dir.print();

	return 0;
}