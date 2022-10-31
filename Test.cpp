#include <iostream>
#include <vector>

using namespace std;

double baba = 33.3333;

/*this is documentation? öfaklfja
alfjdaöslfslöfjsld*/ 
void changebab(){
    baba = 30;
}

int main(){
    changebab();
    std::cout<<baba<<std::endl;

    auto fee = changebab;

    fee();
    vector<void(*&)()> v;

    v.push_back(fee);


    return 0;
}