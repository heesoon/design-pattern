#include <iostream>
#include <memory>
#include <map>
#include <string>

/*
	c++ command pattern - version 1
	
	reference : https://www.bogotobogo.com/DesignPatterns/command.php
*/

// command class
class CCmd
{
public:
	virtual void execute() = 0;
	virtual ~CCmd() = default;
};

// receiver class
class CLight
{
public:
	void on()
	{
		std::cout << "light turn on" << std::endl;
	}
	
	void off()
	{
		std::cout << "light turn off" << std::endl;
	}
};

// command for light turn on : request를 객체로 캡슐화한다.
// receiver를 가지고 있어야 한다. 여기서 receiver는 CLight
class CLightOnCmd : public CCmd
{
public:
	CLightOnCmd(std::shared_ptr<CLight> l) : light(l) {}

	virtual void execute() override
	{
		light->on();
	}

private:
	std::shared_ptr<CLight> light;
};

// command for light turn off : request를 객체로 캡슐화한다.
// receiver를 가지고 있어야 한다. 여기서 receiver는 CLight
class CLightOffCmd : public CCmd
{
public:
	CLightOffCmd(std::shared_ptr<CLight> l) : light(l) {}

	virtual void execute() override
	{
		light->off();
	}

private:
	std::shared_ptr<CLight> light;
};

// invoker (sender)
// 실제 구체화된 command를 호출한다.
// command를 가지고 있어야 한다.
class CRemoteControl
{
public:
	void setCmd(std::shared_ptr<CCmd> c)
	{
		cmd = c;
	}
	
	// 사용자의 각 request를 함수로 매핑에서, 각 request에 해당하는 함수를 호출하는 것이 아니고,
	// 대신 객체를 변경하면서, 해당 request의 객체를 호출한다.
	void buttonPressed()
	{
		cmd->execute();
	}
private:
	std::shared_ptr<CCmd> cmd;
};

int main()
{
	// client 코드
	// 1. 호출할 command를 선택 -> command 초기화 시에 receiver도 설정 (이부분이 조금 이상하기는 함)
	std::shared_ptr<CLight> light = std::make_shared<CLight>();
	
	// 현재 구조에서 CLightOnCmd는 어차피 CLight의 동작을 제어하는 command임으로 구지 아래 코드처럼 Receiver를
	// 따로 외부에서 해 주는 것은 좋은 방식이 아닌 것으로 보인다.
	std::shared_ptr<CLightOnCmd> lightOnCmd = std::make_shared<CLightOnCmd>(light);
	std::shared_ptr<CRemoteControl> remoteControl = std::make_shared<CRemoteControl>();
	remoteControl->setCmd(lightOnCmd);
	remoteControl->buttonPressed();

	return 0;
}