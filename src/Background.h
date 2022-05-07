#pragma once
#ifndef BACKGROUND_HPP_INCLUDED
#define BACKGROUND_HPP_INCLUDED

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <vector>

class Background
{
private:
    int x, y; //toa do goc duoi cua ground

    SDL_Texture* texture;
    SDL_Rect currentFrame;

    Uint8 a = 255, b = 0;

public:
    Background(int _x, int _y, SDL_Texture* tex);

    int getX();
    int getY();
    int getW();
    int getH();

    void setX(int _x);

    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();

    void updateMainBg();
    void updateBase();
    void updateBlendingLight();
    void updateBlendingDark();
    void reset();
};
#endif // BACKGROUND_HPP_INCLUDED
