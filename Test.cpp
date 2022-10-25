#include <iostream>


using namespace std;

double baba = 33.3333;

void changebab(double& baba){
    baba = 30;
}

int main(){
    changebab(baba);
    std::cout<<baba<<std::endl;



    return 0;
}