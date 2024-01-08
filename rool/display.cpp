#include "display.h"


Display::Display(Window &win) : window(win)
{
	
}

Display::~Display()
{

}

void Display::drawPixel(Point p){
	SDL_RenderDrawPoint(window.getRenderer(), p.x, p.y);
}
void Display::drawPixel(Point p,Color c){
	SDL_SetRenderDrawColor(window.getRenderer(), c.r, c.g, c.b, c.a);
	SDL_RenderDrawPoint(window.getRenderer(), p.x, p.y);
}

void Display::drawLine(const Line &l)
{
	SDL_RenderDrawLine(window.getRenderer(),l.p1.x,l.p1.y,l.p2.x,l.p2.y);
}
void Display::drawLine(const Line &l,const Color &c)
{
	SDL_SetRenderDrawColor(window.getRenderer(), c.r, c.g, c.b, c.a);
	SDL_RenderDrawLine(window.getRenderer(),l.p1.x,l.p1.y,l.p2.x,l.p2.y);
}

void Display::drawRect(Rectangle r){
	SDL_Rect rect = r.toSDL();
	if(r.fill)
		SDL_RenderFillRect(window.getRenderer(), &rect);
	else
		SDL_RenderDrawRect(window.getRenderer(), &rect);
}

void Display::drawRect(Rectangle r,Color c){
	SDL_SetRenderDrawColor(window.getRenderer(), c.r, c.g, c.b, c.a);
	SDL_Rect rect = r.toSDL();
	if(r.fill)
		SDL_RenderFillRect(window.getRenderer(), &rect);
	else
		SDL_RenderDrawRect(window.getRenderer(), &rect);
}

void Display::drawTexture(Texture &t,Rectangle srcRect, Rectangle dstRect)
{
	SDL_Rect s = srcRect.toSDL();
	SDL_Rect d = dstRect.toSDL();
	SDL_RenderCopy(window.getRenderer(),t.getTexture(),&s,&d);
}

void Display::drawTexture(Texture &t, Rectangle dstRect)
{
	SDL_Rect d = dstRect.toSDL();
	SDL_RenderCopy(window.getRenderer(),t.getTexture(),NULL,&d);
}

void Display::drawText(Text &t,Rectangle dstRect)
{
	SDL_Rect dim = dstRect.toSDL();
	SDL_RenderCopy(window.getRenderer(),t.getTexture(),NULL,&dim);
}

void Display::drawSprite(Raycast &r,Item &i)
{
	if(i.isInWorld())
	{
		Rectangle aff=sprite.spriteItem(window,r.getPlayer(),i);
		
		int w,h;
		i.getTexture().getTextureDim(w,h);

		for(int x = 0; x<aff.w;x++)
		{
			if(sprite.isLineValid(window,r,aff.x+x)) 
			{
				int wAff = (int)(w/(float)aff.w);
				if(wAff == 0){wAff=1;}

				drawTexture(i.getTexture(),Rectangle((int)((w/(float)aff.w)*x),0,wAff,h),Rectangle(aff.x+x,aff.y,1,aff.h));
				//drawRect(Rectangle((int)((w/(float)aff.w)*x),0,wAff,h));
				//drawRect(Rectangle(aff.x+x,aff.y,1,aff.h));
			}
		}
	}
}

void Display::drawSprite(Raycast &r,Monster &m)
{
	Rectangle tex(0,0,0,0);
	tex=m.getPartTexture();
	Rectangle aff=sprite.spriteMonster(window,r.getPlayer(),m);

	for(int x = 0; x<aff.w;x++)
	{
		if(sprite.isLineValid(window,r,aff.x+x)) 
		{
			int wAff = (int)(tex.w/(float)aff.w);
			if(wAff == 0){wAff=1;}

			drawTexture(m.getTexture(),Rectangle((int)(tex.x+(tex.w/(float)aff.w)*x),0,wAff,tex.h),Rectangle(aff.x+x,aff.y,1,aff.h));
			//drawRect(Rectangle((int)((w/(float)aff.w)*x),0,wAff,h));
			//drawRect(Rectangle(aff.x+x,aff.y,1,aff.h));
		}
	}
	
}

