// Add by pc

#include <iostream>
#include <tuple>
#include "ChessMan.h"
#include "ChessBoard.h"
#include "Rules.h"

using namespace std;

int main() {
    ChessBoard chessBoard;
    chessBoard.setChessMan(0, 1, make_pair(6, 7));
    chessBoard.setChessMan(0, 1, make_pair(6, 8));
    chessBoard.setChessMan(0, 1, make_pair(6, 9));
    chessBoard.setChessMan(1, 1, make_pair(6, 5));
    cout << chessBoard << endl;
    Rules rules{&chessBoard};
    cout << chessBoard.getChessManByPos(make_pair(6, 8))->getColor() << endl;
    vector<int> tmp = rules.getLine(chessBoard.getChessManByPos(make_pair(6, 7)), 2, 9);
    for(auto x: tmp){
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
