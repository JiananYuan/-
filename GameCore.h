#ifndef GAMECORE_H
#define GAMECORE_H

const int nxt[][2] = { {-1,0},{0,1},{1,0},{0,-1} };

class GameCore {
public:
    int Map[4][4];

    GameCore();
    void move(int x,int y);
    bool check();
};

#endif // GAMECORE_H
