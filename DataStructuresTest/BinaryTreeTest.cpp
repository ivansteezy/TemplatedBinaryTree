#include "gtest/gtest.h"
#include "../BinaryTree/BinaryTree.h"
#include "../BinaryTree/BinaryTree.cpp"
TEST(BinaryTreeTest, InsertTest) {
    auto tree = std::make_shared<Tree::BinaryTree<int>>();

    tree->Insert(2);
    tree->Insert(3);
    tree->Insert(4);
    tree->Insert(1);

    EXPECT_NE(tree, nullptr);
}

TEST(BinaryTreeTest, SearchTest) {
    auto tree = std::make_shared<Tree::BinaryTree<int>>();

    tree->Insert(2);
    tree->Insert(3);
    tree->Insert(4);
    tree->Insert(1);

    auto exists = tree->Search(2);
    EXPECT_EQ(exists, true);

    auto notExists = tree->Search(5);
    EXPECT_EQ(notExists, false);
}

TEST(BinaryTreeTest, RemoveTest) {
    auto tree = std::make_shared<Tree::BinaryTree<int>>();

    tree->Insert(2);
    tree->Insert(3);
    tree->Insert(4);
    tree->Insert(1);

    tree->Remove(2);

    auto exists = tree->Search(2);
    EXPECT_EQ(exists, false);

    auto notExists = tree->Search(4);
    EXPECT_EQ(notExists, true);
}

TEST(BinaryTreeTest, OrderTest) {
    auto tree = std::make_shared<Tree::BinaryTree<int>>();

    tree->ShowOrder(Tree::Order::InOrder);
    tree->ShowOrder(Tree::Order::PostOrder);
    tree->ShowOrder(Tree::Order::PreOrder);

    EXPECT_NE(tree, nullptr);
}