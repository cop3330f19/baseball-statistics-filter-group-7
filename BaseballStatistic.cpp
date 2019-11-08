#include "BaseballStatistic.h"
#include "StringHelper.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>


using namespace std;

/*BaseballStatistic::BaseballStatistic()
{
    firstName;
    lastName;
    teamName;
    position;
    year;
    month;
    day;
    jerseyNum;
    atBats;
    hr;
    rbi;
    sb;
    batting;
    throwing;
    battingAverage;
    ops;
    era;
}*/

BaseballStatistic::BaseballStatistic(string tName, int jNum, string lName, string fName, int y, int m, int d,
                                     char bat, char thrw, int atB, double batAvg, int homeR, int runB, 
                                     int stoleB, double onP, double earnedR, string pos)
{
    firstName = fName;
    lastName = lName;
    teamName = tName;
    position = pos;
    year = y;
    month = m;
    day = d;
    jerseyNum = jNum;
    atBats = atB;
    hr = homeR;
    rbi = runB;
    sb = stoleB;
    batting = bat;
    throwing = thrw;
    battingAverage = batAvg;
    ops = onP;
    era = earnedR;
    dob = new Date(y, m, d);
    
}

void BaseballStatistic::setFirstName(string fName)
{
    firstName = fName;
}

void BaseballStatistic::setLastName(string lName)
{
    lastName = lName;
}

void BaseballStatistic::setTeamName(string tName)
{
   teamName = tName;
}

void BaseballStatistic::setJerseyNum(int jNum)
{
   jerseyNum = jNum;
}

void BaseballStatistic::setPosition(string pos)
{
   position = pos;
}

void BaseballStatistic::setBatting(char bat)
{
   batting = bat;
}

void BaseballStatistic::setThrowing(char thrw)
{
   throwing = thrw;
}

void BaseballStatistic::setAtBats(int atB)
{
   atBats = atB;
}

void BaseballStatistic::setBattingAverage(double batAvg)
{
   battingAverage = batting;
}

void BaseballStatistic::setHR(int homeR)
{
   hr = homeR;
}

void BaseballStatistic::setRBI(int runB)
{
   rbi = runB;
}

void BaseballStatistic::setSB(int stoleB)
{
   sb = stoleB;
}

void BaseballStatistic::setOBS(double onP)
{
   ops = onP;
}

void BaseballStatistic::setERA(double earnedR)
{
   era = earnedR;
}

string BaseballStatistic::getFirstName() const
{
    return firstName;
}

string BaseballStatistic::getLastName() const
{
    return lastName;
}

string BaseballStatistic::getTeamName() const
{
    return teamName;
}

int BaseballStatistic::getJerseyNum() const
{
    return jerseyNum;
}

string BaseballStatistic::getPosition() const
{
    return position;
}

char BaseballStatistic::getBatting() const
{
    return batting;
}

char BaseballStatistic::getThrowing() const
{
    return batting;
}

int BaseballStatistic::getAtBats() const
{
    return atBats;
}

double BaseballStatistic::getBattingAverage() const
{
    return battingAverage;
}

int BaseballStatistic::getHR() const
{
    return hr;
}

int BaseballStatistic::getRBI() const
{
    return rbi;
}

int BaseballStatistic::getSB() const
{
    return sb;
}

double BaseballStatistic::getOBS() const
{
    return ops;
}

double BaseballStatistic::getERA() const
{
    return era;
}

void BaseballStatistic::print() const
{
    
    string f_l = lastName + ", " + firstName;
    
    cout << left << setw(24) << f_l << setw(5) << dob->getAge() << setw(3) << jerseyNum << setw(12) << teamName << setw(4)
        << position << batting << "/" << setw(5) << throwing << setw(4) << atBats << setw(6) << battingAverage 
        << setw(4) << hr << setw(6) << rbi << setw(4) << sb << setw(6) << ops 
        << era << endl;
    
    
}