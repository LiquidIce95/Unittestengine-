#include </home/Dave/Dokumente/projects/c++/UZH_Advanced_C++/L1.2/fraction.h>
#include <iostream>


using namespace std;


int main(int argc, char* argv[]){

    cout<<argv[1]<<endl;
    int arg = *argv[1]-'0';

    cout<<"'1' for running tests, '2' for own testing"<<endl;
    int a;
    //cin>>a;

    const std::string red("\033[1;31m");
    const std::string green("\033[1;32m");
    std::string reset("\033[0m");


    if(arg == 1){
        //run these tests
        //tests for + operator

        bool suc = true;
        std::string succ = "Testing successfull, all tets passed";
        std::string fail = "Testing unsuccessfull, some tests failed";

        frac a = frac(2,3);
        frac b = frac(3,3);

        frac c = a+b;

        //TEST 1
        if(c.c == 15 && c.d == 9){
            cout<<green<<"."<<reset;
        } else {
            cout<<red<<"."<<reset;
            suc = false;
        }


        a = frac(1,4);
        b = frac( 8,9);
        c = a+b;

        //TEST 2
        if(c.c == 4*8+9 && c.d == 9*4){
            cout<<green<<"."<<reset;
        } else {
            cout<<red<<"."<<reset;
            suc = false;
        }

        //Testing for -
        c = -a;

        //TEST 3
        if(c.c == -a.c ^ c.d == -a.d){
            cout<<green<<"."<<reset;
        } else {
            cout<<red<<"."<<reset;
            suc = false;
        }
 
        //Testing for *
        c = a*b;
        
        //TEST 4
        if(c.c == a.c*b.c && c.d == a.d* b.d){
            cout<<green<<"."<<reset;
        } else {
            cout<<red<<"."<<reset;
            suc = false;
        }

        c = a/b;
        
        //TEST 5
        if(c.c == a.c* b.d && c.d == a.d * b.c){
            cout<<green<<"."<<reset;
        } else {
            cout<<red<<"."<<reset;
            suc = false;
        }



        cout<<endl;

        if(suc){
            cout<<succ;
        } else {
            cout<<fail;
        }

    } else {
        //user testing environment

        int c,d;


        frac a = frac(c,d);



        frac b = frac(c,d);

        bool ex,skip = false;

        std::string op = "#";

        while(!ex){
            
            if(!skip){
                cout<<"type in a/b#c/d for #= +,-,*,/ to perform operations, type n to define new fractions a and b, type e to exit program"<<endl;
                cout<<endl;
                cin>>op;

            } else {
                skip = false;
            }
            cout<<endl;
            if(op == "e"){
                break;
            }
            else if (op == "n"){
                //user testing environment
                cout<<"type in nominator and then denominator for fraction a"<<endl;

                int c,d;
                cin>>c,d;
                

                a = frac(c,d);

                cout<<"type in nominator and then denominator for fraction b"<<endl;

                cin>>c,d;

                b = frac(c,d);
            }
            else if (op == "+"){
                cout<<a+b<<endl;
            }
            else if ( op == "-"){
                cout<<a-b<<endl;

            }
            else if (op == "*"){
                cout<<a*b<<endl;
            }
            else if (op == "/"){
                cout<<a/b<<endl;
            }
            else if(op.size() == 7){
                int ac,ad,bc,bd;

                
                ac = op[0]-'0';
                ad = op[2]-'0';

                bc = op[4]-'0';
                bd = op[6]-'0';

                op = op[3];

                a = frac(ac,ad);
                b = frac(bc,bd);

                cout<<a<<op<<b<<" will be performed"<<endl;

                skip = true;

            }
            else{
                //invalid input
                cout<<"received invalid input, read carefully and be precise!"<<endl;
            }


        }


    }

    return 0;
}