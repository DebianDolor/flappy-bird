#include "Pipe.h"

Pipe::Pipe(float _x, float _y, std::vector<SDL_Texture*>_tex, float _space)
{
    x = _y;
    y = _y;
    currentFrame.x = 0;
    currentFrame.y = 0;
    PipeSpace = _space;
    tex = _tex;
    SDL_QueryTexture(tex[0], NULL, NULL, &currentFrame.w, &currentFrame.h);
}

int Pipe::getSize() { return tex.size(); }

int Pipe::getWidth() { return getCurrentFrame().w; }

int Pipe::getHeight() { return getCurrentFrame().h; }

float Pipe::getPipeSpace() { return PipeSpace; }

float Pipe::getX() { return x; }

float Pipe::getY() { return y; }

bool Pipe::isScored() { return PipeScored; }

bool Pipe::getMovingPipe() { return MovingPipe; }

void Pipe::setPipeScored(bool s) { PipeScored = s; }

void Pipe::setMovingPipe(bool s) { MovingPipe = s; }

void Pipe::setY(float _y) { y = _y; }

void Pipe::setX(float _x) { x = _x; }

SDL_Texture* Pipe::getTex(int index) { return tex[index]; }

SDL_Rect Pipe::getCurrentFrame() { return currentFrame; }


void Pipe::update(int index) //index: so thu tu cua pipe (co 2 pipe: 0, 1 render luan phien)
{
    if (getX() > -static_cast<float>(getWidth())) //getWidth: pipe di het man hinh
    {
        setX(getX() + velocity); //di chuyen pipe += van toc theo chieu x

        if (getMovingPipe() == true && index == 1)
        {
            setY(getY() + 0.9); //setY: lam cho pipe di chuyen

            if (getY() > 512 - 90 - 30 - (int)PipeSpace - 320) //320: chieu dai cua pipe
                setY(512 - 90 - 30 - (int)PipeSpace - 320);    //30:dau pipe,90:ground
        }
    }

    else
    {
        setMovingPipe(false);
        setX(340 - 52); //340: khi di qua het thi cho quay lai ben phai man hinh
        setY(static_cast<float>(Pipe::getPipeRandom(-(320 - 30), 
            512 - 90 - 30 - (int)PipeSpace - 320))); 
    }
}

int Pipe::getPipeRandom(int min_num, int max_num)
{
    srand(time(NULL));

    int result;

    PipeScored = false;

    if (count % 4 == 0) //sau 4 pipe thi nhay sang count = 1
        result = (rand() % (max_num - min_num)) + min_num + 20;

    else if (count % 4 == 1)
        result = (rand() % (max_num - min_num)) + min_num - 15;

    else
        result = (rand() % (max_num - min_num)) + min_num;

    count++;

    if (count % 2 == 1)
    {
        setMovingPipe(true);
        std::cout << "Moving" << std::endl;
    }
    return result;
}
void Pipe::reset(Pipe& p1, Pipe& p2)
{
    p1.setX(288);
    p1.setY(-220);
    p2.setX(288 + 150); //170: chi la con so
    p2.setY(-90);

    PipeScored = false;
    MovingPipe = true;
}

