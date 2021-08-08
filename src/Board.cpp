#include "Board.hpp"

Board::Board(uint16_t rows, uint16_t columns): row_len(rows), col_len(columns)
{
    SetupBoardVals();
}

Board::~Board()
{
    row_len = 0;
    col_len = 0;
    boardVals.clear();
}

void Board::SetDims(uint16_t rows, uint16_t columns)
{
    row_len = rows;
    col_len = columns;
    boardVals = CopyBoard();
}

char Board::GetAt(Coord c)
{
    return boardVals[c.y][c.x];
}

void Board::PlaceAt(Coord crd, char c)
{
    boardVals[crd.y] = betterSubstr(boardVals[crd.y], 0, crd.x) + c + restOfSubstr(boardVals[crd.y], crd.x+1);
}

std::vector<std::string> Board::CopyBoard()
{
    std::vector<std::string> newBoard(col_len);

    //unsure of size increase or decrease, so plan for both/either

    for(int row = 0; row < row_len; row++){
        std::string taken;
        if(row < boardVals.size() - 1) taken = boardVals[row];
        std::string toSet;
        for(int col = 0; col < col_len; col++){
            if(col == col_len-1 || col == 0) toSet += "X";
            else if(row == row_len-1 || row == 0) toSet += "X";
            else if(taken.length() == 0) toSet += " ";
            else if(taken.length()-1 <= col) toSet += " ";
            else toSet += taken[col];
        }
    }
    return newBoard;
}

void Board::SetupBoardVals()
{
    for(int y = 0; y < row_len; y++)
    {
        std::string toAdd = "";
        for(int x = 0; x < col_len; x++)
        {
            if(y == 0 || y == row_len-1 || x == 0 || x == col_len-1) toAdd += "X";
            else toAdd += " ";
        }
        boardVals.push_back(toAdd);
    }
}
