//
//  BuildTree.cpp
//  cpp_practice
//
//  Created by Shaun Chuang on 2021/9/2.
//
// 二元樹具第k階，有2^k-1個節點
#include "BuildTree.hpp"
#include <iostream>

using namespace std;

class tree {
public:
  int data; // datanode
  class tree *left, *right;
};

typedef class tree node;

typedef node *bintree;

void Inorder(bintree ptr);
int main(void) {
  int i, level;
  int data[] = {6, 3, 5, 9, 7, 8, 4, 2};

  int tree[16] = {0}; // binary tree array

  cout << "init array content" << endl;

  for (i = 0; i < 8; i++)
    cout << "[" << data[i] << "]"; // print init array
  cout << endl;

  for (i = 0; i < 8; i++) //原始陣列逐一比對
  {
    for (level = 1; tree[level] != 0;) {
      if (data[i] > tree[level]) {
        level = level * 2 + 1; //左子樹index為父節點index*2+1

      } else {
        level = level * 2; //右子樹index為父節點index*2
      }
    }
    tree[level] = data[i];
  }
  cout << "binary tree content" << endl;
  for (i = 1; i < 16; i++)
    cout << "[" << tree[i] << "] ";
  cout << endl;
  return 0;
}

void Inorder(bintree ptr) {
  if (ptr != NULL) {
    Inorder(ptr->left);
    cout << "[" << ptr->data << "]";
    Inorder(ptr->right);
  }
}
