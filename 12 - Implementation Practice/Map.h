#pragma once
#include <vector>
#include <iostream>

using namespace std;

// Final 2023

template <class T>
class Node
{
public:
    char key;
    vector<T> value;
    Node<T> *left, *right;
    Node();
    Node(int k, T v);
};

template <class T>
class Map
{
    Node<T> *root;

public:
    Map();
    void insert(char key, T value);
    void find(char key);
}
