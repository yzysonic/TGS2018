#include "MainCamera.h"

MainCamera::MainCamera(void)
{
	far_z	= 1000.0f;
	fov		= Deg2Rad(60.0f);

	coordinate	= AddComponent<CameraSphericalCoordinate>();
	smooth		= AddComponent<CameraSmoothFollow>();

	coordinate->theta		= 1.444f;
	coordinate->distance	= 65.0f;

	smooth->SetActive(false);

	render_target = nullptr;
}

void MainCamera::SetTarget(Transform * target)
{
	at = target->position;
	smooth->target = target;
	smooth->SetActive(true);
}

