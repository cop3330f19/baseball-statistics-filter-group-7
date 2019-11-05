#include <string>
#include <vector>
#include <sstream>
#include "Filter.h"

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

//sort by team name
int Filter::search1(vector<BaseballStatistic> obj, string team)
{
    int lo = 0;
  int hi = obj.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid
        if (obj[location].getTeamName() == team) 
            return location; 
  
        // If name greater, ignore left half 
        if (obj[location].getTeamName() < team) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
}

int Filter::search2(vector<BaseballStatistic> obj, string pos)
{
    int lo = 0;
  int hi = obj.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid
        if (obj[location].getPosition() == pos) 
            return location; 
  
        // If name greater, ignore left half 
        if (obj[location].getPosition() < pos) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
}

int Filter::search3(vector<BaseballStatistic> obj, char bat)
{
    int lo = 0;
  int hi = obj.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid
        if (obj[location].getBatting() == bat) 
            return location; 
  
        // If name greater, ignore left half 
        if (obj[location].getBatting() < bat) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
}

int Filter::search4(vector<BaseballStatistic> obj, double atBat)
{
    int lo = 0;
  int hi = obj.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid
        if (obj[location].getBattingAverage() == atBat) 
            return location; 
  
        // If name greater, ignore left half 
        if (obj[location].getBattingAverage() < atBat) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
}

int Filter::search5(vector<BaseballStatistic> obj, int hr)
{
    int lo = 0;
  int hi = obj.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid
        if (obj[location].getHR() == hr) 
            return location; 
  
        // If name greater, ignore left half 
        if (obj[location].getHR() < hr) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
}

int Filter::search6(vector<BaseballStatistic> obj, int rbi)
{
    int lo = 0;
  int hi = obj.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid
        if (obj[location].getRBI() == rbi) 
            return location; 
  
        // If name greater, ignore left half 
        if (obj[location].getRBI() < rbi) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
}

int Filter::search7(vector<BaseballStatistic> obj, int sb)
{
    int lo = 0;
  int hi = obj.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid
        if (obj[location].getSB() == sb) 
            return location; 
  
        // If name greater, ignore left half 
        if (obj[location].getSB() < sb) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
}

int Filter::search8(vector<BaseballStatistic> obj, double ops)
{
    int lo = 0;
  int hi = obj.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid
        if (obj[location].getOBS() == ops) 
            return location; 
  
        // If name greater, ignore left half 
        if (obj[location].getOBS() < ops) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
}

int Filter::search9(vector<BaseballStatistic> obj, double era)
{
    int lo = 0;
  int hi = obj.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid
        if (obj[location].getERA() == era) 
            return location; 
  
        // If name greater, ignore left half 
        if (obj[location].getERA() < era) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
}

