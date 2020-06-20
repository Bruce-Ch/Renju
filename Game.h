//
// Created by pc on 2020/6/5.
//

#ifndef RENJU_GAME_H
#define RENJU_GAME_H


#include <stack>
#include <tuple>
#include <string>
#include <ostream>
#include "ChessBoard.h"
#include "Manipulation.h"


class Game {
    ChessBoard* chessBoard_ = nullptr;
    std::stack<std::tuple<int, int, int>>* stack_ = nullptr; // 颜色，位置，位置
public:
    Game();
    ~Game();
    std::vector<int> manipulate(const std::vector<int>& info);
    friend std::ostream& operator<<(std::ostream& out, const Game& game);
};


#endif //RENJU_GAME_H
