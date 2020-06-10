//
// Created by pc on 2020/6/4.
//

#include <stdexcept>
#include "Rules.h"
using namespace std;

std::list<ChessMan> Rules::getLine(Pos pos, int dir, int window) {
    list<ChessMan> chessManList(1, *chessBoard_->getChessManByPos(pos));
    ChessMan* chessMan = chessBoard_->getChessManByPos(pos);
    for(int i = 0; i < window; i ++){
        try {
            chessMan = chessBoard_->getChessManWithDir(chessMan, dir);
            chessManList.push_back(*chessMan);
        } catch (out_of_range&){
            break;
        }
    }
    chessMan = chessBoard_->getChessManByPos(pos);
    for(int i = 0; i < window; i ++){
        try {
            chessMan = chessBoard_->getChessManWithDir(chessMan, (dir + 4) % 8);
            chessManList.push_front(*chessMan);
        } catch (out_of_range&){
            break;
        }
    }
    return chessManList;
}

std::list<ChessMan> Rules::getLine(ChessMan *chessMan, int dir, int window) {
    return getLine(chessMan->getPos(), dir, window);
}

int Rules::cntThree(ChessMan *chessMan, int dir) {

}