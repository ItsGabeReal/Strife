#include "stpch.h"

/*
* This file imports symbols from ImGui while letting ImGui remain as a submodule (I think)
*/

#define IMGUI_IMPL_OPENGL_LOADER_GLAD // Necessary for imgui_impl_opengl3.h
#include "backends/imgui_impl_opengl3.cpp"
#include "backends/imgui_impl_glfw.cpp"