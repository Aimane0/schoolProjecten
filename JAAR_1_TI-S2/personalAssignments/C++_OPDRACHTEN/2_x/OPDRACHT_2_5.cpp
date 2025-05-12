// AIMANE CHAKIRI 

#include <iostream>
#include <vector>
using namespace std;

int count(const vector<int> &numbers, const int x)
{
    int totalCount = 0;
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == x)
        {
            totalCount += 1;
        }
    }
    return totalCount;
}

int main()
{
    vector<int> n = {37, 4, 9, 4, 9, 37, 3, 5, 4, 1, 9};

    int selectedNumber;
    cout << "Select a number: ";
    cin >> selectedNumber;

    int numberWeAreSearchingFor = count(n, selectedNumber);
    cout << "Amount of " << selectedNumber << " in the vector: " << numberWeAreSearchingFor << "\n";
}
