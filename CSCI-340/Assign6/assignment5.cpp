
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"
using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}

binTree::binTree()
{
	root = nullptr;
}

void binTree::insert(int val)
{
	insert(root, val);
}

unsigned binTree::height() const
{
	return height(root);
}

unsigned binTree::size() const
{
	return size(root);
}

void binTree::inorder(void(*p) (int))
{
	inorder(root, p);
}

void binTree::preorder(void(*p) (int))
{
	preorder(root, p);
}

void binTree::postorder(void(*p) (int))
{
	postorder(root, p);
}

void binTree::insert(Node*& r, int x)
{
	if (r == nullptr)
	{
		r = new Node(x);
	}
	else
	{
		if (height(r->right) < height(r->left))
		{
			insert(r->right, x);
		}
		else
		{
			insert(r->left, x);
		}
	}
}

unsigned binTree::height(Node* r) const
{
	if(r == NULL)
	{
		return 0;
	}
	int left = height(r->left);
	int right = height(r->right);
	return 1 + max(left, right);
}

unsigned binTree::size(Node* p) const
{
if(p == NULL)
{
     return 0;
}
else
{
     return size(p->left) + size(p->right) + 1;
}
}

void binTree::inorder(Node* p, void(*fun) (int))
{
   if(p != NULL)
   {
   inorder(p->left, fun);
  
   fun(p->data);
  
   inorder(p->right, fun);
   }

}

void binTree::preorder(Node* p, void(*fun) (int))
{
   if(p != NULL)
   {
  
   fun(p->data);

   preorder(p->left, fun);

   preorder(p->right, fun);
  
   }

}

void binTree::postorder(Node* p, void(*fun) (int))
{
	if(p != NULL)
	{
		postorder(p->left, fun);
		postorder(p->right, fun);
		fun(p->data);
	}
}
