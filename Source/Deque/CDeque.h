#ifndef _CDEQUE_H__
#define _CDEQUE_H__
#include "CDoublyLinkedList.h"

class CDeque
{
public:
	CDeque();
	~CDeque();

	void EnqueueFront(int _iData);
	void EnqueueBack(int _iData);

	// Dequeue and Peek functions return bool depending on if operation has been performed (depends on if the list is empty or not)
	// Dequeue and Peek functions are passed an integer by referance; this int is used to hold the value being peeked or dequeued in calling function 
	bool DequeueFront(int& _riData);
	bool DequeueBack(int& _riData);

	bool PeekFront(int& _riData);
	bool PeekBack(int& _riData);

	bool IsEmpty();
	int Size();
	void Display();

private:
	CDoublyLinkedList* m_pContainer;
};

#endif // !_CDEQUE_H__

