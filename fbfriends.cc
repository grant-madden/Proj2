#include "fbfriends.h"
#include<iostream>
#include<string>
#include<fstream>
#include <iostream>
using namespace std;

FBFriends::FBFriends(){
    used = 0;
    capacity = 5;
    current_index = 0; 
    data = new Friend[capacity];
}

//The functions known as the Big 3
FBFriends::~FBFriends(){

}
FBFriends::FBFriends(const FBFriends& other){
    
}
void FBFriends::operator = (const FBFriends& other){
    return;
}

// Functions for the internal iterator
void FBFriends::start(){
    return;
}
void FBFriends::advance(){
    return;
}
bool FBFriends::is_item(){
    bool tmp;
    return tmp;
}
Friend FBFriends::current(){
    Friend tmp;
    return tmp;
}
void FBFriends::remove_current(){
    return;
}
void FBFriends::insert(const Friend& f){
    Friend tmp;
    if (used == capacity){
        resize();
    }
    if (used < capacity){
        for (int i = used - 1; i >= 0; i--){
            data[i + 1] = data[i];
        }
        data[0] = f;
        used++;
    }   
    
}
void FBFriends::attach(const Friend& f){
    Friend tmp;
    if (used == capacity){
        resize();
    }
    if (used < capacity){
        data[used] = f;
        used++;
    }   
    return;
}
void FBFriends::show_all(ostream& outs)const{
    for (int i = 0; i < used; i++){
        outs << data[i].get_name() << endl;
        outs << data[i].get_bday() << endl;
    }
}
void FBFriends::bday_sort(){
    sort(data, used);
    return;
}
void FBFriends::sort(Friend data[], int count){
    int minIndex;
    for (size_t i = 0; i< count - 1; i++){
        minIndex = indexOfSmallest(data,i, count);
        swap(data[i], data[minIndex]);
    }
}
int FBFriends::indexOfSmallest( Friend data[], int startIndex, int endIndex){
    Friend min = data[startIndex];
    int minIndex = startIndex;
    for (size_t i = startIndex; i < endIndex; i++){
        if (data[i].get_bday() < min.get_bday()){
            min = data[i];
            minIndex = i;
        }
    }
    return minIndex;
}
Friend FBFriends::find_friend(const string& name)const{
    Friend tmp;
    return tmp;
}
bool FBFriends::is_friend(const Friend& f) const{
    bool tmp;
    return tmp;
}
void FBFriends::load(istream& ins){
    int counter = 0;
    int i = 0;
    Friend tmp;
    while (ins.peek() == '\n' || ins.peek() == '\r'){
        ins.ignore();
    }
    while (!ins.eof()){
        if (used == capacity){
        resize();
    }
        ins >> tmp;
        data[i] = tmp;
        used++;
        i++;   
    }
    used -= 1;
    return;
}
void FBFriends::save(ostream& outs){
    for (int i = 0; i < used; i++){
        outs << data[i].get_name() << endl;
        outs << data[i].get_bday() << endl;
    }
    return;
}
void FBFriends::resize(){
    Friend *tmp; 
    tmp = new Friend[capacity + 5];
    capacity += 5;
    for (int i = 0; i < used; i++){
        tmp[i] = data[i];
    }
    delete [] data;
    data = tmp;
    return;
} // increases the capacity of the container by 5
