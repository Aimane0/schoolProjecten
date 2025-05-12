// AIMANE CHAKIRI 

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortVector(vector<int> & v)
{
    for (unsigned int i = 0; i < v.size() -1; i++)
    {
        for (unsigned int j = i + 1; j < v.size(); j++)
        {
            if (v[i] >= v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }
    return v;
}

int main()
{
    vector<int> vect{55, 53, 67, 39, 66, 12, 5, 79};
    for (unsigned int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }
    cout << "\n";

    sortVector(vect);
    for (unsigned int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }
}