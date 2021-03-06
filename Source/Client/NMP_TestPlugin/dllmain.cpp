#define _SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#define USE_BOOST_ASIO 1

#include <Windows.h>
#include <string>

#include "../NM_Engine/NM_Main.h"
#include "../NM_Engine/NM_App.h"

#define PLUGIN_NAME "Test plugin"

static auto gs_szErrorMessae	= std::string("");
static auto gs_hModule			= HMODULE(nullptr);
static auto gs_nmApp			= std::shared_ptr<CNM_App>();

extern "C" __declspec(dllexport) const char* __cdecl PluginName(void)
{
	return PLUGIN_NAME;
}

extern "C" __declspec(dllexport) const char* __cdecl PluginVersion(void)
{
	return __TIME__;
}

extern "C" __declspec(dllexport) const char* __cdecl PluginErrorMessage(void)
{
	return gs_szErrorMessae.c_str();
}

extern "C" __declspec(dllexport) bool __cdecl PluginOnInit(LPVOID pAppClassPtr)
{
#if 0
	char szModuleName[MAX_PATH] = { 0 };
	GetModuleFileNameA(NULL, szModuleName, MAX_PATH);

	char szMsg[512] = { 0 };
	sprintf(szMsg, "Hello world! App ptr: %p Plugin: %s(%s!PluginOnInit)", pAppClassPtr, szModuleName, PLUGIN_NAME);

	MessageBoxA(0, szMsg, "Plugin", 0);
#endif
	return true;
}

extern "C" __declspec(dllexport) bool __cdecl PluginOnFinal(void)
{
	MessageBoxA(0, "Bye!", "PluginOnFinal", 0);
	return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (!gs_hModule)
		gs_hModule = hModule;

	return TRUE;
}
