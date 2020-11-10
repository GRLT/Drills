#include "../std_lib_facilities.h"

int main()
{
    string FirstName = "";
    string Friend_Name = "";
    char Friend_Sex = 0;
    double Age = 0;
    int AgeOfFriend = 0;

    cout << "Enter the name of the person you want to write to" << endl;
    cin >> FirstName;
    cout << "Dear " << FirstName << "," << Friend_Name << endl;
    cout << "How are you?" << endl
         << "I am fine." << endl
         << "I miss you" << endl
         << "How's things?" << endl;
    cout << "Name another friend!" << endl;

    cin >> Friend_Name;
    cout << "Have you seen " << Friend_Name << " lately?" << endl;
    cout << "Please enter your friend gender(m or f)" << endl;
    cin >> Friend_Sex;
    if (Friend_Sex == 'm')
    {
        cout << "If you see " << Friend_Name << " please ask him to call me" << endl;
    }
    else if (Friend_Sex == 'f')
    {
        cout << "If you see " << Friend_Name << " please ask her to call me." << endl;
    }

    cout << "Please enter the age of your friend!" << endl;
    cin >> AgeOfFriend;
    if (AgeOfFriend >= 110 || AgeOfFriend <= 0)
    {
        simple_error("You're kidding!");
    }
    else
    {
        cout << "I hear you just had a birthday and you are " << AgeOfFriend << " years old." << endl;
    }

    if (AgeOfFriend < 12)
    {
        cout << "Next year you will be " << AgeOfFriend + 1 << " years old" << endl;
    }
    else if (AgeOfFriend == 17)
    {
        cout << "Next year you will be able to vote" << endl;
    }
    else if (AgeOfFriend > 70)
    {
        cout << "I hope you're enjoying retirement" << endl;
    }

    cout << "Yours sincerely" << endl << endl << "Laci";
    

    return 0;
}