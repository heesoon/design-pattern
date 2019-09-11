#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ visitor pattern - version 1
	
	reference :
*/
template<typename T> struct Node
{
	T value;
	Node *next;
};

// Element class
template<typename T> class xlist
{
public:
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

	list.print();

	return 0;
}