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
#include "congrats.h"
#include "Level2.h"
#include "AudioEngine.h"
#include "FinalScene.h"
#include "LevelUp.h"
#include <scripting/deprecated/CCDeprecated.h>
USING_NS_CC;

Scene* Level2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
   //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -500));


    // 'layer' is an autorelease object
    auto layer = Level2::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());


    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Level2::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
 

    /////////////////////////////mymaap/////////////
 
    Sprite* map2 = Sprite::create("bg22.jpg");
    map2->setPosition(Vec2(visibleSize.width/2  , visibleSize.height /2));
    this->addChild(map2, 100);
    /////////////////////////////////////////////////////////////////////////////////////////////
    auto label = Label::createWithTTF("Level 2:  ", "fonts/arial.ttf", 24);

    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height + origin.y-35 ));
    this->addChild(label, 200);
    //-----------------------------my player//

    Knight = Sprite::create("alien2.png");
    Knight->setPosition(Vec2(990, (visibleSize.height / 8) + 40));
    Knight->setScale(0.5);

    // Create physics body for player sprite and set its tag to 1
    auto playerBody = PhysicsBody::createBox(Size(70, 120));
    playerBody->setTag(11);
    playerBody->setDynamic(true);
    playerBody->setContactTestBitmask(true);

    //playerBody->applyImpulse(Vec2(0, 100));
    //auto mobBody = PhysicsBody::createBox(Knight->getContentSize());
   // mobBody->setContactTestBitmask(true); // Set contact test bitmask to true
    //Knight->setPhysicsBody(mobBody);

    // Attach physics body to player sprite
    Knight->setPhysicsBody(playerBody);

    this->addChild(Knight,200);


    //--------enemies------------//
       ////////////////////////edgenode///////////////////////////

    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
  
    auto edgeNode = Node::create();

    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 65));
    edgeNode->setPhysicsBody(edgeBody);

    this->addChild(edgeNode);

    {
        auto Enemy2 = Sprite::create("enemy2.png");
        Enemy2->setPosition(Vec2(300,(visibleSize.height / 7) + 50));
        Enemy2->setScale(1);

        // Create physics body for enemy sprite and set its tag to 2
        auto enemyBody = PhysicsBody::createBox(Size(40, 30));

        enemyBody->setContactTestBitmask(true);
        enemyBody->setDynamic(false);
        enemyBody->setTag(12);

        // Attach physics body to enemy sprite
        Enemy2->setPhysicsBody(enemyBody);

        // Add enemy sprite to the scene
        this->addChild(Enemy2, 200);

        // Create the move action that moves the character from top to bottom
        auto moveToBottom = MoveTo::create(5, Vec2(origin.x + visibleSize.width / 2, origin.y + 100)); // Move to bottom of the screen in 8 seconds
        auto moveToTop = MoveTo::create(5, Vec2(origin.x + visibleSize.width / 2, origin.y + 200));
        // Create a sequence of actions that includes the move action
        auto sequence = Sequence::create(moveToBottom, moveToTop, nullptr);

        // Create a repeat forever action that repeats the sequence of actions indefinitely
        auto repeatForever = RepeatForever::create(sequence);
        // Run actions on enemy sprite
        Enemy2->runAction(repeatForever);
    }
    {
        auto Enemy2 = Sprite::create("enemy2.png");
        Enemy2->setPosition(Vec2(100, (visibleSize.height/2) + 50));
        Enemy2->setScale(1);

        // Create physics body for enemy sprite and set its tag to 2
        auto enemyBody = PhysicsBody::createBox(Size(40, 30));

        enemyBody->setContactTestBitmask(true);
        enemyBody->setDynamic(false);
        enemyBody->setTag(12);

        // Attach physics body to enemy sprite
        Enemy2->setPhysicsBody(enemyBody);

        // Add enemy sprite to the scene
        this->addChild(Enemy2, 250);

        // Create the move action that moves the character from top to bottom
        auto moveToBottom = MoveTo::create(2, Vec2(300, 300)); // Move to bottom of the screen in 8 seconds
        auto moveToTop = MoveTo::create(2, Vec2(300 , 400));
        // Create a sequence of actions that includes the move action
        auto sequence = Sequence::create(moveToBottom, moveToTop, nullptr);

        // Create a repeat forever action that repeats the sequence of actions indefinitely
        auto repeatForever = RepeatForever::create(sequence);
        // Run actions on enemy sprite
        Enemy2->runAction(repeatForever);
    }
    {
        auto Enemy2 = Sprite::create("enemy2.png");
        Enemy2->setPosition(Vec2(150, (visibleSize.height / 2) + 50));
        Enemy2->setScale(1);

        // Create physics body for enemy sprite and set its tag to 2
        auto enemyBody = PhysicsBody::createBox(Size(40, 30));

        enemyBody->setContactTestBitmask(true);
        enemyBody->setDynamic(false);
        enemyBody->setTag(12);

        // Attach physics body to enemy sprite
        Enemy2->setPhysicsBody(enemyBody);

        // Add enemy sprite to the scene
        this->addChild(Enemy2, 250);

        // Create the move action that moves the character from top to bottom
        auto moveToBottom = MoveTo::create(5, Vec2(50, 400)); // Move to bottom of the screen in 8 seconds
        auto moveToTop = MoveTo::create(5, Vec2(1100, 400));
        // Create a sequence of actions that includes the move action
        auto sequence = Sequence::create(moveToBottom, moveToTop, nullptr);

        // Create a repeat forever action that repeats the sequence of actions indefinitely
        auto repeatForever = RepeatForever::create(sequence);
        // Run actions on enemy sprite
        Enemy2->runAction(repeatForever);
    }
    {
        auto Enemy2 = Sprite::create("enemy2.png");
        Enemy2->setPosition(Vec2(150, (visibleSize.height / 2) + 50));
        Enemy2->setScale(1);

        // Create physics body for enemy sprite and set its tag to 2
        auto enemyBody = PhysicsBody::createBox(Size(40, 30));

        enemyBody->setContactTestBitmask(true);
        enemyBody->setDynamic(false);
        enemyBody->setTag(12);

        // Attach physics body to enemy sprite
        Enemy2->setPhysicsBody(enemyBody);

        // Add enemy sprite to the scene
        this->addChild(Enemy2, 250);

        // Create the move action that moves the character from top to bottom
        auto moveToBottom = MoveTo::create(5, Vec2(1100, 200)); // Move to bottom of the screen in 8 seconds
        auto moveToTop = MoveTo::create(5, Vec2(50, 200));
        // Create a sequence of actions that includes the move action
        auto sequence = Sequence::create(moveToBottom, moveToTop, nullptr);

        // Create a repeat forever action that repeats the sequence of actions indefinitely
        auto repeatForever = RepeatForever::create(sequence);
        // Run actions on enemy sprite
        Enemy2->runAction(repeatForever);
    }

  auto contactListener = EventListenerPhysicsContact::create();
     contactListener->onContactBegin = CC_CALLBACK_1(Level2::onContactBegin, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

  auto contactListen = EventListenerPhysicsContact::create();
  contactListen->onContactBegin = CC_CALLBACK_1(Level2::onContactBegin1, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListen, this);
 
   
    {//1
        auto stone = Sprite::create("stone.png");
        stone->setPosition(Vec2(850, 100));
        auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

        stone->setScale(0.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        stone->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(stone, 200);


    }
    {
    auto stone = Sprite::create("stone.png");
    stone->setPosition(Vec2(200, 100));
    auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

    stone->setScale(0.7);
    // Create physics body for enemy sprite and set its tag to 2
    ;

    spaceshipBody->setTag(3);
    spaceshipBody->setDynamic(false);
    spaceshipBody->setContactTestBitmask(true);
    // Attach physics body to enemy sprite
    stone->setPhysicsBody(spaceshipBody);

    // Add enemy sprite to the scene
    this->addChild(stone, 200);


    }
    {//2
        auto stone = Sprite::create("stone.png");
        stone->setPosition(Vec2(750,200));
        auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

        stone->setScale(0.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        stone->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(stone,200);


    }
    {//3
        auto stone = Sprite::create("stone.png");
        stone->setPosition(Vec2(950, 300));
        auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

        stone->setScale(0.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        stone->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(stone, 200);


    }
    {//4
        auto stone = Sprite::create("stone.png");
        stone->setPosition(Vec2(740, 360));
        auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

        stone->setScale(0.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        stone->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(stone, 200);


    }
    {//5
        auto stone = Sprite::create("stone.png");
        stone->setPosition(Vec2(950, 450));
        auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

        stone->setScale(0.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        stone->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(stone, 200);


    }
    {//6
        auto stone = Sprite::create("stone.png");
        stone->setPosition(Vec2(730, 500));
        auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

        stone->setScale(0.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        stone->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(stone, 200);


    }
    {//7
        auto stone = Sprite::create("stone.png");
        stone->setPosition(Vec2(550,390));
        auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

        stone->setScale(0.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        stone->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(stone, 200);


    }
    {//8
        auto stone = Sprite::create("stone.png");
        stone->setPosition(Vec2(340, 450));
        auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

        stone->setScale(0.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        stone->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(stone, 200);


    }
    {//9
        auto stone = Sprite::create("stone.png");
        stone->setPosition(Vec2(190, 390));
        auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

        stone->setScale(0.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        stone->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(stone, 200);


    }
    {//10
        auto stone = Sprite::create("stone.png");
        stone->setPosition(Vec2(70, 450));
        auto spaceshipBody = PhysicsBody::createBox(Size(200, 40));

        stone->setScale(0.7);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(3);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        stone->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(stone, 200);


    }
    //----spaceship----------//
    {
        auto spaceship = Sprite::create("spaceship2.png");
        spaceship->setPosition(Vec2(73, 540));
        auto spaceshipBody = PhysicsBody::createBox(Size(50, 330));

        spaceship->setScale(0.4);
        // Create physics body for enemy sprite and set its tag to 2
        ;

        spaceshipBody->setTag(14);
        spaceshipBody->setDynamic(false);
        spaceshipBody->setContactTestBitmask(true);
        // Attach physics body to enemy sprite
        spaceship->setPhysicsBody(spaceshipBody);

        // Add enemy sprite to the scene
        this->addChild(spaceship, 200);


    }


  


    ////////////////////////////////////////////////////////////////////////////



    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode)
        {
        case EventKeyboard::KeyCode::KEY_W:
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_SPACE:


            DirY += 4.0f;
            AudioEngine::play2d("jumpP.mp3", false, 1.0f);
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

            DirY -= 4.0f;

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

 
 
   
   
    return true;
}


void Level2::update(float dt) {

    float newPosX = Level2::Knight->getPositionX() + (DirX);
    float newPosY = Level2::Knight->getPositionY() + (DirY);
    Level2::Knight->setRotation(0);// to stop him from fallin down 
    Level2::Knight->setPosition(newPosX, newPosY);
    if (newPosX < 70){
        // Replace the scene
        auto replace = CallFunc::create([&]() {
            auto scene = FinalScene::createScene();
            Director::getInstance()->replaceScene(scene);
            });

    }
}


bool Level2::onContactBegin(PhysicsContact& contact)
{
    auto bodyA = contact.getShapeA()->getBody();
    auto bodyB = contact.getShapeB()->getBody();

    if ((bodyA->getTag() == 11 && bodyB->getTag() == 12) ||
        (bodyA->getTag() == 12 && bodyB->getTag() == 11))
    {
        // Collision between player and enemy
        // Player takes damage
        AudioEngine::play2d("stop.mp3", false, 1.0f);
        auto visibleSize = Director::getInstance()->getVisibleSize();
        // Vec2 origin = Director::getInstance()->getVisibleOrigin();//variable is not in scope or has not been declared.
         // Create a message label
        auto label = Label::createWithTTF("You failed!", "fonts/arial.ttf", 40);
        label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
        this->addChild(label, 2000);

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

bool Level2::onContactBegin1(PhysicsContact& contact)
{
    auto bodyA = contact.getShapeA()->getBody();
    auto bodyB = contact.getShapeB()->getBody();

    if ((bodyA->getTag() == 11 && bodyB->getTag() == 14) ||
        (bodyA->getTag() == 14 && bodyB->getTag() == 11))
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
                    auto scene = Congrats::createScene();
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


