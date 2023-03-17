#include <iostream>

const int Cities = 5;
const int Years = 4;

int main() {
  using namespace std;
  const string cities[Cities] = {
    "Gribble City",
    "Gribbletown",
    "New Gribble",
    "San Gribble",
    "Gribble Vista"
  };
  int maxtemps[Years][Cities] = {
    { 96, 100, 87, 101, 105 },
    { 96, 98, 91, 107, 104 },
    { 97, 101, 93, 108, 107 },
    { 98, 103, 95, 109, 108 }
  };

  cout << "        \e[1mMaxium temperatures for 2008 - 2011\e[0m\n\n";
  cout << "\e[1m";
  cout.width(16);
  cout << "Name" << " | ";
  for (int year = 0; year < Years; ++year) {
    cout.width(8);
    cout << 2008 + year;
  }
  cout << "\e[0m" << endl;
  for (int city = 0; city < Cities; ++city) {
    cout.width(16);
    cout << cities[city] << " | ";
    for (int year = 0; year < Years; ++year) {
      cout.width(8);
      cout << maxtemps[year][city];
    }
    cout << endl;
  }

  return 0;
}
