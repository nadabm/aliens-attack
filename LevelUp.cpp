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

#include "LevelUp.h"
#include "Level1.h"
#include "Level2.h"
#include <scripting/deprecated/CCDeprecated.h>
USING_NS_CC;

Scene* LevelUp::createScene()
{
    return LevelUp::create();
}


// on "init" you need to initialize your instance
bool LevelUp::init()
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
 

    auto up = Sprite::create("levelUp.png");
    up->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(up, -7);

    auto menu_item_up = MenuItemFont::create("LEVEL 2", CC_CALLBACK_1(LevelUp::Level2, this));
    menu_item_up->setFontName("Futura");

    menu_item_up->setPosition(Vec2(visibleSize.width / 2 +origin.x-10, (visibleSize.height / 8) +origin.y));
    auto label = Label::createWithTTF("GONGRATULATIONS!", "fonts/arial.ttf", 36);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(label, 10);


    auto* menu2 = Menu::create(menu_item_up, NULL);
    menu2->setPosition(Vec2(0, 0));
    this->addChild(menu2);

 
 
   
   
    return true;
}
void LevelUp::Level2(cocos2d::Ref* pSender) {
    auto scene = Level2::createScene();
    Director::getInstance()->pushScene(scene);
}





