//
//  CityScene.cpp
//  MiniGame
//
//  Created by wangrc on 2019/3/5.
//

#include <time.h>
#include "CityScene.h"
USING_NS_CC;
using namespace std;


CityScene* CityScene::create()
{
    auto ret = new CityScene();
    if(ret && ret->init())
        ret->autorelease();
    else
        CC_SAFE_RELEASE(ret);
    
    return ret;
}

bool CityScene::init()
{
    if(!Scene::init())
        return false;
    
    Size win_size = Director::getInstance()->getWinSize();
    
    // init title panel
    Sprite* title_bg = createSprite("opaque/B_UI_Title_Frame.png");
    Sprite* button = createSprite("opaque/B_Btn_Black.png");
    title_bg->setAnchorPoint(ccp(0, 0));
    button->setAnchorPoint(ccp(0, 0));
    
    Node* title_panel = Node::create();
    title_panel->setContentSize(title_bg->getContentSize());
    title_panel->addChild(title_bg);
    title_panel->addChild(button);
    
//    title_panel->setPositionX(640);
    title_panel->setAnchorPoint(ccp(0.5, 1));
    title_panel->setPosition(ccp(win_size.width / 2, win_size.height));
    addChild(title_panel);
    
    // init content
    _content_panel = Node::create();
    _content_panel->setContentSize(Size(win_size.width, win_size.height - title_panel->getContentSize().height));
    addChild(_content_panel);
    
//    addSprite("alpha/BTN_mail_all.png", _content_panel);
//    addSprite("alpha/FB_jiyinjindutiao_red.png", _content_panel);
//    addSprite("alpha/FB_jiyinjindutiao_Green.png", _content_panel);
//    addSprite("alpha/FB_T_junhuogongying_jianzhuxiaolv1.png", _content_panel);
//    addSprite("alpha/FB_T_junhuogongying_jianzhuxiaolv1.png", _content_panel);
    addSprite("alpha/lianbing.png", _content_panel, ccp(win_size.width / 2, win_size.height / 2));
    
    return true;
}

Sprite* CityScene::createSprite(string file_path)
{
    return Sprite::create(file_path);
}

void CityScene::addSprite(string file_path, Node* parent)
{
    if(!parent)
        return;
    
    Sprite* sprite = createSprite(file_path);
    if(!sprite)
        return;
    
    sprite->setPosition(getRandomPosition());
    addChild(sprite);
}

void CityScene::addSprite(string file_path, Node* parent, Vec2 pos)
{
    if(!parent)
        return;
    
    Sprite* sprite = createSprite(file_path);
    if(!sprite)
        return;
    
    sprite->setPosition(pos);
    addChild(sprite);
}

Vec2 CityScene::getRandomPosition()
{
    srand(time(NULL));
    
    auto content_size = _content_panel->getContentSize();
    float x = rand() % (int)content_size.width;
    float y = rand() % (int)content_size.height;
    return ccp(x, y);
}
