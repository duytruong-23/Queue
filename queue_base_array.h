#ifndef QUEUE_BASE_ARRAY
#define QUEUE_BASE_ARRAY

#include <iostream>

using namespace std;

template<class type>
class Queue
{
private:
	type* item;
	int size;
	int front;
	int rear;
	int length;
public:
	Queue(int size);
	~Queue();
	bool fail();
	bool isEmpty();
	bool isFull();
	type enQueue(type X);
	type deQueue();
};

template<class type>
Queue<type>::Queue(int size)
{
	if (size <= 0) { item == nullptr };
	item = new (nothrow) type[size];
	if (item != nullptr)
	{
		this->size = size;
		this->front = 0;
		this->rear = -1;
		this->length = 0;
	}
}

template<class type>
Queue<type>::~Queue()
{
	if (fail()) { return; }
	this->size = 0;
	this->front = 0;
	this->rear = -1;
	this->length = 0;
	delete[] item;
	item = nullptr;
}

template<class type>
bool Queue<type>::fail()
{
	return (item == nullptr);
}

template<class type>
bool Queue<type>::isEmpty()
{
	return (length == 0);
}

template<class type>
bool Queue<type>::isFull()
{
	return (length == size);
}

template<class type>
type Queue<type>::enQueue(type X)
{
	if (rear == size - 1)
	{
		rear = 0;
	}
	else { rear++; }
	item[rear] = X;
	length++;
	return X;
}

template<class type>
type Queue<type>::deQueue()
{
	type X = item[front];
	if (front == size - 1) { front = 0; }
	else { front++; }
	length--;
	return X;
}
#endif
