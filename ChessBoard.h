//
// Created by pc on 2020/6/4.
//

#ifndef RENJU_CHESSBOARD_H
#define RENJU_CHESSBOARD_H

#include <ostream>
#include "ChessMan.h"
#include "Rules.h"

class ChessBoard {
public:
    bool posIsEmpty(Pos pos);
    ChessMan* getChessManByPos(Pos pos);
    ChessMan* getChessManById(int id);
    ChessMan* getChessManWithDir(Pos pos, int dir); // 以上为0，按顺时针计算
    ChessMan* getChessManWithDir(ChessMan* chessMan, int dir);
    void setChessMan(int color, Pos pos);
    void eraseChessMan(ChessMan* chessMan);
    friend std::ostream& operator<<(std::ostream& out, ChessBoard chessBoard);
};


#endif //RENJU_CHESSBOARD_H
