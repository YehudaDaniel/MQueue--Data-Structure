
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

//We can presume only whole numbers are recieved
class Queue {
public:
	virtual void Enqueue(int x) = 0;
	virtual int Dequeue() = 0;
	virtual int const First() = 0;
};


#endif