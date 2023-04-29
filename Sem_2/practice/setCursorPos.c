#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Shell.h>

int main()
{
    for(int i=0; i<1000; i++)
    {
    
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Error: could not open display\n");
        return 1;
    }

    int screen = DefaultScreen(display);
    Window root = RootWindow(display, screen);
    XWarpPointer(display, None, root, 0, 0, 0, 0, i, i);
    for(int i=0; i<1000000; i++);
    XFlush(display);

    XCloseDisplay(display);
    
    }
    return 0;
}
