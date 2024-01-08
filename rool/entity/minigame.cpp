#include "minigame.h"

PowerLightGame::PowerLightGame()
{
    AllLever = { 
        {1,true},
        {4,true},
        {2,true},
        {3,true},
        {6,true},
    };
    DisplayPL = false;
    result = 0 ;
    lever_Spritespace.push_back(0); 
    leverWidth = 100; 
    leverHeight = 150;
    LightDim = 60;
    GoalPL = 8;
}

PowerLightGame::~PowerLightGame()
{

}

void PowerLightGame::powerLightReset()
{
    AllLever = { 
        {1,true},
        {4,true},
        {2,true},
        {3,true},
        {6,true},
    };
    DisplayPL = false;
    result = 0 ;
    lever_Spritespace.push_back(0); 
    leverWidth = 100; 
    leverHeight = 150;
    LightDim = 60;
    GoalPL = 8;
}

void PowerLightGame::gameUpdate(int i) 
{
    if (result<GoalPL) {
        if (AllLever[i].AddEnigma == true) {
            if (result<GoalPL){ 
                result += AllLever[i].leverValue;
                AllLever[i].AddEnigma =false;
            } else {
                result =0;
                for (int i=0; i<AllLever.size() ; i++){
                    AllLever[i].AddEnigma = true;
                }
            }
        } else {
            if (result>0){
                result -= AllLever[i].leverValue;
                AllLever[i].AddEnigma =true;
            }
        }
    } else { // le result ne peut pas être negatif et si il depasse GoalPL alors on reinitialise le jeu
        result = AllLever[i].leverValue;
        AllLever[i].AddEnigma =false;
        for (int k=0; k<AllLever.size() ; k++){
            if (k != i){
                AllLever[k].AddEnigma = true;
            }
        }
    }
}

void PowerLightGame::whichLeverIsClicked(Point mouse) { 
  if (DisplayPL == true) {
    int j= 1; 
    for (int i=0; i<AllLever.size();i++){
      if (mouse.x>leverWidth*i + lever_Spritespace[i] && mouse.x < leverWidth*j + lever_Spritespace[i] && mouse.y>(500/1.75) && mouse.y< ( (500/1.75)) + leverHeight ) 
      {
        gameUpdate(i);
      }
      j+=1;
    }
  }
}


bool MiniGame::isGameOn(bool isGameDisplayed){
    if(isGameDisplayed == true){return true;}
    else return false;
}

SuperSimonGame::SuperSimonGame()
{

}

SuperSimonGame::~SuperSimonGame()
{
    
}