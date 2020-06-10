//
// Created by pc on 2020/6/4.
//

#ifndef RENJU_RULES_H
#define RENJU_RULES_H


#include <list>
#include "ChessBoard.h"

class Rules {
    ChessBoard* chessBoard_;
public:
    explicit Rules(ChessBoard* chessBoard): chessBoard_(chessBoard){}
    int cntThree(ChessMan* chessMan, int dir);
    int cntThree(Pos pos, int color, int dir);
    int cntFour(ChessMan* chessMan, int dir);
    int cntFour(Pos pos, int color, int dir);
    bool checkFive(ChessMan* chessMan, int dir);
    bool checkFive(Pos pos, int color, int dir);
    bool checkLong(ChessMan* chessMan, int dir);
    bool checkLong(Pos pos, int color, int dir);
    int finished();

private:
    std::list<ChessMan> getLine(Pos pos, int dir, int window); // window表示不包括中心点在内的每侧长度
    std::list<ChessMan> getLine(ChessMan* chessMan, int dir, int window);
};


#endif //RENJU_RULES_H
