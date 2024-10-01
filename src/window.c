#include "window.h"

#include <adwaita.h>

#include <glib/gi18n.h>
#include <locale.h>

#include "application.h"
#include "config.h"

/**
 * This class handles all window logic.
 */
typedef struct _CaffeineWindow {
    AdwApplicationWindow parent;
} CaffeineWindow;

G_DEFINE_TYPE(CaffeineWindow, caffeine_window, ADW_TYPE_APPLICATION_WINDOW)
/**
 * This function initializes a CaffeineWindow object.
 *
 * @param window CaffeineWindow to be initialized
 */
static void caffeine_window_init(CaffeineWindow *window)
{
    gtk_widget_init_template(GTK_WIDGET(window));
}

/**
 * This function initializes the CaffeineWindow class.
 *
 * @param class CaffeineWindowClass to be initialized
 */
static void caffeine_window_class_init(CaffeineWindowClass *class)
{
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
                                                UI_RESOURCE("window.ui"));
}

/**
 * This function creates a new CaffeineWindow object.
 *
 * @param app CaffeineApplication to create the new CaffeineWindow for
 *
 * @return CaffeineWindow
 */
CaffeineWindow *caffeine_window_new(CaffeineWindow *app)
{
    return g_object_new(CAFFEINE_TYPE_WINDOW, "application", app, NULL);
}

/**
 * This function opens a CaffeineWindow window.
 *
 * @param window Window to be opened
 * @param file File to be processed with the window
 */

void caffeine_window_open(CaffeineWindow *window, GFile *file)
{
}
