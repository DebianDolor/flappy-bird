#include "Entity.h"

Entity::Entity(float _srcX, float _srcY, float _dstX, float _dstY, SDL_Texture* _texture)
{
    x = _srcX;
    y = _srcY;
    dstX = _dstX;
    dstY = _dstY;
    texture = _texture;
    currentFrame.x = 0;
    currentFrame.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &currentFrame.w, &currentFrame.h);
}

float Entity::getX() { return x; }

float Entity::getY() { return y; }

void Entity::setY(float _y) { y = _y; }

void Entity::setX(float _x) { x = _x; }

int Entity::getWidth() { return getCurrentFrame().w; }

int Entity::getHeight() { return getCurrentFrame().h; }

int Entity::getCount() { return count; }

bool Entity::isInDst() { return inDst; }

SDL_Rect Entity::getCurrentFrame() { return currentFrame; }

SDL_Texture* Entity::getTex() { return texture; }


void Entity::updateScoreBoard()
{

    if (getY() > dstY && count > 11) //khi > vi tri bang score board (dstY) thi lui lai (-=7)
    {
        if (getY() < 512 - 67 * 4)
            ScoreBoardVelocity -= 7;

        setY(getY() + ScoreBoardVelocity);
    }

    else if (getY() <= dstY) //den roi thi set velocity = 0
    {
        setY(dstY);

        ScoreBoardVelocity = 0;
    }

    count++;
}
// scoreboard & gameover nguoc nhau vi 
// scoreboard set o ben tren(giau di) (scoreboard di tu tren->duoi->giua man hinh)
// con gameover set o nguyen 1 vi tri 
void Entity::updateGameOver()
{
    if (getY() < dstY && count > 4)
    {
        if (getY() > 70)
            GameOverVelocity -= 0.7;

        setY(getY() + GameOverVelocity);
    }

    else if (getY() >= dstY)
    {
        setY(dstY);
        GameOverVelocity = 0;
    }

    count++;
}

void Entity::reset()
{
    count = 0;
    ScoreBoardVelocity = -24;
    GameOverVelocity = 4;
    if (getY() < 100)
        setY(55);

    else setY(512);
}
