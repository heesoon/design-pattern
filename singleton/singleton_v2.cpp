#include <iostream>
#include <memory>
#include <string>

/*
	singleton design pattern - vsersion 2

	앞의 signleton_v1.cpp의 동적할당의 문제점인 main 함수 종료 후의 메모리 누수를 없애기 위해서
	정적으로 instance를 할당하였다.
	static 변수를 외부에서 초기화해야 하는 것과 같은 지저분한 코드가 모두 사라졌으며, main함수 종료후의
	메모리 누수에 대한 걱정은 사라졌다.
*/

class CPizza
{
public:
	static CPizza* getInstance()
	{
		static CPizza instance;
		return &instance;
	}

	void print() const
	{
		std::cout << "called print function .." << std::endl;
	}

private:
	CPizza() = default;
	CPizza(const CPizza &other) = delete;
	CPizza& operator=(const CPizza& other) = delete;
	~CPizza() = default;
	//~CPizza() {std::cout << "~CPizza() .. " << std::endl;}
};

int main()
{
	CPizza *p = CPizza::getInstance();
	p->print();

	return 0;
}
