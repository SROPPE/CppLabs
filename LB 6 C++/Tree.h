//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
#include <Vcl.Controls.hpp>
struct Node
{
	int key;
	int size;
	Node* left;
	Node* right;
	Node(int k) { key = k; left = right = 0; size = 1; }
};

int GetSize(Node* p)
{
	if (!p) return 0;
	return p->size;
}

void FixSize(Node* p)
{
	p->size = GetSize(p->left) + GetSize(p->right) + 1;
}
class Tree
{
private:

	Node* Join(Node* p, Node* q)
	{
		if (!p) return q;
		if (!q) return p;
		if (rand() % (p->size + q->size) < p->size)
		{
			p->right = Join(p->right, q);
			FixSize(p);
			return p;
		}
		else
		{
			q->left = Join(p, q->left);
			FixSize(q);
			return q;
		}
	}
	Node* RotateRight(Node* p)
	{
		Node* q = p->left;
		if (!q) return p;
		p->left = q->right;
		q->right = p;
		q->size = p->size;
		FixSize(p);
		return q;
	}
	Node* RotateLeft(Node* q)
	{
		Node* p = q->right;
		if (!p) return q;
		q->right = p->left;
		p->left = q;
		p->size = q->size;
		FixSize(q);
		return p;
	}
	Node* InsertRoot(Node* p, int k)
	{
		if (!p) return new Node(k);
		if (k < p->key)
		{
			p->left = InsertRoot(p->left, k);
			return RotateRight(p);
		}
		else
		{
			p->right = InsertRoot(p->right, k);
			return RotateLeft(p);
		}
	}
public:
	int max = INT_MIN, min = INT_MAX;
	double nearest = DBL_MAX;
	double midVal = 0;
	Node* root;
	Tree()
	{

	}
	Node* Find(Node* p, int k)
	{
		if (!p) return nullptr;
		if (k == p->key)
			return p;
		if (k < p->key)
			return Find(p->left, k);
		else
			return Find(p->right, k);
	}
	Node* Insert(Node* p, int k)
	{
		if (!p) return new Node(k);
		if (rand() % (p->size + 1) == 0)
		{
			return InsertRoot(p, k);

		}
		if (p->key > k)
			p->left = Insert(p->left, k);
		else
			p->right = Insert(p->right, k);
		FixSize(p);
		return p;
	}
	Node* Remove(Node* p, int k)
	{
		if (!p) return p;
		if (p->key == k)
		{
			Node* q = Join(p->left, p->right);
			delete p;
			return q;
		}
		else if (k < p->key)
			p->left = Remove(p->left, k);
		else
			p->right = Remove(p->right, k);
		return p;
	}
	void PreOrder(TMemo *mem,Node* t)
	{
		if (!t) return;
		mem->Lines->Add(IntToStr(t->key));
			PreOrder(mem,t->left);
		PreOrder(mem,t->right);
	}
	int CalcNeareast(Node *t)
	{
		InorderCalcMinMax(t);
		midVal = (min + max) / 2;
		InorderCalcNearest(t);
		return nearest;
	}
	void InorderCalcMinMax(Node* t)
	{

		if (!t)	return;
		if (t->key < min)
			min = t->key;
		if (t->key > max)
			max = t->key;
		InorderCalcMinMax(t->left);
		InorderCalcMinMax(t->right);

	}
	void InorderCalcNearest(Node* t)
	{

		if (!t)	return;
		if (fabs(t->key - midVal) < fabs(nearest - midVal))
			nearest = t->key;
		InorderCalcNearest(t->left);
		InorderCalcNearest(t->right);

	}
	void Inorder(TMemo *mem,Node* t)
	{
		if (!t)	return;
			Inorder(mem,t->left);
			mem->Lines->Add(IntToStr(t->key));
			Inorder(mem,t->right);

	}
	void PostOrder(TMemo *mem,Node* t)
	{
		if (!t) return;
			PostOrder(mem,t->left);
			PostOrder(mem,t->right);
			mem->Lines->Add(IntToStr(t->key));
	}
};
//---------------------------------------------------------------------------
#endif
