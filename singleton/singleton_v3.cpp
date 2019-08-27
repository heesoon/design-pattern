#include <iostream>
#include <memory>
#include <mutex>
#include <string>

/*
	singleton design pattern - vsersion 3

	앞의 두 예제를 종합해 보면,
	1) main 함수 종료와 함께 정확하게 객체는 소멸됨을 보증해야 한다.
	2) thread safe 해야 한다. 앞의 두 예제는 아직까지 두 문제를 해결하지 못했다.

	전통적인 방식은 Mutex를 사용해서 처리했을 것이다.
	하지만 이는 조사를 더 해 보아야 하겠지만
	std::call_once 와 std::once_flag를 사용하면 위의 두 조건을 만족시킬 수 있다고 한다.
*/

class CPizza
{
public:
	static CPizza* getInstance()
	{
		std::call_once(flag, [](){
			std::cout << "called once function .. " << std::endl;
			up.reset(new CPizza);
		});
        
        return up.get();
	}

	void print() const
	{
		std::cout << "called print function .." << std::endl;
	}

	~CPizza() = default;
    //~CPizza() {std::cout << "~CPizza() .. " << std::endl;}
    
private:
	static std::once_flag flag;
	static std::unique_ptr<CPizza> up;

private:
	CPizza() = default;
	CPizza(const CPizza &other) = delete;
	CPizza& operator=(const CPizza& other) = delete;
	//~CPizza() = default;
	//~CPizza() {std::cout << "~CPizza() .. " << std::endl;}
};

std::once_flag CPizza::flag;
std::unique_ptr<CPizza> CPizza::up = nullptr;

int main()
{
	CPizza *p = CPizza::getInstance();
	p->print();

    CPizza *p2 = CPizza::getInstance();
	p2->print();
    
	return 0;
}
