#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "BaseballStatistic.h"
#include "StringHelper.h"
#include "Filter.h"
#include "Date.h"


using namespace std;

void loadFile(vector<BaseballStatistic>&);
void printHeading();

int main(){
    //create a vector of the baseballstatistic class with the name test1
    vector<BaseballStatistic> test1;
    
    
    //use the loadfile function to load in the .csv file 
    loadFile(test1);
    
    //create string for decision at end of program
    string dec = "";
    
    //create variables needed for program
    string filter = "";
    string key = "";
    vector<BaseballStatistic> result;
    bool indicator;
    int sort_option;

    //start of entire program
    do
    {
        
        //set indicator to false so that it does the first search that creates the result list
        indicator = false;
        //set sort_option to 0
        sort_option = 0;
        
        cout << "Enter all filter key pairs you would like to use (enter F when finished): " << endl;
        do
        {
            //get user input
            cin >> filter;
            filter = StringHelper::toUpper(filter);
            if (filter != "F" && filter != "T" && filter != "P" && filter != "B" && filter != "BA" && filter != "H" && filter != "R" && filter != "S" && filter != "O" && filter != "E")
            {
                cout << "Invalid input! Please select from the filter options or F to end filter options." << endl;
            }
            else if (filter != "F" && !indicator)
            {
                //check for key after checking the if they want to end
                cin >> key;
                key = StringHelper::toUpper(key);
                Filter::search(test1, result, filter, key);
                indicator = true;
            }
            else if (filter != "F" && indicator)
            {
                //check for key after checking the if they want to end
                cin >> key;
                key = StringHelper::toUpper(key);
                Filter::search2(result, filter, key);
            }
        } while (filter != "F");
        
        
        //ask user if they want to sort the results of their search 
        if(indicator == true)
        {
            cout << "Sorting Options\n" << "1 - By Player Name & Position \n";
            cout << "2 - By Team& Jersey Number \n" << "3 - None \n";
            cout << "Please enter your sorting option: ";
            cin >> sort_option;
            //check user input
            while(sort_option != 1 && sort_option != 2 && sort_option != 3)
            {
                cout << "Invalid option, re-enter choice: ";
                cin >> sort_option;
            }
        }
        
        //select sorting option 
        if(indicator == true)
        {
            if(sort_option == 1)
            {
                Filter::sort1(result);
            }
            else if(sort_option == 2)
            {
                Filter::sort2(result);
            }
        }
        
        //print the heading to display the information with error check
        if(indicator == true)
        {
            printHeading();
        }
        
        //print results with error check
        if(indicator == true)
        {
            for(int i = 0; i < result.size(); i++)
                {
                    result[i].print();
                }
        }
        
        //clear the result list since we are finished with this round
        if(indicator == true)
        {
            result.clear();
        }

        
        //first reset the decision variable and then ask user if they would like to do the search again
        dec = "";
        cout << "Would you like to do a new filter? (Y/N) ";
        cin >> dec;
        dec = StringHelper::toUpper(dec);
        while(dec != "Y" && dec != "N")
        {
            cout << "Would you like to do a new filter? (Y/N) ";
            cin >> dec;
            dec = StringHelper::toUpper(dec);
        }
        
        
    }while(dec != "N");
        
	return 0;
}



//load in file
void loadFile(vector<BaseballStatistic>& obj)
{
    //create variables
    string fname, lname, tname, pos, temp;
    int year, month, day, jNum, atB, hr, rbi, sb;
    char batt, thrw;
    double batAvg, ops, era;
    
    //prepare and open file
    ifstream inF;
    inF.open("BStats.csv");

    //read in file
   while(inF.good())
    {
       //use temp string variable to read in value
        getline(inF, temp, ',');
       //set read in value to corresponding variable
       tname = temp;
        getline(inF, temp,',');
       //convert the string to an int
       stringstream geek1(temp);
       //set converted variable to corresponding variable 
       geek1 >> jNum;
        getline(inF, temp, ',');
       fname = temp;
        getline(inF, temp, ',');
       lname = temp;
        getline(inF, temp, ',');
       stringstream geek2(temp);
       geek2 >> year;
        getline(inF, temp, ',');
       stringstream geek3(temp);
       geek3 >> month;
        getline(inF, temp, ',');
       stringstream geek4(temp);
       geek4 >> day;
        getline(inF, temp, ',');
       //create a char variable of the same length of the read in variable
       char p[temp.length()];
       //set the temp char variable to the read in variable
       p[0] = temp[0];
       //set the temp char variable to the corresponding variable
       batt = p[0];
        getline(inF, temp, ',');
       p[0] = temp[0];
       thrw = p[0];
        getline(inF, temp, ',');
       stringstream geek5(temp);
       geek5 >> atB;
        getline(inF, temp, ',');
       stringstream geek6(temp);
       geek6 >> batAvg;
        getline(inF, temp, ',');
       stringstream geek7(temp);
       geek7 >> hr;
        getline(inF, temp, ',');
       stringstream geek8(temp);
       geek8 >> rbi;
        getline(inF, temp, ',');
       stringstream geek9(temp);
       geek9 >> sb;
        getline(inF, temp, ',');
       stringstream geek10(temp);
       geek10 >> ops;
        getline(inF, temp, ',');
       stringstream geek11(temp);
       geek11 >> era;
        getline(inF, temp);
       pos = temp;
       
       //cout << tname << " " << jNum << " " << lname << " " << fname << " " << year << " " << month << " " << day << " " << batt << " " << thrw << " " << atB << " " << batAvg << " " << hr << " " << rbi << " " << sb << " " << ops << " " << era << " " << pos << endl;
       //the current variables hold the needed information for the object
       //using the object's constructor insert the variables into the object
       BaseballStatistic test3(tname, jNum, lname, fname, year, month, day, batt, thrw, atB, batAvg, hr, rbi, sb, ops, era, pos);
       //add that new object to the vector
       obj.push_back(test3);
    }
    
}

void printHeading(){
	cout << right << "Player Name" << setw(16) << "Age" << setw(4) << "# " << setw(5) << "Team" << setw(9)
        << "P" << setw(6) << "B/T" << setw(6) << "AB" << setw(5) << "AVG" 
        << setw(5) << "HR" << setw(5) << "RBI" << setw(5) << "SB" << setw(5) << "OPS" 
        << setw(5) << "ERA" << endl;
	
	for(int i =0; i < 93; i++)
		cout<< "-";
	cout << endl;
}