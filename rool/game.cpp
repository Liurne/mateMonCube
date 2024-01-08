#include "game.h"

Game::Game(Window &win_,Controls &ctrls_,bool &run_) : win(win_), ctrls(ctrls_),run(run_), map("data/map/mapNiveau1.json"),
raycast(player,map,win_.getWindowWidth(),win_.getWindowHeight()),player("lules",map.getSpawnPlayerX(),map.getSpawnPlayerY(),0.001,0.0004),
monster(map),generator(12,52), isGameWin(false) ,  isGameLost(false) , isMiniMapDisplayed(false) , whenMusic(false)
{}


Game::~Game()
{   
    Mix_FreeMusic(musiqueBackground);
    Mix_FreeChunk(keySong); 
}

bool Game::gameInit(Window &win)
{
    KeyAction ka(SDL_BUTTON_LEFT,true);
    mKeyboard.push_back(ka);
    for(int i=0;i<9;i++)
    {
        KeyAction ka(SDLK_a);
        mKeyboard.push_back(ka);
    }
    mKeyboard[1].key = SDLK_z;
    mKeyboard[2].key = SDLK_q;
    mKeyboard[3].key = SDLK_s;
    mKeyboard[4].key = SDLK_d;
    mKeyboard[5].key = SDLK_a;
    mKeyboard[6].key = SDLK_e;
    mKeyboard[7].key = SDLK_f;
    mKeyboard[8].key = SDLK_m;
    mKeyboard[9].key = SDLK_LSHIFT;
    if(player.getEntity().x >  map.getMapWidth() || player.getEntity().x < 0 || player.getEntity().y >map.getMapHeight() || player.getEntity().y < 0)
    {
        cout<<"The player is outside the map"<<endl;
        return false;
    }

    for(int i = 0; i < 5; i++) {
        Texture txtr;
        texturesWall.push_back(txtr);
    }
    texturesWall[0].setTexture(win,"data/texture/wall1.png");
    texturesWall[1].setTexture(win,"data/texture/wall2.png");
    texturesWall[2].setTexture(win,"data/texture/wall5.png");
    texturesWall[3].setTexture(win,"data/texture/wall3.png");
    texturesWall[4].setTexture(win,"data/texture/door.png");

    powerlight.LeverTexture.setTexture(win,"data/texture/lever_04_01.png");
    powerlight.BackgroundTexture.setTexture(win,"data/texture/BackgroundPowerLight.png");
    powerlight.LightTextureGreen.setTexture(win,"data/texture/Lightbublegreen.png");
    powerlight.LightTextureYellow.setTexture(win,"data/texture/lightbubleyellow.png");
    powerlight.LightTextureRed.setTexture(win,"data/texture/lightbublered.png");
    powerlight.LightTextureON.setTexture(win,"data/texture/LightON.png");

    monster.setMonsterTexture(win,"data/texture/monster.png");

    for(int i = 0; i < 3; i++){
        Item keyItems;
        item.push_back(keyItems);
    }
    item[0].setItemTexture(win,"data/texture/Key.png");
    item[0].setItemId("key");
    item[0].setPostion(23.0,95.0);
    item[1].setItemTexture(win,"data/texture/Key.png");
    item[1].setItemId("key");
    item[1].setPostion(29.162,38.57);
    item[2].setItemTexture(win,"data/texture/Key.png");
    item[2].setItemId("key");
    item[2].setPostion(28.54,1.8);

    generator.setGeneratorTexture(win,"data/texture/generator.png");

    for(int i = 0; i < 7; i++) {
        Text txt;
        message.push_back(txt);
    }
    message[0].setTextFont("data/font/Papernotes.ttf",25);
    message[0].setText(win,"Press [f] to open the door");
    message[1].setTextFont("data/font/Papernotes.ttf",25);
    message[1].setText(win,"Press [shift] to crawl under the door");
    message[2].setTextFont("data/font/Papernotes.ttf",25);
    message[2].setText(win,"Press [f] to interact");
    message[3].setTextFont("data/font/game_over.ttf",150);
    message[3].setTextColor(RED);
    message[3].setText(win,"Game Over");
    message[4].setTextFont("data/font/Papernotes.ttf",25);
    message[4].setText(win,"Press [f] to open the exit");
    message[5].setTextFont("data/font/Papernotes.ttf",150);
    message[3].setTextColor(GREEN);
    message[5].setText(win,"You Win!");
    message[6].setTextFont("data/font/Papernotes.ttf",15);
    message[6].setText(win,"0");
    /*
    musiqueBackground = Mix_LoadMUS("data/son/BackgroundSong.mp3");
    Mix_PlayMusic(musiqueBackground, -1);
    keySong = Mix_LoadWAV("data/son/GetKey.wav");*/
    
    return true;
}

