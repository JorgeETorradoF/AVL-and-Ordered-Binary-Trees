#ifndef OrderedBinaryTree_hxx
#define OrderedBinaryTree_hxx
#include "OrderedBinaryTree.h"
template<class T>
OrderedBinaryTree<T>::OrderedBinaryTree()
{
  this-> root = nullptr;
}
template<class T>
OrderedBinaryTree<T>::~OrderedBinaryTree()
{
  delete this->root;
}
template<class T>
BinaryNode<T>* OrderedBinaryTree<T>::getRoot()
{
  return this->root;
}
template<class T>
bool OrderedBinaryTree<T>::isEmpty()
{
  return this->root == nullptr;
}
template<class T>
bool OrderedBinaryTree<T>::isLeaf(BinaryNode<T>* node)
{
  return (node->getRightChild() == nullptr && node->getLeftChild() == nullptr);
}
template<class T>
int OrderedBinaryTree<T>::getHeight(BinaryNode<T>* node)
{
  if (node == nullptr)
  {
    return -1;
  }
  int rightHeight = getHeight(node->getRightChild());
  int leftHeight = getHeight(node->getLeftChild());
  if(rightHeight<leftHeight)
    return leftHeight + 1;
  else
    return rightHeight + 1;
}

template <class T>
bool OrderedBinaryTree<T>::addNode(T value) {
  BinaryNode<T>* node = this->root;
  BinaryNode<T>* dad = this->root;
  bool added = false;
  bool duplicated = false;

  if (this->root == nullptr) {
    this->root = new BinaryNode<T>(value);
    added = true;
    return added;
  }

  while (node != nullptr) {
    dad = node;  

    if (value < node->getData()) {
      node = node->getLeftChild();
    } else if (value > node->getData()) {
      node = node->getRightChild();
    } else {
      duplicated = true;
      break;
    }
  }

  if (!duplicated) {
    BinaryNode<T>* auxNode = new BinaryNode<T>(value);
    if (auxNode != nullptr) {
      if (value < dad->getData())
        dad->setLeftChild(auxNode);
      else
        dad->setRightChild(auxNode);
    }
    added = true;
  }

  return added;
}
template<class T>
bool OrderedBinaryTree<T>::deleteNode(T value)
{
  bool deleted = false;
  bool isRightChild = true;
  BinaryNode<T>* auxNode = this->root;
  BinaryNode<T>* dad = this->root;
  if(findNode(value))
  {
    while(auxNode!= nullptr)
      {
        if (value < auxNode->getData()) 
        {
          dad = auxNode;
          auxNode = auxNode->getLeftChild();
        } else if (value > auxNode->getData()) 
        {
          dad = auxNode;
          auxNode = auxNode->getRightChild();
        } else {
        break;
        }
      }
    //ahora que tenemos el nodo, desde el papa miramos si el nodo es hijo derecho o izquierdo
    if(value < dad->getData())
    {
      isRightChild = false; 
    }
    //ya identifique si es derecho o no, ahora debo evaluar los 3 casos, hoja, 1 hijo o 2 hijos
    //caso hoja
    if(isLeaf(auxNode))
    {
      if(this->root->getData() == value)
      {
        this->root = nullptr;
        delete this->root;
      }
      else
      {
        if(isRightChild)
          dad->deleteRightChild();
        else
          dad->deleteLeftChild();
      }
    }
    //caso 1 hijo
    if(auxNode->getLeftChild() == nullptr && auxNode->getRightChild() != nullptr)
    { 
      if(this->root->getData() == value)
      {
        this->root = this->root->getRightChild();
      }
      else
      {
        if(isRightChild)
        {
          dad->setRightChild(auxNode->getRightChild());
        }
        else
        {
          dad->setLeftChild(auxNode->getRightChild());
        }
      }
    }
    if(auxNode->getLeftChild() != nullptr && auxNode->getRightChild() == nullptr)
    {
      if(this->root->getData() == value)
      {
        this->root = this->root->getLeftChild();
      }
      else
      {
        if(isRightChild)
        {
          dad->setRightChild(auxNode->getLeftChild());
        }
        else
        {
            dad->setLeftChild(auxNode->getLeftChild());
        }
      }
    }
      //caso 2 hijos
    if(auxNode->getLeftChild() != nullptr && auxNode->getRightChild() != nullptr)
    {
        T newValue = getBiggestData(auxNode->getLeftChild())->getData();
        if(this->root->getData() == value)
        {
            auxNode = this->root->getLeftChild();
            deleteNode(auxNode->getData());
            this->root->setData(getBiggestData(auxNode)->getData());
        }
        else
        {
          if(isRightChild)
          {
              deleteNode(newValue);
              dad->getRightChild()->setData(newValue);
          }
          else
          {  
               deleteNode(newValue);
               dad->getLeftChild()->setData(newValue);
          }
        }
    }
    deleted = true;
}
    return deleted;
}
template <typename T>
void OrderedBinaryTree<T>::preOrderAux(BinaryNode<T> *node, std::list<T>* treeList)
{
    if (node == nullptr)
    {
        return;
    }

    treeList->push_back(node->getData());
    preOrderAux(node->getLeftChild(), treeList);
    preOrderAux(node->getRightChild(), treeList);
}

template <class T>
void OrderedBinaryTree<T>::inOrderAux(BinaryNode<T>*node, std::list<T>* treeList) {
    if (node != nullptr){
      inOrderAux(node->getLeftChild(), treeList);
      treeList->push_back(node->getData());
      inOrderAux(node->getRightChild(), treeList);
    }
}

template <class T>
void OrderedBinaryTree<T>::postOrderAux(BinaryNode<T> *node, std::list<T>* treeList) 
{
    if (node == nullptr)
    {
        return;
    }

    postOrderAux(node->getLeftChild(), treeList);
    postOrderAux(node->getRightChild(), treeList);
    treeList->push_back(node->getData());
}
template <class T>
std::list<T> OrderedBinaryTree<T>::preOrder()
{
    std::list<T> list;
    preOrderAux(this->root, &list);
    return list;
}

template <class T>
std::list<T> OrderedBinaryTree<T>::inOrder()
{
    std::list<T> list;
    inOrderAux(this->root, &list);
    return list;
}

template <class T>
std::list<T> OrderedBinaryTree<T>::postOrder()
{
    std::list<T> list;

    postOrderAux(this->root, &list);

    return list;
}
template<class T>
bool OrderedBinaryTree<T>::findNode(T value)
{
  bool found = false;
  BinaryNode<T>*auxNode = this->root;
  while(auxNode != nullptr)
    {
      if (value < auxNode->getData()) {
      auxNode = auxNode->getLeftChild();
      } else if (value > auxNode->getData()) {
      auxNode = auxNode->getRightChild();
      } else {
      found = true;
      break;
      }
    }
  return found;
}
template<class T>
BinaryNode<T>* OrderedBinaryTree<T>::getBiggestData(BinaryNode<T>* node)
{
  BinaryNode<T>* current = node;
    while (current->getRightChild() != nullptr)
        current = current->getRightChild();
     
    return (current);
}
#endif //OrderedBinaryTree_hxx