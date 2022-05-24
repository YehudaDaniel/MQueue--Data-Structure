#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Queue.h";
#include "Node.h"

//When creating an instance of the class
//You should create it with "nullptr" and then use "insertToList" to initiate the first node
class LinkedList{

private:
	Node* m_head;
public:
	LinkedList() :m_head(nullptr) {}
	int size() const;
	void printList() const;
	void insertToHead(int x);
	//Consider: changing the return value to int
	Node* findInList(int x) const;
	Node* findLast() const;
	void removeFromList(int x);
	void removeFirst();
	int getFirstVal() const {
		return this->m_head->getData();
	}
	Node* getHead() const { return this->m_head; }
};

#endif