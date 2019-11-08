#include <string>
#include <vector>
#include <sstream>
#include "BaseballStatistic.h"

class Filter
{
    public:
    //swap function
    static void swap(std::vector<BaseballStatistic>&, int, int);

    //first sort function
    static void sort1(std::vector<BaseballStatistic>&);
    
    //second sort function
    static void sort2(std::vector<BaseballStatistic>&);
    
    static int search1(std::vector<BaseballStatistic>, std::string);
    
    static int search2(std::vector<BaseballStatistic>, std::string);
    
    static int search3(std::vector<BaseballStatistic>, char);
    
    static int search4(std::vector<BaseballStatistic>, double);
    
    static int search5(std::vector<BaseballStatistic>, int);
    
    static int search6(std::vector<BaseballStatistic>, int);
    
    static int search7(std::vector<BaseballStatistic>, int);
    
    static int search8(std::vector<BaseballStatistic>, double);
    
    static int search9(std::vector<BaseballStatistic>, double);
    
    static void search(std::vector<BaseballStatistic> &, std::vector<BaseballStatistic> &, std::string, std::string);
    
    static void search2(std::vector<BaseballStatistic> &, std::string, std::string);
};


