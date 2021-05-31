#ifndef QUEUE_BASE_SLLIST_H
#define QUEUE_BASE_SLLIST_H

#include <iostream>
#include"Node.h"

using namespace std;

template<class type>
class Queue
{
private:
	NODE<type>* head;
	NODE<type>* tail;
public:
	Queue();
	~Queue();
	bool isEmpty();
	bool enQueue(type X);
	type deQueue();
private:
	void deleteNODE(NODE<type>*& X);
};

template<class type>
Queue<type>::Queue()
{
	head = nullptr;
	tail = nullptr;
}

template<class type>
bool Queue<type>::isEmpty()
{
	return (head == nullptr);
}

template<class type>
NODE<type>* enQueue(type X)
{
	NODE<type>* newNODE = new (nothrow) NODE<type>(X);
	if (newNODE == nullptr) { return nullptr; }
	if (head == nullptr)
	{
		head = tail = newNODE;
		return newNODE;
	}
	tail->next = newNODE;
	tail = newNODE;
	return newNODE;
}

template<class type>
type Queue<type>::deQueue()
{
	NODE<type>* p = head;
	if (head == tail)
	{
		head = tail = nullptr;
	}
	else
	{
		head = head->next;
	}
	type X = p->data;
	deleteNODE(p);
	return X;
}

template<class type>
void deleteNODE(NODE<type>*& X)
{
	if (X == nullptr) { return; }
	X->next = nullptr;
	delete X;
	X = nullptr;
}

template<class type>
Queue<type>::~Queue()
{
	while (head != nullptr)
	{
		deQueue();
	}
}
#endif
