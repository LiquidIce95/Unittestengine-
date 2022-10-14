#include <iostream>
#include "TestSuite.h"



int main(){

    TetsCase series1;

    series1.asser("Test1",2,1+1);
    series1.asser("Test2",0,3);

    series1.feedback();
    
    return 0;
}