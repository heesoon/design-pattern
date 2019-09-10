#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ mediate pattern - version 1
	
	reference : https://zamjad.wordpress.com/2012/04/25/mediator-design-pattern-using-c/
*/
class CObject;

class CMediator
{
public:
	virtual void registerObj(CObject* obj) = 0;
	virtual void send(const std::string &msg, CObject *obj) = 0;
	virtual ~CMediator() = default;
};

class CObject
{
public:
	virtual void send(const std::string &msg, CObject* obj) = 0;
	virtual void receive(const std::string &msg) = 0;
	virtual ~CObject() = default;
};

class CObjectA : public CObject
{
public:
	//CObject(std::shared<CMediator> m) : mediator(m)
	CObjectA(CMediator *m) : mediator(m)
	{
		mediator->registerObj(this);
	}

	virtual void send(const std::string &msg, CObject* obj) override
	{
		mediator->send(msg, obj);
	}
		
	virtual void receive(const std::string &msg) override
	{
		std::cout << "Object A receive : " << msg << std::endl;
	}

	virtual ~CObjectA() = default;

protected:
	//std::shared<CMediator> mediator
	CMediator *mediator;
};

class CObjectB : public CObject
{
public:
	//CObject(std::shared<CMediator> m) : mediator(m)
	CObjectB(CMediator *m) : mediator(m)
	{
		mediator->registerObj(this);
	}

	virtual void send(const std::string &msg, CObject* obj) override
	{
		mediator->send(msg, obj);
	}

	virtual void receive(const std::string &msg) override
	{
		std::cout << "Object B receive : " << msg << std::endl;
	}

	virtual ~CObjectB() = default;

protected:
	//std::shared<CMediator> mediator
	CMediator *mediator;
};

class CMediatorA : public CMediator
{
public:
	virtual void registerObj(CObject *obj) override
	{
		v.push_back(obj);
	}
	
	virtual void send(const std::string &msg, CObject *obj) override
	{
		for(auto x : v)
		{
			if(x == obj)
			{
				x->receive(msg);
			}
		}
	}

	virtual ~CMediatorA() = default;

private:
	std::vector<CObject*> v;
};

int main()
{
	CMediatorA ma;
	
	CObjectA objA(&ma);
	CObjectB objB(&ma);
	
	objB.send("222", &objA);
	ma.send("1111", &objA);
	
	return 0;
}