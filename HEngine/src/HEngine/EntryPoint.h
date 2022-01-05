#pragma once

#ifdef HE_PLATFORM_WINDOWS

extern HEngine::Application* HEngine::CreateApplication();

int main(int argc, char** argv)
{
	HEngine::Log::Init();
	HE_CORE_WARN("Init Finish!");
	HE_INFO("TEST! Var = {0}", 123);

	auto app = HEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif