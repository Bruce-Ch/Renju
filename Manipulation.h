//
// Created by pc on 2020/6/5.
//

#ifndef RENJU_MANIPULATION_H
#define RENJU_MANIPULATION_H

#include <utility>
#include <stack>

#include "ChessMan.h"
#include "ChessBoard.h"
#include "Rules.h"

class Manipulation {
protected:
    ChessBoard* chessBoard_;
    std::stack<std::tuple<int, int, int>>* stack_;
    int color_;
public:
    explicit Manipulation(ChessBoard* chessBoard, std::stack<std::tuple<int, int, int>>* stack, int color):
        chessBoard_(chessBoard), stack_(stack), color_(color){}
    virtual std::vector<int> main() = 0;
    virtual ~Manipulation() = default;
};


class Go: public Manipulation{
    Pos pos_;
    int id_;
public:
    Go(ChessBoard* chessBoard, std::stack<std::tuple<int, int, int>>* stack, int color, Pos pos, int id):
        Manipulation(chessBoard, stack, color), pos_(std::move(pos)), id_(id){}
    std::vector<int> main() override ;
};


class Retract: public Manipulation{
public:
    explicit Retract(ChessBoard* chessBoard, std::stack<std::tuple<int, int, int>>* stack, int color):
        Manipulation(chessBoard, stack, color){}
    std::vector<int> main() override ;
};


class SueForPeace: public Manipulation{
public:
    explicit SueForPeace(ChessBoard* chessBoard, std::stack<std::tuple<int, int, int>>* stack, int color):
        Manipulation(chessBoard, stack, color){}
    std::vector<int> main() override ;
};


#endif //RENJU_MANIPULATION_H
