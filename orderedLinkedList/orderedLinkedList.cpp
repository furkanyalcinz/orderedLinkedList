//22 34 56 22 89 90 0 14 56 11 34 55 -999

/*
******************
*  Furkan YALÇIN *
*  20181701039   *
*                *
* ****************/



#include <iostream>
#include "orderedLinkedList.h"

using namespace std;

int main()
{
    orderedLinkedList<int> list1;
    
    //********************
    list1.insert(22);  //*
    list1.insert(34);  //*
    list1.insert(89);  //*
    list1.insert(90);  //*
    list1.insert(0);   //*  These are our list. 
    list1.insert(14);  //*
    list1.insert(56);  //*
    list1.insert(11);  //*
    list1.insert(34);  //*
    list1.insert(55);  //*
    list1.insert(-999);//*
    //********************
    list1.insert(34); // in this line we try to add an element whic is already exist in the list1
    list1.insert(0);  // in this line we try to add an element whic is already exist in the list1
    list1.insert(22); // in this line we try to add an element whic is already exist in the list1
    list1.print(); // in this line we printing the list1
    return 0;
}