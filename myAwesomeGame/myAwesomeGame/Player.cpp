#include "Player.h"
Player::Player() {
    //һ������������Ҫtransform���
    TransformComponent transform;
    //���ôӸ���̳еķ����������
    AddComponent(&transform);
}