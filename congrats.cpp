/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "HelloWorldScene.h"
#include "FinalScene.h"
#include "Level2.h"
#include "Level1.h"
#include "congrats.h"
#include <scripting/deprecated/CCDeprecated.h>
USING_NS_CC;

Scene* Congrats::createScene()
{
    return Congrats::create();
}


// on "init" you need to initialize your instance
bool Congrats::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
 

    auto g = Sprite::create("uwin.png");
    g->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(g, -7);
    //----------------------start-button-----------------//
    auto menu_item_go = MenuItemFont::create("MENU", CC_CALLBACK_1(Congrats::MENU, this));
    menu_item_go->setFontName("Futura");
    menu_item_go->setPosition(Vec2(visibleSize.width / 2,150));

    auto menu_item_2 = MenuItemFont::create("QUIT", CC_CALLBACK_1(Congrats::menuCloseCallback, this));
    menu_item_2->setPosition(Vec2(visibleSize.width / 2,100));


    auto* menu1 = Menu::create(menu_item_go, menu_item_2, NULL);
    menu1->setPosition(Vec2(0, 0));
    this->addChild(menu1,200);
   
    return true;
}


void Congrats::MENU(cocos2d::Ref* pSender) {
    //CCLOG("RETRY");

          auto scene = HelloWorld::createScene();
            Director::getInstance()->pushScene(scene);
       
}
void Congrats::menuCloseCallback(cocos2d::Ref* pSender) {


    Director::getInstance()->end();


}





