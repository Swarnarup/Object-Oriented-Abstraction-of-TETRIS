#pragma once
#include <vector>
#include <raylib.h>

using namespace std;

class Grid{
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool outsideGrid(int x, int y);
    bool isCellEmpty(int x, int y);
    int cleanCompleted();
    vector<vector<int>> grid;

private:
    bool rowFull(int row);
    void clearRow(int row);
    void lowerRow(int row, int cnt);
    int numRows, numCols, cellSize;
    vector<Color> colors;
};