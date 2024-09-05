#pragma once
#include<map>
#include<vector>
#include "positions.h"
#include "colors.h"

using namespace std;

class Block{
public:
    Block();
    void Draw();
    int id;
    void Move(int x, int y);
    void rotate();
    void undoRotation();
    vector<Positions> getBlockPosition();
    map<int, vector<Positions>> cells;

private:
    int cellSize;
    int rotationState;
    vector<Color> colors;
    int rowOffset, colOffset;
};