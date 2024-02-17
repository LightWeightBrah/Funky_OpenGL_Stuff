#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum CameraMovement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP
};

const float DEFAULT_YAW = -90.0f; //yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left
const float DEFAULT_PITCH = 0.0f;

const float MOVEMENT_SPEED = 2.5f;
const float MOUSE_SENSITIVITY = 0.1f;
const float MIN_ZOOM = 45.0f; //the higher value the farther zoom out
const float MAX_ZOOM = 1.0f; //the higher value the nearer zoom in

class Camera
{
public:
	glm::vec3 cameraPosition;
	glm::vec3 cameraUp;
	glm::vec3 cameraFront;
	glm::vec3 cameraRight;

	glm::vec3 worldUp;

	float yaw;
	float pitch;
	float fieldOfView;

	Camera(glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f), 
		float yaw = DEFAULT_YAW, 
		float pitch = DEFAULT_PITCH);

	glm::mat4 GetViewMatrix();

	void ProcessKeyboard(CameraMovement direction, float deltaTime);
	void ProcessMouseMovement(float xOffset, float yOffset);
	void ProcessMouseScroll(float yOffset);

private:
	void UpdateCameraVectors();
};