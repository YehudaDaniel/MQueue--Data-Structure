#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H

#include "Queue.h";
#include "LinkedList.h";

//We can presume only whole numbers are recieved
class LinkedListQueue : public Queue {
public:
	LinkedListQueue();

	virtual void Enqueue(int x);
	virtual int Dequeue();
	virtual int const First();
	LinkedList getLinkedList() { return m_ll; };
private:
	LinkedList m_ll;
};


#endif