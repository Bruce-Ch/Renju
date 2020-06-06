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

class Game {
    ChessBoard* chessBoard_ = nullptr;
    std::stack<std::tuple<int, int, int>> stack_;
public:
    Game();
    std::vector<int> manipulate(const std::vector<int>& info);
    friend std::ostream& operator<<(std::ostream& out, Game game);
};


#endif //RENJU_GAME_H
