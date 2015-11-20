///* 
// * File:   TreeTest.cpp
// * Author: catherinehuang
// *
// * Created on November 18, 2015, 11:19 PM
// */
//
//#include <cstdlib>
//
//#include "TreeDB.h"
//#include "DBentry.h"
//
//using namespace std;
//
///*
// * 
// */
//int main(int argc, char** argv) {
//    TreeDB db;
//    DBentry *dbe = new DBentry ("www.mcgill.ca", 1303, true);
//    db.insert(dbe);
//    dbe = new DBentry ("www.google.ca", 7777, true);
//    db.insert(dbe);
//    dbe = new DBentry ("www.utoronto.ca", 7777, true);
//    db.insert(dbe);
//    dbe = new DBentry ("www.loo.ca", 7777, true);
//    db.insert(dbe);
//    dbe = new DBentry ("www.ms.ca", 1318, false);
//    db.insert(dbe);
//    dbe = new DBentry ("www.apple.ca", 1111, true);
//    db.insert(dbe);
//    dbe = new DBentry ("www.apple.ca", 1111, true);
//    db.insert(dbe);
//    
//    cout << "\nnumber of active sites: ";
//    db.countActive();
//    db.print();
//    
//    cout <<"\n# of probes in finding www.ms.ca = ";
//    cout << *(db.find("www.ms.ca"));
//    db.printProbes();
//    
//    cout << "\nremoving mcgill from the list";
//    db.remove("www.mcgill.ca");
//    cout << "removed mcgill and show the rest" << endl;
//    db.print();
//    
//    //find google
//    cout << endl;
//    if (!db.find("www.mcgill.ca"))
//        cout << "www.mcgill.ca is not found" << endl;
//    
//    //update
//    cout << "\nUpdating google to inactive" << endl;
//    DBentry *dbe1 = db.find("www.google.ca");
//    dbe1->setActive(false);
//    cout << *db.find("www.google.ca");
//    dbe1->setActive(true);
//    cout << *db.find("www.google.ca");
//    //deleting all
//    cout << "\ndeleting all nodes" << endl;
//    db.removeAll();
//    
//    cout <<"\nprint after all has been deleted: " << endl;
//    db.print();
//    
//    return 0;
//}
//
