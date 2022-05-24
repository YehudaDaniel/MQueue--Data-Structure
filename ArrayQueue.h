#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "Queue.h";

//We can presume only whole numbers are recieved
class ArrayQueue: public Queue {
public:
	ArrayQueue();

	virtual void Enqueue(int x);
	virtual int Dequeue();
	virtual int const First();
	//Returns size
	int getSize() { return size; };
	int* getArr() { return &m_arr[0]; };

private:
	int* first, *last;
	int m_arr[60], size;
};


#endif