#ifndef _CDOUBLYNODE_H__
#define _CDOUBLYNODE_H__

class CDoublyNode {
public:
	CDoublyNode();
	~CDoublyNode();

	void SetData(int _iData);
	int GetData() const;

	void SetNextNode(CDoublyNode* _nextNode);
	CDoublyNode* GetNextNode() const;

	void SetPreviousNode(CDoublyNode* _previousNode);
	CDoublyNode* GetPreviousNode() const;

private:
	int m_iData;
	CDoublyNode* m_pNextNode;
	CDoublyNode* m_pPreviousNode;
};

#endif