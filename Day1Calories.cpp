#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream infile("input.txt");
  string line;
  int maxValue = 0;
  int maxValue2 = 0;
  int maxValue3 = 0;
  int elfTotal = 0;

  while (getline(infile, line)) {
    if (line.size() == 0) {
        if(elfTotal >= maxValue) {
            maxValue3 = maxValue2;
            maxValue2 = maxValue;
            maxValue = elfTotal;
        } else if(elfTotal >= maxValue2) {
            maxValue3 = maxValue2;
            maxValue2 = elfTotal;
        } else if(elfTotal >= maxValue3) {
            maxValue3 = elfTotal;
        }
      elfTotal = 0;
    } else {
      int value = stoi(line);
      elfTotal += value;
    }
  }

  cout << maxValue << "\n";
  cout << maxValue2 << "\n";
  cout << maxValue3 << "\n";
  cout << (maxValue + maxValue2 + maxValue3);
}
