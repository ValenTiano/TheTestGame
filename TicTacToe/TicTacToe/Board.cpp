#include "Board.h"
#include <iostream>

using namespace std;

Board::Board() {
    NewBoard();
}

void Board::NewBoard() {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            _board[x][y] = ' ';
        }
    }
}

char Board::getSymbol(int x, int y) {
    return _board[x][y];
}
void Board::Print() {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            cout << _board[x][y];
            if (y < SIZE-1) {
                cout << "|";
            }
        }
        cout << endl;
        if (x < SIZE-1) {
            for (int i = 0; i < SIZE - 1; i++) {
                cout << "-+";
            }
            cout << "-\n";
        }
    }
}

void Board::PlaceSymbol(int x, int y, char symbol) {
    _board[x-1][y-1] = symbol;
}
