//
// Created by pc on 2020/6/4.
//

#ifndef RENJU_CHESSBOARD_H
#define RENJU_CHESSBOARD_H

#include <ostream>
#include <vector>
#include "ChessMan.h"

class ChessBoard {
    std::vector<std::vector<ChessMan*>> chessManPtrMatrix;
public:
    ChessBoard(): chessManPtrMatrix(15, std::vector<ChessMan*>(15)){}
    ~ChessBoard();
    bool posIsEmpty(Pos pos);
    ChessMan* getChessManByPos(Pos pos);
    ChessMan* getChessManById(int id);
    ChessMan* getChessManWithDir(Pos pos, int dir); // 以上为0，按顺时针计算
    ChessMan* getChessManWithDir(ChessMan* chessMan, int dir);
    void setChessMan(int color, int id, Pos pos);
    void eraseChessMan(ChessMan* chessMan);
    friend std::ostream& operator<<(std::ostream& out, const ChessBoard& chessBoard);

private:
    static void checkOutOfRange(int row, int col);
    static void checkOutOfRange(Pos pos);
};


#endif //RENJU_CHESSBOARD_H
