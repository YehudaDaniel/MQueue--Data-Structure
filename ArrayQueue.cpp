#include "ArrayQueue.h"

//Default Ctor
ArrayQueue::ArrayQueue() {
	first = NULL;
	last = NULL;
	size = 0;
}
//-the first number in the array is the first one woh got in and the first one to go out

//takes an integer and puts it at the end of the array
void ArrayQueue::Enqueue(int x) {
	if (!first || !last) {
		first = &m_arr[0];
		last = &m_arr[0];
		m_arr[0] = x;
		size++;
	}else if(size <= 60){
		last = last + 1;
		m_arr[size] = x;
		size++;
	}
}
int ArrayQueue::Dequeue() {
	if (!first || !last) {
		return -1;
	}else {
		size--;
		first = first + 1;
		return *(first - 1);
	}
}
int const ArrayQueue::First() {
	if (!first || !last) return -1;
	return *first;
}