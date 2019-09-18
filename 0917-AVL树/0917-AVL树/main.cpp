#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		:_pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
		, _data(data), _bf(0)
	{}
	AVLTreeNode* _pLeft;
	AVLTreeNode* _pRight;
	AVLTreeNode* _pParent;
	T _data;
	int _bf;
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
	typedef Node* PNode;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}
	~AVLTree()
	{
		dele(_pRoot);
	}
	void dele(PNode pCur)
	{
		if (pCur->_pLeft)
			dele(pCur->_pLeft);
		if (pCur->_pRight)
			dele(pCur->_pRight);
		free(pCur);
		cout << "1 ";
	}
	PNode Find(const T&data)
	{
		PNode pCur = _pRoot;
		while (pCur)
		{
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data>pCur->_data)
				pCur = pCur->_pRight;
			else
				return pCur;
		}
		return nullptr;
	}
	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data>pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		pCur = new Node(data);
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
		//����ƽ������
		while (pParent)
		{
			if (pCur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;

			if (0 == pParent->_bf)//����Ľ��ʹ�ø����Ķ�Ϊ0
				                  //˵��ԭ�Ⱦ���һ����ڵ�����ҽڵ㣬��Ӱ����������
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
				//��Ϊ+-1���˴�������������ϼ��������Ƿ�����Ҫ������
			{
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else//�����˶�Ϊ+-2���������Ҫ����
			{
				if (2 == pParent->_bf)
				{
					if (1 == pParent->_pRight->_bf)//���ң�����
					{
						Left(pParent);
						break;
					}
					else//-1 == pParent->_pRight->_bf 
						//�������ҵ�����������
					{
						RightLeft(pParent);
						break;
					}
				}
				else
				{
					if (-1 == pParent->_pLeft->_bf)//�����ҵ���
					{
						Right(pParent);
						break;
					}
					else//���ң���������������
					{
						LeftRight(pParent);
						break;
					}
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
		root->_pParent = pParent;
		pParent->_pLeft = root;

		if (root->_pParent == nullptr)
		{
			pParent->_pParent = nullptr;
			_pRoot = pParent;
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
		root->_bf = pParent->_bf = 0;
	}
	void Right(PNode root)//�ҵ���
	{
		PNode pParent = root->_pLeft;
		PNode pCur = pParent->_pRight;
		root->_pLeft = pCur;
		if (pCur != nullptr)
			pCur->_pParent = root;
		root->_pParent = pParent;
		pParent->_pRight = root;
		if (root->_pParent == nullptr)
		{
			pParent->_pParent = nullptr;
			_pRoot = pParent;
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
		root->_bf = pParent->_bf = 0;
	}
	void show()
	{
		_show(_pRoot);
	}
	void _show(PNode pt)
	{
		if (pt->_pLeft != nullptr)
			_show(pt->_pLeft);
		if (pt->_pRight != nullptr)
			_show(pt->_pRight);
		printf("��㣺%d �ȣ�%d \n", pt->_data, pt->_bf);
	}
	void LeftRight(PNode pParent)//������
	{
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;
		int bf = pSubLR->_bf;
		Left(pParent->_pLeft);
		Right(pParent);
		if (1 == bf)
			pSubL->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}
	void RightLeft(PNode pParent)//������
	{
		PNode pSubR = pParent->_pRight;
		PNode pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;
		Right(pParent->_pRight);
		Left(pParent);
		if (1 == bf)
			pSubR->_bf = 1;
		else if (-1 == bf)
			pParent->_bf = -1;
	}

	int _Height(PNode pRoot);
	bool _IsBalanceTree(PNode pRoot)//��֤�Ƿ���AVL��
	{
		if (nullptr == pRoot)
			return true;
		int leftHeight = _Height(pRoot->_pLeft);
		int rightHeight = _Height(pRoot->_pRight);
		int diff = rightHeight - leftHeight;

		if (diff != pRoot->_bf || (diff > 1 || diff < -1))
			return false;
		return _IsBalanceTree(pRoot->_pLeft) && _IsBalanceTree(pRoot->_pRight);
	}
private:
	PNode _pRoot;
}; 

AVLTree<int> tree;
int main()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
		tree.Insert(e);
	tree.show();

	system("pause");
	return 0;
}