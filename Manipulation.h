//
// Created by pc on 2020/6/5.
//

#ifndef RENJU_MANIPULATION_H
#define RENJU_MANIPULATION_H

#include <utility>

#include "ChessMan.h"
#include "ChessBoard.h"

class Manipulation {
protected:
    ChessBoard* chessBoard_;
public:
    explicit Manipulation(ChessBoard* chessBoard): chessBoard_(chessBoard){}
    virtual void main();
    virtual bool isValid();
    virtual void act();
};


class Go: public Manipulation{
    int color_;
    Pos pos_;
public:
    Go(ChessBoard* chessBoard, int color, Pos pos): Manipulation(chessBoard), color_(color), pos_(std::move(pos)){}
    void main() override ;
    bool isValid() override ;
    void act() override ;
};


class Retract: public Manipulation{
public:
    explicit Retract(ChessBoard* chessBoard): Manipulation(chessBoard){}
    void main() override ;
    bool isValid() override ;
    void act() override ;
};


class SueForPeace: public Manipulation{
public:
    explicit SueForPeace(ChessBoard* chessBoard): Manipulation(chessBoard){}
    void main() override ;
    bool isValid() override ;
    void act() override ;
};


#endif //RENJU_MANIPULATION_H
