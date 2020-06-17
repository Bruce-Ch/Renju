// Add by pc

#include <iostream>
#include <tuple>
#include "ChessMan.h"
#include "ChessBoard.h"

using namespace std;

int main() {
    ChessBoard chessBoard;
    chessBoard.setChessMan(0, 1, make_pair(6, 7));
    cout << chessBoard << endl;
    chessBoard.eraseChessMan(chessBoard.getChessManByPos(make_pair(6, 7)));
    cout << chessBoard << endl;
    return 0;
}
