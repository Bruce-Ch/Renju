//
// Created by pc on 2020/6/4.
//

#include <stdexcept>
#include "Rules.h"
using namespace std;

int Rules::cntThree(ChessMan *chessMan, int dir) {
    int cnt = 1;
    ChessMan* chessManFront = chessMan;
    ChessMan* chessManBack = chessMan;
    int color = chessMan->getColor();
    while (true){
        chessManFront = chessBoard_->getChessManWithDir(chessManFront, getReverseDir(dir));
        if(!chessManFront) { break;}
        cnt++;
        //TODO:修改数据结构
    }

}