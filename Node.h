#ifndef NODE_H
#define NODE_H

template<class type>
class Queue;

template<class type>
class NODE
{
	friend class Queue<type>;
private:
	type data;
	NODE* next;
public:
	NODE(type X, NODE<type>* next = nullptr);
	void deleteNODE();
	~NODE();
};

template <class type>
NODE<type>::NODE(type X, NODE<type>* next)
{
	this->data = X;
	this->next = next;
}


#endif
