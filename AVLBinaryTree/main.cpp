#include <iostream>
#include "AVLBinaryTree.h"
#include<list>

int main() {
  AVLBinaryTree<int>* intGroot = new AVLBinaryTree<int>();
  
  intGroot->addNode(1);
  intGroot->addNode(5);
  intGroot->addNode(7);
  /*
  intGroot->addNode(10);
  intGroot->addNode(15);
  intGroot->addNode(3);
  intGroot->addNode(5);
  intGroot->addNode(1);
  intGroot->addNode(6);
  intGroot->addNode(0);
  intGroot->addNode(2);
  intGroot->addNode(4);
  intGroot->addNode(-10);
  intGroot->addNode(-15);
  intGroot->addNode(-3);
  intGroot->addNode(-5);
  intGroot->addNode(-1);
  intGroot->addNode(-6);
  intGroot->addNode(-2);
  */
  std::cout <<"\nBiggest node: " << intGroot->getBiggestData(intGroot->getRoot())->getData()<< "\n";
  std::cout <<"\nTree's height: " << intGroot->getHeight(intGroot->getRoot()) <<"\n"; 
  std::cout <<"\nDifference of heights between root's left and right children: " << intGroot->heightDifference(intGroot->getRoot()->getLeftChild(), intGroot->getRoot()->getRightChild()) <<"\n"; 
  std::cout <<"\nIs 3 in the tree? " << intGroot->findNode(3)<<"\n"; 
  std::cout <<"\nIs 10 in the tree? " << intGroot->findNode(10) <<"\n"; 
  std::cout <<"\nIs 100 in the tree? " << intGroot->findNode(100) <<"\n"; 
  std::list<int> tree;
  tree = intGroot->preOrder();
  std::list<int>::iterator it;
  std::cout<<"\nPre Order:\n";
  for (it = tree.begin(); it != tree.end(); ++it) 
  {
    std::cout << *it << " ";
  }
  std::cout<<"\n";
  tree = intGroot->inOrder();
  std::cout<<"\nIn Order:\n";
  for (it = tree.begin(); it != tree.end(); ++it) 
  {
    std::cout << *it << " ";
  }
  std::cout<<"\n";
  tree = intGroot->postOrder();
  std::cout<<"\nPost Order:\n";
  for (it = tree.begin(); it != tree.end(); ++it) 
  {
    std::cout << *it << " ";
  }
  std::cout <<"\n";
  std::cout<<"\nWhat if we kill the 5?\n";
  intGroot->deleteNode(5);
  tree = intGroot->preOrder();
  std::cout<<"\nPre Order:\n";
  for (it = tree.begin(); it != tree.end(); ++it) 
  {
    std::cout << *it << " ";
  }
  std::cout<<"\n";
  std::cout<<"\nWhat if we kill the 1?\n";
  intGroot->deleteNode(1);
  tree = intGroot->preOrder();
  std::cout<<"\nPre Order:\n";
  for (it = tree.begin(); it != tree.end(); ++it) 
  {
    std::cout << *it << " ";
  }
  std::cout<<"\n";
}