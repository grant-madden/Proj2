/************************************************
   This is the header file for a class called Friend.
   It holds the information about a single Facebook
   friend, just their name and birthday. It uses a class
   called Date for the storage of the birthday. The member 
   functions are just accessors and input/output functions.
       John Dolan	Spring 2014	Ohio University
***********************************************************/

#include<iostream>
#include<string>
#include "date.h"
#ifndef FRIEND_H
#define FRIEND_H

using namespace std;


class Friend{
    public:
	Friend();
	string get_name()const;
	Date get_bday()const;
	void set_name(string newName);
	void set_bday(Date newBday);
	bool operator == (const Friend& other)const;
	bool operator != (const Friend& other)const;
	void input(istream& ins);
	void output(ostream& outs)const;
    private:
	string name;
	Date bday;
};

istream& operator >>(istream& ins,Friend& f);
ostream& operator <<(ostream& outs,const Friend& f);

#endif
