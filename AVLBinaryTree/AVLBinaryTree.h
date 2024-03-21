#ifndef AVLBinaryTree_h
#define AVLBinaryTree_h
#include "BinaryNode.h"
#include <list>
template<class T>
class AVLBinaryTree{

protected:

BinaryNode<T>* root;

public:

AVLBinaryTree<T>();
~AVLBinaryTree<T>();
bool isEmpty();
int getHeight(BinaryNode<T>* node);
bool isLeaf(BinaryNode<T>* node);
bool addNode(T value);
void postOrderAux(BinaryNode<T> *node, std::list<T>* treeList);
void preOrderAux(BinaryNode<T> *node, std::list<T>* treeList);
void inOrderAux(BinaryNode<T> *node, std::list<T>* treeList);
bool findNode(T value);
std::list<T> inOrder();
std::list<T> postOrder();
std::list<T> preOrder();
BinaryNode<T>* getRoot();
bool deleteNode(T value);
BinaryNode<T>* getBiggestData(BinaryNode<T>* node);
int heightDifference(BinaryNode<T>* node1, BinaryNode<T>* node2);
void AVLBalancing();
BinaryNode<T>* AVLBalancingAux(BinaryNode<T> *node);
BinaryNode<T>*rightRotation(BinaryNode<T>* axisNode);
BinaryNode<T>*leftRotation(BinaryNode<T>* axisNode);

};
#include "AVLBinaryTree.hxx"
#endif //AVLBinaryTree_h
