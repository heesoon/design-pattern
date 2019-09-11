#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ visitor pattern - version 2
	
	reference : 강석민 강사 강의 내용
*/

template<typename T> struct Node
{
	T value;
	Node *next;
};

// 기존 객체에 기능을 추가하거나 확장하고 할 때 사용한다.
template<typename T> struct IVisitor
{
	virtual void visit(T& v) = 0;
	virtual ~IVisitor() = default;
};

template<typename T> class TwiceValue : public IVisitor<T>
{
public:
	virtual void visit(T& v) override
	{
		v = v * 2;
	}
};

// 방문의 대상이 되는 객체는 IAcceptor를 상속 받아야 하고, 방문자를 받아들일 accept 함수를 가지고 있어야 한다.
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* v) = 0;
	virtual ~IAcceptor() = default;
};

// 기존 xlist에 비해, accept 함수가 추가되었다. 기능을 확장하고자 하는 visitor에게 visitor를 받아들이기위함.
template<typename T> class xlist : public IAcceptor<T>
{
public:
    // visitor 패턴을 위해서 추가된 accept 함수
	virtual void accept(IVisitor<T>* v) override
	{
		Node<T> *it = head;
		while(it != nullptr)
		{
			v->visit(it->value);
			it = it->next;
		}
	}
	
	void add(T value)
	{
		if(head == nullptr)
		{
			head = new Node<T>;
			head->value = value;
			head->next = nullptr;
		}
		else
		{
			Node<T> *it = head;
			while(it->next != nullptr)
			{
				it = it->next;
			}
			
			Node<T> *temp = new Node<T>;
			temp->value = value;
			temp->next = nullptr;
			
			it->next = temp;
		}
	}
	
	void print()
	{
		Node<T> *it = head;
		while(it != nullptr)
		{
			std::cout << it->value << " ";
			it = it->next;
		}
		std::cout << std::endl;
	}
	
	virtual ~xlist()
	{
		while(head->next != nullptr)
		{
			Node<T> *del = head;
			head = head->next;
			delete del;
		}
		
		if(head != nullptr)
		{	
			delete head;
		}
		
		std::cout << "~xlist() called .. " << std::endl;
	}

private:
	Node<T>* head = nullptr;
};

int main()
{
	xlist<int> list;
	for(int i = 0; i < 10; i++)
	{
		list.add(i);
	}

	// 값을 두 배로 변경하고자 하는 visitor
	TwiceValue<int> tv;
	list.accept(&tv);
	list.print();

	return 0;
}