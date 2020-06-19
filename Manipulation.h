//
// Created by pc on 2020/6/5.
//

#ifndef RENJU_MANIPULATION_H
#define RENJU_MANIPULATION_H

#include <utility>

#include "ChessMan.h"
#include "ChessBoard.h"
#include "Game.h"

class Game;

class Manipulation {
protected:
    Game* game_;
public:
    explicit Manipulation(Game* game): game_(game){}
    virtual std::vector<int> main() = 0;
    virtual ~Manipulation() = default;
};


class Go: public Manipulation{
    int color_;
    Pos pos_;
    int id_;
public:
    Go(Game* game, int color, Pos pos, int id): Manipulation(game), color_(color), pos_(std::move(pos)), id_(id){}
    std::vector<int> main() override ;
};


class Retract: public Manipulation{
    int color_;
public:
    explicit Retract(Game* game, int color): Manipulation(game), color_(color){}
    std::vector<int> main() override ;
};


class SueForPeace: public Manipulation{
    int color_;
public:
    explicit SueForPeace(Game* game, int color): Manipulation(game), color_(color){}
    std::vector<int> main() override ;
};


#endif //RENJU_MANIPULATION_H