void Display::drawSprite(Raycast &r,Generator &g)
{
	Rectangle aff=sprite.spriteGenerator(window,r.getPlayer(),g);
	
	int w,h;
	g.getTexture().getTextureDim(w,h);

	for(int x = 0; x<aff.w;x++)
	{
		if(sprite.isLineValid(window,r,aff.x+x)) 
		{
			int wAff = (int)(w/(float)aff.w);
			if(wAff == 0){wAff=1;}

			drawTexture(g.getTexture(),Rectangle((int)((w/(float)aff.w)*x),0,wAff,h),Rectangle(aff.x+x,aff.y,1,aff.h));
			//drawRect(Rectangle((int)((w/(float)aff.w)*x),0,wAff,h));
			//drawRect(Rectangle(aff.x+x,aff.y,1,aff.h));
		}
	}
	
}

void Display::drawPickedItem(vector<Item> &it)
{
	//Rectangle sizeItem (5,5,50,50);
	Texture &key = it[0].getTexture();
	drawTexture(key,Rectangle(window.getWindowWidth()-80,-20,100,100));
}

void Display::drawRaycast(Raycast &r, vector<Texture> &t)
{
    for(int x = 0; x < (int)window.getWindowWidth(); x++)
    {
        //drawColorWall(r,x);
		drawTextureWall(r,x,t);
    }
}

void Display::drawColorWall(Raycast &r,int &x)
{
	Color wallColor;
	Line l;
	do{
		l=r.getLineForColor(x,window.getWindowWidth(),window.getWindowHeight());
		switch(r.getCase())
		{
			case 2:  wallColor = RED;
			break;
			case 3:  wallColor = GREEN;
			break;
			case 4:  wallColor = BLUE;
			break;
			case 5:  wallColor = MAGENTA;
			break;
			default: wallColor = RED;
			break;
		}
		window.setDrawColor(wallColor);
		if(r.getSide() == 1)
		{
			window.setDrawColor(wallColor.shadowed());
		}
		drawLine(l);
	}while(r.isSpeWall());
}

void Display::drawTextureWall(Raycast &r,int &x,vector<Texture> &t)
{
	Rectangle aff;
	Rectangle tex;
	Texture &wallText = t[1];
	do{
		aff = r.getRectForTexture(x,window.getWindowWidth(),window.getWindowHeight(),wallText.getTextureWidth());
		tex.setRectangle(r.getTexX(),0,1,wallText.getTextureWidth());
		if(aff.y < 0)
		{
			tex.y = ((aff.y*tex.h)/aff.h)*-1;
			tex.h -= tex.y;
			if(tex.x > wallText.getTextureWidth())
			{
				tex.x = tex.h-1;
				tex.h = 1;
			}
			aff.y= 0;
		}
		switch(r.getCase())
		{
			case 1:  t[1] = t[3];
			break;
			case 2:  t[1] = t[0];
			break;
			case 3:  t[1] = t[2];
			break;
			case 10:  t[1] = t[4];
			break;
			case 12:  t[1] = t[4];
			break;
			default: t[1] = t[3];
			break;
		}
		drawTexture(wallText,tex,aff);
		
	}while(r.isSpeWall());
}

void Display::drawMiniMap(Raycast &ray,Monster& m)
{
	int xo=0,yo=0;
	if(ray.getMap().getMapHeight()>ray.getMap().getMapWidth())
	{
		for(int x=0;x<(int)ray.getMap().getMapWidth();x++)
		{
			for(int y=0;y<(int)ray.getMap().getMapHeight();y++)
			{
				if(ray.getMap().getWorldCase(x,y)>=1)
				{
					// création d'un rectangle blanche
					drawRect(Rectangle(xo, yo, 5, 5),Color(255,255,255,255));
				}
				if(ray.getMap().getWorldCase(x,y)==0)
				{
					// creation de petite case noir de taille 40
					drawRect(Rectangle(xo, yo, 5, 5),Color(0,0,0,155));
				}
				xo += 5;
			}
			xo = 0;
			yo += 5;
		}
		for(int i=0;i<m.getPathSize();i++)
		{
			drawRect(Rectangle(m.getPathCase(i).y*5,m.getPathCase(i).x*5,5,5),Color(255,255,0,255));
		}

		drawRect(Rectangle(ray.getPlayer().getEntity().y*5-3,ray.getPlayer().getEntity().x*5-3,6,6),Color(255,125,0,255));
	}
	else
	{
		for(int x=0;x<(int)ray.getMap().getMapWidth();x++)
		{
			for(int y=0;y<(int)ray.getMap().getMapHeight();y++)
			{
				if(ray.getMap().getWorldCase(x,y)>=1)
				{
					// création d'un rectangle blanche
					drawRect(Rectangle(yo, xo, 5, 5),Color(255,255,255,255));
				}
				if(ray.getMap().getWorldCase(x,y)==0)
				{
					// creation de petite case noir de taille 40
					drawRect(Rectangle(yo, xo, 5, 5),Color(0,0,0,155));
				}
				xo += 5;
			}
			xo = 0;
			yo += 5;
		}
		for(int i=0;i<m.getPathSize();i++)
		{
			drawRect(Rectangle(m.getPathCase(i).x*5,m.getPathCase(i).y*5,5,5),Color(255,255,0,255));
		}
		drawRect(Rectangle(ray.getPlayer().getEntity().x*5-3,ray.getPlayer().getEntity().y*5-3,6,6),Color(255,125,0,255));
	}

}