void Game::gameReset()
{
    isGameLost = false;
    isGameWin = false;
    map.mapReset();
    player.playerReset();
    item[0].itemReset();
    item[1].itemReset();
    item[2].itemReset();
    monster.monsterReset();
    generator.generatorReset();
    powerlight.powerLightReset();
}

void Game::gameUpdate()
{
    ctrls.event(run,mKeyboard);
    if(!isGameLost)
    {
        if(mKeyboard[0].isPressed)
        {
            powerlight.whichLeverIsClicked(ctrls.getMousePos());
            if (powerlight.result ==powerlight.GoalPL)
            {
                powerlight.DisplayPL=false;
                generator.activateGenerator();
            
            }
            mKeyboard[0].isPressed = false;
        }
        if(mKeyboard[1].isPressed && !mKeyboard[3].isPressed)
            player.getEntity().moveForward(map,win.getFPS());
        if(mKeyboard[2].isPressed && !mKeyboard[4].isPressed)
            player.getEntity().moveLeft(map,win.getFPS());
        if(mKeyboard[3].isPressed && !mKeyboard[1].isPressed)
            player.getEntity().moveBackward(map,win.getFPS());
        if(mKeyboard[4].isPressed && !mKeyboard[2].isPressed)
            player.getEntity().moveRight(map,win.getFPS());
        if(mKeyboard[5].isPressed && !mKeyboard[6].isPressed)
            player.getEntity().rotateLeft(win.getFPS());
        if(mKeyboard[6].isPressed && !mKeyboard[5].isPressed)
            player.getEntity().rotateRight(win.getFPS());
        if(mKeyboard[7].isPressed)
        {
            if(generator.isNearGenerator(player))
            {
                powerlight.DisplayPL = true;
                cout<<"oui"<<endl;
            }
            if(player.isNearDoor(map))
            {
                player.openDoor(map);
            }
            if(player.isNearFinalDoor(map))
            {
                player.openFinalDoor(map,generator.isGeneratorActivate(),isGameWin);
            }
            mKeyboard[7].isPressed = false;
        }
        if(mKeyboard[8].isPressed)
        {
            if(isMiniMapDisplayed) isMiniMapDisplayed=false;
            else isMiniMapDisplayed = true;
            mKeyboard[8].isPressed = false;
        }
        if(mKeyboard[9].isPressed)
        {
            player.getEntity().setSneakTrue();
        }
        else
        {
            player.getEntity().setSneakFalse();
        }
    }
    
    if(!isGameWin)
    {
        for(int i=0; i<3; i++){
            if(item[i].isItemPicked(player))
            {
                Mix_PlayChannel(1, keySong, 0);
                player.addItem(item[i].getId());
            }
        }
        if(!powerlight.DisplayPL)
        {
            monster.move(map,Point(player.getEntity().x,player.getEntity().y),120);
            if(whenMusic) Mix_PlayMusic(musiqueBackground, -1);
            whenMusic = false;
        }
        if(powerlight.DisplayPL)
        { 
            whenMusic = true;
            
        }
        if(monster.hasKilledPlayer(player))
        {
            Mix_PauseMusic(); //Mettre en pause la musique
            isGameLost = true;
        }
    }
}

