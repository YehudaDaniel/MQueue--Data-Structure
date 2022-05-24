
#define SIZE 101

#include <iostream>
#include <time.h>
#include "MQueue.h"

using namespace std;

int main() {
	//Defining array the size of 101 numbers
	srand(time(NULL));
	int h, j;
	int number;
	int arr[SIZE];
	int randNum = rand() % 10000;
	bool unique;
	//Generating 101 randum numbers in the area of [1, 10,000]
	for (h = 0; h < SIZE; h++){
		do {
			number = (rand() % 10000) + 1;
			unique = true;
			for (j = 0; j < h; j++)
				if (arr[j] == number) unique = false;
		} while (!unique);
		arr[h] = number;
	}

	//-------------------------------------------------
	//Printing the items of the array
	for (j = 0; j < SIZE; j++) {
		cout << arr[j] << ", ";
	}
	
	cout << endl;
	cout << "<--------------------------------->" << endl;

	//New instance of MQueue
	MQueue mq = MQueue();

	//Inserting to MQueue 51 numbers
	int i;
	for (i = 0; i < 51; i++) {
		mq.MEnqueue(arr[i]);
		cout << "- The number that was inserted is: " << arr[i] << endl;
	}

	//Printing the result of middle
	cout << "<-------------------------------------->" << endl;
	cout << "The middle value of MQueue is: " << mq.Middle() << endl;

	//Removing 2 numbers from the MQueue, 1 by 1
	cout << "~ Removing the number: " << mq.MDequeue() << " from start of the Queue" << endl;
	cout << "~ Removing the number: " << mq.MDequeue() << " from start of the Queue" << endl;

	//Printing the result of middle
	cout << "<-------------------------------------->" << endl;
	cout << "The middle value of MQueue ~After Removal~ is: " << mq.Middle() << endl;


	//Inserting to MQueue the rest 50 numbers
	for (; i < 101; i++) {
		mq.MEnqueue(arr[i]);
		cout << "- The number that was inserted is: " << arr[i] << endl;
	}

	//Printing the middle after inserting the rest 50 numbers
	cout << "<-------------------------------------->" << endl;
	cout << "The middle value of MQueue ~After New Insertion~ is: " << mq.Middle() << endl;

	cout << "done" << endl;
	return 0;

}