#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include "slist.h"

/*
Class Library File
*/


// Constructor
slist::slist(){
    this->length = 0;
    this->head = NULL;
}


//Adds a new value to the end of this list.
void slist::add(Airport data) {
    Node *temp=new Node;

    Node* newNode = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        while(temp != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

}

// clear()					//Removes all elements from this list.

void slist::clear(){

    Node *temp=new Node;

    while(head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }

}


//Returns the element at the specified index in this list.
Airport slist::get(int index){
    Node *temp=new Node;
    temp = head;

    int count = 0;
    while (temp != NULL)
    {
        if (count == index)
            return(temp->data);
        count++;
        temp = temp->next;
    }

}

//swap(index1,index2)***		//Swaps node located at index1 with node at index2
int slist::swap(int pos1, int pos2)
{
    Node *node1, *node2, *prev1, *prev2, *temp = new Node;
    int i;

    // Get the far position among both
    const int maxPos = (pos1 > pos2) ? pos1 : pos2;

    // Get total nodes in the list
    const int totalNodes = size();

    // Validate swap positions
    if ((pos1 <= 0 || pos1 > totalNodes) || (pos2 <= 0 || pos2 > totalNodes))
    {
        return -1;
    }

    // If both positions are same then no swapping required
    if (pos1 == pos2)
    {
        return 1;
    }


    // Identify both nodes to swap
    i = 1;
    temp  = head;
    prev1 = NULL;
    prev2 = NULL;

    // Find nodes to swap
    while (temp != NULL && (i <= maxPos))
    {
        if (i == pos1 - 1)
            prev1 = temp;
        if (i == pos1)
            node1 = temp;

        if (i == pos2 - 1)
            prev2 = temp;
        if (i == pos2)
            node2 = temp;

        temp = temp->next;
        i++;
    }

    // If both nodes to swap are found.
    if (node1 != NULL && node2 != NULL)
    {
        // Link previous of node1 with node2
        if (prev1 != NULL)
            prev1->next = node2;

        // Link previous of node2 with node1
        if (prev2 != NULL)
            prev2->next = node1;

        // Swap node1 and node2 by swapping their
        // next node links
        temp        = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        // Make sure to swap head node when swapping
        // first element.
        if (prev1 == NULL)
            head = node2;
        else if (prev2 == NULL)
            head = node1;
    }

    return 1;
}

// size()					//Returns the number of elements in this list.

int slist::size() {

    int nodes = 0;

    while (head != NULL)
    {
        nodes++;
        head = head->next;
    }

    return nodes;
}

// toString()	***			//Converts the list to a printable string representation.

string slist::toString(){
    Node *temp = new Node;

    while (temp != NULL){
        cout << "Code: "<< temp -> data.code;
        cout << "Latitude: " << temp -> data.latitude;
        cout << "Longitude: " << temp -> data.longitude << endl;
        temp = temp -> next;
    }

}