void Display::drawBackgroundPL(PowerLightGame &p) { 
	int w,h;
	p.BackgroundTexture.getTextureDim(w,h);
	drawTexture(p.BackgroundTexture,Rectangle(0,0,w,h),Rectangle(0,0,window.getWindowWidth(),window.getWindowHeight()));
}

void Display::drawAllLever(PowerLightGame &p){
	p.lever_Spritespace[0] = window.getWindowWidth()/6;
	int w,h;
	p.LeverTexture.getTextureDim(w,h);
	for (int i = 0; i<(int)p.AllLever.size(); i++) {
		drawTexture(p.LeverTexture,Rectangle(0,0,w,h),Rectangle(p.leverWidth*i +p.lever_Spritespace[i],window.getWindowHeight()/1.75,p.leverWidth,p.leverHeight));
		p.lever_Spritespace.push_back(p.lever_Spritespace[i] +10);
	}
}

void Display::drawLight(PowerLightGame &p) {
	int w,h;
	p.LightTextureGreen.getTextureDim(w,h);
	int w2,h2;
	p.LightTextureYellow.getTextureDim(w2,h2);
	int w3,h3;
	p.LightTextureRed.getTextureDim(w3,h3);
	for (int i = 0; i< 7; i++) {
		drawTexture(p.LightTextureGreen,Rectangle(0,0,w,h),Rectangle(p.LightDim*i,(window.getWindowHeight()/2) -p.LightDim,p.LightDim,p.LightDim));
	}
	drawTexture(p.LightTextureYellow,Rectangle(0,0,w2,h2),Rectangle(p.LightDim*7,(window.getWindowHeight()/2) -(p.LightDim +20),p.LightDim+20,p.LightDim+20)); // Le goal
	for (int i = 7; i< 12; i++) {
		drawTexture(p.LightTextureRed,Rectangle(0,0,w3,h3),Rectangle((p.LightDim*i) + p.LightDim+20,(window.getWindowHeight()/2) -(p.LightDim),p.LightDim,p.LightDim));
	}
}

void Display::drawResult(PowerLightGame &p) { 
	int w,h;
	p.LightTextureON.getTextureDim(w,h);
	if (p.result<8) {
         for (int i = 0; i<p.result; i++) {
			drawTexture(p.LightTextureON,Rectangle(0,0,w,h),Rectangle( p.LightDim*i,(window.getWindowHeight()/2) -p.LightDim,p.LightDim ,p.LightDim));
		 }
	}
	if (p.result == 8){ 
		for (int i = 0; i<p.result-1; i++) {
			drawTexture(p.LightTextureON,Rectangle(0,0,w,h),Rectangle( p.LightDim*i,(window.getWindowHeight()/2) -p.LightDim,p.LightDim ,p.LightDim));
		 }
		drawTexture(p.LightTextureON,Rectangle(0,0,w,h),Rectangle( p.LightDim*7,(window.getWindowHeight()/2) -(p.LightDim+20),p.LightDim+20 ,p.LightDim+20));
	}
	if (p.result > 8){ 
		for (int i = 0; i<7; i++) {
			drawTexture(p.LightTextureON,Rectangle(0,0,w,h),Rectangle( p.LightDim*i,(window.getWindowHeight()/2) -p.LightDim,p.LightDim ,p.LightDim));
		 }
		drawTexture(p.LightTextureON,Rectangle(0,0,w,h),Rectangle( p.LightDim*7,(window.getWindowHeight()/2) -(p.LightDim+20),p.LightDim+20 ,p.LightDim+20));
		 for (int i = 7; i<p.result-1; i++) {
			drawTexture(p.LightTextureON,Rectangle(0,0,w,h),Rectangle( p.LightDim*i+ (p.LightDim+20),(window.getWindowHeight()/2) -p.LightDim,p.LightDim ,p.LightDim));
		 }
	}
}

void Display::drawPowerlight(PowerLightGame &p) { 
	drawBackgroundPL(p);
	drawAllLever(p);
	drawLight(p);
	drawResult(p);
}
