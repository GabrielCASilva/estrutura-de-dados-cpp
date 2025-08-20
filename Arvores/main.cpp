#include <print>
#include <iostream>
#include "Arvore.h"

//  g++ -std=c++23 main.cpp -o main

int main() {
    auto node = new Node<int>(2);
    auto node2 = new Node<int>(3);

    node->add_child(*node2);
    std::println("Node: {}",  **node);
    for (const auto n : node->get_children())
    {
        std::println("{}", **n);
        std::println("Parent: {}", *(*n->get_parent()));
    }

    auto node3 = new Node<int>(*node2);
    std::cout << node3 << std::endl;
    std::cout << node2 << std::endl;
    node->remove_child(*node2);

    delete node;
    return 0;
}