#pragma once
#ifndef BIRD_HPP_INCLUDED
#define BIRD_HPP_INCLUDED

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<SDL_mixer.h>

#include <iostream>
#include<math.h>
#include<vector>

#include "Pipe.h"


const float GRAVITY = 0.8;
const int DEAD = 1, ALIVE = 0, PLAYING = 2;
const bool TRUE = true;
const float PI = 3.14159265;

class Bird
{
private:
    float x, y;
    float velocity = 0;
    float angle = 0; // goc dau con chim huong len/xuong

    int changeImg = 0;
    int changeBirdDirectInMainScreen = 0; //khi chua play thi render cho bird vo canh
    int playerStatus = ALIVE;
    int ActualScore = 0;

    bool SplashWhenDie = false; //nhay sang man hinh khi chet

    Mix_Chunk* hitSfx = Mix_LoadWAV("asset/die2.wav");
    Mix_Chunk* pointSfx = Mix_LoadWAV("asset/point.wav");

    SDL_Rect currentFrame;
    std::vector<SDL_Texture*>tex;

public:
    Bird(float _x, float _y, std::vector<SDL_Texture*>_tex);

    float getX();
    float getY();
    float getAngle();

    float getTopRightX(float a);
    float getTopRightY(float a);
    float getTopLeftX(float a);
    float getTopLeftY(float a);
    float getBottomLeftX(float a);
    float getBottomLeftY(float a);
    float getBottomRightX(float a);
    float getBottomRightY(float a);

    int getHeight();
    int getWidth();
    int isDead();
    int getActualScore();
    int getImgIndex();

    void setY(float _y);
    void setX(float _x);
    void setAngle(float _angle);
    void setCheckSplash(bool s);

    SDL_Texture* getTex(int index);
    SDL_Rect getCurrentFrame();

    void jump();
    void update(Pipe& b1, Pipe& b2, bool mainScreen);
    void reset();
    bool checkSplashWhenDie();
};
#endif // BIRD_HPP_INCLUDED
