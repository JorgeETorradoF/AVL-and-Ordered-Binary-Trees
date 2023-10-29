#ifndef BinaryNode_hxx
#define BinaryNode_hxx
#include "BinaryNode.h"
template<class T>
BinaryNode<T>::BinaryNode(T value)
{
  this->data = value;
  this->rightChild = nullptr;
  this->leftChild = nullptr;
}
template<class T>
BinaryNode<T>::~BinaryNode()
{
  delete leftChild;
  delete rightChild;
}
template<class T>
T BinaryNode<T>::getData()
{
  return this->data;
}
template<class T>
BinaryNode<T>* BinaryNode<T>::getRightChild()
{
  return this->rightChild;
}
template<class T>
BinaryNode<T>* BinaryNode<T>::getLeftChild()
{
  return this->leftChild;
}
template<class T>
void BinaryNode<T>::setData(T value)
{
  this->data = value;
}
template<class T>
void BinaryNode<T>::setRightChild(BinaryNode<T>* node)
{
  this->rightChild = node;
}
template<class T>
void BinaryNode<T>::setLeftChild(BinaryNode<T>* node)
{
  this->leftChild = node;
}
template<class T>
void BinaryNode<T>::deleteLeftChild()
{
  this->leftChild = nullptr;
}
template<class T>
void BinaryNode<T>::deleteRightChild()
{
  this->rightChild = nullptr;
}
#endif //BinaryNode_hxx