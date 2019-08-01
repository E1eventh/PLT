#ifndef NARY_TREE_H
#define NARY_TREE_H

#include "QString"

class nary_tree
{
    struct node
    {
        QString data;
        node *parrent;
    };

public:
    nary_tree();
};

#endif // NARY_TREE_H
