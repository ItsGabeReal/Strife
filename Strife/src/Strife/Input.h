#pragma once

#include "Strife/Core.h"

namespace Strife {

	struct MousePosition
	{
		MousePosition(float mouseX, float mouseY)
			: X(mouseX), Y(mouseY) {}
		float X = 0;
		float Y = 0;
	};

	class STRIFE_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static MousePosition GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0; // This gets defined separately on each platform
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual MousePosition GetMousePositionImpl() = 0;

	private:
		static Input* s_Instance; // This should be the only instance of input that exists
	};

}