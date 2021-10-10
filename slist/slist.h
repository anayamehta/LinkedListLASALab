#include <iostream>
#include <string>
#ifndef SLIST_H
#define SLIST_H

using namespace std;

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    string ident;
    string type;
    string name;
    double elevation_ft;
    string continent;
    string iso_country;
    string iso_region;
    string municipality;
    string gps_code;
    string iata_code;
    string local_code;

};

class Node
{
public:
    Node* next;
    Airport data;
};


class slist {
  public:
    int length;
    Node* head;

    slist();
    //~slist();
    void add(Airport value);				//Adds a new value to the end of this list.
    void clear();					//Removes all elements from this list.
    bool equals(slist list);				//Returns true if the two lists contain the same elements in the same order.
    Airport get(int index);				//Returns the element at the specified index in this list.
    void insert(int index, Airport value);		//Inserts the element into this list before the specified index.
    void exchg(int index1, int index2);		//Switches the payload data of specified indexex.
    int swap(int index1, int index2);	    //Swaps node located at index1 with node at index2
    bool isEmpty();				    //Returns true if this list contains no elements.
    //void mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.
    void remove(int index);			    //Removes the element at the specified index from this list.
    void set(int index, Airport value);	        //Replaces the element at the specified index in this list with a new value.
    int size();					    //Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

    string toString();				//Converts the list to a printable string representation.

};



#endif // SLIST_H_INCLUDED
