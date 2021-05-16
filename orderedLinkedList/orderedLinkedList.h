#ifndef H_orderedListType
#define H_orderedListType
 
/*
******************
*  Furkan YAL�IN *
*  20181701039   *
*                *
* ****************/



//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an ordered linked list. This class is
// derived from the class linkedListType. 
//***********************************************************
#include <iostream>
#include "linkedList.h"
#include "stdio.h"
#include <string>
using namespace std;

template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the list, 
    //    otherwise the value false is returned.

    void insert(const Type& newItem);
    //Function to insert newItem in the list.
    //Postcondition: first points to the new list, newItem 
    //    is inserted at the proper place in the list, and
    //    count is incremented by 1.

    void insertFirst(const Type& newItem);
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //    inserted at the beginning of the list, last points
    //    to the last node in the list, and count is incremented
    //    by 1.

    void insertLast(const Type& newItem);
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem 
    //    is inserted at the end of the list, last points to the
    //    last node in the list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem
    //    is deleted from the list; first points to the first
    //    node of the new list, and count is decremented by 1.
    //    If deleteItem is not in the list, an appropriate 
    //    message is printed.
};


template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type>* current; //pointer to traverse the list

    current = this->first;  //start the search at the first node

    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;

    if (found)
        found = (current->info == searchItem); //test for equality

    return found;
}//end search

//*****************************************************************************//
//*****************************************************************************//
//*****************************************************************************//
//*****************************************************************************//
template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type>* current = NULL; //pointer to traverse the list
    nodeType<Type>* trailCurrent = NULL; //pointer just before current
    nodeType<Type>* newNode = NULL;  //pointer to create a node
    bool found;

    newNode = new nodeType<Type>; // I created the node,
    newNode->info = newItem;   //store newItem in the node,
    newNode->link = NULL;      //set the link field of the node to NULL


    if (this->first == NULL) // with this statement, I create new nodes for last and first
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;

        nodeType<Type>* temp = current;

        /*This is a while loop.
         * It iterates over the list to check if the element is already exit in the list,
         * then it sets found to true.*/

        while (temp != NULL && !found) //It searches the list.
        {
            if (temp->info == newItem) // whit this statement if an element is exist this statement become active and the elemenet wont add the list
            {
                found = true;
                cout <<to_string(newItem) + " element is already found in the list" << endl;
            }
            else
                temp = temp->link;

        }

        //This statement checks if element is not found in the list then this statement will add the list.
        if (!found)
        {
            trailCurrent = current;
            current = current->link;

            if (current == this->first)
            {
                newNode->link = this->first;
                this->first = newNode;
                this->count++;
            }
            else
            {
                trailCurrent->link = newNode;
                newNode->link = current;

                if (current == NULL)
                    this->last = newNode;

                this->count++;
            }
        }

    }//end else
}//end insert
//*****************************************************************************//
//*****************************************************************************//
//*****************************************************************************//
//*****************************************************************************//

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current; //pointer to traverse the list
    nodeType<Type>* trailCurrent; //pointer just before current
    bool found;
    trailCurrent = NULL;
    if (this->first == NULL) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = this->first;
        found = false;

        while (current != NULL && !found)  //search the list
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == NULL)   //Case 4
            cout << "The item to be deleted is not in the "
            << "list." << endl;
        else
            if (current->info == deleteItem) //the item to be 
                                   //deleted is in the list
            {
                if (this->first == current)       //Case 2
                {
                    this->first = this->first->link;

                    if (this->first == NULL)
                        this->last = NULL;

                    delete current;
                }
                else                         //Case 3
                {
                    trailCurrent->link = current->link;

                    if (current == this->last)
                        this->last = trailCurrent;

                    delete current;
                }
                this->count--;
            }
            else                            //Case 4
                cout << "The item to be deleted is not in the "
                << "list." << endl;
    }
}
//end deleteNode


#endif