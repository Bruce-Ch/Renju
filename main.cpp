// Add by pc

#include <iostream>
#include <tuple>
#include "ChessMan.h"
#include "ChessBoard.h"
#include "Rules.h"

using namespace std;

void chessBoardInitialize(ChessBoard& chessBoard){
    char tmp;
    for(int i = 1; i <= 15; i ++){
        for(int j = 1; j <= 15; j ++){
            cin >> tmp;
            if(tmp == '*'){
                chessBoard.setChessMan(2, -1, make_pair(i, j));
            } else if(tmp == 'O'){
                chessBoard.setChessMan(0, -1, make_pair(i, j));
            } else if(tmp == 'X'){
                chessBoard.setChessMan(1, -1, make_pair(i, j));
            } else {
                assert(0);
            }
        }
    }
}

int main() {
    ChessBoard chessBoard;
    chessBoardInitialize(chessBoard);
    cout << chessBoard << endl;
    Rules rules{&chessBoard};
    cout << rules.checkFive(chessBoard.getChessManByPos(make_pair(6, 6)), 2) << endl;
    cout << rules.finished(chessBoard.getChessManByPos(make_pair(6, 6))) << endl;
    /*
    vector<int> tmp = rules.getLine(chessBoard.getChessManByPos(make_pair(6, 7)), 2, 9);
    for(auto x: tmp){
        cout << x << ' ';
    }
    cout << endl;
     */
    return 0;
}

/*
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * X O O O O X * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
 */