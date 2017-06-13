#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>
#include <stdio.h>

int main() {
  int x = 0;
  int y = 0;

  Display* display = NULL;
  XImage* image = NULL;
  Window root;
  Cursor crosshair;
  XEvent ev;

  display = XOpenDisplay(NULL);
  root = DefaultRootWindow(display);
  crosshair = XCreateFontCursor(display, XC_crosshair);

  XGrabPointer(
    display, root, False, ButtonPressMask, GrabModeAsync, GrabModeAsync, None,
    crosshair, CurrentTime
  );

  while (1) {
    XNextEvent(display, &ev);

    if (ev.type == ButtonPress) {
      x = ev.xbutton.x;
      y = ev.xbutton.y;
      break;
    }
  }

  image = XGetImage(display, root, x, y, 1, 1, AllPlanes, ZPixmap);

  printf("#%06X\n", XGetPixel(image, 0, 0));

  XDestroyImage(image);
  XUngrabPointer(display, CurrentTime);
  XFreeCursor(display, crosshair);
  XCloseDisplay(display);
  return 0;
}
