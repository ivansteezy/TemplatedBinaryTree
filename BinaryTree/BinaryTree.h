#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <memory>
#include <iostream>

//i use this because i have problems with type alias on template nested classes, 
//but i dont think its a good practice
#define NodePtr std::shared_ptr<typename Tree::BinaryTree<T>::Node>

namespace Tree
{
    enum class Order
    {
        PreOrder = 0x00,
        InOrder = 0x01,
        PostOrder = 0x02
    };

    template <typename T>
    class BinaryTree
    {
        struct Node;

        struct Node
        {
            T data{};
            NodePtr left;
            NodePtr right;
        };

        NodePtr m_Root;

        NodePtr ClearTree(NodePtr root);
        NodePtr PushData(T data, NodePtr root);
        NodePtr PopData(T data, NodePtr root);
        NodePtr Find(NodePtr root, T data);
        NodePtr FindMin(NodePtr root);

        void InOrder(NodePtr root);
        void PreOrder(NodePtr root);
        void PostOrder(NodePtr root);

    public:
        BinaryTree();
        ~BinaryTree();

    public:
        void ShowOrder(const Order& order);
        void Insert(T data);
        void Remove(T data);
        bool Search(T data);
    };
}

#endif