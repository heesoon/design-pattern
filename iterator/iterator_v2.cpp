#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ iterator pattern - version 2
	
	reference :
	
	c++ 표준 iterator를 흉내내보기 위해서 GoF에 기본 구조에서 더 추가적으로 begin, end함수가 포함되었다.
	어떤 Container에서 container를 검색하거나 tracing하는 알고리즘을 별도의 iterator 객체로 분리하였다.
	container에서도 iterator가 정상적으로 동작하기 위해서는 필요한 함수를 iterator를 위해서 구현해줘야 한다.
	이 함수가 begin, end가 되겠다.
	
	container와 iterator간에 잘 분리하는 설계를 통해서 container와 관련없이 통일된 iterator가 설계가 가능해 보인다.
	예제를 간단히 하기 위해서 많은 부분 축약해서 구현하였다.

*/
struct CNode
{
	int value;
	CNode* next;
};

template<typename T>
class CArray;

// iterator base class
template <typename T>
class CIteratorBase
{
public:
	// next와 동일
	virtual T* begin() = 0;
	virtual T* end() = 0;
	virtual T* next() = 0;
	virtual ~CIteratorBase() = default;
};

// base aggregate class for supporting iterator pattern
template<typename T>
class CBaseAggregate
{
public:
	virtual CIteratorBase<T>* createIterator() = 0;
	virtual T* begin() = 0;
	virtual T* end() = 0;
	virtual ~CBaseAggregate() = default;
};

template<typename T>
class CArrayIterator : public CIteratorBase<T>
{
public:
	CArrayIterator(CBaseAggregate<T> *p) : pAggregate(p) {}

	virtual T* begin() override
	{
		mCurr = pAggregate->begin();
		return pAggregate->begin();
	}
	
	virtual T* end() override
	{
		return pAggregate->end();
	}
	
	virtual T* next() override
	{
		return ++mCurr;
	}

	virtual ~CArrayIterator()
	{
		std::cout << "~CArrayIterator() " << std::endl;
		//delete pAggregate;
	}
private:
	CBaseAggregate<T> *pAggregate;
	T* mCurr = nullptr;
};

// concrete aggregate class for iterator
template<typename T>
class CArray : public CBaseAggregate<T>
{
public:	
	CArray(size_t sz) : mSz(sz)
	{
		pArr = new int [sz];
	}
	
	// next는 사라졌다.
	virtual CIteratorBase<T>* createIterator() override
	{
		return new CArrayIterator<T>(this);
	}

	T& operator[](int index)
	{
		return pArr[index];
	}
	
	virtual T* begin() override
	{
		return &pArr[0];
	}
	
	virtual T* end() override
	{
		return &pArr[mSz];
	}
	
	~CArray()
	{
		delete [] pArr;
		pArr = nullptr;
		std::cout << "~CArray() " << std::endl;
	}
	
private:
	size_t mSz;
	T *pArr = nullptr;
};

template<typename T>
class CListIterator : public CIteratorBase<T>
{
public:
	CListIterator(CBaseAggregate<T> *p) : pAggregate(p) {}

	virtual T* begin() override
	{
		mCurr = pAggregate->begin();
		return pAggregate->begin();
	}
	
	virtual T* end() override
	{
		return pAggregate->end();
	}
	
	virtual T* next() override
	{
		mCurr = mCurr->next;
		return mCurr;
	}

	virtual ~CListIterator()
	{
		std::cout << "~CListIterator() " << std::endl;
		//delete pAggregate;
	}
private:
	CBaseAggregate<T> *pAggregate;
	T* mCurr = nullptr;
};

template <typename T>
class CList : public CBaseAggregate<T>
{
public:

	CList() : pHead(nullptr), pEnd(nullptr) {}

	// next는 사라졌다.
	virtual CIteratorBase<T>* createIterator() override
	{
		return new CListIterator<T>(this);
	}

	virtual T* begin() override
	{
		return pHead;
	}
	
	virtual T* end() override
	{
		return pEnd;
	}
	
	void push_back(int v)
	{
		T *n = new T;
		n->value = v;
		n->next = nullptr;
		
		if(pHead == nullptr)
		{
			pHead = n;
			pEnd = n;
		}
		else
		{
			T *h = pHead;
			while(h->next != nullptr)
			{
				h = h->next;
			}
			
			h->next = n;
			pEnd = n->next;
		}
	}
	
	virtual ~CList()
	{
		T* iter = pHead;
		while(iter != nullptr)
		{
			T *del = iter;
			iter = iter->next;
			delete del;
		}
		
		pHead = nullptr;
		
		std::cout << "~CList() " << std::endl;
	}
	
private:
	T *pHead = nullptr;
	T *pEnd = nullptr;
};

int main()
{
	// array
	CArray<int> array(10);
	for(int i = 0; i < 10; i++)
	{
		array[i] = i+1;
	}
	
	CIteratorBase<int> *pArrayIterator = array.createIterator();
	
	for(int* iter = pArrayIterator->begin(); iter != pArrayIterator->end(); iter = pArrayIterator->next())
	{
		std::cout << *iter << std::endl;
	}
	delete pArrayIterator;

	// list
	CList<CNode> list;
	for(int i = 0; i < 10; i++)
	{
		list.push_back(i+1);
	}
	
	CIteratorBase<CNode> *pListIterator = list.createIterator();
	
	for(CNode* iter = pListIterator->begin(); iter != pListIterator->end(); iter = pListIterator->next())
	{
		std::cout << iter->value << std::endl;
	}
	delete pListIterator;

	return 0;
}