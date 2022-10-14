#include <iostream>
#include <fstream>

using namespace std;

//Unix uses \n as line seperator
//MSDOS uses \r\n as line seperator

//the arguments in the main function must be typed in by the user like ./a.out input.txt output.txt
//This version assumes the files to be correctly formatted
//we could make it easier by demanding the user to type in the conversion type like 1 for unix to msdos
int main(int argc, char *argv[])
{
    //this stays the same
    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);
    char c;
    bool uni = false;
    bool firstline = true;
    for (;;) {
        //now we must check if 
        ifs.get(c);
        if (!ifs.good()) break;

        if (c== '\r\n'){
            ofs<< "\n";
            if(firstline){
                uni = true;
                firstline = false;

            }
        } 

        
        if (!uni && c=='\n'){
            ofs << "\r\n";

            if(firstline){
                firstline = false;
            }
        } 
        else ofs << c;

    }

    std::cout<<"output file"<<std::endl;


    //checking output file
    ifstream f1(argv[2]);

    for(;;){
        f1.get(c);
        if(!f1.good()) break;
        if(c == '\r\n'){
            std::cout<<std::endl;
            
        }
        std::cout<<c;

    }
}