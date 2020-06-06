//
// Created by pc on 2020/6/4.
//

#ifndef RENJU_CHESSMAN_H
#define RENJU_CHESSMAN_H

#include <map>
#include <utility>
typedef std::pair<int, int> Pos;

class ChessMan {
    int color_; // 0为白，1为黑
    int id_; // 从0开始
    Pos pos_; // 从0到14
public:
    ChessMan(int color, int id, Pos pos):color_(color), id_(id), pos_(std::move(pos)){}
    int getColor();
    int getId();
    Pos getPos();
};


#endif //RENJU_CHESSMAN_H
