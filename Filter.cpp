#include <iostream>
//initial search function that will create the first list of which the other searches will look at#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "Filter.h"
#include "StringHelper.h"

using namespace std;


//swap function for sorting functions
void Filter::swap(vector<BaseballStatistic>& eList, int oIdx, int nIdx){
    
    BaseballStatistic temp = eList[oIdx]; //temporary employee variable to hold the old value during swap
    eList[oIdx] = eList[nIdx]; // assign the min_idx(element to be moved) to it's position
    eList[nIdx] = temp; //assign the element previously at the now sorted postion
}


//sort by player first and last name and position
void Filter::sort1(vector<BaseballStatistic>& eList){
    
     int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < eList.size()-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
      
        //I am using 2 differnt methods of comparing strings. One is the string compare function which is apart of the string class. 
        //The other is standard comparisson operators.
        
        for (j = i+1; j < eList.size(); j++) 
          if (
              (eList[j].getLastName().compare(eList[min_idx].getLastName()) < 0) //if getLName() @ j is < getLName() @ min_idx
              
              || (eList[j].getLastName().compare(eList[min_idx].getLastName()) == 0 && eList[j].getFirstName().compare(eList[min_idx].getFirstName() ) < 0) //getLName()s are equal and getFName() @ j is < getFName() @ min_idx
              
              || (eList[j].getLastName().compare(eList[min_idx].getLastName()) == 0 && eList[j].getFirstName().compare(eList[min_idx].getFirstName()) == 0 && eList[j].getPosition() < eList[min_idx].getPosition() ) // getLName()s and getFName()s are equal and getDepartment() @ j is < getDepartment() @ min_idx
              )
            min_idx = j; 
      
        // Swap the found minimum element with the first element 
        swap(eList, min_idx, i);
        
       
    } 
}

//sort by team name and jersey number
void Filter::sort2(vector<BaseballStatistic>& eList){
    
     int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < eList.size()-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
      
        //I am using 2 differnt methods of comparing strings. One is the string compare function which is apart of the string class. 
        //The other is standard comparisson operators.
        
        for (j = i+1; j < eList.size(); j++) 
          if (
              (eList[j].getTeamName().compare(eList[min_idx].getTeamName()) < 0) //if getLName() @ j is < getLName() @ min_idx
              
              || (eList[j].getTeamName().compare(eList[min_idx].getTeamName()) == 0 && (eList[j].getJerseyNum() < eList[min_idx].getJerseyNum()) ) //getLName()s are equal and getFName() @ j is < getFName() @ min_idx
              
              )
            min_idx = j; 
      
        // Swap the found minimum element with the first element 
        swap(eList, min_idx, i);
        
       
    } 
}

//initial search function that will create the first list of which the other searches will look at
void Filter::search(vector<BaseballStatistic> & temp, vector<BaseballStatistic> & result, string filter, string key){
   
    //if there was a confirmed match, set search to true
    bool search;

    for(int i = 0; i < temp.size(); i++)
    { //Start of for loop
       
        search = false;
       
        if(filter == "T")
        {
            if(StringHelper::toUpper(temp[i].getTeamName()) == key)   // Team
            {
                search = true;
            }
        }        

        else if(filter == "P")
        {
            if(temp[i].getPosition() == key) // Position
                search = true;
        }
       
        else if(filter == "B")
        {
            if(temp[i].getBatting() == key[0]) //Batting
                search = true;
        }
       
        else if(filter == "BA")
        {
            if(temp[i].getBattingAverage() >= atof(key.c_str())) //Batting Average
                search = true;
        }
       
        else if(filter == "H")
        {
            if(temp[i].getHR() >= atoi(key.c_str())) //Home Runs
                search = true;
        }
       
        else if(filter == "R")
        {
            if(temp[i].getRBI() >= atoi(key.c_str())) //Runs Batted In
                search = true;
        }
       
        else if(filter == "S")
        {
            if(temp[i].getSB() >= atoi(key.c_str())) //Stolen Bases
                search = true;
        }
       
        else if(filter == "O")
        {
            if(temp[i].getOBS() >= atof(key.c_str())) //OPS
                search = true;
        }
       
        else if(filter == "ERA")
        {
            if(temp[i].getERA() >= atof(key.c_str())) //ERA
                search = true;
        }
       // end of if statements
       // 
       // 
        if(search == true) //if serach is true, then add to the result
        {
              result.push_back(temp[i]);
        }
    } // End of for loop
   
    //return result;
   
}

void Filter::search2(vector<BaseballStatistic> & result, string filter, string key){
   
    //if there was a confirmed match, set search to true
    bool search;

    int og_size = result.size();
    int i = 0;
    
    while(i < result.size())
    { //Start of for loop
       
        search = false;
       
        if(filter == "T")
        {
            if(StringHelper::toUpper(result[i].getTeamName()) == key)   // Team
            {
                search = true;
                i++;
            }
        }        

        else if(filter == "P")
        {
            if(StringHelper::toUpper(result[i].getPosition()) == key) // Position
            {
                search = true;
                i++;
            }
        }
       
        else if(filter == "B")
        {
            if(toupper(result[i].getBatting()) == key[0]) //Batting
            {
                search = true;
                i++;
            }
        }
       
        else if(filter == "BA")
        {
            if(result[i].getBattingAverage() >= atof(key.c_str())) //Batting Average
            {
                search = true;
                i++;
            }
        }
       
        else if(filter == "H")
        {
            if(result[i].getHR() >= atoi(key.c_str())) //Home Runs
            {
                search = true;
                i++;
            }
        }
       
        else if(filter == "R")
        {
            if(result[i].getRBI() >= atoi(key.c_str())) //Runs Batted In
            {
                search = true;
                i++;
            }
        }
       
        else if(filter == "S")
        {
            if(result[i].getSB() >= atoi(key.c_str())) //Stolen Bases
            {
                search = true;
                i++;
            }
        }
       
        else if(filter == "O")
        {
            if(result[i].getOBS() >= atof(key.c_str())) //OPS
            {
                search = true;
                i++;
            }
        }
       
        else if(filter == "H")
        {
            if(result[i].getERA() >= atof(key.c_str())) //ERA
            {
                search = true;
                i++;
            }
        }
       // end of if statements
       // 
       // 
        if(search == false) //if serach is true, then add to the result
        {
              result.erase(result.begin() + i);
            //cout << result.size() << endl;
        }

    } // End of for loop
   
    //return result;
   
}