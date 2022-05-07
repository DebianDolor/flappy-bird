#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <iostream>
#include<vector>

#include "RenderWindow.h"

using namespace std;



RenderWindow window("Flappy Bird", 288, 512);

vector<SDL_Texture*> entities; // all entities
vector<SDL_Texture*> p;        // pipes
vector<SDL_Texture*>bird;      // birds

SDL_Texture* city = window.loadTexture("asset/pinknightbg.png");
SDL_Texture* ground = window.loadTexture("asset/pinkbase2.png");

Mix_Chunk* jumpSfx;
Mix_Chunk* hitSfx;
Mix_Chunk* swooshSfx;
Mix_Chunk* pointSfx;
Mix_Chunk* dieSfx;

bool init()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    p.push_back(window.loadTexture("asset/FbUpperPipe.png"));
    p.push_back(window.loadTexture("asset/FbUnderPipe.png"));
    bird.push_back(window.loadTexture("asset/FbBlueBird1.png"));
    bird.push_back(window.loadTexture("asset/FbBlueBird2.png"));
    bird.push_back(window.loadTexture("asset/FbBlueBird3.png"));
    bird.push_back(window.loadTexture("asset/FbYellowBird1.png"));
    bird.push_back(window.loadTexture("asset/FbYellowBird2.png"));
    bird.push_back(window.loadTexture("asset/FbYellowBird3.png"));
    bird.push_back(window.loadTexture("asset/FbRedBird1.png"));
    bird.push_back(window.loadTexture("asset/FbRedBird2.png"));
    bird.push_back(window.loadTexture("asset/FbRedBird3.png"));

    entities.push_back(window.loadTexture("asset/FbTapToPlay.png"));    //0
    entities.push_back(window.loadTexture("asset/WhiteTex.png"));       //1
    entities.push_back(window.loadTexture("asset/ScoreBoard.png"));     //2
    entities.push_back(window.loadTexture("asset/FbGetReady.png"));     //3
    entities.push_back(window.loadTexture("asset/FbGameOver.png"));     //4
    entities.push_back(window.loadTexture("asset/FbPlayButton.png"));   //5
    entities.push_back(window.loadTexture("asset/Fb2ndPlayButton.png"));//6
    entities.push_back(window.loadTexture("asset/BlendBg.png"));        //7

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Volume(-1, MIX_MAX_VOLUME);

    jumpSfx = Mix_LoadWAV("asset/wing.wav");
    hitSfx = Mix_LoadWAV("asset/die2.wav");
    pointSfx = Mix_LoadWAV("asset/point.wav");
    swooshSfx = Mix_LoadWAV("asset/swoosh.wav");
    dieSfx = Mix_LoadWAV("asset/die.wav");

    return true;
}

int a;

bool check = false, hitSFx = false, swooshSFx = false;
bool load = init();
bool mainScreen = true;

Entity ScoreBoard(288 / 2 - 226 / 2, 512, 288 / 2 - 226 / 2, 512 - 90 - 114 - 130,entities[2]), 
       GameOver(288 / 2 - 186 / 2, 55, 288 / 2 - 186 / 2, 80, entities[4]);

Bird player(50, 512 / 2 - 18, bird);

Background bg1(0, 0, city), bg2(288, 0, city), 
           blendBg(0, 0, entities[7]);

Background base1(0, 512 - 90, ground), 
           base2(288, 512 - 90, ground);

Pipe pipe1(288, -220, p, 112), 
     pipe2(288 + 170, -90, p, 112);

TTF_Font* flappyFont = TTF_OpenFont("asset/fBirdFont.ttf", 28);

SDL_Color textColor = { 255,255,255 };

Score playerScore(144 - 9, 60, flappyFont, textColor);


void reset()
{
    player.reset();

    pipe1.reset(pipe1, pipe2);

    ScoreBoard.reset();

    GameOver.reset();

    mainScreen = true;

    playerScore.reset();

    blendBg.reset();

    a = 0;

    check = false;
    swooshSFx = false;
}

