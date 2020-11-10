#include "my.h"
#include "../../std_lib_facilities.h"

void print_foo(){
    cout << foo << endl;
}

void print(int i){
    cout << i << endl;
}

void swap_v(int a,int b){
    int temp; 
    temp = a, 
    a=b; 
    b=temp;
    cout << "The first value is : " << a << endl;
    cout << "The second value is : " << b << endl;
}

void swap_r(int& a, int& b){
    int temp; 
    temp = a, 
    a=b; 
    b=temp;
    cout << "The first value is : " << a << endl;
    cout << "The second value is : " << b << endl;
}

/*const int swap_cr(const int a, const int b){
    int temp; 
    temp = a, 
    a=b; 
    b=temp;
}*/
