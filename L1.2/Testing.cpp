#include </home/Dave/Dokumente/projects/c++/UZH_Advanced_C++/L1.2/fraction.h>
#include <iostream>
#include </home/Dave/Dokumente/projects/c++/UZH_Advanced_C++/Testing/TestSuite.h>
#include <sstream>

//testing
int main(){

    TestCase serie0;

    serie0.asser("S0_T1",2,frac::gcd(2,4));
    serie0.asser("S0_T2",6,frac::gcd(12,6));
    serie0.asser("S0_T3",1,frac::gcd(2324,2421));
    serie0.asser("S0_T4",3,frac::gcd(33,873));
    serie0.asser("S0_T5",1,frac::gcd(51,49));

    serie0.feedback();


    // frac class testing
    TestCase series1;

    //T1
        stringstream f;

        frac a =frac(1,2);
        
        f<<a;

    series1.asser("T1","1/2",f.str());

    //T2
        frac b = frac(2,3);
        frac res = frac(7,6);

    series1.asser("T2",res,a+b);


    //T3
        frac z = frac(2,4);
        frac r = frac(1,2);
    series1.asser("T3",z,r);

    //T3.1
        frac n = frac(3,5);
    series1.asser("T3.1",n,r);

    //T4
    series1.asser("T4",false,z<r);

    //T5
    series1.asser("T5",true,z<=r);
    //T6
    series1.asser("T6",false, z>r);

    //T7
    z = frac(1,2);
    r = frac(3,5);
    series1.asser("T7",true, z<r);

    series1.feedback();

    return 0;
}