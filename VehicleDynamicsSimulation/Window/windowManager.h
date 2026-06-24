#pragma once

namespace WindowManager
{
    // Creates window, initializes GLAD, runs the render loop, and returns 0 on success or -1 on failure.
    int CreateAndRunWindow(int width = 1280, int height = 720, const char* title = "Vehicle Dynamics Simulator");
}
