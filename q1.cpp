/*
    QUESTION FROM
*/

#include<iostream>

using namespace std;

class Complex{
    public:
        int real, imaginary;
        Complex(int r, int i){
            real = r;
            imaginary = i;
        }

        void operator--(){
            Complex toReturn(this->real - 1, this->imaginary);
            *this = toReturn;
            //Prefix Unary - Operator
        }

        Complex operator*(int scalar){
            // Scalar Multiplication
            Complex toReturn(scalar*this->real, scalar*this->imaginary);
            return toReturn;
        }

        Complex operator+(Complex c){
            // Binary + Operator
            Complex toReturn(this->real+c.real, this->imaginary+c.imaginary);
            return toReturn;
        }

        Complex operator-(Complex c){
            // Binary - Operator
            Complex toReturn(this->real-c.real, this->imaginary-c.imaginary);
            return toReturn;
        }

        void operator+=(int a){
            // Shorthand += operator
            Complex toReturn(this->real + a, this->imaginary);
            *this = toReturn;
        }

        bool operator==(Complex c){
            // Equals to == operator
            bool toReturn = false;
            if(this->real == c.real && this->imaginary == c.imaginary) toReturn = true;
            return toReturn;
        }

        bool operator!=(Complex c){
            // Not Equal to != operator
            bool toReturn = true;
            if(this->real == c.real && this->imaginary == c.imaginary) toReturn = false;
            return toReturn;
        }

        bool operator>(Complex c){
            // Greather Than Operator
            bool toReturn = false;
            if(this->real > c.real) toReturn = true;
            return toReturn;
        }

       friend ostream& operator<<(ostream& output, Complex c){
            if(c.imaginary>=0){
                output << c.real << '+' << c.imaginary<<'i';
            }else{
                output << c.real << c.imaginary<<'i';
            }
            return output;
        }

};

int main(){
    string compare;
    Complex c1(2,3), c2(4,5);
    Complex c3 = c1+c2;
    cout<<"c1+c2: " << c3 <<endl;
    c3 = c1-c2;
    cout<<"c1-c2: " << c3 <<endl;
    /* All 'cout' functions with direct c3 supplied 
        is an expample of stream insertion operator <<
    */
    --c3;
    cout << "--c2: " << c3 <<endl;
    c3 = c1 * 2;
    cout << "c1*2: " << c3 << endl;
    c3 += 5;
    cout << "c3+=5: " << c3 << endl;
    compare = c1 == c2? "TRUE" : "FALSE";
    cout << "c1 == c2: " << compare << endl;
    compare = c1 != c2? "TRUE" : "FALSE";
    cout << "c1 != c2: " << compare << endl;
    compare = c1 > c2? "TRUE" : "FALSE";
    cout << "c1 > c2: " << compare <<endl;
    return 0;
}