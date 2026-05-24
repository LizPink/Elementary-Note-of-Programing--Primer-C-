#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include <vector>
#include "Screen.h"

class Window_mgr{
    using ScreenIndex = std::vector<Screen>::size_type;

    public:
        void clear(ScreenIndex);

    private:
        // 这个 window_mgr 追踪的screen
        std::vector<Screen> screens{Screen(24,80,'c')};
};

#endif