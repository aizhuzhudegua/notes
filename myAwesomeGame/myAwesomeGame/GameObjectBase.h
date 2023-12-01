#pragma once
#include <vector>
#include "ComponentBase.h"
using namespace std;

class GameObjectBase
{
public:
	vector<ComponentBase*> components;
	GameObjectBase() {
		
	}
	//�ö�̬,component�Ǿ�������
	void AddComponent(ComponentBase* component) {
		this->components.push_back(component);
	}
	~GameObjectBase() {
		vector<ComponentBase *>::iterator it = components.begin();
		//�ͷ�����ָ��ָ��Ŀռ�
		while (it != components.end()) {
			//it�Ľ�������һ��ָ�����
			if (*it != nullptr) {
				delete *it;
			}
			++it;
		}
	}
};

