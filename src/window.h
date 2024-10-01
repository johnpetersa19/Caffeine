#ifndef WINDOW_H
#define WINDOW_H

#include <adwaita.h>

#define CAFFEINE_TYPE_WINDOW (caffeine_window_get_type())

G_DECLARE_FINAL_TYPE(CaffeineWindow, caffeine_window, CAFFEINE, WINDOW,
                     AdwApplicationWindow)
CaffeineWindow *caffeine_window_new(CaffeineWindow *app);
void caffeine_window_open(CaffeineWindow *window, GFile *file);

#endif                          // WINDOW_H
