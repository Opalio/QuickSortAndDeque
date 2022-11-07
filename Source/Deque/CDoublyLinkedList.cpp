#include <iostream>
#include "CDoublyLinkedList.h"

// Includes iostream to output errors in indexing when inserting/deleting from middle
//				also for the Display() function
using std::cout;
using std::endl;

CDoublyLinkedList::CDoublyLinkedList()
{
	m_pFirstNode = nullptr;
	m_pLastNode = nullptr;
}

CDoublyLinkedList::~CDoublyLinkedList()
{
	// Delete nodes from the front until the list is empty
	while (m_pFirstNode != nullptr)
	{
		DeleteFromTheFront();
	}
}

CDoublyNode* CDoublyLinkedList::GetFirstNode() const
{
	return (m_pFirstNode);
}

CDoublyNode* CDoublyLinkedList::GetLastNode() const
{
	return (m_pLastNode);
}

void CDoublyLinkedList::InsertAtTheFront(int _iData)
{
	// >0 nodes exist on list: Attach new node in front of the firstnode and set it to be the firstnode
	if (m_pFirstNode != nullptr)
	{
		CDoublyNode* pdnodeToInsertAtFront = new CDoublyNode;
		//CDoublyNode* pdnodeOldFirstNode = m_pFirstNode;
		pdnodeToInsertAtFront->SetData(_iData);

		pdnodeToInsertAtFront->SetNextNode(m_pFirstNode);
		m_pFirstNode->SetPreviousNode(pdnodeToInsertAtFront);

		m_pFirstNode = pdnodeToInsertAtFront;

		pdnodeToInsertAtFront = nullptr;
		//pdnodeOldFirstNode = nullptr;
	}
	else // 0 nodes: Create new nod and set it as first and last node
	{
		m_pFirstNode = new CDoublyNode;
		m_pFirstNode->SetData(_iData);
		m_pLastNode = m_pFirstNode;
	}

	return;
}

void CDoublyLinkedList::InsertInTheMiddle(int _iData, int _index)
{
	if (m_pFirstNode != nullptr)
	{
		if (_index > 0)
		{
			CDoublyNode* pdnodeToInsertBefore = m_pFirstNode;

			for (int i = 0; i < _index; i++)
			{
				if (pdnodeToInsertBefore != m_pLastNode)
				{
					pdnodeToInsertBefore = pdnodeToInsertBefore->GetNextNode();
				}
				else
				{
					cout << "Index exceeds list size; use InsertAtEnd instead" << endl;
					system("pause");

					pdnodeToInsertBefore = nullptr;

					return;
				}
			}

			CDoublyNode* pdnodePrevious = pdnodeToInsertBefore->GetPreviousNode();

			CDoublyNode* pdnodeToInsert = new CDoublyNode;
			pdnodeToInsert->SetData(_iData);
			pdnodeToInsert->SetNextNode(pdnodeToInsertBefore);
			pdnodeToInsert->SetPreviousNode(pdnodePrevious);

			pdnodePrevious->SetNextNode(pdnodeToInsert);
			pdnodeToInsertBefore->SetPreviousNode(pdnodeToInsert);

			pdnodePrevious = nullptr;
			pdnodeToInsert = nullptr;
			pdnodeToInsertBefore = nullptr;
		}
		else
		{
			cout << "Must insert an index >0; use InsertAtFront to insert at index 0" << endl;
			system("pause");
		}
	}
	else
	{
		cout << "Cant InsertInTheMiddle as there are no nodes on the list; use InsertAtFront instead" << endl;
		system("pause");
	}

	return;
}

void CDoublyLinkedList::InsertAtTheEnd(int _iData)
{
	if (m_pLastNode != nullptr)
	{
		CDoublyNode* pdnodeToInsertAtEnd = new CDoublyNode;
		pdnodeToInsertAtEnd->SetData(_iData);

		pdnodeToInsertAtEnd->SetPreviousNode(m_pLastNode);
		m_pLastNode->SetNextNode(pdnodeToInsertAtEnd);

		m_pLastNode = pdnodeToInsertAtEnd;

		pdnodeToInsertAtEnd = nullptr;
	}
	else
	{
		m_pFirstNode = new CDoublyNode;
		m_pFirstNode->SetData(_iData);
		m_pLastNode = m_pFirstNode;
	}

	return;
}

void CDoublyLinkedList::DeleteFromTheFront()
{
	if (m_pFirstNode != nullptr)
	{
		if (m_pFirstNode != m_pLastNode)
		{
			CDoublyNode* pdnodeToDeleteFromFront = m_pFirstNode;

			m_pFirstNode = m_pFirstNode->GetNextNode();
			m_pFirstNode->SetPreviousNode(nullptr);

			delete pdnodeToDeleteFromFront;
			pdnodeToDeleteFromFront = nullptr;
		}
		else
		{
			delete m_pFirstNode;
			m_pFirstNode = nullptr;
			m_pLastNode = nullptr;
		}
	}
	else
	{
		cout << "Cant DeleteFromTheFront as there are no nodes on the list" << endl;
		system("pause");
	}

	return;
}

