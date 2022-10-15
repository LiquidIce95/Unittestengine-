#include <iostream>
#include <vector>
#include </home/Dave/Dokumente/projects/c++/UZH_Advanced_C++/TestSuite/TestSuite.h>


void RPN(std::string input,std::vector<double>& stack){


    while(input != "q"){
        //must get entire line at once, or change default delimiter to \n
        if(input == ""){
            std::cin>>input;

            std::cout<<"input: "<<input<<std::endl;
        }
        

        //n 4 is a valid input
        if(input.at(0) == 'n'){
            double n = input.at(2) - '0';
            stack.push_back(n);
        }
        else if (input == "d"){
            stack.erase(stack.end(),stack.end()+1);
        }
        else if (input == "+"){
            std::cout<<*(stack.end()-1)+*(stack.end())<<std::endl;
        }
        else if (input == "-"){
            std::cout<<*(stack.end()-1)-*(stack.end())<<std::endl;
        }
        else if (input == "*"){
            std::cout<<*(stack.end()-1)**(stack.end())<<std::endl;
        }
        else if (input == "/"){
            std::cout<<*(stack.end()-1)/ *(stack.end())<<std::endl;
        }
        else {
            std::cout<<"invalid input!"<<std::endl;
        }
        for(int i = 0; i < stack.size(); ++i){
            std::cout<<stack.at(i);
        }
        std::cout<<" is on stack "<<std::endl;
    }
}




int main(){

    TestCase s;

    std::vector<double> stack;

    std::vector<double> test;
    //T1
    RPN("n 2.3",stack);
    test.push_back(2.3);
    s.asser("T1",test,stack);


    return 0;
}