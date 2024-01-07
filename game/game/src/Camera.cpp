#include <Camera.h>

Camera::Camera(glm::vec3 _position, glm::vec3 _target, glm::vec3 worldup)
{
	Position = _position;
	WorldUp = worldup;
	// _target指向相机的单位向量
	Forward = glm::normalize(Position - _target);
	// 世界Up叉乘Forward向量可以得到右向量
	Right = glm::normalize(glm::cross(WorldUp,Forward));
	// Forward叉乘Right自然得到Up
	Up = glm::normalize(glm::cross(Forward, Right));
}

//欧拉角版本
Camera::Camera(glm::vec3 _position, float pitch, float yaw, glm::vec3 worldup) {
	
	Position = _position;
	WorldUp = worldup;
	Pitch = pitch;
	Yaw = yaw;
	UpdateCameraVectors();
};

Camera::~Camera() {

}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(Position,Position-Forward,WorldUp);
}

void Camera::UpdateCameraVectors() {
	//注意Forward算出来是个单位向量
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw);
	// 世界Up叉乘Forward向量可以得到右向量
	Right = glm::normalize(glm::cross(WorldUp, Forward));
	// Forward叉乘Right自然得到Up
	Up = glm::normalize(glm::cross(Forward, Right));
};

void Camera::ProcessMouseMovement(float deltaX, float deltaY) {

	Pitch += deltaY * SenseX;
	Yaw -= deltaX * SenseY;

	// 避免Pitch到达90度，会有bug
	if (Pitch > 89.0f)
		Pitch = 89.0f;
	if (Pitch < -89.0f)
		Pitch = -89.0f;

	UpdateCameraVectors();

};

void Camera::UpdateCameraPos() {

	Position += Forward * -speedZ * 0.1f;
	Position += Right * speedX * 0.1f;
	Position += Up * speedY * 0.1f;
};