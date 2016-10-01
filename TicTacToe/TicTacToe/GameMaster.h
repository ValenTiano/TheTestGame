#pragma once
#include "Board.h"

class GameMaster
{
    static const int PLAYERS_NUM = 2;
public:
    GameMaster();
    void StartGame();
private:
    int _emptyCells;
    void _MakeTurn();
    bool _isWinner;
    void _CheckWinner();
    char _players[PLAYERS_NUM];
    int _currentPlayerNum;
    Board _board;
    void _ChangePlayer();
};

