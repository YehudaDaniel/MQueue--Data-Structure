#include "LinkedList.h"
using namespace std;

int LinkedList::size() const{
	Node* temp = this->m_head;
	int counter = 0;
	while (temp) {
		counter++;
		temp = temp->getNext();
	}
	return counter;
}

void LinkedList::printList() const{
	if (this->size() == 0) {
		cout << "The list is empty!" << endl;
		return;
	}
	//prints the size of the list and its nodes
	cout << "The size of the list is: " << this->size() << endl;

	Node* temp = this->m_head;
	cout << "<=>" << endl;
	while (temp) {
		temp->printNode();
		temp = temp->getNext();
		cout << "<=>" << endl;
	}
	cout << "----" << endl;

}

void LinkedList::insertToHead(int x){
	Node* newNode = new Node(x);
	//if the list is empty, insert to the Head
	if (this->size() == 0) {
		this->m_head = newNode;
		return;
	}
	//Inserting the new node to the head(first) and moving the rest of the nodes forward by 1
	newNode->setNext(this->m_head);
	this->m_head->setPrev(newNode);
	this->m_head = newNode;
}

Node* LinkedList::findInList(int x) const{
	Node* temp = this->m_head;
	while (temp) {
		if (temp->getData() == x) {
			return temp;
		}
		temp = temp->getNext();
	}
	return 0;
}
Node* LinkedList::findLast() const{
	Node* temp = this->m_head;
	while (temp) {
		temp = temp->getNext();
	}
	return temp;
}
//removes an item from the list by its key value
void LinkedList::removeFromList(int x){
	//if the LinkedList size is 0, theres nothing to remove, return
	if (this->size() == 0) return;

	if (this->size() == 1) {
		delete this->m_head;
		this->m_head = nullptr;
		return;
	}
	//first we'll find the Node that contains the key=x
	Node* temp = this->findInList(x);

	//deleting the Node that contains the key=x
	//manipulating pointers
	delete this->findInList(x);
	temp->getPrev()->setNext(temp->getNext()); // prev of temp, gets next of temp
	temp->getNext()->setPrev(temp->getPrev()); // next of temp, gets prev of temp
}

void LinkedList::removeFirst(){
	if (this->size() == 0) return;

	if (this->size() == 1) {
		delete this->m_head;
		this->m_head = nullptr;
		return;
	}

	this->m_head = this->m_head->getNext();
	delete this->m_head->getPrev();
	this->m_head->setPrev(nullptr);
}
