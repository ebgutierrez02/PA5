#pragma once
#include "Node.hpp"
#include <iostream>

using std::cin; 
using std::cout;
using std::endl;
using std::string;

class Queue
{
public: 

	Queue();
	~Queue();

	bool isEmpty() const;
	bool enqueue(int customerCounter, int serviceTime);
	Data* dequeue();
	void printQueue() const;
	void incrementWaitTime(void);
	void processCustomer(void);

	QueueNode* getHead() const;
	QueueNode* getTail() const;

	void setHead(QueueNode* newHead);
	void setTail(QueueNode* newTail);

	ItemNode* buildItemList(int numItems);   
	void printItems(ItemNode* pHead) const;  

private:
	QueueNode* pHead,
		* pTail;
};