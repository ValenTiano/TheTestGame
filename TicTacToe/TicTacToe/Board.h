#pragma once
class Board
{
public:
    static const int SIZE = 3;
    static const char emptyCell = ' ';
    Board();
    void NewBoard();
    void Print();
    void PlaceSymbol(int x, int y, char symbol);
    char getSymbol(int x, int y);
private:
    char _board[SIZE][SIZE];
};

