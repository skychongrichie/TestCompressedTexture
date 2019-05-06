//
//  CityScene.hpp
//  MiniGame
//
//  Created by wangrc on 2019/3/5.
//

#ifndef CityScene_hpp
#define CityScene_hpp

#include "cocos2d.h"


class CityScene : public cocos2d::Scene
{
public:
    static CityScene* create();

protected:
    virtual bool init();
    cocos2d::Sprite* createSprite(std::string file_path);
    void addSprite(std::string file_path, Node* parent);
    void addSprite(std::string file_path, Node* parent, cocos2d::Vec2 pos);
    cocos2d::Vec2 getRandomPosition();
    
    Node* _content_panel;
};

#endif /* CityScene_hpp */
