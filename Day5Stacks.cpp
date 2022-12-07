#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Part 1
int main()
{
    ifstream infile("input.txt");
    string line;

    vector<char> stack1 = {'Q', 'M', 'G', 'C', 'L'};
    vector<char> stack2 = {'R', 'D', 'L', 'C', 'T', 'F', 'H', 'G'};
    vector<char> stack3 = {'V', 'J', 'F', 'N', 'M', 'T', 'W', 'R'};
    vector<char> stack4 = {'J', 'F', 'D', 'V', 'Q', 'P'};
    vector<char> stack5 = {'N', 'F', 'M', 'S', 'L', 'B', 'T'};
    vector<char> stack6 = {'R', 'N', 'V', 'H', 'C', 'D', 'P'};
    vector<char> stack7 = {'H', 'C', 'T'};
    vector<char> stack8 = {'G', 'S', 'J', 'V', 'Z', 'N', 'H', 'P'};
    vector<char> stack9 = {'Z', 'F', 'H', 'G'};

    vector<vector<char>> stacks = {stack1, stack2, stack3, stack4, stack5, stack6, stack7, stack8, stack9};

    for (int i = 0; i < 9; i++)
    {
        getline(infile, line);
    }

    while (getline(infile, line))
    {
        stringstream ss(line);

        string temp;
        int movingCount;
        int movingFrom;
        int movingTo;

        ss >> temp >> movingCount >> temp >> movingFrom >> temp >> movingTo;

        movingFrom--;
        movingTo--;
        vector<char> tempVec = {};
        for (int i = 0; i < movingCount && stacks[movingFrom].size() > 0; i++)
        {
            tempVec.push_back(stacks[movingFrom].back());
            stacks[movingFrom].pop_back();
        }

        while(tempVec.size() > 0)
        {
            stacks[movingTo].push_back(tempVec.back());
            tempVec.pop_back();
        }
    }

    for (auto stack : stacks)
    {
        cout << stack.back() << "\n";
    }
}
