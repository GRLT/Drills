#include "../../std_lib_facilities.h"

const vector<string> months = {
    "January",
    "Febuary",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "Septermber",
    "October",
    "November",
    "December"
};

enum class Month{
    jan, feb, mar, apr, may, jun, july, aug, sept, oct, nov, dec
};

Month operator++(Month& m){
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
    return m;
}

ostream& operator<<(ostream& os, Month m){
    return os << months[int(m)];
}

main(){
    Month m = Month::jan;
    m = Month::apr;
    ++m;
    cout << m << endl;

    return 0;
}