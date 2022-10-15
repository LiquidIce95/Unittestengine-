#include <iostream>
#include <vector>
#include </home/Dave/Dokumente/projects/c++/UZH_Advanced_C++/TestSuite/TestSuite.h>

//testing version
void RPN(std::string input,std::vector<double>& stack, std::vector<double>& output){

        //n 4 is a valid input
        if(input.at(0) == 'n'){
            double n = std::stod(input.substr(2,input.size()-2));
            stack.push_back(n);
        }
        else if (stack.size()>1 && input == "d"){
            stack.erase(stack.end()-1,stack.end());
        }
        else if (stack.size()>1 && input == "+"){
            output.push_back(*(stack.end()-2)+*(stack.end()-1));
        }
        else if (stack.size()>1 && input == "-"){
            output.push_back(*(stack.end()-2)-*(stack.end()-1));
        }
        else if (stack.size()>1 && input == "*"){
            output.push_back(*(stack.end()-2)**(stack.end()-1));
        }
        else if (stack.size()>1 && input == "/"){
            output.push_back(*(stack.end()-2)/ *(stack.end()-1));
        }
    
}

//Continous version of the RPN
void contRPN(){
    std::string rep;
    getline(std::cin,rep);

    std::vector<double> stack;
    std::vector<double> output;

    while (rep!= "q")
    {
        RPN(rep,stack,output);

        if(output.size()>=1){
            std::cout<<" is last output "<<*(output.end()-1)<<std::endl;
        }

        for(std::vector<double>::iterator i = stack.begin(); i != stack.end(); ++i){
            std::cout<<" is on stack "<<*i<<std::endl;
        }
        getline(std::cin,rep);

    }
    
}

int main(){

    TestCase s;

    std::vector<double> stack;
    std::vector<double> output;
    std::vector<double> test;
    std::vector<double> test2;
    //T1
    RPN("n 2.3",stack, output);
    test = {2.3};
    s.asser("T1",test,stack);

    //T2
    stack ={2.3};
    RPN("n 3.0",stack, output);
    test = {2.3,3.0};
    s.asser("T2",test,stack);

    //T3
    output = {};
    stack = {2.3,3.0};
    RPN("+",stack,output);
    test2 = {5.3};
    s.asser("T3",test2,output);

    //T4
    output ={};
    stack = {};
    RPN("n 4",stack,output);
    RPN("n 9.9",stack,output);
    RPN("-",stack,output);
    RPN("*",stack,output);
    test = {4,9.9};
    test2 = {4-9.9,4*9.9};

    s.asser("T4.1",stack,test);
    s.asser("T4.2",test2,output);

    s.feedback();

    contRPN();

    return 0;
}