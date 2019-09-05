#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ facade pattern - version 1
	
	사용자가 원하는 목표 기능을 달성하기 위해서는 많은 서브 시스템이 존재해야하고 설정해야 한다고 가정하자. 서브시스템은 클래스의 객체로 보면된다.
	하지만 사용자가 각 서브시스템의 설정을 일일이 해 준다면 비효율적일 것이다.
	서브시스템에 대한 세부 설정은 사용자에게 숨기고, 단순한 interface를 통해서 사용자가 원하는 목표를 달성할 수 있도록 제공하는 패턴전략이다.
*/

// subsystem class
class CPowerSupplier
{
public:
	void supplyPower()
	{
		std::cout << "supply power " << std::endl;
	}
};

// subsystem class
class CCPU
{
public:
	void cpuPowerOn()
	{
		std::cout << "power on cpu " << std::endl;
	}
	
	void reset()
	{
		std::cout << "reset cpu " << std::endl;
	}
};

// subsystem class
class CMotherBoard
{
public:
	void motherBoardPowerOn()
	{
		std::cout << "power on mother board " << std::endl;
	}
};

// facede class
class CFacade
{
public:

	CFacade()
	{
		powerSupplier = std::make_shared<CPowerSupplier>();
		cpu = std::make_shared<CCPU>();
		motherboard = std::make_shared<CMotherBoard>();
	}

	void powerOn()
	{
		powerSupplier->supplyPower();
		motherboard->motherBoardPowerOn();
		cpu->cpuPowerOn();
		cpu->reset();
	}

private:
	std::shared_ptr<CPowerSupplier> powerSupplier;
	std::shared_ptr<CCPU> cpu;
	std::shared_ptr<CMotherBoard> motherboard;
};

int main()
{
	CFacade facade;
	facade.powerOn();

	return 0;
}