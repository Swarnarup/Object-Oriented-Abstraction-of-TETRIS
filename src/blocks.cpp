#include "positions.h"
#include "block.h"

class LBlock: public Block{
public:
    LBlock(){
        id = 1;
        cells[0] = {Positions(0, 2), Positions(1, 0), Positions(1, 1), Positions(1, 2)};
        cells[1] = {Positions(0, 1), Positions(1, 1), Positions(2, 1), Positions(2, 2)};
        cells[2] = {Positions(1, 0), Positions(1, 1), Positions(1, 2), Positions(2, 0)};
        cells[3] = {Positions(0, 0), Positions(0, 1), Positions(1, 1), Positions(2, 1)};
    }
};



class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2;
        cells[0] = {Positions(0, 0), Positions(1, 0), Positions(1, 1), Positions(1, 2)};
        cells[1] = {Positions(0, 1), Positions(0, 2), Positions(1, 1), Positions(2, 1)};
        cells[2] = {Positions(1, 0), Positions(1, 1), Positions(1, 2), Positions(2, 2)};
        cells[3] = {Positions(0, 1), Positions(1, 1), Positions(2, 0), Positions(2, 1)};
        // Move(0, 3);
    }
};

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3;
        cells[0] = {Positions(1, 0), Positions(1, 1), Positions(1, 2), Positions(1, 3)};
        cells[1] = {Positions(0, 2), Positions(1, 2), Positions(2, 2), Positions(3, 2)};
        cells[2] = {Positions(2, 0), Positions(2, 1), Positions(2, 2), Positions(2, 3)};
        cells[3] = {Positions(0, 1), Positions(1, 1), Positions(2, 1), Positions(3, 1)};
        // Move(-1, 3);
    }
};

class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4;
        cells[0] = {Positions(0, 0), Positions(0, 1), Positions(1, 0), Positions(1, 1)};
        // Move(0, 4);
    }
};

class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;
        cells[0] = {Positions(0, 1), Positions(0, 2), Positions(1, 0), Positions(1, 1)};
        cells[1] = {Positions(0, 1), Positions(1, 1), Positions(1, 2), Positions(2, 2)};
        cells[2] = {Positions(1, 1), Positions(1, 2), Positions(2, 0), Positions(2, 1)};
        cells[3] = {Positions(0, 0), Positions(1, 0), Positions(1, 1), Positions(2, 1)};
        // Move(0, 3);
    }
};

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;
        cells[0] = {Positions(0, 1), Positions(1, 0), Positions(1, 1), Positions(1, 2)};
        cells[1] = {Positions(0, 1), Positions(1, 1), Positions(1, 2), Positions(2, 1)};
        cells[2] = {Positions(1, 0), Positions(1, 1), Positions(1, 2), Positions(2, 1)};
        cells[3] = {Positions(0, 1), Positions(1, 0), Positions(1, 1), Positions(2, 1)};
        // Move(0, 3);
    }
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;
        cells[0] = {Positions(0, 0), Positions(0, 1), Positions(1, 1), Positions(1, 2)};
        cells[1] = {Positions(0, 2), Positions(1, 1), Positions(1, 2), Positions(2, 1)};
        cells[2] = {Positions(1, 0), Positions(1, 1), Positions(2, 1), Positions(2, 2)};
        cells[3] = {Positions(0, 1), Positions(1, 0), Positions(1, 1), Positions(2, 0)};
        // Move(0, 3);
    }
};