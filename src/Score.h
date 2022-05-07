#ifndef SCORE_HPP_INCLUDED
#define SCORE_HPP_INCLUDED

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <string>
#include <vector>

class Score
{
private:
    float x, y;

    int width, height;
    int score;
    int countingScore = 0;
    int HighScore = 0;

    TTF_Font* font;
    SDL_Color fontColor;

public:
    Score(float _x, float  _y, TTF_Font* _font, SDL_Color _fontColor);

    float getX();
    float getY();

    int getWidth();
    int getHeight();
    int getScore();
    int getHighScore();
    int getCountingScore();

    void setScore(int _score);
    void setHighScore();
    void setCountingScore(int x);

    TTF_Font* getFont();
    SDL_Color getFontColor();

    void update();
    void reset();
};
#endif // SCORE_HPP_INCLUDED
