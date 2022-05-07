#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include<iostream>
#include<vector>

const int GAMEOVER = 4, SCOREBOARD = 0;

class Entity
{
private:
    SDL_Texture* texture;
    SDL_Rect currentFrame;

    bool inDst;

    float x, y, dstX, dstY; //toa do goc duoi ben trai cua scoreboard/ gameover
    float ScoreBoardVelocity = -24;
    float GameOverVelocity = 4;

    int count = 0; //sau khi chet la bat dau chay count
                   //sau 1 ktg thi render man hinh chet (gom scoreboard & gameover)

public:
    Entity(float _srcX, float _srcY, float _dstX, float _dstY, SDL_Texture* _texture);

    float getX();
    float getY();

    void setX(float _x);
    void setY(float _y);

    int getWidth();
    int getHeight();
    int getCount();

    bool isInDst();
    
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
    
    void reset();
    void updateScoreBoard();
    void updateGameOver();
};
