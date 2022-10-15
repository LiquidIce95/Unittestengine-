#include <iostream>
#include <vector>
#include </home/Dave/Dokumente/projects/c++/UZH_Advanced_C++/TestSuite/TestSuite.h>
#include </home/Dave/Dokumente/projects/c++/UZH_Advanced_C++/L1.2/fraction.h>
#include <sstream>

//testing version
template <typename T>
void RPN(std::string input,std::vector<T>& stack, std::vector<T>& output){

        //n 4 is a valid input
        if(input.at(0) == 'n'){
            std::istringstream s(input.substr(2,input.size()-2));
            T n;
            s>>n;
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
template <typename T>
void contRPN(){
    std::string rep;
    getline(std::cin,rep);

    std::vector<T> stack;
    std::vector<T> output;

    while (rep!= "q")
    {
        RPN(rep,stack,output);

        if(output.size()>=1){
            std::cout<<" is last output "<<*(output.end()-1)<<std::endl;
        }

        for(int i = 0; i < stack.size(); ++i){
            std::cout<<" is on stack "<<stack.at(i)<<std::endl;
        }
        getline(std::cin,rep);

    }
    
}

int main(){

    TestCase s;
    //Creating scope so that we can re-use variables
    if(true){
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

        s.asser("T4.1",test,stack);
        s.asser("T4.2",test2,output);
    }
    

    //Tests for custom types
    if(true){
        std::vector<frac> stack;
        std::vector<frac> output;
        std::vector<frac> test;
        std::vector<frac> test2;

        RPN("n 4 3",stack,output);

        frac a = frac(4,3);
        test = {a};

        s.asser("T5",test,stack);

        frac b = frac(7,8);
        RPN("n 7 8",stack,output);
        test = {a,b};
        s.asser("T6",test,stack);

        RPN("+",stack,output);
        test2 = {a+b};
        s.asser("T7",test2,output);

    }
    

    s.feedback();

    contRPN<double>();

    return 0;
}