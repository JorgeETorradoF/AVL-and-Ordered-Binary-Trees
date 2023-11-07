#ifndef AVLBinaryTree_hxx
#define AVLBinaryTree_hxx
#include "AVLBinaryTree.h"
template<class T>
AVLBinaryTree<T>::AVLBinaryTree()
{
  this-> root = nullptr;
}
template<class T>
AVLBinaryTree<T>::~AVLBinaryTree()
{
  delete this->root;
}
template<class T>
BinaryNode<T>* AVLBinaryTree<T>::getRoot()
{
  return this->root;
}
template<class T>
bool AVLBinaryTree<T>::isEmpty()
{
  return this->root == nullptr;
}
template<class T>
bool AVLBinaryTree<T>::isLeaf(BinaryNode<T>* node)
{
  return (node->getRightChild() == nullptr && node->getLeftChild() == nullptr);
}
template<class T>
int AVLBinaryTree<T>::getHeight(BinaryNode<T>* node)
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
bool AVLBinaryTree<T>::addNode(T value) {
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
  AVLBalancing();
  return added;
}
template<class T>
bool AVLBinaryTree<T>::deleteNode(T value)
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
    // now I have the node, so lets check from the dad if its a right or left child
    if(value < dad->getData())
    {
      isRightChild = false; 
    }
    //I already know whether its left or right child, so let's evalute the 3 cases: no children, 1 child, 2 children
    //case 0 children (leaf)
    if(isLeaf(auxNode))
    {
      if(this->root->getData() == value)
      {
        this->root = nullptr;
      }
      else
      {
        if(isRightChild)
          dad->deleteRightChild();
        else
          dad->deleteLeftChild();
      }
    }
    //case 1 child
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
      //case 2 children
    if(auxNode->getLeftChild() != nullptr && auxNode->getRightChild() != nullptr)
    {
        T newValue = getBiggestData(auxNode->getLeftChild())->getData();
        if(this->root->getData() == value)
        {
            newValue = getBiggestData(this->root->getLeftChild())->getData();
            deleteNode(newValue);
            this->root->setData(newValue);
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
    AVLBalancing();
    return deleted;
}
template <typename T>
void AVLBinaryTree<T>::preOrderAux(BinaryNode<T> *node, std::list<T>* treeList)
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
void AVLBinaryTree<T>::inOrderAux(BinaryNode<T>*node, std::list<T>* treeList) {
    if (node != nullptr){
      inOrderAux(node->getLeftChild(), treeList);
      treeList->push_back(node->getData());
      inOrderAux(node->getRightChild(), treeList);
    }
}

template <class T>
void AVLBinaryTree<T>::postOrderAux(BinaryNode<T> *node, std::list<T>* treeList) 
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
std::list<T> AVLBinaryTree<T>::preOrder()
{
    std::list<T> list;
    preOrderAux(this->root, &list);
    return list;
}

template <class T>
std::list<T> AVLBinaryTree<T>::inOrder()
{
    std::list<T> list;
    inOrderAux(this->root, &list);
    return list;
}

template <class T>
std::list<T> AVLBinaryTree<T>::postOrder()
{
    std::list<T> list;

    postOrderAux(this->root, &list);

    return list;
}
template<class T>
bool AVLBinaryTree<T>::findNode(T value)
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
BinaryNode<T>* AVLBinaryTree<T>::getBiggestData(BinaryNode<T>* node)
{
  BinaryNode<T>* current = node;
    while (current->getRightChild() != nullptr)
        current = current->getRightChild();
     
    return (current);
}
template<class T>
int AVLBinaryTree<T>::heightDifference(BinaryNode<T>* node1, BinaryNode<T>* node2)
{
  return (getHeight(node1)-getHeight(node2));
}
template<class T>
BinaryNode<T>* AVLBinaryTree<T>::rightRotation(BinaryNode<T>* axisNode)
{
  BinaryNode<T>* auxAxis = axisNode;
  axisNode = axisNode->getLeftChild();
  auxAxis->setLeftChild(axisNode->getRightChild());
  axisNode->setRightChild(auxAxis);
  return axisNode;
}
template<class T>
BinaryNode<T>* AVLBinaryTree<T>::leftRotation(BinaryNode<T>* axisNode)
{
  BinaryNode<T>* auxAxis = axisNode;
  axisNode = axisNode->getRightChild();
  auxAxis->setRightChild(axisNode->getLeftChild());
  axisNode->setLeftChild(auxAxis);
  return axisNode;
}
template <typename T>
BinaryNode<T>* AVLBinaryTree<T>::AVLBalancingAux(BinaryNode<T> *node)
{
    if (node == nullptr)
    {
        return node;
    }
    node->setLeftChild(AVLBalancingAux(node->getLeftChild()));
    node->setRightChild(AVLBalancingAux(node->getRightChild()));
    int heightDiff = heightDifference(node->getLeftChild(),node->getRightChild());
      if(heightDiff > 1)
      {
      //left bigger than right
        int heightDiffAux = heightDifference(node->getLeftChild()->getLeftChild(),node->getLeftChild()->getRightChild());
        if(heightDiffAux >=0)
        {
          //rotate right
          node = rightRotation(node);
        }
        else
        {
          //rotate child to left and dad to right
          node->setLeftChild(leftRotation(node->getLeftChild()));
          node = rightRotation(node);
        }
        
      }
      if(heightDiff < -1)
      {
      //right bigger than left
         int heightDiffAux = heightDifference(node->getRightChild()->getLeftChild(),node->getRightChild()->getRightChild());
         if(heightDiffAux <0)
        {
          //rotate left
          node = leftRotation(node);
        }
        else
        {
          //rotate child to right and dad to left
          node->setRightChild(rightRotation(node->getRightChild()));
          node = leftRotation(node);
        }
      } 
    return node;
}
template<class T>
void AVLBinaryTree<T>::AVLBalancing() {
    // Start from the root and traverse up to the root's parent
    this->root = AVLBalancingAux(this->root);
}
#endif //AVLBinaryTree_hxx
