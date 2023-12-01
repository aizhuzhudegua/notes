# 用迭代器迭代vector容器

```c++
#include <vector>
using namespace std;
vector<ComponentBase *>::iterator it = components.begin();
//释放所有指针指向的空间
while (it != components.end()) {
	//it的解引用是一个指针变量
	if (*it != nullptr) {
		delete *it;
	}
	++it;
}
```

