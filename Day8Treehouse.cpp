#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Part 1
// bool CheckUp(vector<vector<int>> &aGrid, int aRow, int aColumn) {
//   bool visible = true;

//   for (auto i = aRow - 1; i >= 0; i--) {
//     if ((aGrid[i])[aColumn] >= (aGrid[aRow])[aColumn]) {
//       visible = false;
//       break;
//     }
//   }

//   return visible;
// }

// bool CheckDown(vector<vector<int>> &aGrid, int aRow, int aColumn) {
//   bool visible = true;

//   for (auto i = aRow + 1; i < aGrid.size(); i++) {
//     if ((aGrid[i])[aColumn] >= (aGrid[aRow])[aColumn]) {
//       visible = false;
//       break;
//     }
//   }

//   return visible;
// }

// bool CheckLeft(vector<vector<int>> &aGrid, int aRow, int aColumn) {
//   bool visible = true;

//   for (auto i = aColumn - 1; i >= 0; i--) {
//     if ((aGrid[aRow])[i] >= (aGrid[aRow])[aColumn]) {
//       visible = false;
//       break;
//     }
//   }

//   return visible;
// }

// bool CheckRight(vector<vector<int>> &aGrid, int aRow, int aColumn) {
//   bool visible = true;

//   for (auto i = aColumn + 1; i < aGrid[aRow].size(); i++) {
//     if ((aGrid[aRow])[i] >= (aGrid[aRow])[aColumn]) {
//       visible = false;
//       break;
//     }
//   }

//   return visible;
// }

// // Part 1
// int main() {
//   ifstream infile("C:\\grmn\\prj\\otdr\\advent\\input.txt");
//   string line;

//   vector<vector<int>> grid;

//   while (getline(infile, line)) {
//     vector<int> temp{};

//     for (int i = 0; i < line.size(); i++) {
//       temp.push_back(stoi(line.substr(i, 1)));
//     }

//     grid.push_back(temp);
//   }

//   auto totalVisible = 0;

//   for (auto row = 0; row < grid.size(); row++) {
//     for (auto column = 0; column < grid[row].size(); column++) {
//       auto visible = CheckUp(grid, row, column);
//       if (!visible) {
//         visible = CheckDown(grid, row, column);
//         if (!visible) {
//           visible = CheckLeft(grid, row, column);
//           if (!visible) {
//             visible = CheckRight(grid, row, column);
//           }
//         }
//       }

//       if(visible) {
//         totalVisible++;
//       }
//     }
//   }
//   cout << totalVisible;
// }

// Part 2
int CheckUp(vector<vector<int>> &aGrid, int aRow, int aColumn) {
  int visibleTrees = 0;

  for (auto i = aRow - 1; i >= 0; i--) {
    visibleTrees++;
    if ((aGrid[i])[aColumn] >= (aGrid[aRow])[aColumn]) {
      break;
    }
  }

  return visibleTrees;
}

int CheckDown(vector<vector<int>> &aGrid, int aRow, int aColumn) {
  int visibleTrees = 0;

  for (auto i = aRow + 1; i < aGrid.size(); i++) {
    visibleTrees++;
    if ((aGrid[i])[aColumn] >= (aGrid[aRow])[aColumn]) {
      break;
    }
  }

  return visibleTrees;
}

int CheckLeft(vector<vector<int>> &aGrid, int aRow, int aColumn) {
  int visibleTrees = 0;

  for (auto i = aColumn - 1; i >= 0; i--) {
    visibleTrees++;
    if ((aGrid[aRow])[i] >= (aGrid[aRow])[aColumn]) {
      break;
    }
  }

  return visibleTrees;
}

int CheckRight(vector<vector<int>> &aGrid, int aRow, int aColumn) {
  int visibleTrees = 0;

  for (auto i = aColumn + 1; i < aGrid[aRow].size(); i++) {
    visibleTrees++;
    if ((aGrid[aRow])[i] >= (aGrid[aRow])[aColumn]) {
      break;
    }
  }

  return visibleTrees;
}

int main() {
  ifstream infile("C:\\grmn\\prj\\otdr\\advent\\input.txt");
  string line;

  vector<vector<int>> grid;

  while (getline(infile, line)) {
    vector<int> temp{};

    for (int i = 0; i < line.size(); i++) {
      temp.push_back(stoi(line.substr(i, 1)));
    }

    grid.push_back(temp);
  }

  auto maxScore = 0;

  for (auto row = 1; row < grid.size() - 1; row++) {
    for (auto column = 1; column < grid[row].size() - 1; column++) {
      auto visibleUp = CheckUp(grid, row, column);
      auto visibleDown = CheckDown(grid, row, column);
      auto visibleLeft = CheckLeft(grid, row, column);
      auto visibleRight = CheckRight(grid, row, column);
      auto score = (visibleUp * visibleDown * visibleLeft * visibleRight);

      if (score > maxScore) {
        maxScore = score;
      }
    }
  }

  cout << maxScore;
}
