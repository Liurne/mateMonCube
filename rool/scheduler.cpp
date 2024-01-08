#include "scheduler.h"

Scheduler::Scheduler() :  window(800,500,RESIZABLE),display(window),onMenu(true),game(window,controls,isRunning)
{
  actScene = GAME;
  isRunning = true;
  window.setMaxFPS(120);
  gameNeedReset=false;
}

Scheduler::~Scheduler()
{
}

bool Scheduler::init()
{
  if(!window.init())
  {
    isRunning=false;
    return false;
  }
  window.setWindowTitle("Ran Out Of Light");

  if(!game.gameInit(window))
  {
    isRunning=false;
    return false;
  }

  dispFPS.setTextFont("data/font/arial.ttf",24);
  dispFPS.setTextColor(Color(255,255,255,255));
  dispFPS.setText(window,to_string(window.getFPS()).c_str());

  for(int i = 0; i < 7; i++) {
        Text txt;
        texts.push_back(txt);
  }
  texts[0].setTextFont("data/font/horror.ttf",60);
  texts[0].setText(window,"Ran Out Of Light");
    
  texts[1].setTextFont("data/font/Papernotes.ttf",25);
  texts[1].setText(window,"<Press any key to start>");

  return true;
}

bool Scheduler::loop()
{
  while(isRunning)
  {
    if(onMenu)
    {
      while(onMenu)
      {
        window.winClear();
        display.drawText(texts[0],Rectangle((window.getWindowWidth()-texts[0].getTextureWidth())/2,
            (window.getWindowHeight()*0.25)-(texts[0].getTextureHeight()/2),texts[0].getTextureWidth(),texts[0].getTextureHeight()));
        display.drawText(texts[1],Rectangle((window.getWindowWidth()-texts[1].getTextureWidth())/2,
            (window.getWindowHeight()-texts[1].getTextureHeight())/2,texts[1].getTextureWidth(),texts[1].getTextureHeight()));
        window.winUpdate();
        controls.event(isRunning);
        if(!isRunning)return 0;
        if(controls.isKeyPressed()) onMenu=false;
      }
    }
    if(gameNeedReset)
    {
      game.gameReset();
      gameNeedReset =false;
    }

    window.winClear();
    
    switch(actScene)
    {
      case GAME:
        game.gameUpdate();
        game.gameDisplay(display);
        break;
      case MAPEDITOR:
        actScene = GAME;
        break;
		  default: ;
        actScene = GAME;
		    break;
    }

    display.drawText(dispFPS,Rectangle(window.getWindowWidth()-dispFPS.getTextureWidth()-10,2,
                      dispFPS.getTextureWidth(),dispFPS.getTextureHeight()));

    window.winUpdate();
    dispFPS.setText(window,to_string(window.getFPS()).c_str());
    
  }
  return 0;
}

Game& Scheduler::getGame()
{
  return game;
}

