/* 
 * File:   TreeNode.h
 * Author: catherinehuang
 *
 * Created on November 11, 2015, 10:08 PM
 */

#ifndef TREENODE_H
#define	TREENODE_H
#include "DBentry.h"

class TreeNode {
public:
    TreeNode(DBentry* entry_ptr_);
    TreeNode(const TreeNode& orig);
    virtual ~TreeNode();
    
    void setLeft (TreeNode *left_);
    void setRight (TreeNode *right_);
    void setEntry (DBentry* entry_);
   
    TreeNode* getLeft() const;
    TreeNode* getRight() const;
    DBentry* getEntry() const;
    
private:
    DBentry *entry_ptr;
    TreeNode *left, *right;
};

#endif	/* TREENODE_H */

