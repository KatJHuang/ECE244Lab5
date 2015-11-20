/* 
 * File:   TreeDB.cpp
 * Author: catherinehuang
 * 
 * Created on November 15, 2015, 7:44 PM
 */

#include "TreeDB.h"
#include <cstdlib>

using namespace std; 

TreeDB::TreeDB() {
    root = NULL;
    probesCount = 0;
}

TreeDB::TreeDB(const TreeDB& orig) {
}

TreeDB::~TreeDB() {
}

DBentry* TreeDB::find(string name){
    return findHelper(name, root);
}

DBentry* TreeDB::findHelper(string name, TreeNode* node){
    probesCount++;
    if (node == NULL)
        return NULL;
//    cout << "find: addr of current node = " << node << endl;
//    cout << "find: inside node = " << *(node->getEntry()) ;
    if (node->getEntry()->getName() == name)
        return node->getEntry();
    if (node->getEntry()->getName() > name){
        //recursion through left tree
        return findHelper (name, node->getLeft());
    }
    if (node->getEntry()->getName() < name){
        //recursion through left tree
        return findHelper (name, node->getRight());
    }
    return NULL;
}

bool TreeDB::insert(DBentry* newEntry){
    if (root == NULL){
        root = new TreeNode (newEntry);
        return true;
    }
    return insertHelper(newEntry, root);
}

bool TreeDB::insertHelper(DBentry* entry, TreeNode *node){
    
//    cout << "insert: goint down" << endl;
    cout << *entry ;
    
    if (entry->getName() == node->getEntry()->getName()){
        delete entry;
        return false;
    }
    
    if (entry->getName() < node->getEntry()->getName()){
        //go to left subtree
        if (node->getLeft() == NULL){
            node->setLeft(new TreeNode(entry));
            return true;
        }
        else{
            return insertHelper(entry, node->getLeft());
        }
    }
    else{
        //go to right subtree
        if (node->getRight() == NULL){
            node->setRight(new TreeNode(entry));
            return true;
        }
        else{
            return insertHelper(entry, node->getRight());
        }
    }
}

void TreeDB::remove(string name){
    TreeNode *node = removeHelper(name, root);
}

TreeNode* TreeDB::removeHelper(string name, TreeNode* node){
    //if node is null - end of the tree
    if (node == NULL) 
        return NULL;
    if (name < node->getEntry()->getName()){
        //if you are less than me, go to my left 
        node->setLeft(removeHelper(name, node->getLeft()));
        return node;
    }
    if (name > node->getEntry()->getName()){
        //if you are more than me, go to my right 
        node->setRight(removeHelper(name, node->getRight()));
        return node;
    }
    //when it gets to this point, name is matched with an existing entry
    //now find my replacement from right subtree
    if (node->getRight() != NULL){
        node->getEntry()->setName(findMin(node->getRight()));
        //steal the identity of that poor leaf node who will be mercilessly killed 
        //after it's exploited
        node->setRight(removeHelper(node->getEntry()->getName(), node->getRight()));
        //now find the residence of that node, and stand at its door
        return node;
    }
    //there's no right subtree
    //go check my left subtree and find the biggest in there
    if (node->getLeft() != NULL){
        node->getEntry()->setName(findMax(node->getLeft()));
        node->setLeft(removeHelper(node->getEntry()->getName(), node->getLeft()));
        return node;
    }
    
    delete node;
    //assassinate the leaf node
    return NULL;
    //bye
}

string TreeDB::findMax(TreeNode* node) const{
    if (node->getRight() == NULL)
        return node->getEntry()->getName();
    return findMax(node->getRight());
}

string TreeDB::findMin(TreeNode* node) const{
    if (node->getLeft() == NULL)
        return node->getEntry()->getName();
    return findMin(node->getLeft());
}

void TreeDB::print() const{
    cout << "going to print" << endl;
    printHelper (root);
}

void TreeDB::printHelper(TreeNode* node) const{
    if (node == NULL) // stops when you reach the end from a branch
        return;
    printHelper(node->getLeft());
    cout << *(node->getEntry());
    printHelper(node->getRight());
}

void TreeDB::countActive() const{
    int num;
    num = countActiveHelper(root);
    cout << "count active: " << num << endl;    
}

int TreeDB::countActiveHelper(TreeNode* node) const{
    if(node == NULL) //tree is empty
        return 0;
    else if (node->getLeft() == NULL && node->getRight() == NULL)
        //I'm a leaf
        if(node->getEntry()->getActive())
            return 1;
        else 
            return 0;
    else{
        if (node->getEntry()->getActive())
            return countActiveHelper(node->getLeft()) + countActiveHelper(node->getRight()) + 1;
        return countActiveHelper(node->getLeft()) + countActiveHelper(node->getRight());
    }
}

void TreeDB::printProbes(){
    cout << probesCount << endl;
    probesCount = 0;
}

void TreeDB::removeAll(){
    if (root != NULL)
        removeHelper(root);
}

void TreeDB::removeAllHelper(TreeNode* node){
    //stopping condition 
    if (node == NULL){
        return;
    }
    removeAllHelper(node->getLeft());
    removeAllHelper(node->getRight());
    delete node;
    node = NULL;
}