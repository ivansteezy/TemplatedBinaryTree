#ifndef MENU_H
#define MENU_H

#include "BinaryTree.h"
#include "BinaryTree.cpp"

#include<iostream>

auto tree = std::make_shared<Tree::BinaryTree<int>>();

void MenuOptions()
{
    std::cout << "1.-Insertar un nuevo nodo.\n" <<
                 "2.-Buscar elemento en el arbol.\n" <<
                 "3.-Recorrido PreOrder.\n" <<
                 "4.-Recorrido InOrder.\n" <<
                 "5.-Recorrido PostOrden.\n" <<
                 "6.-Eliminar un nodo del arbol\n" <<
                 std::endl;
}

void InsertInkover()
{
    unsigned int data;

    std::cout << "Ingrese su dato a insertar en el arbol" << std::endl;
    std::cin >> data;

    tree->Insert(data);

    std::cout << "Dato insertado correctamente" << std::endl;
    system("pause");
    system("cls");
}

void SearchInvoker()
{
    unsigned int data;

    std::cout << "Ingrese un dato a buscar en el arbol" << std::endl;
    std::cin >> data;

    bool res = tree->Search(data);

    if(res) std::cout << "Dato encontrado" << std::endl;
    else std::cout << "Dato no encontrado" << std::endl;

    system("pause");
    system("cls");
}

void RemoveInvoker()
{
    unsigned int data;

    std::cout << "Ingrese un dato a eliminar en el arbol" << std::endl;
    std::cin >> data;

    tree->Remove(data);

    std::cout << "Dato eliminado correctamente" << std::endl;
    system("pause");
    system("cls");
}

void FunctionCaller(unsigned int menuOption)
{
    switch (menuOption)
    {
    case 1:
        InsertInkover();
        break;
    case 2:
        SearchInvoker();
        break;
    case 3:
        std::cout << "Recorrido Pre-order \n";
        tree->ShowOrder(Tree::Order::PreOrder);
        std::cout << "\n \n";
        system("pause");
        system("cls");
        break;
    case 4:
        std::cout << "Recorrido In-order \n";
        tree->ShowOrder(Tree::Order::InOrder);
        std::cout << "\n \n";
        system("pause");
        system("cls");
        break;
    case 5:
        std::cout << "Recorrido Post-order \n";
        tree->ShowOrder(Tree::Order::PostOrder);
        std::cout << "\n \n";
        system("pause");
        system("cls");
        break;
    case 6:
        RemoveInvoker();
        break;
    }
}

void Begin()
{
    unsigned int option;

    do
    {
        MenuOptions();
        std::cout << "Ingrese su opcion" << std::endl;
        std::cin >> option;
        FunctionCaller(option);
    } while (option != 7);
}

#endif
