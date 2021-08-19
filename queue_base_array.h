#ifndef QUEUE_BASE_ARRAY
#define QUEUE_BASE_ARRAY

#include <new>

template<class type>
class Queue
{
private:
	type* m_pItems;
	int m_nSize;
	int m_nFront;
	int m_nRear;
	int m_nLength;
public:
	Queue(const int& size);
	~Queue();
	bool isFail();
	bool isEmpty();
	bool isFull();
	bool enQueue(const type& X);
	type deQueue();
};

template<class type>
Queue<type>::Queue(const int& size)
{
	if (size <= 0) { m_pItems == nullptr; }
	m_pItems = new (std::nothrow) type[size];
	if (m_pItems != nullptr)
	{
		this->m_nSize = size;
		this->m_nFront = 0;
		this->m_nRear = -1;
		this->m_nLength = 0;
	}
}

template<class type>
Queue<type>::~Queue()
{
	if (isFail()) { return; }
	this->m_nSize = 0;
	this->m_nFront = 0;
	this->m_nRear = -1;
	this->m_nLength = 0;
	delete[] m_pItems;
	m_pItems = nullptr;
}

template<class type>
bool Queue<type>::isFail()
{
	return (m_pItems == nullptr);
}

template<class type>
bool Queue<type>::isEmpty()
{
	return (m_nLength == 0);
}

template<class type>
bool Queue<type>::isFull()
{
	return (m_nLength == m_nSize);
}

template<class type>
bool Queue<type>::enQueue(const type& X)
{
	if (isFull()) { return false; }
	m_nRear = (++m_nRear) % m_nSize;
	m_pItems[m_nRear] = X;
	m_nLength++;
	return true;
}

template<class type>
type Queue<type>::deQueue()
{
	if (isEmpty())
	{
		throw "Error : Queue Is Empty!";
	}
	type X = m_pItems[m_nFront];
	m_nFront = (++m_nFront) % m_nSize;
	m_nLength--;
	return X;
}
#endif
