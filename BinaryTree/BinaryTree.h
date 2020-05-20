#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <memory>
#include <iostream>

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
        struct Node
        {
            T data{};
            std::shared_ptr<typename Tree::BinaryTree<T>::Node> left;
            std::shared_ptr<typename Tree::BinaryTree<T>::Node> right;
        };

        std::shared_ptr<typename Tree::BinaryTree<T>::Node> m_Root;

        std::shared_ptr<typename Tree::BinaryTree<T>::Node> ClearTree(std::shared_ptr<typename Tree::BinaryTree<T>::Node> root);
        std::shared_ptr<typename Tree::BinaryTree<T>::Node> PushData(T data, std::shared_ptr<typename Tree::BinaryTree<T>::Node> root);
        std::shared_ptr<typename Tree::BinaryTree<T>::Node> PopData(T data, std::shared_ptr<typename Tree::BinaryTree<T>::Node> root);
        std::shared_ptr<typename Tree::BinaryTree<T>::Node> Find(std::shared_ptr<typename Tree::BinaryTree<T>::Node> root, T data);
        std::shared_ptr<typename Tree::BinaryTree<T>::Node> FindMin(std::shared_ptr<typename Tree::BinaryTree<T>::Node> root);
        std::shared_ptr<typename Tree::BinaryTree<T>::Node> FindMax(std::shared_ptr<typename Tree::BinaryTree<T>::Node> root);

        void InOrder(std::shared_ptr<typename Tree::BinaryTree<T>::Node> root);
        void PreOrder(std::shared_ptr<typename Tree::BinaryTree<T>::Node> root);
        void PostOrder(std::shared_ptr<typename Tree::BinaryTree<T>::Node> root);

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