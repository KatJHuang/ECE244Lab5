/* 
 * File:   DBentry.h
 * Author: catherinehuang
 *
 * Created on November 11, 2015, 9:38 PM
 */

#ifndef DBENTRY_H
#define	DBENTRY_H

#include <string>
#include <iostream>
using namespace std;

class DBentry {
public:
    DBentry(string name_, unsigned int IPaddr_, bool active_);
    DBentry(const DBentry& orig);
    virtual ~DBentry();
    
    void setName(string name_);
    void setIPaddr(unsigned int IPaddr_);
    void setActive (bool active_);
    
    string getName() const;
    unsigned int getIPaddr() const;
    bool getActive() const;
    
    friend ostream& operator << (ostream& out, const DBentry& rhs);
    //to output the entry in the format - name : IPaddr : active
private:
    string name;
    unsigned int IPaddr;
    bool active;
};

ostream& operator << (ostream& out, const DBentry& rhs);
#endif	/* DBENTRY_H */

