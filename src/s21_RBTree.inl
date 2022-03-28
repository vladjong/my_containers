// #include "s21_RBTree.h"

namespace s21 {

template <class Key, class Value>
RBTNode<Key, Value>::RBTNode() : color(Black), left(nullptr), right(nullptr), parent(nullptr) {}

template <class Key, class Value>
RBTNode<Key, Value>::RBTNode(std::pair<Key, Value> number, RBTNode<Key, Value>* temp)
    : color(Red), left(temp), right(temp), parent(nullptr) {
    data.first = number.first;
    data.second = number.second;
}

template <class Key, class Value>
RBTree<Key, Value>::RBTree() : _size(0) {
    NIL = new RBTNode<Key, Value>;
    root = NIL;
}

template <class Key, class Value>
RBTree<Key, Value>::~RBTree() {
    clear();
}

template <class Key, class Value>
void RBTree<Key, Value>::clear() {
    if (root) {
        if (root != NIL) {
            delete_tree(root);
        }
        delete NIL;
        root = nullptr;
    }
}

template <class Key, class Value>
void RBTree<Key, Value>::delete_tree(Node root) {
    if (root->left != NIL) {
        delete_tree(root->left);
    }
    if (root->right != NIL) {
        delete_tree(root->right);
    }
    if (root) {
        delete root;
        root = nullptr;
    }
}

template <class Key, class Value>
RBTColor RBTree<Key, Value>::get_color(Node node) {
    if (node == nullptr) {
        return Black;
    }
    return node->color;
}

template <class Key, class Value>
void RBTree<Key, Value>::set_color(Node node, RBTColor color) {
    node->color = color;
}

template <class Key, class Value>
std::pair<typename RBTree<Key, Value>::Node, bool> RBTree<Key, Value>::insert_value(const value_type& value,
                                                                                    TYPE type) {
    Node node = new RBTNode<Key, Value>(value, NIL);
    if (search(value.first).second == true && type == Same) {
        delete node;
        return std::make_pair(NIL, false);
    }
    insert_RBTree(node);
    fix_insert_RBTree(node);
    _size++;
    return std::make_pair(node, true);
}

template <class Key, class Value>
void RBTree<Key, Value>::insert_RBTree(Node node) {
    Node child = nullptr;
    Node parent = root;
    while (parent != NIL) {
        child = parent;
        if (node->data.first < parent->data.first) {
            parent = parent->left;
        } else {
            parent = parent->right;
        }
    }
    node->parent = child;
    if (child == nullptr) {
        root = node;
    } else if (node->data.first < child->data.first) {
        child->left = node;
    } else {
        child->right = node;
    }
    if (node->parent == nullptr) {
        set_color(node, Black);
        return;
    }
    if (node->parent->parent == nullptr) {
        return;
    }
}

template <class Key, class Value>
void RBTree<Key, Value>::case_one_insert(Node node, Node grandParent) {
    grandParent = node->parent->parent->left;
    if (get_color(grandParent) == Red) {
        change_color_insert(node, grandParent);
    } else {
        if (node == node->parent->left) {
            node = node->parent;
            rotate_right(node);
        }
        set_color(node->parent, Black);
        set_color(node->parent->parent, Red);
        rotate_left(node->parent->parent);
    }
}

template <class Key, class Value>
void RBTree<Key, Value>::case_two_insert(Node node, Node grandParent) {
    grandParent = node->parent->parent->right;
    if (get_color(grandParent) == Red) {
        change_color_insert(node, grandParent);
    } else {
        if (node == node->parent->right) {
            node = node->parent;
            rotate_left(node);
        }
        set_color(node->parent, Black);
        set_color(node->parent->parent, Red);
        rotate_right(node->parent->parent);
    }
}

template <class Key, class Value>
void RBTree<Key, Value>::change_color_insert(Node node, Node grandParent) {
    set_color(grandParent, Black);
    set_color(node->parent, Black);
    set_color(node->parent->parent, Red);
    node = node->parent->parent;
}

template <class Key, class Value>
void RBTree<Key, Value>::fix_insert_RBTree(Node node) {
    Node grandParent = nullptr;
    while (get_color(node->parent) == Red) {
        if (node->parent == node->parent->parent->right) {
            case_one_insert(node, grandParent);
        } else {
            case_two_insert(node, grandParent);
        }
    }
    NIL->parent = maximum_value(root, NIL);
    set_color(root, Black);
}

template <class Key, class Value>
void RBTree<Key, Value>::delete_value(Node node) {
    delete_RBTree(root, node->data.first);
    _size--;
    NIL->parent = maximum_value(root, NIL);
}

template <class Key, class Value>
void RBTree<Key, Value>::transplant_RBTree(Node one, Node two) {
    if (one->parent == nullptr) {
        root = two;
    } else if (one == one->parent->left) {
        one->parent->left = two;
    } else {
        one->parent->right = two;
    }
    two->parent = one->parent;
}

template <class Key, class Value>
void RBTree<Key, Value>::delete_RBTree(Node node, Key number) {
    Node tempNode = NIL;
    Node child = nullptr;
    Node brother = nullptr;
    while (node != NIL) {
        if (node->data.first == number) {
            tempNode = node;
        }
        if (node->data.first <= number) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    brother = tempNode;
    RBTColor checkColor = brother->color;
    if (tempNode->left == NIL) {
        child = tempNode->right;
        transplant_RBTree(tempNode, tempNode->right);
    } else if (tempNode->right == NIL) {
        child = tempNode->left;
        transplant_RBTree(tempNode, tempNode->left);
    } else {
        brother = minimum_value(tempNode->right, NIL);
        checkColor = brother->color;
        child = brother->right;
        if (brother->parent == tempNode) {
            child->parent = brother;
        } else {
            transplant_RBTree(brother, brother->right);
            brother->right = tempNode->right;
            brother->right->parent = brother;
        }
        transplant_RBTree(tempNode, brother);
        brother->left = tempNode->left;
        brother->left->parent = brother;
        set_color(brother, tempNode->color);
    }
    delete tempNode;
    if (checkColor == Black) {
        fix_delete_RBTree(child);
    }
}

template <class Key, class Value>
void RBTree<Key, Value>::case_one_delete(Node node, Node child) {
    node = child->parent->right;
    if (get_color(node) == Red) {
        set_color(node, Black);
        set_color(child->parent, Red);
        rotate_left(child->parent);
        node = child->parent->right;
    }
    if (get_color(node->left) == Black && get_color(node->right) == Black) {
        set_color(node, Red);
        child = child->parent;
    } else {
        if (get_color(node->right) == Black) {
            set_color(node->left, Black);
            set_color(node, Red);
            rotate_right(node);
            node = child->parent->right;
        }
        set_color(node, child->parent->color);
        set_color(child->parent, Black);
        set_color(node->right, Black);
        rotate_left(child->parent);
        child = root;
    }
}

template <class Key, class Value>
void RBTree<Key, Value>::case_two_delete(Node node, Node child) {
    node = child->parent->left;
    if (get_color(node) == Red) {
        set_color(node, Black);
        set_color(child->parent, Red);
        rotate_right(child->parent);
        node = child->parent->left;
    }
    if (get_color(node->right) == Black && get_color(node->left) == Black) {
        set_color(node, Red);
        child = child->parent;
    } else {
        if (get_color(node->left) == Black) {
            set_color(node->right, Black);
            set_color(node, Red);
            rotate_left(node);
            node = child->parent->left;
        }
        set_color(node, child->parent->color);
        set_color(child->parent, Black);
        set_color(node->left, Black);
        rotate_right(child->parent);
        child = root;
    }
}

template <class Key, class Value>
void RBTree<Key, Value>::fix_delete_RBTree(Node child) {
    Node node = nullptr;
    while (child != root && get_color(child) == Black) {
        if (child == child->parent->left) {
            case_one_delete(node, child);
        } else {
            case_two_delete(node, child);
        }
    }
    set_color(child, Black);
}

template <class Key, class Value>
void RBTree<Key, Value>::rotate_left(Node node) {
    Node right_child = node->right;
    node->right = right_child->left;
    if (node->right != nullptr) {
        node->right->parent = node;
    }
    right_child->parent = node->parent;
    if (node->parent == nullptr) {
        root = right_child;
    } else if (node == node->parent->left) {
        node->parent->left = right_child;
    } else {
        node->parent->right = right_child;
    }
    right_child->left = node;
    node->parent = right_child;
}

template <class Key, class Value>
void RBTree<Key, Value>::rotate_right(Node node) {
    Node left_child = node->left;
    node->left = left_child->right;
    if (node->left != nullptr) {
        node->left->parent = node;
    }
    left_child->parent = node->parent;
    if (node->parent == nullptr) {
        root = left_child;
    } else if (node == node->parent->left) {
        node->parent->left = left_child;
    } else {
        node->parent->right = left_child;
    }
    left_child->right = node;
    node->parent = left_child;
}

template <class Key, class Value>
void RBTree<Key, Value>::prefix_insert(Node node, Node NIL, TYPE type) {
    if (node != NIL) {
        insert_value(node->data, type);
        prefix_insert(node->left, NIL, type);
        prefix_insert(node->right, NIL, type);
    }
}

template <class Key, class Value>
std::pair<typename RBTree<Key, Value>::Node, bool> RBTree<Key, Value>::search(const Key& value) {
    return search_RBTree(root, value);
}

template <class Key, class Value>
void RBTree<Key, Value>::set_size(size_type size) {
    _size = size;
}

template <class Key, class Value>
std::pair<typename RBTree<Key, Value>::Node, bool> RBTree<Key, Value>::search_RBTree(Node node, Key value) {
    if (value == node->data.first) {
        return std::make_pair(node, true);
    } else if (node == NIL) {
        return std::make_pair(node, false);
    }
    if (value < node->data.first) {
        return search_RBTree(node->left, value);
    }
    return search_RBTree(node->right, value);
}

template <class Key, class Value>
typename RBTree<Key, Value>::size_type RBTree<Key, Value>::size() {
    return _size;
}

template <class Key, class Value>
RBTNode<Key, Value>* successor(RBTNode<Key, Value>* node, RBTNode<Key, Value>* NIL) {
    if (node->right != NIL) {
        return minimum_value(node->right, NIL);
    }
    if (NIL->parent == node) {
        return NIL;
    }
    RBTNode<Key, Value>* nodeTemp = node->parent;
    while (nodeTemp != NIL && nodeTemp && node == nodeTemp->right) {
        node = nodeTemp;
        nodeTemp = nodeTemp->parent;
    }
    return nodeTemp;
}

template <class Key, class Value>
RBTNode<Key, Value>* predecessor(RBTNode<Key, Value>* node, RBTNode<Key, Value>* NIL) {
    RBTNode<Key, Value>* twinNode = nullptr;
    if (node->left != NIL) {
        return maximum_value(node->left, NIL);
    }
    RBTNode<Key, Value>* nodeTemp = node->parent;
    while (nodeTemp != NIL && node == nodeTemp->left) {
        node = nodeTemp;
        nodeTemp = nodeTemp->parent;
        if (twinNode == nodeTemp) {
            return NIL;
        }
    }
    return nodeTemp;
}

template <class Key, class Value>
RBTNode<Key, Value>* minimum_value(RBTNode<Key, Value>* node, RBTNode<Key, Value>* NIL) {
    while (node->left != NIL) {
        node = node->left;
    }
    return node;
}

template <class Key, class Value>
RBTNode<Key, Value>* maximum_value(RBTNode<Key, Value>* node, RBTNode<Key, Value>* NIL) {
    while (node->right != NIL) {
        node = node->right;
    }
    return node;
}

}  // namespace s21
