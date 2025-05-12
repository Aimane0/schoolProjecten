// AIMANE CHAKIRI
// NOG NIET AF


// A
#include <iostream>
#include <string.h>
using namespace std;

string reverse(string &word)
{
  int index = word.size() - 1; // Geeft de hoogste index aan // COMMENTAAR GERA: index unsigned int van maken, want dan worden 2 unsigned vergeleken met elkaar. Niet de zelfde types vergelijken 
  for (unsigned int i = 0; i < index; i++)                   // Niet de zelfde types vergelijken kan complicaties veroorzaken. In dit geval vergelijk ik ze niet, maar is een tip!
                                                             // Consistent zelfde data types gebruiken tijdens vergelijkingen.
  {
    char letter = word[i]; // slaat de letter op, zodat na het swappen van de ene letter de andere ook geswapped kan worden

    word[i] = word[index]; // Swapped de letters

    word[index] = letter; // Swapped weer letters

    index -= 1; // Veranderd de index die vanaf rechts naar links telt
  }
  return word;
}

bool isPalindroom(const string &word)
{
  string orginalWord = word;
  reverse(orginalWord);
  for (unsigned int i = 0; i < word.size(); i++)
  {
    if (word[i] != orginalWord[i])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  string trueWord = "lepel";
  string reversedWord = reverse(trueWord);

  cout << reversedWord << "\n";

  cout << isPalindroom(trueWord);
  return 0;
}