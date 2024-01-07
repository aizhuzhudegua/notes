#include <Camera.h>

Camera::Camera(glm::vec3 _position, glm::vec3 _target, glm::vec3 worldup)
{
	Position = _position;
	WorldUp = worldup;
	// _targetָ������ĵ�λ����
	Forward = glm::normalize(Position - _target);
	// ����Up���Forward�������Եõ�������
	Right = glm::normalize(glm::cross(WorldUp,Forward));
	// Forward���Right��Ȼ�õ�Up
	Up = glm::normalize(glm::cross(Forward, Right));
}

//ŷ���ǰ汾
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
	//ע��Forward������Ǹ���λ����
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw);
	// ����Up���Forward�������Եõ�������
	Right = glm::normalize(glm::cross(WorldUp, Forward));
	// Forward���Right��Ȼ�õ�Up
	Up = glm::normalize(glm::cross(Forward, Right));
};

void Camera::ProcessMouseMovement(float deltaX, float deltaY) {

	Pitch += deltaY * SenseX;
	Yaw -= deltaX * SenseY;

	// ����Pitch����90�ȣ�����bug
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