#include <iostream>
#include <memory>
#include <map>
#include <string>

/*
	c++ chain of responsibility pattern - version 1
	
	reference : https://www.geeksforgeeks.org/chain-responsibility-design-pattern/
*/

enum class RESOLUTION
{
	RESOLUTION_SD,
	RESOLUTION_HD,
	RESOLUTION_FHD,
	RESOLUTION_UHD
};

class CIChain
{
public:
	virtual void setNext(CIChain *n) = 0;
	virtual void handler(const RESOLUTION& res) = 0;
	virtual ~CIChain() = default;
};

class CSD : public CIChain
{
public:
	void setNext(CIChain *n)
	{
		next = n;
	}
	
	void handler(const RESOLUTION& res)
	{
		if(res == RESOLUTION::RESOLUTION_SD)
		{
			std::cout << "handled SD resolution" << std::endl;
		}
		else
		{
			std::cout << "SD handler, next handler will process" << std::endl;
			if(next != nullptr)
			{
				next->handler(res);
			}
		}
	}
	
	// only for debuging purpose, destroy code is not required
	virtual ~CSD()
	{
		std::cout << "~CSD() called .." << std::endl;
	}

private:
	CIChain *next = nullptr;	
};

class CHD : public CIChain
{
public:
	void setNext(CIChain *n)
	{
		next = n;
	}
	
	void handler(const RESOLUTION& res)
	{
		if(res == RESOLUTION::RESOLUTION_HD)
		{
			std::cout << "handled HD resolution" << std::endl;
		}
		else
		{
			std::cout << "HD handler, next handler will process" << std::endl;
			if(next != nullptr)
			{
				next->handler(res);
			}
		}
	}

	// only for debuging purpose, destroy code is not required
	virtual ~CHD()
	{
		std::cout << "~CHD() called .." << std::endl;
	}
private:
	CIChain *next = nullptr;	
};

class CFHD : public CIChain
{
public:
	void setNext(CIChain *n)
	{
		next = n;
	}
	
	void handler(const RESOLUTION& res)
	{
		if(res == RESOLUTION::RESOLUTION_FHD)
		{
			std::cout << "handled FHD resolution" << std::endl;
		}
		else
		{
			std::cout << "FHD handler, next handler will process" << std::endl;
			if(next != nullptr)
			{
				next->handler(res);
			}
		}
	}

	// only for debuging purpose, destroy code is not required
	virtual ~CFHD()
	{
		std::cout << "~CFHD() called .." << std::endl;
	}
private:
	CIChain *next = nullptr;	
};

class CUHD : public CIChain
{
public:
	void setNext(CIChain *n)
	{
		next = n;
	}
	
	void handler(const RESOLUTION& res)
	{
		if(res == RESOLUTION::RESOLUTION_UHD)
		{
			std::cout << "handled UHD resolution" << std::endl;
		}
		else
		{
			std::cout << "UHD handler, next handler will process" << std::endl;
			if(next != nullptr)
			{
				next->handler(res);
			}
		}
	}

	// only for debuging purpose, destroy code is not required
	virtual ~CUHD()
	{
		std::cout << "~CUHD() called .." << std::endl;
	}
private:
	CIChain *next = nullptr;	
};

int main()
{
	std::shared_ptr<CSD> sd = std::make_shared<CSD>();
	std::shared_ptr<CHD> hd = std::make_shared<CHD>();
	std::shared_ptr<CFHD> fhd = std::make_shared<CFHD>();
	std::shared_ptr<CUHD> uhd = std::make_shared<CUHD>();

	sd->setNext(hd.get());
	hd->setNext(fhd.get());
	fhd->setNext(uhd.get());
	
	sd->handler(RESOLUTION::RESOLUTION_UHD);
	hd->handler(RESOLUTION::RESOLUTION_UHD);
	
	return 0;
}