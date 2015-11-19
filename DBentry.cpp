/* 
 * File:   DBentry.cpp
 * Author: catherinehuang
 * 
 * Created on November 11, 2015, 9:38 PM
 */

#include "DBentry.h"
using namespace std; 

DBentry::DBentry(string name_, unsigned int IPaddr_, bool active_){
    name = name_;
    IPaddr = IPaddr_;
    active = active_;
}

DBentry::DBentry(const DBentry& orig) {
}

DBentry::~DBentry() {
    cout << "delete an entry" << endl;
}

void DBentry::setActive(bool active_){
    active = active_;
}

void DBentry::setIPaddr(unsigned int IPaddr_){
    IPaddr = IPaddr_;
}

void DBentry::setName(string name_){
    name = name_;
}

bool DBentry::getActive() const{
    return active;
}

unsigned int DBentry::getIPaddr() const{
    return IPaddr;
}

string DBentry::getName() const{
    return name;
}

ostream& operator << (ostream& out, const DBentry& rhs){
    string active_ = rhs.active ? "active" : "inactive";
    out << rhs.name << " : " << rhs.IPaddr << " : " << active_ << endl;
    return out;
}