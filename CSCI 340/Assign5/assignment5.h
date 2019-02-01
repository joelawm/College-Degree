#ifndef ASSIGNMENT5
#define ASSIGNMENT5
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Node
{
   friend class binTree;
   public:
   Node(int d)
   {
     data = d;
     left = nullptr;
     right = nullptr;
   }

   private:
   int data;
   Node *left;
   Node *right;
};

class binTree {
    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;
    private:
        void insert( Node*&, int );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
        void inorder( Node*, void(*)(int) );
        void preorder( Node*, void(*)(int) );
        void postorder( Node*, void(*)(int) );
};

#endif