#pragma once
#include <iostream>

class Vector3 {
public:
	Vector3() {
		//default constructor
	}
	//initialize xyz
	Vector3(int x,int y,int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3 operator +(Vector3 & v) {
		return Vector3(this->x+v.x, this->y + v.y, this->z + v.z);
	}
	Vector3 operator -(Vector3& v) {
		return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
	}
	friend std::ostream& operator<<(std::ostream& out, const Vector3& v);
	

private:
	int x,y,z;

};
