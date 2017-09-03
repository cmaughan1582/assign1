#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void helpmessage();
int fib(int n);
double ecalc(int n);
int factorial (int n);

int main(int argc, char* argv[]){
    if(argc > 1){
        for(int i = 0; i < argc; i++){
            string test = argv[i];
            if(test == "-pi"){
                string param = argv[i+1];
                int dec = 0;
                try{
                dec = stoi(param);
                } catch (exception& e){
                    helpmessage();
                    return 0;
                }
                
                if(dec < 1 || dec > 10){
                    helpmessage();
                }
                else{
                    int a = 22;
                    int b = 7;
                    double pi = 0;
                    pi = (double)a/(double)b;
                    cout.precision(dec+1);
                    cout<<"pi computed to "<<dec<<" decimals is: "<<pi<<endl;
                    return 0;
                }
            }
            else if(test == "-fib"){
                string param = argv[i+1];
                int dec = 0;
                try{
                    dec = stoi(param);
                } catch (exception& e){
                    helpmessage();
                    return 0;
                }
                if(dec < 0 || dec > 40){
                    helpmessage();
                }
                else{
                    cout<<"The fibonacci of "<<dec<<" is: "<<fib(dec)<<endl;
                    return 0;
                }
            }
            else if(test == "-e"){
                string param = argv[i+1];
                int dec = 0;
                try{
                    dec = stoi(param);
                } catch (exception& e){
                    helpmessage();
                    return 0;
                }
                if(dec < 1 || dec > 30){
                    helpmessage();
                }
                else{
                    cout.precision(10);
                    cout<<"e calculated to "<<dec<<" iterations is: "<<ecalc(dec)<<endl;
                    return 0;
                }
            }
        }
        helpmessage();
    }
    else{
        helpmessage();
    }
    
    return 0;
}

void helpmessage(){
    cout<<"That is not valid"<<endl;
    cout<<"Use one of the following commands"<<endl<<endl;
    cout<<"-pi [n]: Compute pi to the nth digit. (n between 1 and 10)"<<endl;
    cout<<"-fib [n]: Compute the fibonacci of n. (n between 0 and 40)"<<endl;
    cout<<"-e [n]: Compute e to the nth iteration. (n between 1 and 30)"<<endl;
}

int fib(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int total = 0;
    total = fib(n-1) + fib(n-2);
    return total;
}

double ecalc(int n){
    double total;
    int fac = factorial(n);
    double dfac = (double)fac;
    double dn = 1.0;
    if (n==0){
        total = 1;
        return total;
    }
    total = dn/dfac + ecalc(n-1);
    return total;
}

int factorial (int n){
    if(n == 0){
        return 1;
    }
    int total = n * factorial (n-1);
    return total;
}