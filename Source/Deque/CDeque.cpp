#include "CDeque.h"

CDeque::CDeque()
{
	m_pContainer = new CDoublyLinkedList;
}

CDeque::~CDeque()
{
	delete m_pContainer;
	m_pContainer = nullptr;
}

void CDeque::EnqueueFront(int _iData)
{
	m_pContainer->InsertAtTheFront(_iData);

	return;
}

void CDeque::EnqueueBack(int _iData)
{
	m_pContainer->InsertAtTheEnd(_iData);

	return;
}

bool CDeque::DequeueFront(int& _riData)
{
	if (!IsEmpty())
	{
		_riData = m_pContainer->GetFirstNode()->GetData();
		m_pContainer->DeleteFromTheFront();

		return true;
	}
	else
	{
		return false;
	}
}

bool CDeque::DequeueBack(int& _riData)
{
	if (!IsEmpty())
	{
		_riData = m_pContainer->GetLastNode()->GetData();
		m_pContainer->DeleteFromTheEnd();

		return true;
	}
	else
	{
		return false;
	}
}

bool CDeque::PeekFront(int& _riData)
{
	if (!IsEmpty())
	{
		_riData = m_pContainer->GetFirstNode()->GetData();

		return true;
	}
	else
	{
		return false;
	}
}

bool CDeque::PeekBack(int& _riData)
{
	if (!IsEmpty())
	{
		_riData = m_pContainer->GetLastNode()->GetData();

		return true;
	}
	else
	{
		return false;
	}
}

bool CDeque::IsEmpty()
{
	if (m_pContainer->GetFirstNode() == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int CDeque::Size()
{
	return (m_pContainer->Size());
}

void CDeque::Display()
{
	// Utilise CDoublyLinkedList existing function
	m_pContainer->Display();

	return;
}

