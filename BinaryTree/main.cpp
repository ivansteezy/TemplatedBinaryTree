// 20-05-2020 Made by Ivan Ayala a.k.a. Churrus, Twitter: @robot_earss

#include "BinaryTree.h"
#include "BinaryTree.cpp"

void MenuOptions()
{
    std::cout << "1.-Insertar un nuevo nodo." <<
                 "2.-Buscar elemento en el arbol." <<
                 "3.-Recorrido PreOrder." <<
                 "4.-Recorrido InOrder." <<
                 "5.-Recorrido PostOrden." <<
                 "6.-Eliminar un nodo del arbol" <<
                 std::endl;
}

int main()
{
    std::cout << "Hola mundo" << std::endl;
    auto tree = std::make_shared<Tree::BinaryTree<int>>();

    tree->Insert(3);
    tree->Insert(6);
    tree->Insert(2);
    tree->Insert(1);
    tree->Insert(9);


    tree->Remove(9);
    auto res = tree->Search(9);

    if (res)
    {
        std::cout << "Si se encontro tu elemento \n \n";
    }
    else
    {
        std::cout << "No se encontro tu elemento \n \n";
    }

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