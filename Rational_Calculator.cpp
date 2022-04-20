// FCAI - Programming 1 - 2022 - Assignment 2 
// Program Name: Rational number calculator
// Program Description: taking two rational numbers and an operation to perform on them
// Last Modification Date: 22/3/2022
// First author / ID : Habiba Alaa Mohamed / 20210121
// Second author / ID : Alaa Hossam Mohamed / 20210072
// Third author / ID : Ahmed Reda Elsayed / 20210018 
// Under The Supervision of: Dr. Mohamed El-Ramly


#include <iostream>
#include <regex>
#include <cstring>
using namespace std;

int n, d, nu, du, num, den;


bool isvalidrational(string& str)
{
    regex validrational("[-+]?[0-9]+(/[1-9][0-9]*)?"); // expression represent the form of the rational (a/b)
    return regex_match(str, validrational); // check if the input correspond the expression that represent the form of the rational (a/b)
}

void first_input()
{
    string str;
    cout << "enter first rational number in form a/b" << endl;
    cin >> str;
    string str2 = "/";


    if (isvalidrational(str))
    {
        cout << "this is a valid rational" << endl;

        size_t _find = str.find(str2); // find the '/' and get it's index

        string part = str.substr(0, _find); // extract anything before the '/' (numerator)
        n = stoi(part); // convert string to integer

        string part2 = str.substr(_find + 1); // extract anything after the '/' (denemenator)
        d = stoi(part2); // convert string to integer
    }
    else
    {
        cout << "invalid rational" << endl;
        exit(0);
    }
    cout << endl;
}

void sec_input()
{
    string stri;
    cout << "enter second rational number in form a/b" << endl;
    cin >> stri;
    string stri2 = "/";


    if (isvalidrational(stri))
    {
        cout << "this is a valid rational" << endl;

        size_t _find = stri.find(stri2); // find the '/' and get it's index

        string part = stri.substr(0, _find); // extract anything before the '/' (numerator)
        nu = stoi(part); // convert string to integer

        string part2 = stri.substr(_find + 1); // extract anything after the '/' (denemenator)
        du = stoi(part2); // convert string to integer
    }
    else
    {
        cout << "invalid rational" << endl;
        exit(0);
    }
    cout << endl;
}

void simplification(int a, int b) // function to simplify the result
{
    bool e = true;
    for (int i = (a * b); i > 1; i--)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            a = a / i;
            b = b / i;

        }
        else
        {
            e = false;
        }
    }
    cout << "simplest form=" << a << "/" << b << endl;
}

void addition() // function that make addition between first and second rational inputs
{
    num = (n * du) + (nu * d);
    den = (d * du);
    cout << "addition result = " << num << "/" << den << endl;
    simplification(num, den);
}

void subtraction() // function that make subtraction between first and second rational inputs
{
    num = (n * du) - (nu * d);
    den = (d * du);
    cout << "subtraction result = " << num << "/" << den << endl;
    simplification(num, den);
}

void multiplication() // function that make multiplication between first and second rational inputs
{
    num = (n * nu);
    den = (d * du);
    cout << "multiplication result = " << num << "/" << den << endl;
    simplification(num, den);
}

void division() // function that make division between first and second rational inputs
{
    num = (n * du);
    den = (d * nu);
    cout << "division result = " << num << "/" << den << endl;
    simplification(num, den);
}

int main()
{
    cout << "1- addition" << endl;
    cout << "2- subtraction" << endl;
    cout << "3- multiplication" << endl;
    cout << "4- division " << endl;
    cout << "5- End" << endl;
    cout << "choose ur operation: ";

    int o;
    cin >> o;

    while ((o < 1) || (o > 5))
    {
        cout << "wrong choice, please choose again from 1 to 5" << endl;
        cin >> o;
    }
    if (o == 1)
    {

        first_input();
        sec_input();
        addition();
    }
    else if (o == 2)
    {
        first_input();
        sec_input();
        subtraction();
    }
    else if (o == 3)
    {

        first_input();
        sec_input();
        multiplication();
    }
    else if (o == 4)
    {
        first_input();
        sec_input();
        division();
    }
    else
    {
        cout << "End" << endl;
    }
}