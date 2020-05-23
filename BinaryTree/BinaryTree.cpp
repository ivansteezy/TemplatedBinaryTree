#include "BinaryTree.h"

template<typename T>
Tree::BinaryTree<T>::BinaryTree()
{
}

template<typename T>
Tree::BinaryTree<T>::~BinaryTree()
{
}

template<typename T>
NodePtr Tree::BinaryTree<T>::ClearTree(NodePtr root)
{
	if (root == nullptr) 
		return nullptr;
	{
		ClearTree(root->left);
		ClearTree(root->right);
	}
	return nullptr;
}

template<typename T>
NodePtr Tree::BinaryTree<T>::PushData(T data, NodePtr root)
{
	if (root == nullptr)
	{
		root = std::make_shared<Tree::BinaryTree<T>::Node>();
		root->data = data;
		root->left = root->right = nullptr;
	}
	else if (data < root->data)
	{
		root->left = PushData(data, root->left);
	}
	else if (data > root->data)
	{
		root->right = PushData(data, root->right);
	}
	return root;
}

template<typename T>
NodePtr Tree::BinaryTree<T>::FindMin(NodePtr root)
{
	if (root == nullptr)
		return nullptr;
	else if (root->left == nullptr)
		return root;
	else
		return FindMin(root->left);
}

template<typename T>
NodePtr Tree::BinaryTree<T>::PopData(T data, NodePtr root)
{
	auto tempNode = std::make_shared<Tree::BinaryTree<T>::Node>();
	if (root == nullptr)
		return nullptr;
	else if (data < root->data)
		root->left = PopData(data, root->left);
	else if (data > root->data)
		root->right = PopData(data, root->right);
	else if (root->left && root->right)
	{
		tempNode = FindMin(root->right);
		root->data = tempNode->data;
		root->right = PopData(root->data, root->right);
	}
	else
	{
		tempNode = root;
		if (root->left == nullptr)
			root = root->right;
		else if (root->right == nullptr)
			root = root->left;
	}

	
	return root;
}

template<typename T>
void Tree::BinaryTree<T>::InOrder(NodePtr root)
{
	if (root == nullptr) return;
	InOrder(root->left);
	std::cout << root->data << " ";
	InOrder(root->right);
}

template<typename T>
void Tree::BinaryTree<T>::PreOrder(NodePtr root)
{
	if (root == nullptr) return;

	std::cout << root->data << " ";
	InOrder(root->left);
	InOrder(root->right);
}

template<typename T>
void Tree::BinaryTree<T>::PostOrder(NodePtr root)
{
	if (root == nullptr) return;
	InOrder(root->left);
	InOrder(root->right);
	std::cout << root->data << " ";
}

template<typename T>
NodePtr Tree::BinaryTree<T>::Find(NodePtr root, T data)
{
	if (root == nullptr)
		return nullptr;
	else if (data < root->data)
		return Find(root->left, data);
	else if (data > root->data)
		return Find(root->right, data);
	else 
		return root;
}

template<typename T>
void Tree::BinaryTree<T>::ShowOrder(const Order& order)
{
	switch (order)
	{
		case Order::PreOrder:  PreOrder(m_Root);  break;
		case Order::InOrder:   InOrder(m_Root);   break;
		case Order::PostOrder: PostOrder(m_Root); break;
	}
}

template<typename T>
void Tree::BinaryTree<T>::Insert(T data)
{
	m_Root = PushData(data, m_Root);
}

template<typename T>
void Tree::BinaryTree<T>::Remove(T data)
{
	m_Root = PopData(data, m_Root);
}

template<typename T>
bool Tree::BinaryTree<T>::Search(T data)
{
	return (Find(m_Root, data) != nullptr ? true : false);
}