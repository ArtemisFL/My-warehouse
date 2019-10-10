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
		free(_pHead);
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
		PNode pCur = pRoot;
		PNode pParent = nullptr;
		if (nullptr == pRoot)//���ڵ�Ϊ��
		{
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
			_pHead->_pParent = pRoot;
		}
		else
		{
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
		}//�½ڵ�������

		// 1.�½ڵ����������˫�׽ڵ����ɫΪ��ɫ����Υ������3��
		//����������һ��ĺ�ɫ��� 
		//2.������½ڵ�Ĭ��Ϊ��ɫ
		while (pParent&&RED == pParent->_color)
		{
			//��ʱgrandFatherһ��������Ϊ�ڣ���ΪpParentΪ�죬������������Ϊ��        
			//��ΪpParent���ڣ��Ҳ��Ǻ�ɫ�ڵ㣬
			//��pParentһ�����Ǹ�������һ����˫��
			PNode grandfather = pParent->_pParent;
			// ������������
			if (pParent == grandfather->_pLeft)
			{
				PNode unclue = grandfather->_pRight;
				//���һ������ڵ���ڣ���Ϊ��
				if (unclue&&RED == unclue->_color)
				{
					pParent->_color = BLACK;
					unclue->_color = BLACK;
					grandfather->_color = RED;
					pCur = grandfather;
					pParent = pCur->_pParent;
				}
				else//����ڵ㲻���ڣ���������ڵ������Ϊ��
				{
					if (pCur == pParent->_pRight)//�����
					{
						if (pParent != _pHead)
						{
							Left(pParent);
							swap(pParent, pCur);
						}
					}
					//�����
					grandfather->_color = RED;
					pParent->_color = BLACK;
					if (grandfather != _pHead)
						Right(grandfather);
				}
			}
			else//pParent���Һ��ӵ������
			{
				PNode unclue = grandfather->_pLeft;
				//���һ������ڵ���ڣ���Ϊ��
				if (unclue&&RED == unclue->_color)
				{
					pParent->_color = BLACK;
					unclue->_color = BLACK;
					grandfather->_color = RED;
					pCur = grandfather;
					pParent = pCur->_pParent;
				}
				else//����ڵ㲻���ڣ���������ڵ������Ϊ��
				{
					if (pCur == pParent->_pLeft)//�����
					{
						if (pParent != _pHead)
						{
							Right(pParent);
							swap(pParent, pCur);
						}
					}
					//�����
					grandfather->_color = RED;
					pParent->_color = BLACK;
					if (grandfather != _pHead)
						Left(grandfather);
				}
			}
		}
		return true;
	}
	void Left(PNode root)//����
	{
		PNode pParent = root->_pRight;
		PNode pCur = pParent->_pLeft;
		root->_pRight = pCur;
		if (pCur != nullptr)
			pCur->_pParent = root;
		if (root->_pParent == _pHead)
		{
			pParent->_pParent = _pHead;
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
	}
	void Right(PNode root)//�ҵ���
	{
		PNode pParent = root->_pLeft;
		PNode pCur = pParent->_pRight;
		root->_pLeft = pCur;
		if (pCur != nullptr)
			pCur->_pParent = root;
		if (root->_pParent == _pHead)
		{
			pParent->_pParent = _pHead;
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
	void show()
	{
		_show(_pHead->_pParent);
	}
	void _show(PNode pt)
	{
		if (pt->_pLeft != nullptr)
			_show(pt->_pLeft);
		if (pt->_pRight != nullptr)
			_show(pt->_pRight);
		printf("��㣺%d ��ɫ��%d \n", pt->_data, pt->_color);
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

	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	for (auto e : a)
	{
		tree.Insert(e);
		tree.show();
		cout << endl;
	}
		

	cout << tree.IsValidRBTree() << endl;
	//cout << "12" << endl;*/
	system("pause");
	return 0;
}