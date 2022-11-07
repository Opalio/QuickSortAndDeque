#include  "CDoublyNode.h"

CDoublyNode::CDoublyNode()
{
	m_iData = 0;
	m_pNextNode = nullptr;
	m_pPreviousNode = nullptr;
}

CDoublyNode::~CDoublyNode()
{
	m_pNextNode = nullptr;
	m_pPreviousNode = nullptr;
}

void CDoublyNode::SetData(int iData)
{
	m_iData = iData;

	return;
}

int CDoublyNode::GetData() const
{
	return(m_iData);
}

void CDoublyNode::SetNextNode(CDoublyNode* nextNode)
{
	m_pNextNode = nextNode;
	return;
}

CDoublyNode* CDoublyNode::GetNextNode() const
{
	return (m_pNextNode);
}

void CDoublyNode::SetPreviousNode(CDoublyNode* _previousNode)
{
	m_pPreviousNode = _previousNode;
	return;
}

CDoublyNode* CDoublyNode::GetPreviousNode() const
{
	return (m_pPreviousNode);
}
