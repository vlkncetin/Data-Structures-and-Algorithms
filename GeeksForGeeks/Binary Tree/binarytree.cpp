#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int data)
{
	Node* node=new Node();
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	
	return node;
}

/* Printing inorder traversal of a binary tree */
void inorderPrint(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorderPrint(temp->left);
    cout << temp->data << ' ';
    inorderPrint(temp->right);
}

// #6
//https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/
Node* InsertNode(Node* root, int data)
{
    if(root==NULL)
    {
        return CreateNode(data);
    }
    
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) 
    {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else 
        {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else 
        {
            temp->right = CreateNode(data);
            return root;
        }
    }
}



int main()
{
	Node* root=CreateNode(10);
	root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);
	
	cout << "Printing inorder traversal before insertion: ";
    inorderPrint(root);
    cout << endl;
 
    int key = 12;
    root = InsertNode(root, key);
 
    cout << "Printing inorder traversal after insertion: ";
    inorderPrint(root);
    cout << endl;
	
	return 0;
}