#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

#include "Utils.hpp"
class Board
{
    public:
        Board(uint16_t rows, uint16_t columns);
        ~Board();
        void SetDims(uint16_t rows, uint16_t columns);
        char GetAt(Coord c);
        void PlaceAt(Coord crd, char c);
        inline std::vector<std::string> GetBoard() {return boardVals;}
    private:
        std::vector<std::string> CopyBoard();
        void SetupBoardVals();
        
        uint16_t row_len, col_len;
        std::vector<std::string> boardVals;
};

#endif