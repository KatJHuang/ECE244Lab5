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
    DBentry* findHelper (string name, TreeNode *node); /////
    void remove (string name); 
    TreeNode* removeHelper (string name, TreeNode *node); 
    bool insert(DBentry* newEntry); /////
    bool insertHelper(DBentry *entry, TreeNode *node); /////
    
    void clear();
    void printProbes();
    string findMin(TreeNode* node) const;
    string findMax(TreeNode* node) const;
    void print() const;
    void printHelper(TreeNode* node) const;
    void countActive () const;
    int countActiveHelper (TreeNode* node) const;
    void removeAll();
    void removeAllHelper(TreeNode* node);
    
//    friend ostream& operator << (ostream& out, TreeNode* rhs);
    //prints out the entire tree in ascending order
    
private:
    TreeNode *root;
    int probesCount;
    int activeCount; 
};

//ostream& operator << (ostream& out, TreeNode* rhs);

#endif	/* TREEDB_H */

