#ifndef BinaryNode_h
#define BinaryNode_h
template<class T>
class BinaryNode {
public:
   BinaryNode(T value);
    ~BinaryNode();
    T getData(); 
    BinaryNode<T>* getRightChild();
    BinaryNode<T>* getLeftChild();
    void setData(T value);
    void setRightChild(BinaryNode<T>* node);
    void setLeftChild(BinaryNode<T>* node);
    void deleteLeftChild();
    void deleteRightChild();
protected:
    T data;
    BinaryNode<T>* rightChild;
    BinaryNode<T>* leftChild;
};
#include "BinaryNode.hxx"
#endif //BinaryNode_h
