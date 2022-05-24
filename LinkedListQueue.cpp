#include "LinkedListQueue.h"

//Head of the LinkedList would be Enqueue, last node of 
//LinkedList would be Dequeue
LinkedListQueue::LinkedListQueue(){
	m_ll = LinkedList();
}

//Inserting a new node to the head of the LinkedList
void LinkedListQueue::Enqueue(int x){
	m_ll.insertToHead(x);
}

//if the function returns zero, the LinkedList is empty
int LinkedListQueue::Dequeue(){
	if (m_ll.size() == 0) return 0;
	//create a copy of the last Node in the LinkedList
	Node* temp = m_ll.findLast();
	m_ll.removeFromList(temp->getData());

	return temp->getData();
}

//returns the value of the last Node in the LinkedList
int const LinkedListQueue::First(){
	return m_ll.findLast()->getData();
}
