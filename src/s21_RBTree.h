/*
 *  Сlass of sorting containers is built on the use of a red-black tree.
 *
 *   A RBtree is one of the types of self-balancing binary search
 *   trees that guarantees a logarithmic growth of the tree height from
 *   the number of nodes and allows you to quickly perform basic search
 *   tree operations: insert, erase, find.
 *
 *   The tree structure consists:
 *   1) Node root - tree root pointer
 *   2) Node NIL -  tree leaf pointer
 *   3) RBTColor color - tree node color | Red or Black
 *
 *   https://en.wikipedia.org/wiki/Red–black_tree
 **/

#pragma once

namespace s21 {

enum RBTColor { Black, Red };
enum TYPE { Same, Different };

template <class Key, class Value>
struct RBTNode {
    std::pair<Key, Value> data;
    RBTColor color;
    RBTNode<Key, Value>* left;
    RBTNode<Key, Value>* right;
    RBTNode<Key, Value>* parent;
    RBTNode();
    RBTNode(std::pair<Key, Value> number, RBTNode<Key, Value>* temp);
};

template <class Key, class Value>
class RBTree {
 public:
    typedef Key key_type;
    typedef Value mapped_type;
    typedef std::pair<key_type, mapped_type> value_type;
    typedef RBTNode<key_type, mapped_type>* Node;
    typedef size_t size_type;

 private:
    size_t _size;

    void insert_RBTree(Node node);
    void fix_insert_RBTree(Node node);
    void change_color_insert(Node node, Node grandParent);
    void case_one_insert(Node node, Node grandParent);
    void case_two_insert(Node node, Node grandParent);

    void delete_RBTree(Node node, Key number);
    void fix_delete_RBTree(Node node);
    void transplant_RBTree(Node one, Node two);
    void case_one_delete(Node node, Node child);
    void case_two_delete(Node node, Node child);
    void delete_tree(Node root);

    void rotate_left(Node node);
    void rotate_right(Node node);
    RBTColor get_color(Node node);
    void set_color(Node node, RBTColor color);

    std::pair<Node, bool> search_RBTree(Node node, Key value);

 public:
    RBTree();
    ~RBTree();
    Node root;
    Node NIL;

    std::pair<Node, bool> insert_value(const value_type& value, TYPE type);
    std::pair<Node, bool> search(const Key& value);

    void prefix_insert(Node node, Node NIL, TYPE type);
    void delete_value(Node node);
    void set_size(size_type size);
    size_type size();
    void clear();
};

}  // namespace s21

#include "s21_RBTree.inl"
