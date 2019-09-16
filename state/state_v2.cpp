#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ state pattern - version 2
	
	reference :
	
	상태 추가나 삭제 시에 코드 변경이 없도록 하는 것이 목표이다. 따라서 version 1에서 구조가 많이 변경되었다.
*/

// State Base class
class CBaseState
{
public:
	virtual ~CBaseState() = default;
	virtual void handle() = 0;
};

// concrete state class
class CPlayState : public CBaseState
{
public:
	virtual ~CPlayState() = default;
	virtual void handle() override
	{
		std::cout << "play.." << std::endl;
	}
};

// concrete state class
class CStopState : public CBaseState
{
public:
	virtual ~CStopState() = default;
	virtual void handle() override
	{
		std::cout << "stop.." << std::endl;
	}
};

// concrete state class
class CPauseState : public CBaseState
{
public:
	virtual ~CPauseState() = default;
	virtual void handle() override
	{
		std::cout << "pause.." << std::endl;
	}
};

// Context class
class CMusicPlayer
{
public:
	virtual ~CMusicPlayer()
	{
		if(pState != nullptr)
		{
			delete pState;
		}
	}
	
	void request()
	{
		// 상태에 따라 먼가 바꾸고자 할 경우, this 전달하는 방식도 고려할 수 있음.
		//pState->handle(this);
		
		// 충실히 GoF Design Pattern Diagram에 입각해서 구현하면
		pState->handle();
	}
	
	void setState(CBaseState *state)
	{
		if(pState != nullptr)
		{
			delete pState;
		}
		
		pState = state;
	}

private:
	CBaseState *pState = nullptr;
};

int main()
{
	std::shared_ptr<CMusicPlayer> musicPlayer = std::make_shared<CMusicPlayer>();
	CPlayState *pStatePlay = new CPlayState();
	musicPlayer->setState(pStatePlay);
	musicPlayer->request();
	
	return 0;
}