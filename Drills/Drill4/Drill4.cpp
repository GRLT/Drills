#include "../std_lib_facilities.h"
const double cm_to_m = 0.01;
const double in_to_m = 2.54 * cm_to_m;
const double ft_to_m = 12.0 * in_to_m;
const vector<string> legal_units{"cm", "m", "in", "ft"};

bool legalUnit(string unit) //Checks if unit is entered correctly!
{
    bool legal = false;
    for (auto legal_unit : legal_units)
    {
        if (unit == legal_unit)
        {
            legal = true;
        }
    }
    return legal;
}

double convertToMeter(double val, string unit) //Conversion
{
    if ("cm" == unit)
    {
        return val * cm_to_m;
    }
    else if ("in" == unit)
    {
        return val * in_to_m;
    }
    else if ("ft" == unit)
    {
        return val * ft_to_m;
    }
    else
    {
        return val;
    }
}

int main()
{

    cout << "Enter a value followed by the unit: ";

    double in = 0.0;
    double inMeter = 0.0;
    double smallest = 0.0;
    double largest = 0.0;
    string unit = " ";
    int count = 0;
    double sum = 0.0;
    vector<double> values(0);

    cout << "\tcm for centimeters\n"
         << "\tm for meters\n"
         << "\tin for inches\n"
         << "\tft for feet\n";

    while (cin >> in >> unit)
    {

        if (legalUnit(unit))
        {
            inMeter = convertToMeter(in, unit);
            cout << in << unit;
            if (unit != "m")
            {
                cout << " (" << inMeter << "m)";
            }

            if (0 == count)
            {
                smallest = in;
                largest = in;

                cout << " is the first value and therefore the smallest and largest so far.\n";
            }
            else if (in < smallest)
            {
                cout << " the smallest so far.\n";
                smallest = inMeter;
            }
            else if (inMeter > largest)
            {
                cout << " the largest so far.\n";
                largest = inMeter;
            }
            else
            {
                cout << '\n';
            }
            sum += in;
            values.push_back(inMeter);
            count++;
        }
        else
        {
            cout << "Error: no legal unit. Enter one of \n";
            cout << "\tcm for centimeters\n"
                 << "\tm for meters\n"
                 << "\tin for inches\n"
                 << "\tft for feet\n";
        }
    }

    cout << "The smallest: " << smallest << "m\n"
         << "The largest: " << largest << "m\n"
         << "Number of values entered: " << count << '\n'
         << "The sum of values: " << sum << "m\n";

    sort(values);

    cout << "The entered values in sorted order: ";
    for (auto value : values)
    {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}