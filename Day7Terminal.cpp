#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class File;

class IContent {
public:
  IContent(string aName) : mName(aName) {}
  virtual ~IContent() = default;

  virtual int GetSize() {
    cout << "Should be overridden\n";
    return 0;
  };
  virtual void Print(){};
  string GetName() const { return mName; }

private:
  string mName;
};

class Directory : public IContent {
public:
  Directory(string aName, Directory *aParent, vector<Directory> aDirectories,
            vector<File> aFiles)
      : IContent(aName), mParent(aParent), mDirectories(aDirectories),
        mFiles(aFiles) {}
  ~Directory() override = default;

  int GetSize() override;
  void Print() override;

  void AddItem(Directory &aNewItem) { mDirectories.push_back(aNewItem); }

  void AddItem(File &aNewItem) { mFiles.push_back(aNewItem); }

  Directory *FindDirectory(string aName) {
    for (int i = 0; i < mDirectories.size(); i++) {
      if (mDirectories[i].GetName() == aName) {
        return &mDirectories[i];
      }
    }
    return nullptr;
  }

  Directory *GetParent() const { return mParent; }

  int GetSmallDirectoriesTotal() {
    int total = 0;
    for (auto dir : mDirectories) {
      total += dir.GetSmallDirectoriesTotal();
      auto size = dir.GetSize();
      if (size < 100000) {
        total += size;
      }
    }
    return total;
  }

  int GetDirectoryToDelete(int aCurrentMatch, int aFreeSpace) {
    int deleterSize = aCurrentMatch;
    string deleterName {};
    for (auto dir : mDirectories) {
      deleterSize = dir.GetDirectoryToDelete(deleterSize, aFreeSpace);
      auto size = dir.GetSize();
      if (size + aFreeSpace >= 30000000 && size < deleterSize) {
        deleterSize = size;
        deleterName = dir.GetName();
      }
    }
    cout << deleterName << "\n";
    return deleterSize;
  }

private:
  Directory *mParent;
  vector<Directory> mDirectories;
  vector<File> mFiles;
};

class File : public IContent {
public:
  File(string aName, Directory *aParent, int aSize)
      : IContent(aName), mParent(aParent), mSize(aSize) {}
  ~File() override = default;

  int GetSize() override { return mSize; }

  void Print() override { cout << GetName() << "\n"; }

  Directory *GetParent() const { return mParent; }

private:
  Directory *mParent;
  int mSize;
};

int Directory::GetSize() {
  auto size = 0;
  for (auto &item : mDirectories) {
    size += item.GetSize();
  }
  for (auto &item : mFiles) {
    size += item.GetSize();
  }
  return size;
}

void Directory::Print() {
  cout << "Directory " << GetName() << "\n";
  for (auto &item : mDirectories) {
    item.Print();
  }
  for (auto &item : mFiles) {
    item.Print();
  }
}

// Part 1
int main() {
  ifstream infile("C:\\grmn\\prj\\otdr\\advent\\inputFull.txt");
  string line;
  int i;
  Directory *currentDirectory;
  stringstream tempSS(line);

  // Build '/' directory before entering loop so we can assume all directories
  // have parents
  getline(infile, line);
  getline(infile, line);

  Directory baseDirectory{"/", nullptr, {}, {}};
  currentDirectory = &baseDirectory;

  while (getline(infile, line)) {
    stringstream ss(line);
    if (line[0] == '$') {
      string dollar;
      string command;
      string arg;
      ss >> dollar >> command >> arg;

      if (command == "cd") {
        if (arg == "..") {
          currentDirectory = currentDirectory->GetParent();
        } else {
          currentDirectory = currentDirectory->FindDirectory(arg);
        }
      } // Else, do nothing since LS is irrelevant
    } else {
      if (line.substr(0, 3) == "dir") {
        string dir;
        string name;
        ss >> dir >> name;

        Directory newDir{name, currentDirectory, {}, {}};
        currentDirectory->AddItem(newDir);
      } else {
        int size;
        string name;
        ss >> size >> name;

        File newFile{name, currentDirectory, size};
        currentDirectory->AddItem(newFile);
      }
    }
  }

  auto freeSpace = 70000000 - baseDirectory.GetSize();
  cout << baseDirectory.GetDirectoryToDelete(70000000, freeSpace);
}