#pragma once

enum Color {
	RED,
	BLACK
};

template<class ValueType>
struct RBTreeNode
{
	RBTreeNode(const ValueType& data = ValueType(), Color color = RED)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_color(color)
	{}

	RBTreeNode<ValueType>* _pLeft;
	RBTreeNode<ValueType>* _pRight;
	RBTreeNode<ValueType>* _pParent;
	ValueType _data;
	Color _color;
};

template<class ValueType>
class RBTree {
	typedef RBTreeNode<ValueType> Node;
	typedef Node* PNode;
public:
	bool Insert(const ValueType& data) {
		PNode& pRoot = GetRoot();   //��ȡ���ڵ�
		if (nullptr == pRoot) {   //��������Ϊ��
			pRoot = new Node(data, BLACK);
			
			pRoot->_pParent = _pHead;
			_pHead->_pParent = pRoot;
		}
		else {
			//����ڵ�
			PNode pParent = nullptr;
			PNode pCur = pRoot;
			while (pCur) {
				pParent = pCur;
				if (data < pCur->_data)
					pCur = pCur->_pLeft;
				else if (data > pCur->_data)
					pCur = pCur->_pRight;
				else
					return false;
			}
			pCur = new Node(data);
			if (data < pParent->_data) {
				pParent->_pLeft = pCur;
				pCur->_pParent = pParent;
			}
			else {
				pParent->_pRight = pCur;
				pCur->_pParent = pParent;
			}
			//����½ڵ����󡣺�����������Ƿ��⵽�ƻ�
			while (pParent&&RED == pParent->_color) {
				PNode pGrand = pParent->_pParent;
				//pParent��pGrand�������
				if (pParent == pGrand->_pLeft) {
					PNode unclue = pGrand->_pRight;
					//���һ
					if (unclue&&RED == unclue->_color) {
						pParent->_color = BLACK;
						unclue->_color = BLACK;
						pGrand->_color = RED;
						
						pCur = pGrand;
						pParent = pCur->_pParent;
					}
					else {
						//�����
						if (pParent->_pRight==pCur) {
							RotateLeft(pParent);
							swap(pParent, pCur);
						}
						//�����
						RotateRight(pGrand);
						pParent->_color = BLACK;
						pGrand->_color = RED;
					}
				}
				//pParent��pGrand�Ҳ�����
				else {
					PNode unclue = pGrand->_pLeft;
					//���һ
					if (unclue&&RED == unclue->_color) {
						pParent->_color = BLACK;
						unclue->_color = BLACK;
						pGrand->_color = RED;

						pCur = pGrand;
						pParent = pCur->_pParent;
					}
					else {
						//�����
						if (pParent->_pLeft == pCur) {
							RotateRight(pParent);
							swap(pParent, pCur);
						}
						//�����
						RotateLeft(pGrand);
						pParent->_color = BLACK;
						pGrand->_color = RED;
					}
				}
			}
		}
		//���ڵ����ɫ���ܱ��޸ģ�����Ļغ�ɫ
		pRoot->_color = BLACK;
		//����ͷ�������Һ���
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}

	bool IsValidRBTree()
	{
		PNode pRoot = GetRoot();
		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;
		// �����ڵ��Ƿ��������
		if (BLACK != pRoot->_color)
		{
			std::cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << std::endl;
			return false;
		}
		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		PNode pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_color)
				blackCount++;
			pCur = pCur->_pLeft;
		}
		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(PNode pRoot, size_t k, const size_t blackCount) {
		//�ߵ�null֮���ж�k��black�Ƿ����
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				std::cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << std::endl;
				return false;
			}
			return true;
		}
		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == pRoot->_color)
			k++;
		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		PNode pParent = pRoot->_pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color)
		{
			std::cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << std::endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}

private:
	PNode& GetRoot() {
		return _pHead->_pParent;
	}
	PNode LeftMost() {
		PNode ptr = GetRoot();
		while (ptr->_pLeft)
			ptr = ptr->_pLeft;
		return ptr;
	}
	PNode RightMost() {
		PNode ptr = GetRoot();
		while (ptr->_pRight)
			ptr = ptr->_pRight;
		return ptr;
	}
	void RotateLeft(PNode pParent) {
		PNode pPParent = pParent->_pParent;
		PNode pRight = pParent->_pRight;
		pParent->_pRight = pRight->_pLeft;
		if (pRight->_pLeft)
			pRight->_pLeft->_pParent = pParent;
		pRight->_pLeft = pParent;
		pParent->_pParent = pRight;
		//��pPParent������ʱ
		if (pPParent==_pHead) {
			//����pRightΪ���ڵ�
			_pHead->_pParent = pRight;
			pRight->_pParent = _pHead;
		}
		else {
			if (pPParent->_pLeft == pParent) {
				pPParent->_pLeft = pRight;
				pRight->_pParent = pPParent;
			}
			else {
				pPParent->_pRight = pRight;
				pRight->_pParent = pPParent;
			}
		}
	}
	void RotateRight(PNode pParent) {
		PNode pPParent = pParent->_pParent;
		PNode pLeft = pParent->_pLeft;
		pParent->_pLeft = pLeft->_pRight;
		if (pLeft->_pRight)
			pLeft->_pRight->_pParent = pParent;
		pLeft->_pRight = pParent;
		pParent->_pParent = pLeft;
		//��pPParent������ʱ
		if (pPParent == _pHead) {
			//����pLeftΪ���ڵ�
			_pHead->_pParent = pLeft;
			pLeft->_pParent = _pHead;
		}
		else {
			if (pPParent->_pLeft == pParent) {
				pPParent->_pLeft = pLeft;
				pLeft->_pParent = pPParent;
			}
			else {
				pPParent->_pRight = pLeft;
				pLeft->_pParent = pPParent;
			}
		}
	}
private:
	PNode _pHead;    //ͷ���(���ڵ�ĸ��׽ڵ�)
};