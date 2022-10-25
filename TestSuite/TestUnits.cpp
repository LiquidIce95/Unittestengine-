#include <iostream>
#include "/home/Dave/Insync/MAINVAULT/projects/c++/UZH_Advanced_C++/TestSuite/TestSuite.h"



int main(){
// if want to only run certain test, comment or uncomment them
    TestCase series1;

    series1.asser("Test1",2,1+1);
    series1.asser("Test2",0,3);

    series1.feedback();
    
    return 0;
}