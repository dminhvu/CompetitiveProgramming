#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* Tree;

Node* getNode(int x);
void insertNode(Tree& T, int x);
void inputTree(Tree& T);
void NLR(Tree T);
bool isSquare(int n);
void SearchStandFor(Node*& p, Node*& q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree& T);

int main()
{
	freopen("input.txt","r",stdin);
    Tree T = NULL;
    inputTree(T);
    cout << "\nNLR: "; NLR(T);
    cout << "\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout << "\nNLR: "; NLR(T);

    return 0;
}

Node* getnode(int x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		return NULL;
	}
	p->info = x;
	p->pLeft = p->pRight = NULL;
	return p;
}

void Insert(Tree& T, int x)
{
	if (T)
	{
		if (T->info == x)
		{
			return;
		}
		if (T->info > x)
			return Insert(T->pLeft, x);
		else
			return Insert(T->pRight, x);
	}
	T = getnode(x);
}

void inputTree(Tree& T) {
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		Insert(T, x);
	}
}

void NLR(Tree T)
{
	if (T)
	{
		cout << T->info << " ";
		NLR(T->pLeft);
		NLR(T->pRight);
	}
}

bool isSquare(int n) {
	for (int i = 0; i * i <= n; i++) {
		if (i * i == n) return true;
	}
	return false;
}

void SearchStandFor(Node*& p, Node*& q) {
	if (q->pRight)
		SearchStandFor(p, q->pRight);
	else
	{
		p->info = q->info;
		p = q;
		q = q->pLeft;
	}
}

void deleteNode(Tree& root, int key)
{
	if (root == NULL)
	{
		return;
	}
	if (root->info > key)
		return deleteNode(root->pLeft, key);
	if (root->info < key)
		return deleteNode(root->pRight, key);

	Node* p = root;
	if (root->pLeft == NULL)
		root = root->pRight;
	else
		if (root->pRight == NULL)
			root = root->pLeft;
		else
			SearchStandFor(p, root->pLeft);
	delete p;
}

void deleteSquareNumbers(Tree& T) {
	if (T==NULL)
		return;
	else
	{
		if (isSquare(T->info))
			deleteNode(T, T->info);
		deleteSquareNumbers(T->pLeft);
		deleteSquareNumbers(T->pRight);
	}
}

bool primeNumber(int x){
    if (x <= 1) return false;
    if (x <= 3) return true;
    for (int i = 2; i * i <= x; i++) {
    	if (x % i == 0) return false;
    }
    return true;
}