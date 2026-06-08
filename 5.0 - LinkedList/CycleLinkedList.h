#pragma once

#include "LinkedList.h"

template <class T>
class CycleLinkedList : public LinkedList<T>
{
public:
    CycleLinkedList();
    bool HasCycle();
    void CreateCycleToPosition(int);
    void BreakCycle();
    ~CycleLinkedList();
};