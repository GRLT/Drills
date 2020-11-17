#include "../../std_lib_facilities.h"

int main()
try {
    int birth_year = 2001;
    int age = 2020-birth_year;
    cout << noshowbase << dec << endl;
    cout << "Decimal" << dec << " " << birth_year << endl;
    cout << "Hexadecimal" << hex << " " << birth_year << endl;
    cout << "Octal" << oct << " " << birth_year << endl;

    cout << showbase << dec << endl;
    cout << "Decimal" << dec << " " << birth_year << endl;
    cout << "Hexadecimal" << hex << " " << birth_year << endl;
    cout << "Octal" << oct << " " << birth_year << endl;

    cout << noshowbase << dec << endl;
    cout << "DefaultFloat" << defaultfloat << " " << birth_year << endl;
    cout << "Fixed" << fixed << " " << birth_year << endl;
    cout << "Scientific" << scientific << " " << birth_year << endl;

    cout << "\n";
    cout << defaultfloat
    << setprecision(5)
    << "DefaultFloat" << 1234567.89 << "\n"
    << "Fixed" << fixed << 1234567.89 << "\n"
    << "Scientific" << scientific << 1234567.89 << "\n";


    cout << "Age:" << age << endl;


   /* cout << "decimal\t\t" << birth_year << '\n' << hex
         << "hexadecimal\t" << birth_year << '\n' << oct
         << "octal\t\t" << birth_year << '\n';

    cout << dec << 38 << '\n';  */

    cout << '|' << setw(8) << "Rae " << '|' << setw(8) << "Davina" 
         << '|' << setw(24) << "vortex@gmail.com"
         << '|' << setw(16) << "111-111" << "|\n"
         << '|' << setw(8) << "Lara " << '|' << setw(8) << "Mcknight"
         << '|' << setw(24) << "imnotcreative@gmail.com"
         << '|' << setw(16) << "111-111" << "|\n";
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something troubling occurred..\n";
    return 2;
}