/*
	Grant Madden
	CS 2401
	2/16/2020
*/
#include "friend.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Friend::Friend(){
    Date tmp(1, 1, 1); 
    name = "";
    bday = tmp;
}
string Friend::get_name()const{
    return name;
}
Date Friend::get_bday()const{
    return bday;
}
bool Friend::operator == (const Friend& other)const{
    if (name == other.get_name() && bday == other.get_bday()){
        return true;
    }
    else {
        return false;
    }
}
bool Friend::operator != (const Friend& other)const{
    if (name == other.get_name() && bday == other.get_bday()){
        return false;
    }
    else {
        return true;
    }
}
void Friend::input(istream& ins){
    if (&ins == &cin){
        cout << "Please enter your friends name and birthday" << endl;
    }
    while (ins.peek() == '\n' || ins.peek() == '\r'){
        ins.ignore();
    }
    getline(ins, name);
    ins >> bday;
}
void Friend::output(ostream& outs)const{
    outs << name << endl;
    outs << bday << endl;
}

istream& operator >>(istream& ins,Friend& f){
    f.input(ins);
    return ins;
}
ostream& operator <<(ostream& outs,const Friend& f){
    f.output(outs);
    return outs;
}
void Friend::set_name(const string newName){
    name = newName;
}
void Friend::set_bday(const Date newBday){
    bday = newBday;
}
