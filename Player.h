//
// Created by pc on 2020/6/4.
//

#ifndef RENJU_PLAYER_H
#define RENJU_PLAYER_H


#include <vector>
#include "ChessMan.h"

class Player {
    int color_;
public:
    Player(int color): color_(color){}
    void updateGameInfo();
    std::vector<int> response(const std::vector<int>& cmd);
    std::vector<int> go(Pos pos);
    std::vector<int> retract();
    std::vector<int> surForPeace();
};


#endif //RENJU_PLAYER_H
