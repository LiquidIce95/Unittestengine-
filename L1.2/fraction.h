#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;
//Class for rational numbers
class frac{

    void reduce(frac& g){
        //figuring out gcd
        int a = gcd(g.c,g.d);

        if(!(a==0)){
            g.c = g.c/a;
            g.d = g.d/a;
        } 
    }


    public:
        int c;
        int d;
        // need this for equality
        static int gcd(int a, int b){
            int c;
            while(b){
                c = a;
                a = b;
                b = c%b;
            }
            return abs(a);
        }
        //New default constructor
        frac(int a, int b){
            int gd = gcd(a,b);

            if(!(gd==0)){
                this->c = a/gd;
                this->d = b/gd;
            }
            else{
                this->c = a;
                this->d = b;
            }

        }
        //Operations
        frac operator*(frac b){
            frac z = frac(0,0);

            z.c = this->c * b.c;
            z.d = this->d * b.d;

            reduce(z);

            return z;
        }

        frac operator+( frac b){
            frac z = frac(0,0);

            z.c = this->c * b.d + this->d* b.c;
            z.d = this->d * b.d;
            
            reduce(z);
            return z;
        }

        frac operator-(frac b){
            frac z = frac(0,0);

            z.c = this->c - b.c;
            z.d = this->d - b.d;

            reduce(z);
            return z;

        }
        frac operator/(frac b){
            frac z = frac(0,0);

            z.c = this->c * b.d;
            z.d = this->d * b.c;

            reduce(z);
            return z;


        }
        //unary operator 

        frac operator-(){

            frac z = frac(0,0);
            z.c = this->c*(-1);
            z.d = this->d;

            reduce(z);
            return z;
        }

        //relational operators
        //this equality is not quite correct, since it excludes multiples
        bool operator==(frac b){
            if(this->c == b.c && this->d == b.d){
                return true;
            }
            else {
                return false;
            }
        }

        bool operator<(frac b){
            float h = this->c/this->d;
            float g = b.c/b.d;

            return (h<g);
        }
        bool operator>(frac b){
            float h = this->c/this->d;
            float g = b.c/b.d;

            return (h>g);
        }

        bool operator<=(frac b){

            return (*this<b || *this == b);
        }

        bool operator>=(frac b){

            return (*this>b || *this == b);
        }

};

//input and output, cannot be static members of a class (apparently)
ostream& operator<<(ostream& os, const frac& f){

    os<<f.c<<"/"<<f.d;
    return os;
}
istream& operator>>(istream& is, frac& f){

    is >>f.c;
    is >>f.d;
    return is;
}