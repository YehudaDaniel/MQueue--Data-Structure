#ifndef MQUEUE_H
#define MQUEUE_H

#include "LinkedListQueue.h";
#include "ArrayQueue.h";

//We can presume only whole numbers are recieved
class MQueue {
public:
	//Ctor for the MQueue, initializing the ctors of LinkedListQueue and ArrayQueue
	MQueue() : m_llq(), m_aq() {}

	void MEnqueue(int x);
	int MDequeue();
	int const Middle();
private:
	LinkedListQueue m_llq;
	ArrayQueue m_aq;
};


#endif