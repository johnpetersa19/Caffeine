#ifndef APPLICATION_H
#define APPLICATION_H

#include <adwaita.h>

#define CAFFEINE_TYPE_APPLICATION (caffeine_application_get_type())

G_DECLARE_FINAL_TYPE(CaffeineApplication, caffeine_application, CAFFEINE,
                     APPLICATION, AdwApplication);

CaffeineApplication *caffeine_application_new(void);

void caffeine_application_show_about(GtkButton * self, GtkWindow * window);

#endif                          // APPLICATION_H
