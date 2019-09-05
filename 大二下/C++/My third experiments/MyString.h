//
//  MyString.h
//  MyString
//
//  Created by Patric on 2018/3/29.
//  Copyright © 2018年 BIT.CS. All rights reserved.
//

#ifndef MyString_h
#define MyString_h
#include <stdio.h>
using namespace std;
class MyString{     //define the class
private:
    char* string;       //the head of string
    int string_length;  //the length of string
    int size;       //the size of array
    int increase;   //the step of increase
public:
    MyString(); //default constructor
    MyString(const char*);  //constructor by char*
    ~MyString();
    MyString(const MyString&);      //copy constructor
    void extend();      //extend function
    friend MyString operator+(const MyString&,const MyString&);     //overload of +
    MyString& operator=(const MyString&);   //overload of =
    int Find(char,int);       //find the index of NO.i char
    MyString Mid(int a,int b);          //find mid between a and b
    int MyStringLen();          //count the len of string
    int count(char);            //count the number of chr
    friend ostream& operator<<(ostream&,const MyString&);       //overload <<
};

MyString::MyString(){       //default construcor
    string=new char[100];           //set the initialsize is 100
    size=100;
    increase=100;
    string_length=0;
    string[0]='\0';
}

MyString::MyString(const char* S){  //initial by a char*
    size=100;
    increase=100;
    int len=0;
    for (int i=0; S[i]!='\0'; i++) {
        len++;
    }
    while (len>size) {
        this->extend();
    }
    string=new char[100];
    if (S==NULL) {
        string_length=0;
    }
    else{
        int i;
        for (i=0; S[i]!='\0'; i++) {            //copy the string
            string[i]=S[i];
        }
        string[i]='\0';
        string_length=i;
    }
}

MyString::~MyString(){      //destructor
    if (string!=NULL) {
        delete []string;
    }
}

MyString::MyString(const MyString& S){          //copy-constructor
    string=new char[S.size];
    for (int i=0; i<=S.string_length; i++) {
        string[i]=S.string[i];          //copy to the new string
    }
    string_length=S.string_length;
    size=S.size;
    increase=S.increase;
}

void MyString::extend(){
    size=size+increase;             //extend the string size
    char* newstring;
    newstring=new char[size];
    for (int i=0; i<string_length; i++) {
        newstring[i]=string[i];         //copy to new size
    }
    delete []string;            //delete temp
    string=newstring;
}

MyString operator+(const MyString& S,const MyString& s){
    MyString newString(S);
    while (newString.size-newString.string_length<s.string_length) {
        newString.extend();         //judge the size and extend it
    }
    for (int i=0; i<s.string_length; i++) {
        newString.string[newString.string_length]=s.string[i];  //cat the string
        newString.string_length++;
    }
    return newString;
}

MyString& MyString::operator=(const MyString& S){
    int i;
    if (size<S.string_length) {
        this->extend();     //judge the size and extend it
    }
    for (i=0; i<S.string_length; i++) {
        string[i]=S.string[i];          //copy to the new string
    }
    string[i]='\0';
    string_length=i;
    return *this;
}

MyString MyString::Mid(int a, int b){   //mid function find the string between a and b
    MyString temp;
    char* p;
    p=new char[this->size];         //define a new string to be temp string
    for (int i=a,j=0; i<=b; i++,j++) {
        p[j]=string[i];         //copy string to p
    }
    temp=p;         //construct the temp
    delete []p;
    return temp;
}

int MyString::MyStringLen(){
    return this->string_length;
}

ostream& operator<<(ostream& os,const MyString& s){//overload the <<
    os<<s.string;
    return os;
}

int MyString::count(char x){        //count the char in stirng
    int count=0;
    for (int i=0; i<string_length; i++) {
        if (string[i]==x) {
            count++;
        }
    }
    return count;
}

int MyString::Find(char c, int x=1){            //find the No.x char in string
    for (int i=0; i<string_length; i++) {       //x is default as first one
        if (string[i]==c) {
            x--;
        }
        if (x==0) {
            return i;
        }
    }
    return -1;
}


#endif /* MyString_h */

