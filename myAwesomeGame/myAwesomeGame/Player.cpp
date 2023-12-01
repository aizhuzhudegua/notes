#include "Player.h"
Player::Player() {
    //一般情况下玩家需要transform组件
    TransformComponent transform;
    //调用从父类继承的方法增加组件
    AddComponent(&transform);
}