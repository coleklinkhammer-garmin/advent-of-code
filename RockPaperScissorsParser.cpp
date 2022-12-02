#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum class Item { Rock, Paper, Scissors, Count };

Item getItem(char aChar) {
  switch (aChar) {
  case 'A':
  case 'X':
    return Item::Rock;

  case 'B':
  case 'Y':
    return Item::Paper;

  case 'C':
  case 'Z':
    return Item::Scissors;

  default:
    return Item::Count;
  }
}

int getItemPoints(Item aItem) {
  switch (aItem) {
  case Item::Rock:
    return 1;

  case Item::Paper:
    return 2;

  case Item::Scissors:
    return 3;

  default:
    return -1;
  }
}

int getLetterPoints(char aChar) {
  switch (aChar) {
  case 'X':
    return 0;

  case 'Y':
    return 3;

  case 'Z':
    return 6;

  default:
    return 0;
  }
}


int getRoundPoints(Item aOppItem, char aMyLetter) {
  if (aOppItem == Item::Rock) {
    switch (aMyLetter) {
    case 'X':
      return 3;

    case 'Y':
      return 1;

    case 'Z':
      return 2;
    }
  } else if (aOppItem == Item::Paper) {
    switch (aMyLetter) {
    case 'X':
      return 1;

    case 'Y':
      return 2;

    case 'Z':
      return 3;
    }
  } else if (aOppItem == Item::Scissors) {
    switch (aMyLetter) {
    case 'X':
      return 2;

    case 'Y':
      return 3;

    case 'Z':
      return 1;
    }
  }
  return 0;
}

int main() {
  ifstream infile("input.txt");
  string line;
  int total = 0;

  while (getline(infile, line)) {
    auto oppItem = getItem(line[0]);
    auto myPoints = getLetterPoints(line[2]);
    auto roundPoints = getRoundPoints(oppItem, line[2]);
    total += (roundPoints + myPoints);
  }

  cout << total << "\n";
}
