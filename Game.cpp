//
// Created by pc on 2020/6/5.
//

#include "Game.h"

using namespace std;

Game::Game() {
    chessBoard_ = new ChessBoard;
    stack_ = new stack<tuple<int, int, int>>;
}

Game::~Game() {
    delete chessBoard_;
    delete stack_;
}

std::vector<int> Game::manipulate(const std::vector<int> &info) {
    /*
     * 1: 落子，由1方发来信息，位置在(2, 3)处
     * 2: 悔棋，由1方发来信息
     * 3: 求和，由1方发来信息
     */
    vector<int> res;
    Manipulation* manipulation;
    switch (info[0]) {
        case 1:
            manipulation = new Go {chessBoard_, stack_, info[1], make_pair(info[2], info[3]), static_cast<int>(stack_->size())};
            break;
        case 2:
            manipulation = new Retract {chessBoard_, stack_, info[1]};
            break;
        case 3:
            manipulation = new SueForPeace {chessBoard_, stack_, info[1]};
            break;
    }
    res = manipulation->main();
    delete manipulation;
    return res;
}

std::ostream& operator<<(std::ostream& out, const Game& game){
    out << *game.chessBoard_;
    return out;
}