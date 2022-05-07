#include "Score.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

Score::Score(float _x, float  _y, TTF_Font* _font, SDL_Color _fontColor)
{
    x = _x;
    y = _y;
    font = _font;
    fontColor = _fontColor;
}

int Score::getHeight() { return height; }

int Score::getWidth() { return width; }

int Score::getHighScore() { return HighScore; }

int Score::getCountingScore() { return countingScore; }

int Score::getScore() { return score; }

float Score::getX() { return x; }

float Score::getY() { return y; }

void Score::setScore(int _score) { score = _score; }

void Score::setCountingScore(int x) { countingScore = x; }

TTF_Font* Score::getFont() { return font; }

SDL_Color Score::getFontColor() { return fontColor; }

void Score::setHighScore()
{
    if (score > HighScore)
        HighScore = score;
}

void Score::update()
{
    if (countingScore < getScore())
        countingScore++;
}

void  Score::reset() { countingScore = 0; }
