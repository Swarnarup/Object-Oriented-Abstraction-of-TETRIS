#include "block.h"

Block::Block(){
    cellSize = 30;
    rotationState = 0;
    rowOffset = 0, colOffset = 0;
    colors = GetColors();
}

void Block::Draw(){
    vector<Positions> tiles = getBlockPosition();
    for(Positions item:tiles){
        DrawRectangle(item.col*cellSize + 26, item.row*cellSize + 26, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int x, int y) {
    rowOffset += x;
    colOffset += y;
}

void Block::rotate()
{
    rotationState = (rotationState+1)%4;
}

void Block::undoRotation()
{
    rotationState = (rotationState-1+4)%4;
}

vector<Positions> Block::getBlockPosition(){
    vector<Positions> temp;
    for(Positions item:cells[rotationState]){
        temp.push_back(Positions(item.row + rowOffset, item.col + colOffset));
    }
    
    return temp;
}