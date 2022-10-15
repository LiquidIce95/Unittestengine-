#pragma once

#include <vector>
#include <sstream>
#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> v){

    for( int i = 0; i < v.size();++i){
        os<<v.at(i);
    }
    return os;
}

class TestCase {

    public:
        //converts types into string , so we can append to messages, << operator needs to be defined for tpye T
        template<class T> std::string tostring(const T& t) {
            std::ostringstream ss;
            ss << t;
            return ss.str();
        }
        std::vector<bool> tests;
        std::vector<std::string> msgs;

        void asser(std::string testname , auto correct, auto output){

            const std::string red("\033[1;31m");
            const std::string green("\033[1;32m");
            std::string reset("\033[0m");


            try {
                if(correct == output){
                    std::cout<<green<<"."<<reset;
                    this->tests.push_back(true);
                } else {
                    std::cout<<red<<"."<<reset;
                    this->tests.push_back(false);
                    std::string message = testname+" FAILED ,expected: "+tostring(correct)+" actual: "+tostring(output);
                    this->msgs.push_back(message);
                }

            }
            catch(const std::exception& e){
                std::cout<<red<<"."<<reset;
                this->tests.push_back(false);
                this->msgs.push_back(testname+" ERROR occured"+e.what());
            }
            
        }

        void feedback(){
            std::cout<<std::endl;
            for (int i = 0; i < msgs.size(); ++i){
                std::cout<<msgs.at(i)<<std::endl;
            }

            if(msgs.size()==0){
                std::cout<<"All tests were successful!"<<std::endl;
            }
        }

};
