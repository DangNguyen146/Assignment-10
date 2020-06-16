#include<iostream>

using namespace std;
struct TNode
{
	float Key;
	struct TNode* pLeft;
	struct TNode* pRight;
};
typedef TNode* Tree;

float insertNode(Tree& T, float x)
{
	if (T)
	{
		if (T->Key == x)
			return 0;
		if (T->Key > x)
			return insertNode(T->pLeft, x);
		else
			return insertNode(T->pRight, x);
	}
	T = new TNode;
	T->Key = x;
	T->pLeft = T->pRight = NULL;
	return 1;
}

TNode* SearchNode(Tree T, float x)
{
	if (T != NULL)
	{
		if (T->Key == x)
			return T;
		else
		{
			if (x > T->Key)
				return SearchNode(T->pRight, x);
			else
				return SearchNode(T->pLeft, x);
		}
	}
	return NULL;
}
void LNR(TNode* T)
{
	if (T != NULL) {
		LNR(T->pLeft);
		cout << T->Key << " ";
		LNR(T->pRight);
	}
}
TNode* SearchNode(Tree T, int x)
{
	if (T != NULL)
	{
		if (T->Key == x)
			return T;
		else
		{
			if (x > T->Key)
				return SearchNode(T->pRight, x);
			else
				return SearchNode(T->pLeft, x);
		}
	}
	return NULL;
}
int main()
{
	Tree T = NULL;
	float n;
	cin >> n;
	float temp;
	float tb=0;
	for (float i = 0; i < n; i++)
	{
		cin >> temp;
		tb =tb+ temp;
		insertNode(T, temp);
	}
	tb /= 8;
	if (SearchNode(T, tb) != NULL)
		cout << 1;
	else
		cout << 0;
	cout << endl;
	LNR(T);

	return 0;

}