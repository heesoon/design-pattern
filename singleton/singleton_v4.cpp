#include <iostream>
#include <memory>
#include <mutex>
#include <string>

/*
	singleton design pattern - vsersion 4
	
	최종정리.
	1) 모든 타입에 적용 가능한 singleton 패턴 정의
	2) 상속도 고려해 본다. 
*/

class CPizza
{
public:
	CPizza() { std::cout << "called CPizza() .. " << std::endl;}
	~CPizza() { std::cout << "called ~CPizza() .. " << std::endl;}
	void print() { std::cout << "print called .." << std::endl;}
};

template<typename T>
class CSingleton
{
public:
	static T* getInstance()
	{
		std::call_once(flag, [](){
			std::cout << "called once function .. " << std::endl;
			up.reset(new T);
		});
        
        return up.get();
	}
    
private:
	static std::once_flag flag;
	static std::unique_ptr<T> up;
};

template<typename T> std::once_flag CSingleton<T>::flag;
template<typename T>  std::unique_ptr<T> CSingleton<T>::up = nullptr;

int main()
{
	CPizza *p = CSingleton<CPizza>::getInstance();
	p->print();
    CPizza *p2 = CSingleton<CPizza>::getInstance();
    p2->print();
    
	return 0;
}
