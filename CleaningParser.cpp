#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Part 1
// int main() {
//   ifstream infile("input.txt");
//   string line;
//   int elfTotal = 0;

//   while (getline(infile, line)) {
//     stringstream ss(line);

//     int rangeStart1;
//     int rangeEnd1;
//     int rangeStart2;
//     int rangeEnd2;
//     char h1;
//     char h2;
//     char c;
//     ss >> rangeStart1 >> h1 >> rangeEnd1 >> c >> rangeStart2 >> h2 >> rangeEnd2;

//     if((rangeStart1 >= rangeStart2 && rangeEnd1 <= rangeEnd2) ||
//        (rangeStart2 >= rangeStart1 && rangeEnd2 <= rangeEnd1)){
//         elfTotal++;
//        }

//   }

//   cout << elfTotal;
// }

// Part 2
int main() {
  ifstream infile("input.txt");
  string line;
  int elfTotal = 0;

  while (getline(infile, line)) {
    stringstream ss(line);

    int rangeStart1;
    int rangeEnd1;
    int rangeStart2;
    int rangeEnd2;
    char h1;
    char h2;
    char c;
    ss >> rangeStart1 >> h1 >> rangeEnd1 >> c >> rangeStart2 >> h2 >> rangeEnd2;


  if((rangeStart1 >= rangeStart2 && rangeStart1 <= rangeEnd2) ||
     (rangeStart2 >= rangeStart1 && rangeStart2 <= rangeEnd1) ||
     (rangeEnd1 >= rangeStart2 && rangeEnd1 <= rangeEnd2) ||
     (rangeEnd2 >= rangeStart1 && rangeEnd2 <= rangeEnd1) ||
     (rangeStart1 <= rangeStart2 && rangeEnd1 >= rangeEnd2) ||
     (rangeStart2 <= rangeStart1 && rangeEnd2 >= rangeEnd1)) {
      elfTotal++;
     }


  }

  cout << elfTotal;
}
