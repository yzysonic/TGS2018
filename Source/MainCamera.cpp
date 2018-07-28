#include "MainCamera.h"

MainCamera::MainCamera(void)
{
	far_z	= 1000.0f;
	fov		= Deg2Rad(60.0f);

	coordinate	= AddComponent<CameraSphericalCoordinate>();

	coordinate->theta		=  0.5;
	coordinate->distance	= 600.0f;

	setBackColor(Color(50, 215, 250, 255));

}

void MainCamera::SetTarget(Transform * target)
{
	at = target->position;
}

