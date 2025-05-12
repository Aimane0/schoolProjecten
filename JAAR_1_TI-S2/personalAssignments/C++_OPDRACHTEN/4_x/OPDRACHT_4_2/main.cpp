#include "winners.hpp"

int main(){
  vector<float> results {5.322,8.76,2.12,745,98.1,23.6,87.3};

  float winner = nearestScore2Average(results);
  float mole = furthestScoreFromWinner(results);

  cout << "De winnaar is: " << winner << "\n";
  cout << "De mol is: " << mole << "\n";

  return 0;
}