#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node{

private:
	int m_key;
	Node* m_next;
	Node* m_prev;
public:
	//Ctor for the Node class
	Node(int x);
	//get func for the key value
	int getData() const { return this->m_key; }
	//set func for the key value
	void setData(int x) { this->m_key = x; }
	//get func for the next node, returns a node
	Node* getNext() const { return this->m_next; }
	//get func for the prev node, returns a node
	Node* getPrev() const { return this->m_prev; }
	//sets a node for the next
	void setNext(Node* n) { this->m_next = n; }
	//sets a node for the previous
	void setPrev(Node* p) { this->m_prev = p; }
	//prints values of the current node
	void printNode() const;
};

#endif