#include "Camera.h"

Camera::Camera(glm::vec3 cameraPosition, glm::vec3 worldUp, glm::vec3 cameraFront , float yaw, float pitch) : 
	cameraPosition(cameraPosition), worldUp(worldUp), cameraFront(cameraFront), yaw(yaw), pitch(pitch), fieldOfView(MIN_ZOOM)
	{
		UpdateCameraVectors();
	}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}

void Camera::ProcessKeyboard(CameraMovement direction, float deltaTime)
{
	float velocity = MOVEMENT_SPEED * deltaTime;
	if (direction == FORWARD)
		cameraPosition += cameraFront * velocity;
	else if (direction == BACKWARD)
		cameraPosition -= cameraFront * velocity;
	else if (direction == LEFT)
		cameraPosition -= cameraRight * velocity;
	else if (direction == RIGHT)
		cameraPosition += cameraRight * velocity;
	else if (direction == UP)
		cameraPosition += worldUp * velocity;
}

void Camera::ProcessMouseMovement(float xOffset, float yOffset)
{
	xOffset *= MOUSE_SENSITIVITY;
	yOffset *= MOUSE_SENSITIVITY;

	yaw += xOffset;
	pitch += yOffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	UpdateCameraVectors();
}

void Camera::ProcessMouseScroll(float yOffset)
{
	fieldOfView -= (float)yOffset;
	if (fieldOfView < MAX_ZOOM) //zoom in
		fieldOfView = MAX_ZOOM;
	if (fieldOfView > MIN_ZOOM) //zoom out
		fieldOfView = MIN_ZOOM;
}

void Camera::UpdateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	//we use glm::normalize to make sure the length of vector is 1
	cameraFront = glm::normalize(front);
	cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
	cameraUp	= glm::normalize(glm::cross(cameraRight, cameraFront));
}