/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Template of TreeNode class
    */

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using namespace std;

template <class T>
class TreeNode{
    public:

        T* data;
        int key;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode();

        TreeNode(T* d, int k);

        ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode(){
  data = T();
  key = -1;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T* d, int k){
  data = d;
  key = k;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
  delete left;
  delete right;
  delete data;
}

#endif
