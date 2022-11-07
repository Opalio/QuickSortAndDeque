#ifndef _CDOUBLYLINKEDLIST_H__
#define _CDOUBLYLINKEDLIST_H__
#include "CDoublyNode.h"

class CDoublyLinkedList {

private:
	CDoublyNode* m_pFirstNode;
	CDoublyNode* m_pLastNode;

public:
	CDoublyLinkedList();
	~CDoublyLinkedList();

	CDoublyNode* GetFirstNode() const;
	CDoublyNode* GetLastNode() const;

	void InsertAtTheFront(int _iData);
	void InsertInTheMiddle(int _iData, int _index); // Not utilised in Deque
	void InsertAtTheEnd(int _iData);

	void DeleteFromTheFront();
	void DeleteFromTheMiddle(int _index); // Not utilised in Deque
	void DeleteFromTheEnd();

	bool Search(int _iData) const;
	int Size() const;
	void Display() const;
};

#endif