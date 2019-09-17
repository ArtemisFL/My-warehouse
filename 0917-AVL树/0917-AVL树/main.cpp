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
						pParent->_bf = pParent->_pRight->_bf = 0;
						break;
					}
					else//-1 == pParent->_pRight->_bf 
						//�������ҵ�����������
					{
						pParent->_bf = -1;
						pParent->_pRight->_bf = pParent->_pRight->_pLeft->_bf = 0;
						Right(pParent->_pRight);
						Left(pParent);
						break;
					}
				}
				else
				{
					if (-1 == pParent->_pLeft->_bf)//�����ҵ���
					{
						Right(pParent);
						pParent->_bf = pParent->_pLeft->_bf = 0;
						break;
					}
					else//���ң���������������
					{
						pParent->_bf = 1;
						pParent->_pLeft->_bf = pParent->_pLeft->_pRight->_bf = 0;
						Left(pParent->_pLeft);
						Right(pParent);
						break;
					}
				}
			}
		}
		return true;
	}
	void Left(PNode root)//����
	{
		PNode pParent = root;
		PNode pCur = root->_pRight;

		if ((pParent->_pParent != nullptr) && (pParent->_pParent->_pLeft == pParent))
		{		
			pParent->_pParent->_pLeft = pCur;
			pCur->_pParent = pParent->_pParent;
		}
		else if ((pParent->_pParent != nullptr) && (pParent->_pParent->_pRight == pParent))
		{
			pParent->_pParent->_pRight = pCur;
			pCur->_pParent = pParent->_pParent;
		}
		pParent->_pRight = pCur->_pLeft;
		if (pCur->_pLeft != nullptr)
			pCur->_pLeft->_pParent = pParent;
		pParent->_pParent = pCur;
		pCur->_pLeft = pParent;
		if (root == _pRoot)
		{
			_pRoot = pCur;
			_pRoot->_pParent = nullptr;
		}
	}
	void Right(PNode root)//�ҵ���
	{
		PNode pParent = root;
		PNode pCur = root->_pLeft;

		if ((pParent->_pParent != nullptr) && (pParent->_pParent->_pLeft == pParent))
		{
			pParent->_pParent->_pLeft = pCur;
			pCur->_pParent = pParent->_pParent;
		}
		else if ((pParent->_pParent != nullptr) && (pParent->_pParent->_pRight == pParent))
		{
			pParent->_pParent->_pRight = pCur;
			pCur->_pParent = pParent->_pParent;
		}
		pParent->_pLeft = pCur->_pRight;
		if (pCur->_pRight!=nullptr)
			pCur->_pRight->_pParent = pParent;
		pCur->_pRight = pParent;
		pParent->_pParent = pCur;
		if (root == _pRoot)
		{
			_pRoot = pCur;
			_pRoot->_pParent = nullptr;
		}
		root
	}

	/*bool Erase(const T& data)
	{
		if (nullptr == _pRoot)
			return false;
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
	LOOP:
		if (nullptr == pCur)//������
			return false;
		if (nullptr == pCur->_pLeft)//���ҵ��ýڵ㣬��������Ϊ��
		{
			if (pParent->_pLeft == pCur)//���ڵ���������Ǹýڵ�
			{
				pParent->_pLeft = pCur->_pRight;
				free(pCur);
			}
			else                         //���ڵ���������Ǹýڵ�
			{
				pParent->_pRight = pCur->_pRight;
				free(pCur);
			}
		}
		else if (nullptr == pCur->_pRight)//������Ϊ��
		{
			if (pParent->_pLeft == pCur)
			{
				pParent->_pLeft = pCur->_pLeft;
				free(pCur);
			}
			else
			{
				pParent->_pRight = pCur->_pLeft;
				free(pCur);
			}
		}
		else//������������Ϊ��
		{
			PNode pnr = pCur->_pRight;//����������С�ڵ�
			pParent = pCur;
			while (pnr->_pLeft)
			{
				pParent = pnr;
				pnr = pnr->_pLeft;
			}
			pCur->_data = pnr->_data;
			pCur = pnr;
			goto LOOP;
		}
		return true;
	}*/
private:
	PNode _pRoot;
}; 

/*void _RotateR(PNode pParent)
{
	PNode pSubL = pParent->_pLeft;
	PNode pSubLR = pSubL->_pRight;

	pParent->_pLeft = pSubLR;
	if (pSubLR)
		pSubLR->_pParent = pParent;

	pSubL->_pRight = pParent;

	PNode pPParent = pParent->_pParent;

	pParent->_pParent = pSubL;

	pSubL->_pParent = pPParent;

	if (NULL == pPParent)
	{
		_pRoot = pSubL;
		pSubL->_pParent = NULL;
	}
	else
	{
		if (pPParent->_pLeft == pParent)
			pPParent->_pLeft = pSubL;
		else
			pPParent->_pRight = pSubL;
	}
	
	pParent->_bf = pSubL->_bf = 0;
}

void _RotateLR(PNode pParent)
{
	PNode pSubL = pParent->_pLeft;
	PNode pSubLR = pSubL->_pRight;

	int bf = pSubLR->_bf;

	_RotateL(pParent->_pLeft);

	_RotateR(pParent);

	if (1 == bf)
		pSubL->_bf = -1;
	else if (-1 == bf)
		pParent->_bf = 1;
}

int _Height(PNode pRoot);
bool _IsBalanceTree(PNode pRoot)
{
	if (nullptr == pRoot)
		return true;
	int leftHeight = _Height(pRoot->_pLeft);
	int rightHeight = _Height(pRoot->_pRight);
	int diff = rightHeight - leftHeight;

	if (diff != pRoot->_bf || (diff > 1 || diff < -1))
		return false;
	return _IsBalanceTree(pRoot->_pLeft) && _IsBalanceTree(pRoot->_pRight);
}*/
AVLTree<int> tree;
int main()
{

	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
	{
		tree.Insert(e);
	}



	system("pause");
	return 0;
}