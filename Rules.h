//
// Created by pc on 2020/6/4.
//

#ifndef RENJU_RULES_H
#define RENJU_RULES_H


#include "ChessBoard.h"

class Rules {
    ChessBoard* chessBoard_;
public:
    Rules(ChessBoard* chessBoard): chessBoard_(chessBoard){}
    int cntThree(ChessMan* chessMan, int dir);
    int cntThree(Pos pos, int color, int dir);
    int cntFour(ChessMan* chessMan, int dir);
    int cntFour(Pos pos, int color, int dir);
    int checkFive(ChessMan* chessMan, int dir);
    int checkFive(Pos pos, int color, int dir);
    int checkLong(ChessMan* chessMan, int dir);
    int checkLong(Pos pos, int color, int dir);
    int finished();
};


#endif //RENJU_RULES_H
