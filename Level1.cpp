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

#include "Level1.h"

#include "LevelUp.h"
#include "FinalScene.h"
#include "HelloWorldScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"
#include "base/ccMacros.h"
#include "AudioEngine.h"

#include <scripting/deprecated/CCDeprecated.h>
#include <libwebsockets.h>

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -600));


    // 'layer' is an autorelease object
    auto layer = MainMenu::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool MainMenu::init()
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
    
    //--------------------ourMAP------------------//
    Sprite* map = Sprite::create("space.png");
    map->setPosition(Vec2(visibleSize.width /2 +origin.x, visibleSize.height/2));
    this->addChild(map, -1);
    /////////////////////////////////////////////////////////////////////////////////////////////
    auto label = Label::createWithTTF("Level 1: Get to the spaceship without getting killed! ", "fonts/arial.ttf", 24);
  
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height +origin.y-35));
    this->addChild(label, 1);
    auto label1 = Label::createWithTTF("(press the 'enter' key to enter the spaceship) ", "fonts/arial.ttf", 20);

    label1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height + origin.y - 55));
    this->addChild(label1, 1);
   

    //    //--------------ourPlayer--------------/
    auto menu_item_mn = MenuItemFont::create("MENU", CC_CALLBACK_1(MainMenu::MENU1, this));
    menu_item_mn->setPosition(Vec2(visibleSize.width /6+ origin.x -100 , visibleSize.height  + origin.y-30));

    auto* menu = Menu::create(menu_item_mn, NULL);
    menu->setPosition(Vec2(0, 0));
    this->addChild(menu);
    ////////////////////////////// */


    Knight = Sprite::create("alien.png");
    Knight->setPosition(Vec2(70, (visibleSize.height / 8 )+50));
    Knight->setScale(1.5);

    // Create physics body for player sprite and set its tag to 1
    auto playerBody = PhysicsBody::createBox(Size(20, 40));
    playerBody->setTag(1);
    playerBody->setDynamic(true);
    playerBody->setContactTestBitmask(true);
     
    //playerBody->applyImpulse(Vec2(0, 100));
    //auto mobBody = PhysicsBody::createBox(Knight->getContentSize());
   // mobBody->setContactTestBitmask(true); // Set contact test bitmask to true
    //Knight->setPhysicsBody(mobBody);

    // Attach physics body to player sprite
    Knight->setPhysicsBody(playerBody);

    this->addChild(Knight);


    //--------levelUp------------//





    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode)
        {
        case EventKeyboard::KeyCode::KEY_W:
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_SPACE:
   
            
                DirY += 5.0f;
                AudioEngine::play2d("jump.mp3", false, 1.0f);
                playerBody->applyImpulse(Vec2(0, -100));
                playerBody->applyForce(Vec2(0, -100));
        
          
            
            break;
        case EventKeyboard::KeyCode::KEY_A:
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            DirX -= 3.0f;
            break;
        case EventKeyboard::KeyCode::KEY_S:
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            DirY -= 1.0f;
            break;
        case EventKeyboard::KeyCode::KEY_D:
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            DirX += 3.0f;
            break;
        }
    };

    keyboardListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode)
        {
        case EventKeyboard::KeyCode::KEY_W:
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_SPACE:
       
            DirY -= 5.0f;
        
            break;
        case EventKeyboard::KeyCode::KEY_A:
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            DirX += 3.0f;
            break;
        case EventKeyboard::KeyCode::KEY_S:
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            DirY += 1.0f;
            break;
        case EventKeyboard::KeyCode::KEY_D:
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            DirX -= 3.0f;
            break;
        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    this->scheduleUpdate();




















    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 2);
    edgeBody->setVelocityLimit(1000);
    auto edgeNode = Node::create();

    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y+65));
    edgeNode->setPhysicsBody(edgeBody);

    this->addChild(edgeNode);

    {
       auto Enemy = Sprite::create("enemy.png");
       Enemy->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height));
       Enemy->setScale(1);

       // Create physics body for enemy sprite and set its tag to 2
       auto enemyBody = PhysicsBody::createBox(Size(40, 30));
       
       enemyBody->setContactTestBitmask(true);
       enemyBody->setDynamic(false);
       enemyBody->setTag(2);

       // Attach physics body to enemy sprite
       Enemy->setPhysicsBody(enemyBody);
       
       // Add enemy sprite to the scene
       this->addChild(Enemy);

       // Create the move action that moves the character from top to bottom
       auto moveToBottom = MoveTo::create(5, Vec2(origin.x + visibleSize.width / 2, origin.y+100)); // Move to bottom of the screen in 8 seconds
       auto moveToTop = MoveTo::create(5, Vec2(origin.x + visibleSize.width / 2, origin.y+200));
       // Create a sequence of actions that includes the move action
       auto sequence = Sequence::create(moveToBottom, moveToTop ,nullptr);

       // Create a repeat forever action that repeats the sequence of actions indefinitely
       auto repeatForever = RepeatForever::create(sequence);
       // Run actions on enemy sprite
       Enemy->runAction(repeatForever);
    }


    {
        auto Enemy = Sprite::create("enemy.png");
        Enemy->setPosition(Vec2(0, 600));
     
          Enemy->setScale(1);
      

        // Create physics body for enemy sprite and set its tag to 2
        auto enemyBody = PhysicsBody::createBox(Size(40, 30));
        enemyBody->setTag(2);
        enemyBody->setDynamic(false);
        enemyBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
      Enemy->setPhysicsBody(enemyBody);

        // Add enemy sprite to the scene
        this->addChild(Enemy);
   

        auto moveToRight = MoveTo::create(5, Vec2(visibleSize.width + origin.x, origin.y +200)); // Move to right side of the screen in 5 seconds
        auto moveToLeft = MoveTo::create(5, Vec2(origin.x, origin.y+200)); // Move back to left side of the screen in 5 seconds
        auto sequence = Sequence::create(moveToRight, moveToLeft, nullptr); // Create sequence of actions
        auto repeatForever = RepeatForever::create(sequence); // Repeat sequence of actions indefinitely

        // Run actions on enemy sprite
        Enemy->runAction(repeatForever);
        
    }
    {
        auto Enemy = Sprite::create("enemy.png");
        Enemy->setPosition(Vec2(0, 600));

        Enemy->setScale(1);


        // Create physics body for enemy sprite and set its tag to 2
        auto enemyBody = PhysicsBody::createBox(Size(40, 30));
        enemyBody->setTag(2);
        enemyBody->setDynamic(false);
        enemyBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        Enemy->setPhysicsBody(enemyBody);

        // Add enemy sprite to the scene
        this->addChild(Enemy);


        auto moveToRight = MoveTo::create(5, Vec2(origin.x, origin.y + 200)); // Move to right side of the screen in 5 seconds
        auto moveToLeft = MoveTo::create(5, Vec2(visibleSize.width + origin.x, origin.y + 00)); // Move back to left side of the screen in 5 seconds
        auto sequence = Sequence::create(moveToRight, moveToLeft, nullptr); // Create sequence of actions
        auto repeatForever = RepeatForever::create(sequence); // Repeat sequence of actions indefinitely

        // Run actions on enemy sprite
        Enemy->runAction(repeatForever);

    }
    {
        auto Enemy = Sprite::create("planSprite.png");
        Enemy->setPosition(Vec2(700, 105));
        auto enemyBody = PhysicsBody::createBox(Size(50, 50));

        Enemy->setScale(0.5);
        // Create physics body for enemy sprite and set its tag to 2
;

        enemyBody->setTag(2);
       enemyBody->setDynamic(false);
        enemyBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
       Enemy->setPhysicsBody(enemyBody);

        // Add enemy sprite to the scene
        this->addChild(Enemy);


        auto rotateBy = RotateBy::create(1.0, 360);  // Rotate by 360 degrees in 1 second
        auto repeatForever = RepeatForever::create(rotateBy);  // Repeat the rotation indefinitely
        // Run actions on enemy sprite
        Enemy->runAction(repeatForever);

    }
    {
        auto spaceship = Sprite::create("spaceship.png");
        spaceship->setPosition(Vec2(980, 135));
        auto spaceshipBody = PhysicsBody::createBox(Size(20, 70));

        spaceship->setScale(1.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        spaceship->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(spaceship);


        auto rotateBy = RotateBy::create(1.0, 360);  // Rotate by 360 degrees in 1 second
        auto repeatForever = RepeatForever::create(rotateBy);  // Repeat the rotation indefinitely
        // Run actions on enemy sprite
       // spaceship->runAction(repeatForever);

    }

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(MainMenu::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

       
    auto contactListen = EventListenerPhysicsContact::create();
    contactListen->onContactBegin = CC_CALLBACK_1(MainMenu::onContactBegin1, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListen, this);


 //------------------------------------------------------------------------//


  

    
    
    return true;

}

void MainMenu::update(float dt) {

    float newPosX = MainMenu::Knight->getPositionX() + (DirX);
    float newPosY = MainMenu::Knight->getPositionY() + (DirY);

    MainMenu::Knight->setPosition(newPosX, newPosY);
}



bool MainMenu::onContactBegin1(PhysicsContact& contact)
{
    auto bodyA = contact.getShapeA()->getBody();
    auto bodyB = contact.getShapeB()->getBody();

    if ((bodyA->getTag() == 1 && bodyB->getTag() == 3) ||
        (bodyA->getTag() == 3 && bodyB->getTag() == 1))
    {
        // Collision between player and enemy
        // Player takes damage




// Define the EventListenerKeyboard object and set its onKeyPressed callback function
        auto keyboardListener = EventListenerKeyboard::create();
        keyboardListener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event* event)
        {
            /*The capture list [this] specifies that the this pointer should be captured by the lambda function.
            This allows you to use the this pointer inside the lambda function to refer to the current object.*/
            // Check for the enter key press
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                // Pause the game for 2 seconds
                auto delay = DelayTime::create(1.0f);

                // Replace the scene
                auto replace = CallFunc::create([&]() {
                    auto scene = LevelUp::createScene();
                    Director::getInstance()->replaceScene(scene);
                    });
                AudioEngine::play2d("levelup.mp3", false, 1.0f);
                // Run the actions in sequence
                auto seq = Sequence::create(delay, replace, nullptr);
                this->runAction(seq);
            }
           
        };

        // Register the EventListenerKeyboard object with the event dispatcher
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
       
    }

    return true;
}
bool MainMenu::onContactBegin(PhysicsContact& contact)
{
    auto bodyA = contact.getShapeA()->getBody();
    auto bodyB = contact.getShapeB()->getBody();

    if ((bodyA->getTag() == 1 && bodyB->getTag() == 2) ||
        (bodyA->getTag() == 2 && bodyB->getTag() == 1))
    {
        // Collision between player and enemy
        // Player takes damage
       bodyA->setVelocity(Vec2::ZERO);
       
        bodyB->setVelocity(Vec2::ZERO);
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();//variable is not in scope or has not been declared.
        // Create a message label
        auto label = Label::createWithTTF("You failed!", "fonts/arial.ttf", 40);
        label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
        this->addChild(label, 10);

        // Pause the game for 2 seconds
        auto delay = DelayTime::create(1.0f);

        // Replace the scene
        auto replace = CallFunc::create([&]() {
            auto scene = FinalScene::createScene();
            Director::getInstance()->replaceScene(scene);
            });

        // Run the actions in sequence
        auto seq = Sequence::create(delay, replace, nullptr);
        this->runAction(seq);
    }
 

    return true;
}
void MainMenu::MENU1(cocos2d::Ref* pSender) {
    CCLOG("MENU");
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(scene);
}


   