void Game::gameDisplay(Display &disp)
{    
    if(!powerlight.DisplayPL) {
        Mix_ResumeMusic(); //Reprendre la musique
        if(player.getEntity().isPlayerSneak())
        {
            disp.drawRect(Rectangle(0,win.getWindowHeight()/2-win.getWindowHeight()/2,win.getWindowWidth(),win.getWindowHeight()),Color(30,30,30,255));
        }
        else
        {
            disp.drawRect(Rectangle(0,win.getWindowHeight()/2,win.getWindowWidth(),win.getWindowHeight()/2),Color(30,30,30,255));
        }
        
        disp.drawRaycast(raycast,texturesWall);
        if(isMiniMapDisplayed) disp.drawMiniMap(raycast,monster);
        for(int x=0; x <3; x++){
            disp.drawSprite(raycast,item[x]);
        }
        disp.drawSprite(raycast,generator);
        disp.drawSprite(raycast,monster);
        if(player.getNumberKey()>0)
        {
            disp.drawPickedItem(item);  
            message[6].setText(win, to_string(player.getNumberKey()).c_str());
            disp.drawText(message[6],Rectangle((message[6].getTextureWidth()+ (win.getWindowWidth()-30)),
            (message[6].getTextureHeight()+60),message[6].getTextureWidth(),message[6].getTextureHeight()));
        }
        if(player.isNearDoor(map))
        {
            disp.drawText(message[0],Rectangle((win.getWindowWidth()-message[0].getTextureWidth())/2,
            (win.getWindowHeight()-message[0].getTextureHeight())/2,message[0].getTextureWidth(),message[0].getTextureHeight()));
        }
        if(player.isNearFinalDoor(map))
        {
            disp.drawText(message[4],Rectangle((win.getWindowWidth()-message[4].getTextureWidth())/2,
            (win.getWindowHeight()-message[4].getTextureHeight())/2,message[4].getTextureWidth(),message[4].getTextureHeight()));
        }
        if(player.isNearSneakDoor(map))
        {
            disp.drawText(message[1],Rectangle((win.getWindowWidth()-message[1].getTextureWidth())/2,
            (win.getWindowHeight()-message[1].getTextureHeight())/2,message[1].getTextureWidth(),message[1].getTextureHeight()));
        }
        if(generator.isNearGenerator(player))
        {
            disp.drawText(message[2],Rectangle((win.getWindowWidth()-message[2].getTextureWidth())/2,
            (win.getWindowHeight()-message[2].getTextureHeight())/2,message[2].getTextureWidth(),message[2].getTextureHeight()));
        }
        if(isGameLost)
        {
            disp.drawRect(Rectangle(0,0,win.getWindowWidth(),win.getWindowHeight()),Color(75,10,00,150));
            disp.drawText(message[3],Rectangle((win.getWindowWidth()-message[3].getTextureWidth())/2,
            (win.getWindowHeight()-message[3].getTextureHeight())/2,message[3].getTextureWidth(),message[3].getTextureHeight()));
        }
        if(isGameWin)
        {
            disp.drawRect(Rectangle(0,0,win.getWindowWidth(),win.getWindowHeight()),Color(10,75,0,150));
            disp.drawText(message[5],Rectangle((win.getWindowWidth()-message[5].getTextureWidth())/2,
            (win.getWindowHeight()-message[5].getTextureHeight())/2,message[5].getTextureWidth(),message[5].getTextureHeight()));
        }
    } else{
        Mix_HaltMusic(); //Mettre en pause la musique
        disp.drawPowerlight(powerlight);   
    } 
}

void Game::gameCout()
{
    cout<<player<<endl;

    cout<<endl;
}