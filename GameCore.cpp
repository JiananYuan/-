#include "GameCore.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <qDebug>
using namespace std;

GameCore::GameCore() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            Map[i][j] = 0;
        }
    }
    int u = 2;
    srand((unsigned)time(nullptr));
    while (u <= 9) {
        int x = (rand() % 3) + 1;
        int y = (rand() % 3) + 1;
        if (Map[x][y] == 0) {
            Map[x][y] = u;
            u++;
        }
    }
}

void GameCore::move(int x,int y) {
    if (Map[x][y] != 0) {
        for (int i = 0; i < 4; i++) {
            int tx = x + nxt[i][0];
            int ty = y + nxt[i][1];
            if(tx >= 1 && ty >= 1 && tx <= 3 && ty <= 3 && Map[tx][ty] == 0) {
                swap(Map[tx][ty],Map[x][y]);
                return ;
            }
        }
    }
}

bool GameCore::check() {
    if(Map[1][1] == 0 && Map[1][2] == 2 && Map[1][3] == 3) {
        if(Map[2][1] == 4 && Map[2][2] == 5 && Map[2][3] == 6) {
            if(Map[3][1] == 7 && Map[3][2] == 8 && Map[3][3] == 9) {
                qDebug() << "Winner";
                return true;
            }
        }
    }
    return false;
}
