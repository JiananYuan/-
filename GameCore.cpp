#include "GameCore.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <QDateTime>
#include <QTextStream>
#include <QDateTime>
#include <QFile>
#include <QDebug>
using namespace std;

GameCore::GameCore() {
    restartGame();
}

void GameCore::restartGame() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            Map[i][j] = 0;
        }
    }
    int u = 2;
    step_cnt = 0;
    time_cnt = 0;
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
                step_cnt++;
                return ;
            }
        }
    }
}

bool GameCore::check() {
    if(Map[1][1] == 0 && Map[2][1] == 2 && Map[3][1] == 3) {
        if(Map[1][2] == 4 && Map[2][2] == 5 && Map[3][2] == 6) {
            if(Map[1][3] == 7 && Map[2][3] == 8 && Map[3][3] == 9) {
                QFile f("./winner-history.txt");
                if (f.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)) {
                    QTextStream out(&f);
                    out << QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss.zzz ddd") << " ";
                    out << step_cnt << "²½ " << time_cnt << "Ãë" << endl;
                    f.close();
                }
                return true;
            }
        }
    }
    return false;
}
