#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ observer pattern - version 1
	
	reference :
*/

class CObserver
{
public:
	virtual void update() = 0;
};

class CButton : public CObserver
{
public:
	virtual void update() override
	{
		std::cout << "button clicked" << std::endl;
	}
};

class CEdit : public CObserver
{
public:
	virtual void update() override
	{
		std::cout << "edit insert" << std::endl;
	}
};

// Subject
class CEventHandler
{
public:
	void attach(std::shared_ptr<CObserver> o)
	{
		v.push_back(o);
	}
	
	void detach(std::shared_ptr<CObserver> o)
	{
		for(auto it = v.begin(); it != v.end(); )
		{
			if(*it == o)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
	
	void notify()
	{
		for(auto it = v.begin(); it != v.end(); it++)
		{
			(*it)->update();
		}		
	}

private:
	std::vector<std::shared_ptr<CObserver>> v;
};

class CWindow
{
public:
	void setEventHandler(std::shared_ptr<CEventHandler> e)
	{
		eventHandler = e;
	}
	void click()
	{
		eventHandler->notify();
	}

private:
	std::shared_ptr<CEventHandler> eventHandler;
};

int main()
{
	CWindow window;
	std::shared_ptr<CEventHandler> eventHandler = std::make_shared<CEventHandler>();
	window.setEventHandler(eventHandler);
	
	std::shared_ptr<CButton> button = std::make_shared<CButton>();
	eventHandler->attach(button);
	eventHandler->attach(std::make_shared<CEdit>());
	window.click();

	eventHandler->detach(button);
	
	window.click();

	return 0;
}