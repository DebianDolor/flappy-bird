#pragma once
#ifndef PIPE_HPP_INCLUDED
#define PIPE_HPP_INCLUDED

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <random>

#include "Score.h"

class Pipe
{
private:
    float x, y; 

    int PipeSpace; //khoang cach giua 2 pipe de con chim bay qua
    int velocity = -3; //van toc cua moving pipe
    int count = 0; //dung de random cac moving pipes

    std::vector<SDL_Texture*>tex;
    SDL_Rect currentFrame;

    bool PipeScored = false; //da vuot qua cai pipe do chua
    bool MovingPipe = true;

public:
    Pipe(float _x, float _y, std::vector<SDL_Texture*>_tex, float _space);

    void setX(float _x);
    void setY(float _y);

    void setPipeScored(bool s);
    void setMovingPipe(bool s);

    float getX();
    float getY();
    float getPipeSpace();

    int getWidth();
    int getHeight();
    int getSize();

    bool isScored();
    bool getMovingPipe();

    SDL_Texture* getTex(int index);
    SDL_Rect getCurrentFrame();

    void update(int index);
    void reset(Pipe& p1, Pipe& p2);

    int getPipeRandom(int min_num, int max_num);
};
#endif // PIPE_HPP_INCLUDED
