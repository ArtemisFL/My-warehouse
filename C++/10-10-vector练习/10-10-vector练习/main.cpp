#include<iostream>
using namespace std;
#include<vector>

#if 0
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ʹ��find����3����λ�õ�iterator
	auto it = v.begin();
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	v.erase(pos);
	cout << *it << endl; // �˴��ᵼ�·Ƿ�����
	// ��posλ�ò������ݣ�����pos������ʧЧ��
	// insert�ᵼ�µ�����ʧЧ������Ϊinsert��
	// �ܻᵼ�����ݣ����ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��ˡ�
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����

	/*int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ͨ��[]��д��0��λ�á�
	v[0] = 10;
	cout << v[0] << endl;
	// ͨ��[i]�ķ�ʽ����vector
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";	cout << endl;
	vector<int> swapv;
	swapv.swap(v);
	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "swapv data:";
	for (size_t i = 0; i < swapv.size(); ++i)
		cout << swapv[i] << " ";
	cout << endl;

	// C++11֧�ֵ���ʽ��Χfor����
	for (auto x : v)
		cout << x << " ";
	cout << endl;*/	
	system("pause");
	return 0;
}
/*void PrintVector(const vector<int>& v)
{
	// const����ʹ��const���������б�����ӡ
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	// ʹ��push_back����4������
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// ʹ�õ��������б�����ӡ
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// ʹ�õ����������޸�
	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		++it;
	}
	// ʹ�÷�����������б����ٴ�ӡ
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	PrintVector(v);
	system("pause");
	return 0;
}
int main()
{
	/*size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(10); // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 10; ++i) {
		bar.push_back(i);
		if (sz != bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}*/

	/*std::vector<int> myvector;// set some initial content:
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);
	myvector.resize(5);
	myvector.resize(8, 100);
	myvector.resize(12);
	std::cout << "myvector contains:";
	for (int i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';*/

	/*int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	v.pop_back();
	v.pop_back();
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;*/	/*int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	// ��posλ��֮ǰ����30
	v.insert(pos, 30);
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 3);
	// ɾ��posλ�õ�����
	v.erase(pos);
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}*/#endif
int main()
{
	vector<int> vv{ 1,2,3,4,5,6,7 };
	auto it = vv.begin();
	printf("*it=%d,&(*it)=%p,it=%p\n", *it, &(*it), it);
	it++;
	printf("*it=%d,&(*it)=%p,it=%p\n", *it, &(*it), it);
	it--;
	printf("*it=%d,&(*it)=%p,it=%p\n", *it, &(*it), it);
	it = vv.erase(it);
	printf("*it=%d,&(*it)=%p,it=%p\n", *it, &(*it), it);
	system("pause");
	return 0;
}