// Add by pc

#include <iostream>
#include <cstdio>
#include <tuple>
#include <string>
#include <sstream>
#include "ChessMan.h"
#include "ChessBoard.h"
#include "Rules.h"
#include "Game.h"

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
/*
int main() {
    Game game;
    cout << game << endl;
    int a1, a2, a3, a4;
    while (true){
        vector<int> ret;
        cout << "Please input the command, the color, and the position. " << endl;
        cin >> a1;
        switch (a1) {
            case 0:
                return 0;
            case 1:
                cin >> a2 >> a3 >> a4;
                ret = game.manipulate(vector<int> {a1, a2, a3, a4});
                break;
            case 2:
                cin >> a2;
                ret = game.manipulate(vector<int> {a1, a2});
                break;
            case 3:
                cin >> a2;
                ret = game.manipulate(vector<int> {a1, a2});
                break;
            default:
                cout << "There is something wrong. " << endl;
                exit(EXIT_FAILURE);
        }
        switch (ret[0]) {
            case 1:
                if(ret[1]){
                    cout << "Cannot go a " << (ret[2] ? "black" : "white") << " stone at position (" << ret[3] << ", " << ret[4] << "). " << endl;
                } else if(!ret[2]){
                    cout << "Game over. The winner is " << (ret[3] ? "black" : "white") << ". " << endl;
                    return 0;
                } else {
                    cout << game << endl;
                }
                break;
            case 2:
                if(ret[1]){
                    cout << "Cannot retract. " << endl;
                } else {
                    cout << game << endl;
                }
                break;
            case 3:
                if(!ret[1]){
                    cout << "Game over with tie. " << endl;
                    return 0;
                }
                break;

        }
    }
    return 0;
}
 */
int main(){
    ChessBoard chessBoard;
    chessBoardInitialize(chessBoard);
    stringstream ss;
    ss << chessBoard;
    char tmp;
    for(int i = 0; i < 15; i ++){
        for(int j = 0; j < 15; j ++){
            ss >> tmp;
            cout << tmp << ' ';
        }
        cout << endl;
    }
    cout << endl;
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

/*
 1 1 8 8
 1 0 9 8
 1 1 8 9
 1 0 9 9
 1 1 8 10
 1 0 9 10
 1 1 8 11
 1 0 9 11
 1 1 8 13
 1 0 1 1
 1 1 8 12
 2 1
 1 1 8 12
 */