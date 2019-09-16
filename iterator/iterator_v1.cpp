#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ iterator pattern - version 1
	
	reference : https://www.robertlarsononline.com/2017/04/24/iterator-pattern-using-cplusplus/
	
	c++ 표준에서는 begin(), end()함수를 통해서 aggregate에 접근할 수 있는 통로를 열어준다. iterator는 이를 통해서 aggregate를
	순회할 수 있다.
	GoF의 design patter는 aggregate는 자신을 순회할 수 있는 iterator를 제공해줘야 하는 식으로 기술되어 있다.
	
	아래 예제는 aggregate인 array와 list이다. aggregate에서 next 처리 방식이 서로 다르다.

*/

class CArray
{
public:	
	CArray(size_t sz) : mSz(sz), mPos(0)
	{
		pArr = new int [sz];
	}
	
	int next()
	{
		if(mPos + 1 >= mSz)
		{
			std::cout << "end of array" << std::endl;
			return pArr[mPos];
		}
		else
		{
			return pArr[++mPos];
		}
	}
	
	int& operator[](int index)
	{
		return pArr[index];
	}
	
	~CArray()
	{
		delete [] pArr;
		pArr = nullptr;
	}
	
private:
	int *pArr = nullptr;
	int mSz;
	int mPos = 0;
};

class CList
{
public:
	struct CNode
	{
		int value;
		CNode* next;
	};
	
	CList() : pList(nullptr)
	{
	}
	
	void push_back(int v)
	{
		CNode *n = new CNode;
		n->value = v;
		n->next = nullptr;
		
		if(pList == nullptr)
		{
			pList = n;
			pCurr = n;
		}
		else
		{
			CNode *h = pList;
			while(h->next != nullptr)
			{
				h = h->next;
			}
			
			h->next = n;
		}
	}
	
	int next()
	{
		if(pCurr->next != nullptr)
		{
			pCurr = pCurr->next;
			return pCurr->value;;
		}
		else
		{
			std::cout << "end of list" << std::endl;
			return pCurr->value;
		}
	}
	
	~CList()
	{
		CNode* iter = pList;
		while(iter != nullptr)
		{
			CNode *del = iter;
			iter = iter->next;
			delete del;
		}
		
		pList = nullptr;
		pCurr = nullptr;
		
		std::cout << "~CList() " << std::endl;
	}
	
private:
	CNode *pList = nullptr;
	CNode *pCurr = nullptr;
};

int main()
{
	CArray array(10);
	for(int i = 0; i < 10; i++)
	{
		array[i] = i+1;
	}
	
	for(int i = 0; i < 10; i++)
	{
		std::cout << array.next() << std::endl;
	}

	CList list;
	for(int i = 0; i < 10; i++)
	{
		list.push_back(i+1);
	}
	
	for(int i = 0; i < 10; i++)
	{
		std::cout << list.next() << std::endl;
	}	
	
	return 0;
}