#include<iostream>
using namespace std;

enum Color
{
	RED,
	BLACK
};

template<class ValueType>
struct RBTreeNode
{
	RBTreeNode(const ValueType&data = ValueType(),Color color=RED)
		:_pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
		, _data(data), _color(color)
	{}

	RBTreeNode<ValueType>* _pLeft;
	RBTreeNode<ValueType>* _pRight;
	RBTreeNode<ValueType>* _pParent;
	ValueType _data;
	Color _color;
};
template<class ValueType>
class RBTree
{
public:
	typedef RBTreeNode<ValueType> Node;
	typedef Node* PNode;
	RBTree()
		:_pHead(nullptr)
	{
		_pHead = new Node;
	}
	~RBTree()
	{
		dele(_pHead->_pParent);
	}
	void dele(PNode pCur)
	{
		if (pCur == nullptr)
			return;
		if (pCur->_pLeft)
			dele(pCur->_pLeft);
		if (pCur->_pRight)
			dele(pCur->_pRight);
		free(pCur);
		cout << "1  ";
	}
	bool Insert(const ValueType& data)
	{
		PNode& pRoot = GetRoot();//��ȡ���ڵ�
		if (nullptr == pRoot)//���ڵ�Ϊ��
		{
			pRoot = new Node(data, BLACK);

			pRoot->_pParent = _pHead;
			_pHead->_pParent = pRoot;
			return true;
		}
		else
		{
			PNode pCur = pRoot;
			PNode pParent = nullptr;
			while (pCur)
			{
				pParent = pCur;
				if (data < pCur->_data)
					pCur = pCur->_pLeft;
				else if (data > pCur->_data)
					pCur = pCur->_pRight;
				else
					return false;
			}
			pCur = new Node(data, RED);
			if (data < pParent->_data)
			{
				pParent->_pLeft = pCur;
				pCur->_pParent = pParent;
			}
			else
			{
				pParent->_pRight = pCur;
				pCur->_pParent = pParent;
			}

			PNode pGrand;//�游�ڵ�
			PNode pUncle;
			while (pParent!=_pHead)
			{
				pParent = pCur->_pParent;
				pGrand = pParent->_pParent;//�游�ڵ�
				if (pGrand->_pLeft == pParent)
					pUncle = pGrand->_pRight;//����ڵ�
				else
					pUncle = pGrand->_pLeft;

				if ((pCur->_color == pParent->_color == RED) && \
					(pGrand->_color == BLACK) && \
					(pUncle&&pUncle->_color == RED))//���һ
				{
					pUncle->_color = pParent->_color = BLACK;
					pGrand->_color = RED;

					pCur = pGrand;
				}
				if ((pCur->_color == pParent->_color == RED) && \
					(pGrand->_color == BLACK) && \
					(!pUncle || pUncle->_color == BLACK))//�����
				{
					if (pGrand->_pLeft == pParent&&pParent->_pRight == pCur)
						//����ת
					{
						Left(pParent);
					}
					else if (pGrand->_pRight == pParent&&pParent->_pLeft == pCur)
					{
						Right(pParent);
					}
				}
				if ((pCur->_color == pParent->_color == RED) && \
					(pGrand->_color == BLACK) && \
					(!pUncle || pUncle->_color == BLACK))//�����
				{
					if (pGrand->_pLeft == pParent&&pParent->_pLeft == pCur)
						//�ҵ���ת
					{
						Right(pGrand);
					}
					else if (pGrand->_pRight == pParent&&pParent->_pRight == pCur)
					{
						Left(pGrand);
					}
					pParent->_color = BLACK;
					pGrand->_color = RED;
					break;
				}
				break;
				pCur = pParent;
			}
			
		}
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}
	void Left(PNode root)//����
	{
		PNode pParent = root->_pRight;
		PNode pCur = pParent->_pLeft;

		root->_pRight = pCur;
		if (pCur != nullptr)
			pCur->_pParent = root;

		if (root->_pParent == nullptr)
		{
			pParent->_pParent = nullptr;
			_pHead->_pParent = pParent;
		}
		else
		{
			if (root->_pParent->_pLeft == root)
			{
				root->_pParent->_pLeft = pParent;
				pParent->_pParent = root->_pParent;
			}
			else
			{
				root->_pParent->_pRight = pParent;
				pParent->_pParent = root->_pParent;
			}
		}
		root->_pParent = pParent;
		pParent->_pLeft = root;

		//root->_bf = pParent->_bf = 0;
	}
	void Right(PNode root)//�ҵ���
	{
		PNode pParent = root->_pLeft;
		PNode pCur = pParent->_pRight;
		root->_pLeft = pCur;
		if (pCur != nullptr)
			pCur->_pParent = root;

		if (root->_pParent == nullptr)
		{
			pParent->_pParent = nullptr;
			_pHead->_pParent = pParent;
		}
		else
		{
			if (root->_pParent->_pLeft == root)
			{
				root->_pParent->_pLeft = pParent;
				pParent->_pParent = root->_pParent;
			}
			else
			{
				root->_pParent->_pRight = pParent;
				pParent->_pParent = root->_pParent;
			}
		}
		root->_pParent = pParent;
		pParent->_pRight = root;

		//root->_bf = pParent->_bf = 0;
	}
	bool IsValidRBTree()
	{
		PNode pRoot = GetRoot();
		if (nullptr == pRoot)
			return true;
		if (BLACK != pRoot->_color)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}
		size_t blackCount = 0;
		PNode pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_color)
				blackCount++;

			pCur = pCur->_pLeft;
		}
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}
	bool _IsValidRBTree(PNode pRoot, size_t k, const size_t blackCount)
	{
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ���ĸ���������ͬ" << endl;
				return false;
			}
			return true;
		}
		if (BLACK == pRoot->_color)
			k++;
		PNode pParent = pRoot->_pParent;
		if (pParent&&RED == pParent->_color&&RED == pRoot->_color)
		{
			cout << "Υ����������û������һ��ĺ�ɫ���" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}
private:
	PNode& GetRoot()//��ȡ���ڵ�
	{
		return _pHead->_pParent;
	}
	PNode LeftMost()
	{
		PNode pt = _pHead->_pParent;
		while (pt->_pLeft != nullptr)
			pt = pt->_pLeft;
		return pt;
	}
	PNode RightMost()
	{
		PNode pt = _pHead->_pParent;
		while (pt->_pRight != nullptr)
			pt = pt->_pRight;
		return pt;
	}

private:
	PNode _pHead;
};

RBTree<int> tree;
int main()
{
	/*int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	for (auto e : a)
		tree.Insert(e);

	cout << tree.IsValidRBTree() << endl;
	//cout << "12" << endl;*/
	system("pause");
	return 0;
}