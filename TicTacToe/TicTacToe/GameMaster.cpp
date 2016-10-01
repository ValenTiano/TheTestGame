#include "GameMaster.h"
#include <iostream>

using namespace std;

GameMaster::GameMaster()
{
    _currentPlayerNum = 0;
    _isWinner = false;
    _players[0] = 'X';
    _players[1] = 'O';
    _emptyCells = _board.SIZE * _board.SIZE;

}

void GameMaster::StartGame() {
    cout << "---- NEW GAME STARTED ----\n\n";
    _board.Print();
    while (!_isWinner && _emptyCells > 0) {
        _MakeTurn();
        _CheckWinner();
        if (_isWinner) {
            cout << "Winner is " << _players[_currentPlayerNum] << endl;
        } else if (_emptyCells > 0) {
            _ChangePlayer();
            _emptyCells--;
        } else {
            cout << "There is no Winner!!" << endl;
            return;
        }
    }
}

void GameMaster::_CheckWinner() {
    char symbolVert = ' ';
    char symbolHori = ' ';
    int numOfSymbolsVert = 0;
    int numOfSymbolsHori = 0;
    for (int x = 0; x < _board.SIZE; x++) {
        symbolHori = _board.getSymbol(x, 0);
        symbolVert = _board.getSymbol(0, y);
        if (symbolHori != _board.emptyCell && symbolVert != _board.emptyCell) {
            numOfSymbolsHori = 1;
            numOfSymbolsVert = 1;
            for (int y = 1; y < _board.SIZE; y++) {
                //check horizontaly
                if (symbolHori == _board.getSymbol(x, y)) {
                    if (++numOfSymbolsHori == 3) {
                        _isWinner = true;
                        cout << " horizontal Winner" << endl;
                        return;
                    }
                }
                //check verticaly
                if (symbolVert == _board.getSymbol(y, x)) {
                    if (++numOfSymbolsVert == 3) {
                        _isWinner = true;
                        cout << " vertical Winner" << endl;
                        return;
                    }
                }
            }
        }
    }
    //check diagonaly
    if ((_board.getSymbol(1, 1) != _board.emptyCell) && (((_board.getSymbol(1, 1) == _board.getSymbol(0, 0)) && (_board.getSymbol(1, 1) == _board.getSymbol(2, 2)))
                                         || ((_board.getSymbol(1, 1) == _board.getSymbol(0, 2)) && (_board.getSymbol(1, 1) == _board.getSymbol(2, 0))))) {
        _isWinner = true;
        cout << " diagonal Winner" << endl;
        return;
    }
    //check vertical


    //check diagonal
}

void GameMaster::_MakeTurn() {
    int x, y;
    cout << "Now is \"" << _players[_currentPlayerNum] << "\"turn" << endl << "Enter, row number: ";
    cin >> x;
    cout << "Enter, column number:";
    cin >> y;
    cout << endl;
    if (_board.getSymbol(x - 1, y - 1) == _board.emptyCell) {
        _board.PlaceSymbol(x, y, _players[_currentPlayerNum]);
        _board.Print();
    } else {
        cout << "Sory there, are symbol alredy \n";
        _MakeTurn();
    }
}

void GameMaster::_ChangePlayer() {
    if (_currentPlayerNum == PLAYERS_NUM - 1) {
        _currentPlayerNum = 0;
    } else {
        _currentPlayerNum++;
    }
}