#include "game.h"
#include <random>


Game::Game(){
    grid = Grid();
    blocks = getBlocks();
    curBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver = false;
}

Block Game::getRandomBlock(){
    return blocks[rand() % blocks.size()];
}

void Game::Draw(){
    grid.Draw();
    curBlock.Draw();
}

vector<Block> Game::getBlocks(){
    return {LBlock(), JBlock(), SBlock(), TBlock(), OBlock(), IBlock(), ZBlock()};
}

void Game::handleInput(){
    int keyPressed = GetKeyPressed();
    if(gameOver && keyPressed != 0){
        gameOver = false;
        Reset();
    }
    switch(keyPressed){
    case KEY_A:
        MoveBlockLeft();
        break;
    case KEY_D:
        MoveBlockRight();
        break;
    case KEY_S:
        MoveBlockDown();
        break;
    case KEY_R:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft(){
    if(gameOver) return;
    curBlock.Move(0, -1);
    if(outsideGrid() || collision())curBlock.Move(0, 1);
}
void Game::MoveBlockRight(){
    if(gameOver) return;
    curBlock.Move(0, 1);
    if(outsideGrid() || collision())curBlock.Move(0, -1);
}
void Game::MoveBlockDown(){
    if(gameOver) return;
    curBlock.Move(1, 0);
    if(outsideGrid() || collision()){
        curBlock.Move(-1, 0);
        FreezeMovement();
    }
}

bool Game::outsideGrid()
{
    for(Positions item:curBlock.getBlockPosition()){
        if(grid.outsideGrid(item.row, item.col)) return true;
    }
    return false;
}

void Game::RotateBlock()
{
    if(gameOver) return;
    curBlock.rotate();
    if(outsideGrid() || collision()) curBlock.undoRotation();
}

void Game::FreezeMovement(){
    for(Positions item:curBlock.getBlockPosition()){
        grid.grid[item.row][item.col] = curBlock.id;
    }
    curBlock = nextBlock;
    if(collision()){
        gameOver = true;
    }
    nextBlock = getRandomBlock();
    grid.cleanCompleted();
}

bool Game::collision(){
    for(Positions item:curBlock.getBlockPosition()){
        if(!grid.isCellEmpty(item.row, item.col)) return true;
    }
    return false;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = getBlocks();
    curBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}
