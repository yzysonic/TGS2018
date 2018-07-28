#pragma once
#include "Core/Core.h"
#include "CameraSphericalCoordinate.h"
#include "CameraSmoothFollow.h"

class MainCamera :public Camera
{
public:
	MainCamera(void);
	void SetTarget(Transform* target);
private:
	CameraSphericalCoordinate* coordinate;
	CameraSmoothFollow* smooth;
};