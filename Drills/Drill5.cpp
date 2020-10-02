#include "../std_lib_facilities.h"
// Correct Code is stored strictly in /* */ Comments
int main()
try
{
    //1. Cout << "Success!\n"; Error due to using capital 'C' when calling  cout
    /* Correct Code for 1.
    cout << "Success!\n";
    */

    //2. cout << "Success!\n; Missing Closing Quotation Mark "
    /*Correct Code for 2.
    cout << "Success!\n";
    */

    //3. cout << "Success" << !\n" Missing Opening Quotation Mark in the second string, also missing semicolon at the end
    /* Correct Code for 3.
    cout << "Success" << "!\n";
    */

    //4. cout << success << '\n'; Variable succes is not defined either changing it to a String or declarion outside is an option
    /* Correct Code for 4.
    string success = "Success!";
    cout << success << '\n';
    */

    //5. string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n"; res is declared to be a string yet a number was assigned to it (Type Error)
    //Due to future operations with res it should be redecleared to be an int beacuse the vector which res will interact with is decleared to be an vector<int>
    /* Correct Code for 5.
    int res = 7; 
    vector<int> v(10); 
    v[5] = res; 
    cout << "Success!\n";
    */

    //6. vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";
    //Syntax Error when trying to uses vector. While using a vector [] need to be used
    //Logical Error The program will never execute the if statement beacuse v[5] contains 7
    /*Correct Code for 6.
    vector<int> v(10);
    v[5] = 7;
        if (v[5]==7)
            cout << "Success!\n";
    */

    //7. if (cond) cout << "Success!\n"; else cout << "Fail!\n";
    // cond is not declared
    /* Correct Code for 7.
   bool cond = true;
    if (cond) 
        cout << "Success!\n"; 
    else 
        cout << "Fail!\n";
    */

    //8. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
    // Logical Error if will never be true beacuse c was declared to be false
    /* Correct Code for 8.
    bool c = true;
    if (c) 
        cout << "Success!\n"; 
    else 
        cout << "Fail!\n";
    */

    //9. string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
    // Syntax error with boo it should be bool and c value has a logic error where < should be change to >
    /* Correct Code for 9.
    string s = "ape";
    bool c = "fool">s;
    if (c)
        cout << "Success!\n";
    */

    //10. string s = "ape"; if (s=="fool") cout << "Success!\n";
    // (Logic Err)Never enters into the if statement beacuse s isn't containts "fool" or the condition in the if statement  should contain "ape"
    /* Correct Code for 10.
    string s = "fool"; 
    if (s=="fool") 
        cout << "Success!\n";
    */

    // 11. string s = "ape"; if (s=="fool") cout < "Success!\n";
    // Syntax Error missing << inside the if statement, never enter into the if because if condition contains "fool" while s is "ape" either chancing the condition or the 's' value
    /* Correct Code for 11.
    string s = "fool";
    if (s=="fool") 
        cout << "Success!\n";
    */

    //12. string s = "ape"; if (s+"fool") cout < "Success!\n";
    //Syntax Error missing "<<" inside if, string has to be changed to bool or converted to bool beacuse if statment can't do anything with the string
    /* Correct Code for 12.
    bool s = "ape";
    if (s+"fool") 
        cout << "Success!\n";
    */

    //13. vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n";
    // For loop 2. conidition contains '0' instead of 'i' when using '0' it will be an infinite loop while using i it will only run it till the vector size, semicolon at the end of for loops should be removed
    /* Correct Code for 13.
    vector<char> v(5);
    for (int i = 0; i < v.size(); ++i)
        cout << "Success!\n";
    */

    //14. vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
    //It only goes trough the for loop once due to the semicolon and execute "Success" only once removing the semicolon will fix the problem
    /* Correct Code For 14.
    vector<char> v(5);
    for (int i=0; i<=v.size(); ++i)
        cout << "Success!\n";
    */

    //15. string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
    //Range error due to the second condition of the for which will miss the last charachter of "Success" and it'l also miss the whitespace"
    //To fix it either chaning the range for 9 so it includes 's' and the whitespace or if we wanted to be more dynamic we'll just use s.size();
    /* Correct Code For 15.
    string s = "Success!\n";
    for (int i = 0; i < s.size(); ++i)
        cout << s[i];
    */

    //16. if (true) then cout << "Success!\n"; else cout << "Fail!\n";
    //Syntax error when using "then" beacuse after if we use {} when using executing multiple line
    /* Correct Code For 16.
    if (true)
        cout << "Success!\n"; 
    else 
        cout << "Fail!\n";
    */

    //17. int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
    //Char cannot store 2000 so it will assign itself with a weird letter then the condition fails chaing char into int will fix the prob
    /* Correct Code For 17.
    int x = 2000;
    int c = x;
    if (c == 2000)
        cout << "Success!\n";
    */

    //18. string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];
    // Don't have any problem but I think it's better to change the second statement of the for loop to i < s.length()
    /*
    string s = "Success!\n";
    for (int i = 0; i < 10; ++i)
        cout << s[i];
    */

    //19. vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
    // vector doesn't have a header which defines the type, changing it to an int will fix the problem
    /* Correct Code For 19.
    vector<int> v(5);
    for (int i = 0; i <= v.size(); ++i)
    cout << "Success!\n";
    */

    //20. int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
    // In the while loop instead of j, i needs to be incremented beacuse it'll loop around till the i becomes a larger number and then if condition will exectue
    /* Correct Code for 20.
    int i = 0;
    int j = 9;
    while (i < 10)
        ++i;
    if (j < i)
        cout << "Success!\n";
    */

    //21. int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n";
    // X-2 will result 0 and dividing with zero is not good. logic err
    /* Correct Code for 21.
    int x = 2;
    double d = 5 / (x - 1);
    if (d == 2 * (x + 0.5))
        cout << "Success!\n";
    */

    //22. string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];
    //Instead of vector string is being used Syntrax err, Insted of <char> string is needed, then the string need to be pushed into the vector via push_back()
    //Finally For statement second condition is containing <= which gives a range error it need to be only < 
    /* Correct Code For 22.
    vector<string> s;
    s.push_back("Success!\n");
    for (int i = 0; i < s.size(); ++i)
        cout << s[i];
    */

    //23. int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n";
    // j is not declared, in the while loop i should be incremented instead of j 
    /* Correct Code For 23.
    int i = 0;
    int j = 0;
    while (i < 10)
        ++i;
    if (j < i)
        cout << "Success!\n";
    */

    //24. int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n";
    // Code run without an error
    /*
    int x = 4;
    double d = 5 / (x-2);
    if (d = 2 * x + 0.5)
        cout << "Success!\n";
    */

    //25. cin << "Success!\n";
    //In order to write out to console we use cout, cin in is used to get input from the user trough console
    /*Corret Code For 25.
    cout << "Success!\n";
    */
    return 0;
}
catch (exception &e)
{
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Oops: unknown exception!\n";
    return 2;
}