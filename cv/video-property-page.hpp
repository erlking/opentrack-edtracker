#pragma once

#ifdef _WIN32
#   include <windows.h>
#   include <dshow.h>
#endif

#include "opencv2/videoio.hpp"

struct video_property_page final
{
    video_property_page() = delete;
    static bool show(int id);
    static bool show_from_capture(cv::VideoCapture& cap, int idx);

private:
#ifdef _WIN32
    static HRESULT ShowFilterPropertyPages(IBaseFilter* filter);
    static IBaseFilter* get_device(int id);
#endif
};
