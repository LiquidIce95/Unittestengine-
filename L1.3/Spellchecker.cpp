#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
    
    //first CL argument is the dictionary, second is the file to be spellchecked
    //file to be spellchecked
    ifstream filecheck(argv[1]);
    //dictionary
    ifstream dic(argv[2]);
    
    vector<std::string> dict;

    string word;

    //loading dictionary into string vector
    while(dic>> word){
        //cout<<word<<" word form dic "<<endl;
        dict.push_back(word);
    }

    //test code
    /*
    for(int i = 0; i < dict.size(); i++ ){
        cout<<dict.at(i)<<endl;
    }
    */

    //spell checking the file

    while(filecheck>>word){
        if(find(dict.begin(),dict.end(),word) != dict.end()){
            //word has been found, therefore do nothing

        }
        else{
            //word has not been found, therefore print out
            cout<<"mistake found: "<<"'"<<word<<"'"<<" is mispelled"<<endl;
        }
    }

    return 0;
}