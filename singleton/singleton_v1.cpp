#include <iostream>
#include <memory>
#include <string>

/*
	singleton design pattern - vsersion 1
	Usage : 단 하나의 객체 생성을 보증한다.

	1) static instance inclusing lazy initialization
	2) static getInstance : provide object access point
	3) 객체 단독으로 생성자 호출을 막기위해서 모든 생성자는 private or protected 에 정의한다.

	singleton의 설계 시, 고려사항
	1) 생성된 전역 객체는 main 함수 종료와 함께 소멸되는가? 소멸되지 않는 경우는 없는가?
	   -> 전역변수(static)은 main 함수 종료 후에 소멸되기 때문에 메모리 누수의 위험이 존재한다.
	2) singleton은 전역 객체를 생성하기 때문에, 이 전역객체가 thread와 함께 사용 시 문제가 없는가? (thread safe 하지 않다)

	아래 instance를 동적으로 할당하는 경우에는 1)의 문제가 발생할 가능성이 존재한다.
*/

class CPizza
{
public:
	static CPizza* getInstance()
	{
		if(instance == nullptr)
		{
			instance = new CPizza();
		}

		return instance;
	}

	void print() const
	{
		std::cout << "called print function .." << std::endl;
	}

	void destroy()
	{
		if(instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}

private:
	static CPizza* instance;
	CPizza() = default;
	CPizza(const CPizza &other) = delete;
	CPizza& operator=(const CPizza& other) = delete;
	~CPizza() = default;
};

CPizza* CPizza::instance = nullptr;

int main()
{
	CPizza *p = CPizza::getInstance();
	p->print();

	return 0;
}
