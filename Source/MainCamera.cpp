#include "MainCamera.h"

MainCamera::MainCamera(void)
{
	far_z	= 1000.0f;
	fov		= Deg2Rad(60.0f);

	coordinate	= AddComponent<CameraSphericalCoordinate>();

	coordinate->theta		= 1.444f;
	coordinate->distance	= 900.0f;


}

void MainCamera::SetTarget(Transform * target)
{
	at = target->position;
}

