#include <cstdint>
#include <Windows.h>

#if defined(DEBUG_MODE) || defined(RELEASE_MODE) || defined(DEVELOPMENT_MODE)
#include <crtdbg.h>
#endif

#include "Application.h"

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
#if defined(DEBUG_MODE) || defined(RELEASE_MODE) || defined(DEVELOPMENT_MODE)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	std::unique_ptr<Application> app = std::make_unique<Application>();
	app->Init();
	app->Run();
	app.reset();

	return 0;
}