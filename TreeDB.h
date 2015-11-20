/* 
 * File:   TreeDB.h
 * Author: catherinehuang
 *
 * Created on November 15, 2015, 7:44 PM
 */

#ifndef TREEDB_H
#define	TREEDB_H
#include "TreeNode.h"

class TreeDB {
public:
    TreeDB();
    TreeDB(const TreeDB& orig);
    virtual ~TreeDB();
    //delete all entries in the tree
    DBentry* find (string name); /////
    void remove (string name); 
    bool insert(DBentry* newEntry); /////
    
    void clear();
    void printProbes();
    DBentry* findMin(TreeNode* node) const;
    DBentry* findMax(TreeNode* node) const;
    void print() const;
    void countActive () const;
    void removeAll();
    
//    friend ostream& operator << (ostream& out, TreeNode* rhs);
    //prints out the entire tree in ascending order
    
private:
    TreeNode *root;
    int probesCount;
    int activeCount;
    DBentry* findHelper (string name, TreeNode *node); /////
    bool insertHelper(DBentry *entry, TreeNode *node); /////
    void printHelper(TreeNode* node) const; 
    TreeNode* removeHelper (string name, TreeNode *node); 
    void removeAllHelper(TreeNode* node);
    int countActiveHelper (TreeNode* node) const;
};

//ostream& operator << (ostream& out, TreeNode* rhs);

#endif	/* TREEDB_H */

