#pragma once

#include "Strife/Input.h"
#include "Strife/Input.h"

namespace Strife {

	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual MousePosition GetMousePositionImpl() override;
	};
}