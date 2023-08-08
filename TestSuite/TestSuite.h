#pragma once

#include <vector>
#include <sstream>
#include <iostream>
#include <chrono>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> v){

    for( int i = 0; i < v.size();++i){
        os<<v.at(i);
    }
    return os;
}

class TestCase {

    std::chrono::duration<double> time;

    public:
        //converts types into string , so we can append to messages, << operator needs to be defined for tpye T
        template<class T> std::string tostring(const T& t) {
            std::ostringstream ss;
            ss << t;
            return ss.str();
        }
        std::vector<bool> tests;
        std::vector<std::string> msgs;
        
        template<typename CorrectType, typename OutputType>
        void asser(std::string testname , CorrectType correct, OutputType output){

            auto start = std::chrono::high_resolution_clock::now();

            const std::string red("\033[1;31m");
            const std::string green("\033[1;32m");
            std::string reset("\033[0m");


            try {
                if(correct == output){
                    std::cout<<green<<"● "<<reset;
                    this->tests.push_back(true);
                    std::string message = testname+" SUCCESS ";
                    this->msgs.push_back(message);
                } else {
                    std::cout<<red<<"● "<<reset;
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
            auto finish = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = finish - start;

            this->msgs[msgs.size()-1] += ", time in miliseconds for this test : "+tostring(std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count());

            this->time += elapsed;
        }

        void feedback(){
            std::cout<<std::endl;
            for (int i = 0; i < msgs.size(); ++i){
                std::cout<<msgs.at(i)<<std::endl;
            }

            if(msgs.size()==0){
                std::cout<<"All tests were successful!"<<std::endl;
            }

            std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(this->time).count()<<" microsseconds total time "<<std::endl;
            std::cout<<std::chrono::duration_cast<std::chrono::milliseconds>(this->time).count()<<" milliseconds total time "<<std::endl;

        }

};
