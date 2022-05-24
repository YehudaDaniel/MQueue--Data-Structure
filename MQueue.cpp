#include "MQueue.h"

//The Constructor of the MQueue class has implementation in the .h file
//Since it has empty implementation

//We will push the numbers to the ArrayQueue until the array[60] is full
//once it is full, we'll start making nodes for the LinkedList
//The first item to go in is the first to go out
void MQueue::MEnqueue(int x){
	if (m_aq.getSize() < 60) { // if the array still have empty space
		m_aq.Enqueue(x);
	}else if (m_aq.getSize() >= 60) { // the array is full
		//start inserting to the LinkedList
		m_llq.Enqueue(x);
	}
}

//We will remove the first number from the ArrayQueue each time until the array is "empty"
//then we will move to removing from the LinkedList
int MQueue::MDequeue(){
	if (m_aq.getSize() != 0) { //There is still something to get from the array
		return m_aq.Dequeue();
	} else if (m_aq.getSize() == 0 && m_llq.getLinkedList().size() != 0) { //if the array is empty but there are nodes in the LinkedList
		//--The array is empty--
		return m_llq.Dequeue();
	}
}

//if the size is less than 60, then the middle is inside the ArrayQueue
//if the size is greater than 60, then the middle is somewhere between the array and the LinkedList
int const MQueue::Middle(){
	//Presume we cant have m_llq > 0 until m_aq is full(60)
	int Msize = m_aq.getSize() + m_llq.getLinkedList().size();
	//TODO: may have some trouble, should test it
	if (Msize < 60) {
		int* temp = m_aq.getArr();
		return *(temp + (int)(Msize / 2));
	} else if (Msize >= 60) {
		if (Msize <= 120) { //the middle is still inside the array
			int* temp = m_aq.getArr();
			return *(temp + (int)(Msize / 2));
		}else { // greater than 120
			int tempSize = Msize / 2;
			Node* tempNode = m_llq.getLinkedList().getHead();
			for (int i = 0; i < (tempSize - 60); i++) {
				tempNode = tempNode->getNext();
			}
			return tempNode->getData();
		}
	}
}
