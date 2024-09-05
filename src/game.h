#pragma once

#include "blocks.cpp"
#include "grid.h"
// #include <vector>


class Game
{
public:
    Game();
    Block getRandomBlock();
    void Draw();
    vector<Block> getBlocks();
    void handleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockUp();
    void MoveBlockDown();
    void FreezeMovement();
    bool collision();
    bool gameOver;
    void Reset();
    Grid grid;

private:
    std::vector<Block> blocks;
    Block curBlock;
    Block nextBlock;
    bool outsideGrid();
    void RotateBlock();
};