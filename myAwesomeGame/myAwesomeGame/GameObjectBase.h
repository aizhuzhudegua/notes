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
	//用多态,component是具体的组件
	void AddComponent(ComponentBase* component) {
		this->components.push_back(component);
	}
	~GameObjectBase() {
		vector<ComponentBase *>::iterator it = components.begin();
		//释放所有指针指向的空间
		while (it != components.end()) {
			//it的解引用是一个指针变量
			if (*it != nullptr) {
				delete *it;
			}
			++it;
		}
	}
};

