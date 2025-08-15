#ifndef ARVORE_H
#define ARVORE_H
#include <vector>

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

    // posição do nó na árvore
    [[nodiscard]] auto get_depth() const -> int {
        // if
    }

    [[nodiscard]] auto size() const -> std::size_t {
        return 0;
    }

    [[nodiscard]] auto is_empty() const -> bool { return true; }

    [[nodiscard]] auto get_root() const -> Node<T> *;

    [[nodiscard]] auto get_nodes() const -> std::vector<Node<T> *>;

private:
    Node<T> *m_root{nullptr};
};
//
#endif //ARVORE_H
