// AIMANE CHAKIRI 

#include <iostream>
#include <vector>
using namespace std;

vector<int> n = {1, 0, 1, 1, 1, 0, 0, 1, 1, 1};
vector<int> m = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

string count(const vector<int> &numbers, const int x)
{
    int total0 = 0;
    int total1 = 0;

    if (x == 1)
    {

        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == 0)
            {
                total0 += 1;
            }
            if (numbers[i] == 1)
            {
                total1 += 1;
            }
        }
        if (total1 > total0)
        {
            return "There are more ones than zeros in this vector.";
        }
        if (total0 > total1)
        {
            return "There are more zeros than ones in this vector";
        }
    }

    if (x == 0)
    {

        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == 0)
            {
                total0 += 1;
            }
            if (numbers[i] == 1)
            {
                total1 += 1;
            }
        }
        if (total0 >= 13)
        {
            return "There are more than twelves zeros in this vector! This is not allowed!";
        } else {
            return "There are less than twelve zeros in this vector!";
        }
    }
}

int main()
{

    cout << "Select 0 to check if the amount of zeros is bigger than twelve." << "\n";
    cout << "Select 1 to check if the amount of ones is bigger than zero." << "\n";
    int selectedCheck;
    cin >> selectedCheck;

    string result1 = count(n, selectedCheck);
    cout << "The result for vector n: " << result1 << "\n";

    string result2 = count(m, selectedCheck);
    cout << "The result for vector m: " << result2 << "\n";
}