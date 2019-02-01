#include <iostream>
#include "assignment5.h"
#include "assignment6.h"
using namespace std;

void BST::insert(Node*& head, int a)
{
	if (head == NULL)
	{
		Node *temp = new Node(a);
		temp->data = a;
		temp->left = temp->right = NULL;
		head = temp;
		return;
	}
	if (head->data>a)
	{
		insert(head->left, a);
	}
	else
	{
		insert(head->right, a);
	}
}

void BST::insert(int a)
{
	Node *head = new Node(a);
	insert(head, a);
}

bool BST::search(Node*& head, int a)
{
	if (head == NULL)
		return false;
	if (head->data == a)
		return true;
	else if (head->data>a)
		return (search(head->left, a));
	else if (head->data<a)
		return (search(head->right, a));
	return false;
}
bool BST::search(int a)
{
	Node *head = new Node(a);
	return search(head, a);
}

Node* minValueNode(Node* node)
{
	Node* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

bool BST::remove(Node*& head, int a)
{
	// base case
	if (head == NULL) return false;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (a < head->data)
		// root->left = deleteNode(root->left, key);
		remove(head->left, a);
	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (a > head->data)
		remove(head->right, a);
	//   root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (head->left == NULL)
		{
			Node* temp = head;
			head = head->right;
			free(temp);
			return true;
		}
		else if (head->right == NULL)
		{
			Node* temp = head;
			head = head->left;
			free(temp);
			return true;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Node* temp = minValueNode(head->right);

		// Copy the inorder successor's content to this node
		head->data = temp->data;

		// Delete the inorder successor
		remove(head->right, temp->data);
	}
	return true;
}

bool BST::remove(int a)
{
	Node *head = new Node(a);
	return remove(head, a);
}

int BST::sumLeftLeaves()
{
	return 0;
}

int BST::sumLeftLeaves(Node*& head)
{
	return 0;
}