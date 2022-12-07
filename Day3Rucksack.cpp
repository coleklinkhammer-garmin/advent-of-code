#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int getPriority(char aChar) {
  if (isupper(aChar)) {
    return aChar - 'A' + 27;
  } else {
    return aChar - 'a' + 1;
  }
}

// Part 1
// int main() {
//   ifstream infile("input.txt");
//   string line;
//   auto totalPriority = 0;

//   while (getline(infile, line)) {
//     auto firstCompartment = line.substr(0, line.size() / 2);
//     auto secondCompartment = line.substr((line.size() / 2), line.size() / 2);
//     cout << "Start New Line: ";

//     for (auto character : firstCompartment) {
//       if (secondCompartment.find(character) != string::npos) {
//         totalPriority += getPriority(character);
//         cout << "Found Char ";
//         cout << character;
//         cout << " for priority ";
//         cout << getPriority(character);
//         cout << "\n";
//         break;
//       }
//     }
//   }

//   cout << totalPriority << "\n";
// }

// Part 2
int main() {
  ifstream infile("input.txt");
  string line;
  string line2;
  string line3;
  auto totalPriority = 0;

  while (getline(infile, line) && getline(infile, line2) &&
         getline(infile, line3)) {
    cout << "Start New Group: ";

    for (auto character : line) {
      if (line2.find(character) != string::npos &&
          line3.find(character) != string::npos) {
        totalPriority += getPriority(character);
        cout << "Found Char ";
        cout << character;
        cout << " for priority ";
        cout << getPriority(character);
        cout << "\n";
        break;
      }
    }
  }

  cout << totalPriority << "\n";
}