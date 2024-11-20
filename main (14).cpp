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
//#include "slist.cpp"

using namespace std;

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};



void simpleSortTotal(Airport* s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    Slist airportArr = new Slist();			// Replace array with Linked List... Still got errors
    int   airportCount;
    //Airport* a[13500];
    
    infile.open ("USAirportCodes.txt", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        bool go = false; 
        while (infile.good())
        {
            
            Airport *temp = new Airport();
            infile.getline(temp->code, 256, ',');
            string test = (string)temp->code; 
            infile.getline(cNum, 256, ',');
            temp->longitude = atof(cNum);
            double test2 = temp->longitude; 
            infile.getline(cNum, 256, '\n');
            temp->latitude = atof(cNum);

            if (c == 0){
              airportArr.header = new Node((void*)temp); 
              //cout<<airportArr.l;
            }
            else{
              airportArr.add((void*)temp);
              Node* t = new Node(temp);
              //cout<<airportArr.l;
            }
            if (!(c % 1000))
               // cout << temp->code << " long: " << temp->longitude << " lat: " << temp->latitude <<  endl;
            
            
            // if (!(c % 1000))
            // {
            //     cout << temp->code << " long: " << temp->longitude << " lat: " << temp->latitude <<  endl;
            //     cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
            // }
            

            
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
        float max = 0; 
        string cod; 
        
         for (int c=1; c < airportCount; c++){
            if (!(c % 1000))
            {
              Airport *temp = new Airport();
              Airport *temp1 = new Airport();
              Node* whoah = airportArr.get(c);
              temp = (Airport*)((airportArr.get(c))->v);
              temp1 = (Airport*)((airportArr.get(c+1))->v);
              string test = (string)(temp->code);
              double test2 = temp->longitude;
                //cout << (string)(temp->code) << " long: " << temp->longitude << " lat: " << temp->latitude <<  endl;
               // cout << temp1->code << " long: " << temp1->longitude << " lat: " << temp1->latitude <<  endl;
               // cout <<"Distance between " << temp->code << " and " << temp1->code << " is "
                  //<< distanceEarth( temp->longitude, temp->latitude , temp1->longitude, temp1->latitude) << endl;
            }
            
        if (distanceEarth(((Airport*)(airportArr.get(10643)->v))->longitude,((Airport*)(airportArr.get(10643)->v))->latitude, ((Airport*)((airportArr.get(c))->v))->longitude, ((Airport*)((airportArr.get(c))->v))->latitude)>max){
            cod = (string)((Airport*)((airportArr.get(c))->v))->code; 
            max = distanceEarth(((Airport*)(airportArr.get(10643)->v))->longitude,((Airport*)(airportArr.get(10643)->v))->latitude, ((Airport*)((airportArr.get(c))->v))->longitude, ((Airport*)((airportArr.get(c))->v))->latitude);
        }
        else if(distanceEarth(((Airport*)(airportArr.get(10643)->v))->longitude,((Airport*)(airportArr.get(10643)->v))->latitude, ((Airport*)((airportArr.get(c))->v))->longitude, ((Airport*)((airportArr.get(c))->v))->latitude)<=100){
            cout<<(string)((Airport*)((airportArr.get(c))->v))->code<<endl;
        }
}
cout<<cod;

    }
    else
    {
        cout << "Error opening file";
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
/*
void simpleSortTotal()
{

}
*/
