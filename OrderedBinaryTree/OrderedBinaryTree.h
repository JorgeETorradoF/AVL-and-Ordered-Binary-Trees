#ifndef OrderedBinaryTree_h
#define OrderedBinaryTree_h
#include "BinaryNode.h"
#include <list>
template<class T>
class OrderedBinaryTree{

private:

BinaryNode<T>* root;

public:

OrderedBinaryTree<T>();
~OrderedBinaryTree<T>();
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

};

#include "OrderedBinaryTree.hxx"
#endif //NodoBinario_h