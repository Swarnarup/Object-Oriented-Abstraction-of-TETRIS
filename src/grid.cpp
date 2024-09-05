#include "grid.h"
#include <iostream>
#include "colors.h"
using namespace std;

Grid::Grid()
{
    numRows = 30;
    numCols = 20;
    cellSize = 30;
    grid = vector<vector<int>>(numRows, vector<int>(numCols, 0));
    Initialize();
    colors = GetColors();
}

void Grid::Initialize()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::Print()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void Grid::Draw()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            int cellVal = grid[i][j];
            DrawRectangle(j * cellSize + 26, i * cellSize + 26, cellSize - 1, cellSize - 1, colors[cellVal]);   // 26 = 50/2 + 1
        }
    }
}

bool Grid::outsideGrid(int x, int y){
    return x<0 || x>=numRows || y<0 || y>=numCols;
}

bool Grid::isCellEmpty(int x, int y){
    return grid[x][y] == 0;
}

int Grid::cleanCompleted()
{
    int completed = 0;
    for(int i = numRows - 1; i>=0; i--){
        if(rowFull(i)){
            completed++;
            clearRow(i);
        }
        else if(completed > 0) lowerRow(i, completed);
    }

    return completed;
}

bool Grid::rowFull(int row){
    for(int j = 0; j<numCols; j++)if(grid[row][j] == 0)return false;
    return true;
}

void Grid::clearRow(int row)
{
    for(int j = 0; j<numCols; j++)grid[row][j] = 0;
}

void Grid::lowerRow(int row, int cnt){
    for(int i = 0; i<numCols; i++)grid[row + cnt][i] = grid[row][i], grid[row][i] = 0;
}