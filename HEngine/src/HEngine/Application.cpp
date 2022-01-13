#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "HEngine/Log.h"

namespace HEngine
{
	Application::Application()
	{
		
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			// Can Enter
			HE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			// Can't Enter
			HE_TRACE(e);
		}

		while (true)
		{
			
		}
	}

}
