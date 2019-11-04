#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "BaseballStatistic.h"
#include "StringHelper.h"
#include "Date.h"



using namespace std;


void swap(vector<BaseballStatistic>&, int int);
void sort(vector<BaseballStatistic>&);
int  search(vecotr<BaseballStatistic>, string, string);
void loadFile(vector<BaseballStatistic>&);    

int main(){
    
   vector<BaseballStatistic> test1;
  string temp ("R");
  char p[temp.length()];
  
  p[0] = temp[0]