void CDoublyLinkedList::DeleteFromTheMiddle(int _index)
{
	if (m_pFirstNode != nullptr)
	{
		if (_index > 0)
		{
			CDoublyNode* pdnodeToDeleteFromTheMiddle = m_pFirstNode;

			for (int i = 0; i < _index; i++)
			{
				if (pdnodeToDeleteFromTheMiddle->GetNextNode() != nullptr)
				{
					pdnodeToDeleteFromTheMiddle = pdnodeToDeleteFromTheMiddle->GetNextNode();
				}
				else
				{
					cout << "Invalid index: input index between 0 and " << i << endl;
					system("pause");
					pdnodeToDeleteFromTheMiddle = nullptr;

					return;
				}
			}

			pdnodeToDeleteFromTheMiddle->GetPreviousNode()->SetNextNode(pdnodeToDeleteFromTheMiddle->GetNextNode()); // set the nextnode for the previousnode to be the node after the one to be deleted
			if (pdnodeToDeleteFromTheMiddle->GetNextNode() != nullptr)
			{
				pdnodeToDeleteFromTheMiddle->GetNextNode()->SetPreviousNode(pdnodeToDeleteFromTheMiddle->GetPreviousNode()); // if there is a nextnode for the node to be deleted; set its previous node to ToDeleteFromTheMiddle's previous node
			}
			else
			{
				m_pLastNode = pdnodeToDeleteFromTheMiddle->GetPreviousNode();
			}

			delete pdnodeToDeleteFromTheMiddle;
			pdnodeToDeleteFromTheMiddle = nullptr;

		}
		else
		{
			cout << "Cant DeleteFromTheMiddle with index <0; use DeleteFromFront instead" << endl;
			system("pause");
		}
	}
	else
	{
		cout << "Cant DeleteFromTheMiddle as there are no nodes on the list" << endl;
		system("pause");
	}

	return;
}

void CDoublyLinkedList::DeleteFromTheEnd()
{
	if (m_pLastNode != nullptr)
	{
		if (m_pLastNode != m_pFirstNode)
		{
			CDoublyNode* pdnodeToDeleteFromEnd = m_pLastNode;

			m_pLastNode = m_pLastNode->GetPreviousNode();
			m_pLastNode->SetNextNode(nullptr);

			delete pdnodeToDeleteFromEnd;
			pdnodeToDeleteFromEnd = nullptr;
		}
		else
		{
			delete m_pLastNode;
			m_pLastNode = nullptr;
			m_pFirstNode = nullptr;
		}
	}
	else
	{
		cout << "Cant DeleteFromTheEnd as there are no nodes on the list" << endl;
		system("pause");
	}

	return;
}

bool CDoublyLinkedList::Search(int _iData) const
{
	if (m_pFirstNode != nullptr)
	{
		CDoublyNode* pdnodeSelect = m_pFirstNode;

		while (pdnodeSelect != m_pLastNode)
		{
			if (pdnodeSelect->GetData() == _iData)
			{
				return (true);
			}
			pdnodeSelect = pdnodeSelect->GetNextNode();
		}

		if (pdnodeSelect->GetData() == _iData) // If select is on last node
		{
			return true;
		}

		pdnodeSelect = nullptr;
	}

	return false;
}

int CDoublyLinkedList::Size() const
{
	if (m_pFirstNode != nullptr)
	{
		if (m_pFirstNode != m_pLastNode)
		{
			int iNumberOfNodes = 1;
			CDoublyNode* pdnodeSelect = m_pFirstNode;

			while (pdnodeSelect != m_pLastNode)
			{
				iNumberOfNodes++;
				pdnodeSelect = pdnodeSelect->GetNextNode();
			}

			pdnodeSelect = nullptr;

			return (iNumberOfNodes);
		}
		else
		{
			return (1);
		}
	}
	else
	{
		return 0;
	}
}

void CDoublyLinkedList::Display() const
{
	if (m_pFirstNode != nullptr)
	{
		CDoublyNode* pdnodeSelect = m_pFirstNode;

		while (pdnodeSelect != m_pLastNode)
		{
			cout << "| " << pdnodeSelect->GetData() << " |";
			pdnodeSelect = pdnodeSelect->GetNextNode();
		}

		cout << "| " << pdnodeSelect->GetData() << " |" << endl;

		pdnodeSelect = nullptr;
	}
	else
	{
		cout << endl; // For correct formating when using in main() in conjuction with other outputs
	}

	return;
}