#pragma once
#include <iostream>

#include <cassert>
#include <stack>

template <class t>
class Undo
{
public:
    int pos;
    string name;
    Node<t> *nodes = nullptr;

    Undo(int p, string n)
    {
        this->pos = p;
        this->name = n;
        nodes = nullptr;
    }

    Undo(int p, string n, Node<t> *d)
    {
        this->pos = p;
        this->name = n;
        this->nodes = d;
    }
};

template <class t>
class Node
{
public:
    t data;
    Node *next;
    Node();
    Node<t>(int);
};

template <class t>
class LinkedList
{
    Node<t> *head;
    Node<t> *tail;
    int size;
    stack<Undo<t>> s;
    bool flag = false;

public:
    LinkedList();
    void append(t);
    void insertAt(int, t);
    void deleteAt(int);
    int length();
    t at(int);
    void display();
    void moveNode(t, int);
    void undo();
};
