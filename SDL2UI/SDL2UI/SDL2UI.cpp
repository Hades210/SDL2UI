#include "stdafx.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "Draw.h"

#include "View.h"
#include "ViewGroup.h"

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 768;

Draw *draw = nullptr;

ViewGroup *viewgroup = nullptr;

int main(int argc, char * argv[]) {

	draw = new Draw();

	viewgroup = new ViewGroup("root", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	viewgroup->setBackground(255, 255, 255, 255);
	ViewParent *viewParent = new ViewParent();
	viewParent->left = 0;
	viewParent->top = 0;
	viewParent->right = viewgroup->getWidth();
	viewParent->bottom = viewgroup->getHeight();
	viewParent->width = viewgroup->getWidth();
	viewParent->htight = viewgroup->getHeight();
	//std::cout << "LEFT:" << viewParent->left << ",RIGHT:" << viewParent->right << std::endl;
	viewgroup->setViewParent(viewParent);

	//Top
	ViewGroup *toolbar = new ViewGroup("toolbar", 0, 0, SCREEN_WIDTH, 300);
	toolbar->setBackground(255, 125, 125, 255);
	viewgroup->addView(toolbar);

	ViewGroup *nav = new ViewGroup("nav", 0, 0, 50, 50);
	nav->setBackground(125, 255, 125, 255);
	toolbar->addView(nav);

	ViewGroup *menu = new ViewGroup("menu", SCREEN_WIDTH - 100, 100, 100, 1000);
	menu->setBackground(125, 255, 125, 255);
	toolbar->addView(menu);

	View *menua = new View("menua", 0, 0, 50, 50);
	menua->setBackground(255, 255, 255, 255);
	menu->addView(menua);

	//Content
	ViewGroup *content = new ViewGroup("Content", 0, 300, SCREEN_WIDTH, SCREEN_HEIGHT - 50);
	content->setBackground(125, 125, 255, 255); 
	viewgroup->addView(content);

	View *viewA = new View("viewA", 200, 200, 400, 400);
	viewA->setBackground(125, 255, 125, 255);
	content->addView(viewA);

	draw->showLOG(true);
	draw->Init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, 200);
	return 0;
}

void Draw::onDraw(SDL_Window *window, SDL_Renderer *renderer) {
	viewgroup->onDraw(draw);
}

void Draw::onKeyDown(int key) {

}

void Draw::onMouseMove(int x, int y) {
	viewgroup->onTouchEvent(View::EVENT_ACTION_MOVE, 0, x, y);
}

void Draw::onMouseDown(int x, int y, int button) {
	viewgroup->onTouchEvent(View::EVENT_ACTION_DOWN, 0, x, y);
}

void Draw::onMouseUP(int x, int y, int button) {
	viewgroup->onTouchEvent(View::EVENT_ACTION_UP, 0, x, y);
}