#include "Node.h"

//Initiating starting values for next and prev = nullptr
Node::Node(int x):m_next(nullptr), m_prev(nullptr){
	this->m_key = x;
}

//Prints the key data
void Node::printNode() const {
	std::cout << this->getData() << std::endl;
}
