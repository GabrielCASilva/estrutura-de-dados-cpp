#ifndef ARVORE_H
#define ARVORE_H

#include <vector>
#include <print>

template<typename T>
class Node {
public:
    Node() = default;

    ~Node() = default;

    Node(const Node &rhs) = delete;

    Node &operator=(const Node &rhs) = delete;

    Node(Node &&rhs) = delete;

    Node &operator=(Node &&rhs) = delete;

    T &operator*() { return m_value; }

    [[nodiscard]] auto get_parent() const -> Node {
        return m_parent;
    }

    [[nodiscard]] auto get_children() const -> std::vector<Node *> & {
        return m_children;
    }

    [[nodiscard]] auto is_leaf() const -> bool {
        return get_children().empty();
    }

    [[nodiscard]] auto is_root() const -> bool {
        return not get_parent();
    }

    [[nodiscard]] auto is_internal() const -> bool {
        return not is_leaf();
    }

private:
    T m_value{};
    Node *m_parent{nullptr};
    std::vector<Node *> m_children{nullptr};
};

template<typename T>
class Arvore {
public:
    [[nodiscard]] auto size() const -> std::size_t { return 0; }

    [[nodiscard]] auto is_empty() const -> bool { return true; }

    [[nodiscard]] auto get_root() const -> Node<T> *;

    [[nodiscard]] auto get_nodes() const -> std::vector<Node<T> *>;

    // [Algoritmos]

    // Retorna a altura de um nó em uma árvore
    [[nodiscard]] static auto get_height(const Node<T> &node) -> int {
        if (node.is_leaf())
            return 0;
        int height{};
        for (auto n: node.m_children)
            height = max(height, get_height(n));
        return 1 + height;
    }

    // Retorna a profundidade de um nó em uma árvore
    [[nodiscard]] static auto get_depth(const Node<T> &node) -> int {
        if (node.is_root())
            return 0;
        return 1 + get_depth(node.get_parent());
    }

    // [Algoritmos] - Acesso aos nós

    // Mostra o nó console e depois acessa seus filhos
    static auto preorder_print(const Node<T> &node) -> void {
        std::print(*node);
        for (auto child : node.get_children()) {
            std::print(" ");
            preorder_print(child);
        }
    }

private:
    Node<T> *m_root{nullptr};
};

#endif //ARVORE_H
