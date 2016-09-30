#pragma once
class Board
{
    static const int SIZE = 3;
public:
    Board();
    void NewBoard();
    void PrintBoard();
private:
    char* _board[SIZE][SIZE];
};

