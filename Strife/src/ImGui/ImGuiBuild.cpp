#include "stpch.h"

/*
* Cherno didn't add these files to our project for some reason (personally I think he's as dumb as a sack of potatoes).
* Instead we're including the symbols we need in this file, and this is in the project, so when this file gets built,
* these cpp files also get built. Seems like a round-about way of including these files, but I'm sure there's a good
* reason for it.
*/

#define IMGUI_IMPL_OPENGL_LOADER_GLAD // Necessary for imgui_impl_opengl3.h
#include "backends/imgui_impl_opengl3.cpp"
#include "backends/imgui_impl_glfw.cpp"