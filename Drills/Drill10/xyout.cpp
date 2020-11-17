#include "../../std_lib_facilities.h"
//Basic Structure of Points
struct Point {
    int x;
    int y;
};

//Format for INPUT
istream& operator>>(istream& is, Point& p)
{
    char ch1;
    if (is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    char ch3;
    int xx;
    int yy;
    is >> xx >> ch2 >> yy >> ch3;
    if (!is || ch3 != ')') {
        if (is.eof()) return is;
        error("bad point");
    }
    p.x = xx;
    p.y = yy;
    return is;
}

//Format for OUTPUT
ostream& operator<<(ostream& os, Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

//Used when reading in from a txt
void fill_from_file(vector<Point>& points, string& name)
{
    ifstream ist {name};
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    if (!ist) error("can't open input file ", name);
    for (Point p; ist >> p; )
        points.push_back(p);
}

//MAIN
int main()
try {
    cout << "Please enter seven sets of x, y points:\n";
    cout << "For Exaple (x,y)\n";
    vector<Point> original_points;
    
    //Read in 7 POINTS into VECTOR NO.1
    while (original_points.size() < 7) {
        Point p;
        cin >> p;
        original_points.push_back(p);
    } 

    //Write out 7 POINTS to CONSOLE
    for (Point p : original_points)
        cout << p;
    cout << '\n';

    //Name of output file
    string fname = "mydata.txt";

    ofstream ost { fname };
    if (!ost) error("could not open file ", fname);
    //Write out 7 POINTS to FILE
    for (Point p : original_points)
        ost << p;
    ost.close();


    vector<Point> processed_points;
    
    //Reads the TXT file and puts them into VECTOR NO.2
    fill_from_file(processed_points, fname);
    
    //Writes out VECTOR NO 2 to CONSOLE
    for (Point p : processed_points)
        cout << p;
    cout << '\n';

    //Prints out an error to Connsole if the 2 VECTORS are not the same
    if (original_points.size() != processed_points.size())
        cout << "Something's wrong!\n";
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Something terrible has happened!\n";
    return 2;
}