/* 
 * File:   main.cpp
 * Author: catherinehuang
 *
 * Created on November 11, 2015, 9:37 PM
 */

#include <cstdlib>
#include "TreeDB.h"
#include <string>
#include <sstream>

using namespace std;
string input_line, token;
int word_count;
TreeDB db;

void insert(string&);
void find(string&);
void remove(string&);
void updateStatus(string&);

int countWord(const string);
bool alertWrongNumOfArgs(int, int);
bool confirmInt (string&);

int main(int argc, char** argv) {
    cout << "> ";
    getline(cin, input_line);
    //bunch of pointers that points to actual nodes
    while(!cin.eof()){
        stringstream input_stream(input_line);
        input_stream >> token;
        if (token == "insert"){
            insert(input_line);
        }
        else if (token == "find"){
            find(input_line);
        }
        else if (token == "remove"){
            remove(input_line);
        }
        else if (token == "printall"){
            db.print();
        }
        else if (token == "printprobes"){
            find(input_line);
            db.printProbes();
        }
        else if (token == "removeall"){
            db.removeAll();
        }
        else if (token == "countactive"){
            db.countActive();
        }
        else if (token == "updatestatus"){
            
        }
        else
            cout << "Error: Invalid command" << endl; 
        cout << "> ";

        getline(cin, input_line);
    }   
}

int countWord(const string line){
    int count = 0;
    stringstream s(line);
    string token_holder;
    while (s >> token_holder) 
        //token holder continues to take objects from string stream till it hits the end
        count++;
    return count;
}

bool alertWrongNumOfArgs(int correct_amount, int actual_amount){
    //checks the number of arguments
    //return 1 when the number is incorrect
    if (actual_amount > correct_amount){
        cout << "Too many arguments" << endl;
        return true;
    }
    else if (actual_amount < correct_amount){
        cout << "Too few arguments" << endl;
        return true;
    }
    else
        return false;
}

bool confirmInt (string& token_){//functional
    //check if the input is the integer type 
    
    stringstream token_stream(token);
    if (!isdigit(token_stream.peek())){
        cout << "Error: invalid argument" << endl;
        return false;
    }
    //if the input that's supposed to contain an int contains characters
    //return false and terminate check
    
    int input_int;
    token_stream >> input_int;
    if (token_stream.peek() != -1){
        cout << "Error: invalid argument" << endl;
        return false;
    }
    //if there is a character trailing off the integer,
    //alert error,
    //return false, 
    //and terminate check
    
    return true;
    //up to this point, the input should be of int type
}

void insert(string& input_line_){
    word_count = countWord(input_line_);
    string name;
    int IPaddr;
    bool status = false;
    
    if (alertWrongNumOfArgs(4, word_count))
        return;
    //check if the command has the right number of arguments
    
    stringstream input_stream (input_line_);
    input_stream >> token;
    //token is "insert" now
    
    input_stream >> token;
    //token is now holding the name of website
    name = token;
    
    input_stream >> token;
    //token is now holding the IP of website
    if (!confirmInt(token)){
        cout << "Error: invalid argument" << endl;
    }
    else{
        stringstream token_stream (token);
        token_stream >> IPaddr;
    }
    
    input_stream >> token;
    //token is now holding the status of website
    if (token == "active")
        status = true;
    
    DBentry *dbe = new DBentry (name, IPaddr, status);
//    cout << *dbe;
    if (db.insert(dbe) == true)
        cout << "Success" << endl;
    else
        cout << "Error: entry already exists" << endl;
    db.print();
}

void find(string& input_line_){
    word_count = countWord(input_line_);
    string name;
    
    if (alertWrongNumOfArgs(2, word_count))
        return;
    //check if the command has the right number of arguments
    
    stringstream input_stream (input_line_);
    input_stream >> token;
    //token is "insert" now
    
    input_stream >> token;
    //token is now holding the name of website
    name = token;
    
    DBentry *matching_entry = db.find(name);
    if (matching_entry == NULL)
        cout << "Error: entry does not exist" << endl;
    else
        cout << *matching_entry;
}

void updateStatus(string& input_line_){
    word_count = countWord(input_line_);
    string name;
    bool status = false;
    
    if (alertWrongNumOfArgs(3, word_count))
        return;
    //check if the command has the right number of arguments
    
    stringstream input_stream (input_line_);
    input_stream >> token;
    //token is "insert" now
    
    input_stream >> token;
    //token is now holding the name of website
    name = token;
    
    input_stream >> token;
    //token is now holding the status of website
    if (token == "active")
        status = true;
    
    DBentry *matching_entry = db.find(name);
    if (matching_entry == NULL)
        cout << "Error: entry does not exist" << endl;
    else{
        matching_entry->setActive(status);
        cout << *matching_entry;
    }
}

void remove(string& input_line_){
    word_count = countWord(input_line_);
    string name;
    
    if (alertWrongNumOfArgs(2, word_count))
        return;
    //check if the command has the right number of arguments
    
    stringstream input_stream (input_line_);
    input_stream >> token;
    //token is "insert" now
    
    input_stream >> token;
    //token is now holding the name of website
    name = token;
    
    db.remove(name);
}