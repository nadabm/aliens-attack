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

#include "FinalScene.h"
#include "Level1.h"
#include <scripting/deprecated/CCDeprecated.h>
USING_NS_CC;

Scene* FinalScene::createScene()
{
    return FinalScene::create();
}


// on "init" you need to initialize your instance
bool FinalScene::init()
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
 

    auto g = Sprite::create("GameOver.png");
    g->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(g, -7);
    //----------------------start-button-----------------//
    auto menu_item_go = MenuItemFont::create("RETRY", CC_CALLBACK_1(FinalScene::RETRY, this));
    menu_item_go->setFontName("Futura");

    menu_item_go->setPosition(Vec2(visibleSize.width / 2 +origin.x-10, (visibleSize.height / 8) +origin.y));
    //-----------------------quit-button-------//
    //auto menu_item_go1 = MenuItemImage::create("closeB.png", "closeB.png", CC_CALLBACK_1(FinalScene::menuCloseCallback, this));
    //menu_item_go1->setPosition(Vec2(visibleSize.width / 2, (visibleSize.height / 8) * 2));


    auto* menu1 = Menu::create(menu_item_go, NULL);
    menu1->setPosition(Vec2(0, 0));
    this->addChild(menu1);

 
 
   
   
    return true;
}
void FinalScene::RETRY(cocos2d::Ref* pSender) {
    CCLOG("RETRY");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // Create a label to display the countdown
    auto label = Label::createWithTTF("3", "fonts/arial.ttf", 45);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height + origin.y - 50));
    this->addChild(label);

    // Run a sequence of actions to countdown from 3 to 1
    label->runAction(Sequence::create(
        CallFunc::create([label]() { label->setString("3"); }),
        DelayTime::create(1.0),
        CallFunc::create([label]() { label->setString("2"); }),
        DelayTime::create(1.0),
        CallFunc::create([label]() { label->setString("1"); }),
        DelayTime::create(1.0),
        CallFunc::create([this]() {
            // Push the main menu scene onto the scene stack when the countdown is finished
          auto scene = MainMenu::createScene();
            Director::getInstance()->pushScene(scene);
            }),
        nullptr
                ));
}





