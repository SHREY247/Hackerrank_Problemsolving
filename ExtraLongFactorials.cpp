//Problem Link: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


int multiply(int number, int resultArray[], int resultArraySize) {
    int carry = 0, mulRes;
    
    //Firstly, resultArray[0]=1 and size = 1
    /*
    *   Calculating the result array by multiplying the
    *   existing array with new number
    */
    for(int i=0; i<resultArraySize; i++) {
        mulRes = number * resultArray[i] + carry;
        resultArray[i] = mulRes%10;
        carry = mulRes / 10;
    }

    /*
    *   Updating the result array
    *   with new value in carry
    */
    while(carry) {
        resultArray[resultArraySize++] = carry%10;
        carry = carry / 10;
    }

    // * Returning the updated result array size
    return resultArraySize;
}

void extraLongFactorials(int n) {

    // * Initializing variables
    int resultArray[200], resultArraySize = 1;
    resultArray[0] = 1;

    /*
    *   For each number in the factorial multiplication,
    *   multiply it with the result array and update
    *   the result array size variable
    */
    while(n) {
        resultArraySize = multiply(n--, resultArray, resultArraySize);
    }

    // * Displaying the result array in reverse order
    for(int i=resultArraySize-1; i>=0; i--) {
        cout<<resultArray[i];
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