int main(int argv, char** args)
{
    SDL_Event e;
    bool isRunning = true;
    while (isRunning)
    {
        window.clear();

        while (SDL_PollEvent(&e))
        {
            //Handle Events
            if (e.type == SDL_QUIT)
                isRunning = false;

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX = 0, mouseY = 0;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (mainScreen == true && e.button.button == SDL_BUTTON_LEFT && SDL_GetTicks() > 200)
                    //sau khi an play thi chuyen sang man hinh choi game
                {
                    mainScreen = false;
                    player.jump();

                    Mix_PlayChannel(-1, jumpSfx, 0);
                }
                else {
                    if (e.button.button == SDL_BUTTON_LEFT && player.isDead() != DEAD)
                    {
                        player.jump();
                        Mix_PlayChannel(-1, jumpSfx, 0);
                    }
                    if (e.button.button == SDL_BUTTON_LEFT 
                        && (mouseX > 288 / 2 - 104 / 2 && mouseX < 288 / 2 - 104 / 2 + 104) 
                        && (mouseY > 512 - 90 - 130 + 30 && mouseY < 512 - 90 - 130 + 30 + 58) 
                        // khoang an duoc cua button play again
                        && player.isDead() == DEAD 
                        && GameOver.getCount() > 30 + playerScore.getScore() * 3)
                        // khi count > 30 + ... thi bat dau render gameover
                    {
                        check = true;
                        a = GameOver.getCount();
                    }
                }
            }
        }
        //Update Screen
        if (mainScreen)
        {
            if (swooshSFx == false)
            {
                swooshSFx = true;
                Mix_PlayChannel(-1, swooshSfx, 0);
            }
            pipe1.reset(pipe1, pipe2);

            blendBg.updateBlendingLight();

            player.setX(288 / 2 - 18);
            player.setY(512 / 2 - 18);
            player.update(pipe1, pipe2, mainScreen);

            bg1.updateMainBg();
            bg2.updateMainBg();

            base1.updateBase();
            base2.updateBase();
        }
        else
        {
            if (player.isDead() != DEAD)
            {
                pipe1.update(1);
                pipe2.update(2);

                bg1.updateMainBg();
                bg2.updateMainBg();

                base1.updateBase();
                base2.updateBase();
            }
            else if (player.getY() == 512 - 90 - (float)player.getWidth() + 6) //if die
            {
                int mouseX = 0, mouseY = 0;

                SDL_GetMouseState(&mouseX, &mouseY);

                ScoreBoard.updateScoreBoard();

                GameOver.updateGameOver();

                if (GameOver.getCount() > 30 && GameOver.getCount() % 3 == 1)
                    playerScore.update();

                if (check == true)
                    blendBg.updateBlendingDark();
            }
        }

        player.update(pipe1, pipe2, mainScreen);
        //Render Screen
        if (mainScreen)
        {
            window.renderBackGround(bg1);
            window.renderBackGround(bg2);

            window.renderPipe(pipe1);
            window.renderPipe(pipe2);

            window.renderBackGround(base2);
            window.renderBackGround(base1);

            window.renderBird(player, player.getImgIndex());

            window.render(288 / 2 - 114 / 2 - 5, 290, entities[0]);
            window.render(288 / 2 - 184 / 2, 49 + 35, entities[3]);

            window.renderBackGround(blendBg);
        }
        else
        {
            if (player.isDead() == ALIVE)
            {
                window.renderBackGround(bg1);
                window.renderBackGround(bg2);

                window.renderPipe(pipe1);
                window.renderPipe(pipe2);

                window.renderBackGround(base2);
                window.renderBackGround(base1);

                window.renderScore(playerScore, player);

                window.renderBird(player, player.getImgIndex());

            }
            else if (player.isDead() == DEAD)
            {
                window.renderBackGround(bg1);
                window.renderBackGround(bg2);

                window.renderPipe(pipe1);
                window.renderPipe(pipe2);

                window.renderBackGround(base2);
                window.renderBackGround(base1);

                window.renderBird(player, player.getImgIndex());

                if (player.checkSplashWhenDie() == false)
                {
                    Mix_PlayChannel(-1, hitSfx, 0);

                    player.setCheckSplash(true);

                    window.render(0, 0, entities[1]);
                    window.display();

                    SDL_Delay(60);

                    continue;
                }
                if (player.getY() == 512 - 90 - (float)player.getWidth() + 6) //if die
                {
                    if (GameOver.getCount() > 30 + playerScore.getScore() * 3)
                        window.render(288 / 2 - 104 / 2, 512 - 90 - 130 + 30, entities[5]);

                    window.renderScoreBoard(ScoreBoard);

                    window.renderGameOver(GameOver);

                    if (GameOver.getCount() > 30)
                    {
                        window.renderScoreWhenDie(playerScore, player);

                        window.renderHighScore(playerScore, player);
                    }
                    window.renderBackGround(blendBg);
                }
            }
        }
        //Display Screen
        window.display();
        //Reset
        if (GameOver.getCount() > a + 13 && check == true)
            reset();

        SDL_Delay(22.5); //delay dung o bird.cpp
    }
    return 0;
}
void gameLoop() { }
