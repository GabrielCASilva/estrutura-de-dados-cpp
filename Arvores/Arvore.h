#ifndef ARVORE_H
#define ARVORE_H

#include <vector>
#include <print>

template<typename T>
class Node {
public:
    Node() = default;

    ~Node() = default;

    explicit Node(T value) {
        m_value = value;
    }

    Node(const Node<T> &rhs){
        if (this == &rhs)
            return;
        m_value = rhs.m_value;
        m_parent = new Node<T>();
        m_parent->m_value = rhs.m_parent->m_value;
        for (auto child : rhs.m_children){
            m_children.push_back(child);
        }
    }

    Node &operator=(const Node<T> &rhs){
        if (this == &rhs)
            return *this;
        m_value = rhs.m_value;
        m_parent = new Node<T>();
        m_parent->m_value = rhs.m_parent->m_value;
        for (auto child : rhs.m_children){
            m_children.push_back(child);
        }
        return *this;
    };

    Node(Node &&lhs) = delete;

    Node<T> &operator=(Node<T> &&lhs) = delete;

    T &operator*() { return m_value; }
    const T &operator*() const { return m_value; }

    T &operator!() { return m_value != nullptr; }
    const T &operator!() const { return m_value != nullptr; }

    auto add_child(Node<T> &node) -> void {
        node.m_parent = this;
        m_children.push_back(&node);
    }

    [[nodiscard]] auto get_parent() const -> Node<T> * { return m_parent; }

    [[nodiscard]] auto get_children() const -> const std::vector<Node<T> *> & { return m_children; }
    [[nodiscard]] auto get_children() -> std::vector<Node<T> *> & { return m_children; }

    [[nodiscard]] auto is_leaf() const -> bool { return get_children().empty(); }

    [[nodiscard]] auto is_root() const -> bool { return !get_parent(); }

    [[nodiscard]] auto is_internal() const -> bool { return !is_leaf(); }

private:
    T m_value{};
    Node<T> *m_parent{nullptr};
    std::vector<Node<T> *> m_children{};
};

template<typename T>
class Arvore {
public:
    Arvore() = default;

    ~Arvore() { delete m_root; }

    explicit Arvore(const Node<T> &node) {
        m_root = node;
    }

    // numero de nós
    [[nodiscard]] auto size() const -> std::size_t {
        if (!m_root)
            return 0;
        return tree_size(m_root);
    }

    // se a árvore está vazia
    [[nodiscard]] auto is_empty() const -> bool {
        if (m_root)
            return false;
        return true;
    }

    [[nodiscard]] auto get_root() const -> Node<T> * {
        return m_root;
    }

    // devolder uma lista com todos os nós
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

    // Mostra o nó no console e depois acessa seus filhos
    static auto preorder_print(const Node<T> &node) -> void {
        std::print(*node);
        for (auto child: node.get_children()) {
            std::print(" ");
            preorder_print(child);
        }
    }

    // Mostra o nó em preorder, mas com um parêntesis
    static auto preorder_paren_print(const Node<T> &node) -> void {
        std::print(*node);
        if (node.is_internal()) {
            std::print("( ");
            for (auto child: node.get_children()) {
                if (child != child.begin())
                    std::print(" ");
                preorder_paren_print(node);
            }
            std::print(")");
        }
    }

    // Acessa os filhos e mostra o nó
    static auto postorder_print(const Node<T> &node) -> void {
        for (auto child: node.get_children()) {
            postorder_print(child);
            std::print(" ");
        }
        std::print(*node);
    }

    static auto tree_size(const Node<T> &node) -> std::size_t {
        std::size_t size{1};
        if (node.is_internal()) {
            for (auto child: node.get_children()) {
                size += tree_size(child);
            }
            return size;
        }
    }

private:
    Node<T> *m_root{nullptr};
};

#endif //ARVORE_H
