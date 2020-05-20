// 20-05-2020 Made by Ivan Ayala a.k.a. Churrus, Twitter: @robot_earss

#include "BinaryTree.h"
#include "BinaryTree.cpp"

int main()
{
    std::cout << "Hola mundo" << std::endl;
    auto tree = std::make_shared<Tree::BinaryTree<int>>();

    tree->Insert(3);
    tree->Insert(6);
    tree->Insert(2);
    tree->Insert(1);
    tree->Insert(9);

    auto res = tree->Search(9);

    if (res) std::cout << "Si se encontro tu elemento" << std::endl;

    std::cout << "Recorridoooos" << std::endl;

    std::cout << "PreOrder" << std::endl;
    tree->ShowOrder(Tree::Order::PreOrder);
    std::cout << "\n";

    std::cout << "InOrder" << std::endl;
    tree->ShowOrder(Tree::Order::InOrder);
    std::cout << "\n";

    std::cout << "PostOrder" << std::endl;
    tree->ShowOrder(Tree::Order::PostOrder);
}