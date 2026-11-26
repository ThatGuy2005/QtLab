#ifndef NODE_H
#define NODE_H

#include "sll.h"

class Csomopont
{
    Csomopont* next;
    int info;
public:
    Csomopont();
    static bool insertHead(SLL* list, Csomopont* node)
    {
        if(node == nullptr)
            return false;
        if(list->head != nullptr)
        {
            node->next = list->head;
            list->head = node;
        } else {
            list->head = node;
        }
    }
    static bool removeHead(SLL* list)
    {
        if(list->head == nullptr)
            return false;
        if(list->head != nullptr)
        {
            Csomopont* temp = list->head;
            list->head = list->head->next;
            delete temp;
        }
    }
};

#endif // NODE_H
