#include <iostream>
#include <memory>
#include <map>
#include <string>

/*
	c++ proxy pattern - version 1
	reference : https://www.bogotobogo.com/DesignPatterns/proxy.php
*/

// abstract class for server requirement
class CIServer
{
public:
	virtual bool login(const std::string& id, const std::string& pw) const = 0;
	virtual void request() = 0;
};

// real server
class CServer : public CIServer
{
public:
	virtual bool login(const std::string& id, const std::string& pw) const override
	{
        auto search = db.find(id); 
		if(search == db.end())
		{
			std::cout << "can't find user id" << std::endl;
			return false;
		}
		
		if(search->second != pw)
		{
			std::cout << "wrong password" << std::endl;
		}
		
		return true;
	}
	
	virtual void request() override
	{
		std::cout << "request work done" << std::endl;
	}

private:
	std::map<std::string, std::string> db{{"heesoon.kim", "12345678"}, {"guest", "guest1234"}};
};

// proxy server
class CProxyServer : public CIServer
{
public:
	CProxyServer()
	{
		// occassionaly lazy initialization can be applied.
		realServer = std::make_unique<CServer>();
	}
	
	virtual bool login(const std::string& id, const std::string& pw) const override
	{
		// 실제 서버에 login하기 전에 password 타당성 검증을 추가할 수 있다.
		if(pw.size() < 8)
		{
			std::cout << "invalid length of password" << std::endl;
			return false;
		}
		
		return realServer->login(id, pw);
	}
	
	virtual void request() override
	{
		realServer->request();
	}

private:
	std::unique_ptr<CIServer> realServer;
};

int main()
{
	// client implementation code
	CProxyServer proxyServer;
	bool retVal = proxyServer.login("heesoon.kim", "12345678");
	if(retVal == true)
	{
		std::cout << "login success" << std::endl;
		proxyServer.request();
	}
	else
	{
		std::cout << "login failed" << std::endl;
	}
	
	return 0;
}