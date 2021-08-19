#ifndef QUEUE_BASE_SLLIST_H
#define QUEUE_BASE_SLLIST_H

#include <new>
#include"Node.h"

template<class type>
class Queue
{
private:
	Node<type>* m_pHead;
	Node<type>* m_pTail;
public:
	Queue();
	~Queue();
	bool isEmpty();
	bool enQueue(const type& X);
	type deQueue();
private:
	void deleteNode(Node<type>*& X);
};

template<class type>
Queue<type>::Queue()
	: m_pHead(nullptr), m_pTail(nullptr)
{
}

template<class type>
bool Queue<type>::isEmpty()
{
	return (m_pHead == nullptr);
}

template<class type>
bool Queue<type>::enQueue(const type& X)
{
	Node<type>* newNode = new (std::nothrow) Node<type>(X);
	if (newNode == nullptr) { return false; }
	if (m_pHead == nullptr)
	{
		m_pHead = m_pTail = newNode;
		return true;
	}
	m_pTail->m_pNext = newNode;
	m_pTail = newNode;
	return newNode;
}

template<class type>
type Queue<type>::deQueue()
{
	if (isEmpty())
	{
		throw "Error : Queue Is Empty!";
	}
	Node<type>* p = m_pHead;
	if (m_pHead == m_pTail)
	{
		m_pHead = m_pTail = nullptr;
	}
	else
	{
		m_pHead = m_pHead->m_pNext;
	}
	type X = p->m_Data;
	deleteNode(p);
	return X;
}

template<class type>
void Queue<type>::deleteNode(Node<type>*& X)
{
	if (X == nullptr) { return; }
	X->m_pNext = nullptr;
	delete X;
	X = nullptr;
}

template<class type>
Queue<type>::~Queue()
{
	while (m_pHead != nullptr)
	{
		deQueue();
	}
}
#endif
