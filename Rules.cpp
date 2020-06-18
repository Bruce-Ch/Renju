//
// Created by pc on 2020/6/4.
//

#include <stdexcept>
#include "MyErrors.h"
#include "Rules.h"
using namespace std;

vector<int> Rules::getLine(ChessMan *chessMan, int dir, int window) {//同1异0空2 一个异则都是异
    assert(chessMan && chessMan->getColor() <= 1);
    vector<int> line(2 * window + 1);
    line[window] = 1;
    int color = chessMan->getColor();
    bool front = true;
    ChessMan* chessManFront = chessMan;
    for(int i = 0; i < window; i++){
        if(front){
            chessManFront = chessBoard_->getChessManWithDir(chessManFront, getReverseDir(dir));
            if(!chessManFront){
                front = false;
                line[window - i - 1] = 0;
            } else if(chessManFront->getColor() == 2){
                line[window - i - 1] = 2;
            } else if(chessManFront->getColor() != color){
                front = false;
                line[window - i - 1] = 0;
            } else if(chessManFront->getColor() == color) {
                line[window - i - 1] = 1;
            } else {
                throw wrong_color("There is no color tagged " + to_string(chessManFront->getColor()));
            }
        } else {
            line[window - i - 1] = 0;
        }
    }
    bool back = true;
    ChessMan* chessManBack = chessMan;
    for(int i = 0; i < window; i++){
        if(back){
            chessManBack = chessBoard_->getChessManWithDir(chessManBack, dir);
            if(!chessManBack){
                back = false;
                line[window + i + 1] = 0;
            } else if(chessManBack->getColor() == 2){
                line[window + i + 1] = 2;
            } else if(chessManBack->getColor() != color){
                back = false;
                line[window + i + 1] = 0;
            } else if(chessManBack->getColor() == color) {
                line[window + i + 1] = 1;
            } else {
                throw wrong_color("There is no color tagged " + to_string(chessManBack->getColor()));
            }
        } else {
            line[window + i + 1] = 0;
        }
    }
    return line;
}

int Rules::cntThree(ChessMan *chessMan, int dir) {

    int cnt = 1;
    ChessMan* chessManFront = chessMan;
    ChessMan* chessManBack = chessMan;
    int color = chessMan->getColor();
    while (true){
        chessManFront = chessBoard_->getChessManWithDir(chessManFront, getReverseDir(dir));
        if(!chessManFront){ break; }
        if(chessManFront->getColor() != chessMan->getColor()){ break; }
        ++cnt;
    }
    while (true){
        chessManBack = chessBoard_->getChessManWithDir(chessManBack, dir);
        if(!chessManBack){ break; }
        if(chessManBack->getColor() != chessMan->getColor()){ break; }
        ++cnt;
    }
    if(cnt > 3) { return 0; }
    if(!chessManFront || !chessManBack || chessManBack->getColor() <= 1 || chessManFront->getColor() <= 1){ return 0; }
    switch (cnt) {
        case 3:
            chessManFront = chessBoard_->getChessManWithDir(chessManFront, getReverseDir(dir));
            chessManBack = chessBoard_->getChessManWithDir(chessManBack, dir);
            if(!chessManFront && !chessManBack){
                return 0;
            } else if(!chessManFront){

            }
            bool haveFour = chessManFront->getColor() == chessMan->getColor() || chessManBack->getColor() == chessMan->getColor();


    }
}