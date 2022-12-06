#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Part 1
int main() {
  ifstream infile("input.txt");
  string line;
  auto totalPriority = 0;
  int i;
  getline(infile, line);

  for (i = 13; i < line.size(); i++) {
    auto subStr = line.substr(i - 13, 14);
    string temp{};
    auto duplicate = false;

    for (auto j = 0; j < subStr.size(); j++) {
      if (temp.find(subStr[j]) != string::npos) {
        duplicate = true;
        break;
      }
      temp += subStr[j];
    }

    if (!duplicate) {
      cout << subStr;
      break;
    }
  }

  cout << i << "\n";
}