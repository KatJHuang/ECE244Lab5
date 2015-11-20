/* 
 * File:   TreeNode.cpp
 * Author: catherinehuang
 * 
 * Created on November 11, 2015, 10:08 PM
 */

#include "TreeNode.h"

TreeNode::TreeNode(DBentry* entry_ptr_){
    left = NULL;
    right = NULL;
    entry_ptr = entry_ptr_;
}

TreeNode::TreeNode(const TreeNode& orig) {
}

TreeNode::~TreeNode() {
//    cout << *entry_ptr;
    delete entry_ptr;
    left = NULL;
    right = NULL;
//    cout << "deleting node" << endl;
//    cout << *entry_ptr;
}

//void setLeft (TreeNode *left_);
//void setRight (TreeNode *right_);
//   
//TreeNode* getLeft() const;
//TreeNode* getRight() const;
//DBentry* getEntry() const;

void TreeNode::setLeft(TreeNode* left_){
    left = left_;
}

void TreeNode::setRight(TreeNode* right_){
    right = right_;
}

void TreeNode::setEntry(DBentry* entry_){
    entry_ptr->setName(entry_->getName());
    entry_ptr->setIPaddr(entry_->getIPaddr());
    entry_ptr->setActive(entry_->getActive());
}

TreeNode* TreeNode::getLeft() const{
    return left;
}

TreeNode* TreeNode::getRight() const{
    return right;
}

DBentry* TreeNode::getEntry() const{
    return entry_ptr;
}

