//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array.
 *
 */


#include <iostream>
#include <fstream>
#include <cmath>
#include "slist.h"

using namespace std;





void mergeSort(slist* arr, int l, int r);
void merge(slist* arr, int l, int m, int r);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i = 0;
    char cNum[10] ;
    //Airport* airportArr[13500];			// Replace array with Linked List
    slist *airportList = new slist(); //syntax??
    int   airportCount;
    //Airport* a[13500];

    infile.open ("./USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            Airport *c  = new Airport();s
            infile.getline(c->code, 256, ',');
            infile.getline(cNum, 256, ',');
            c->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            c->latitude = atof(cNum);

            airportList->add(*c);
            delete c;

            //if (!(c % 1000))
                //cout << c->code << " long: " << c->longitude << " lat: " << c->latitude <<  endl;

            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
            }
            */


            //i++;
            //c++;
        }
        airportCount = c-1;
        infile.close();

         /*for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << c->code << " long: " << c->longitude << " lat: " << c->latitude <<  endl;
                cout << airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
                cout <<"Distance between " << airportArr[c]->code << " and " << airportArr[c+1]->code << " is "
                  << distanceEarth( airportArr[c]->longitude, airportArr[c]->latitude , airportArr[c+1]->longitude, airportArr[c+1]->latitude) << endl;
            } */



    }
    else
    {
        cout << "Error opening file";
    }


    for(int i = 0; i < airportList->size(); i++) {
        if(distanceEarth(airportList->get(i).latitude, airportList->get(i).longitude, 97.6664, 30.1975) <= 160.934){
            cout << airportList->get(i).code << airportList->get(i).latitude << airportList->get(i).longitude << endl;
        }
    }

}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/
void mergeSort(slist* arr, int l, int r)
{
    if (l < r){
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void merge(slist* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    slist *L = new slist();
    slist *R = new slist();

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L->get(i) = arr->get(l + i);
    for (j = 0; j < n2; j++)
      R->get(j) = arr->get(m + 1 + j);

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {

        if (distanceEarth(L->get(i).latitude, L->get(i).longitude, 30.1975, 97.6664) <= distanceEarth(R->get(j).latitude, R->get(j).longitude, 30.1975, 97.6664))
        {
            arr->get(k) = L->get(i);
            i++;
        }
        else
        {
            arr->get(k) = R->get(j);
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr->get(k) = L->get(i);
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr->get(k) = R->get(j);
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */



