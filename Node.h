#ifndef NODE_H
#define NODE_H

template<class type>
class Queue;

template<class type>
class Node
{
	friend class Queue<type>;
private:
	type m_Data;
	Node* m_pNext;
public:
	Node(const type& X, Node<type>* next = nullptr)
		: m_Data(X), m_pNext(next)
	{
	}
	~Node()
	{
	}
};



#endif
