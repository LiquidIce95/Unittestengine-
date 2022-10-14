#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    
    std::ifstream f1(argv[1]);

    //checking output file

    char c;

    for(;;){
        f1.get(c);
        if(!f1.good()) break;
        if(c == '\r\n'){
            std::cout<<std::endl;
            std::cout<<"teststring";
            std::cout<<std::endl;
        }
        std::cout<<c;

    }
    
    return 0;
}