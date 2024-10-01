#include "application.h"

#include <adwaita.h>

#include <glib/gi18n.h>
#include <locale.h>

#include "window.h"
#include "config.h"

/**
 * This class handles all application logic.
 */
struct _CaffeineApplication {
    AdwApplication parent;
};

G_DEFINE_TYPE(CaffeineApplication, caffeine_application, ADW_TYPE_APPLICATION);

/**
 * This function shows the About Dialogue of an GApplication.
 *
 * @param action Action that was activated to call this function
 * @param parameter Parameters passed
 * @param user_data User data passed
 */
static void caffeine_application_show_about(GSimpleAction *action,
                                            GVariant *parameter,
                                            gpointer user_data)
{
    CaffeineApplication *app = CAFFEINE_APPLICATION(user_data);
    CaffeineWindow *window =
        CAFFEINE_WINDOW(gtk_application_get_active_window
                        (GTK_APPLICATION(app)));

    const char *developers[] = { "Konstantin Tutsch", NULL };
    const char *designers[] = { "Konstantin Tutsch", NULL };

    adw_show_about_dialog(GTK_WIDGET(window),
                          "application-name", _("Caffeine"),
                          "application-icon", PROJECT_ID,
                          "developer-name", developers[0],
                          "version", PROJECT_VERSION,
                          "copyright", "© 2024 Konstantin Tutsch",
                          "issue-url",
                          "https://github.com/konstantintutsch/Caffeine/issues",
                          "license-type", GTK_LICENSE_MIT_X11, "developers",
                          developers, "comments",
                          _("Manage your coffee"),
                          "website",
                          "https://github.com/konstantintutsch/Caffeine",
                          "designers", designers, "translator-credits",
                          _("translator-credits"), NULL);
}

/**
 * This function initializes a CaffeineApplication object.
 *
 * @param app CaffeineApplication to be initialized
 */
static void caffeine_application_init(CaffeineApplication *app)
{
    // Register resources
    GResource *resource = g_resource_load(GRESOURCE_FILE, NULL);
    g_resources_register(resource);

    // Add actions
    g_autoptr(GSimpleAction) about_action = g_simple_action_new("about", NULL);
    g_signal_connect(about_action, "activate",
                     G_CALLBACK(caffeine_application_show_about), app);
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(about_action));
}

/**
 * This function activates a GApplication object.
 *
 * @param app GApplication to be activated
 */
static void caffeine_application_activate(GApplication *app)
{
    CaffeineWindow *window;

    window = caffeine_window_new(CAFFEINE_WINDOW(app));
    gtk_window_present(GTK_WINDOW(window));
}

/**
 * This function opens a new instance of a GApplication object.
 *
 * @param app GApplication to be opened
 * @param files GFiles passed
 * @param n_files Number of GFiles passed
 * @param hint Hint how files from GFiles will be processed
 */
static void caffeine_application_open(GApplication *app, GFile **files,
                                      int n_files, const char *hint)
{
    GList *windows;
    CaffeineWindow *window;

    windows = gtk_application_get_windows(GTK_APPLICATION(app));
    if (!windows)
        window = caffeine_window_new(CAFFEINE_WINDOW(app));
    window = CAFFEINE_WINDOW(windows->data);

    for (int i = 0; i < n_files; i++)
        caffeine_window_open(window, files[i]);

    gtk_window_present(GTK_WINDOW(window));
}

/**
 * This function initializes a CaffeineApplication class.
 *
 * @param class CaffeineApplicationClass to be initialized
 */
static void caffeine_application_class_init(CaffeineApplicationClass *class)
{
    G_APPLICATION_CLASS(class)->activate = caffeine_application_activate;
    G_APPLICATION_CLASS(class)->open = caffeine_application_open;
}

/**
 * This function creates a new CaffeineApplication object.
 *
 * @return CaffeineApplication
 */
CaffeineApplication *caffeine_application_new()
{
    return g_object_new(CAFFEINE_TYPE_APPLICATION, "application-id", PROJECT_ID,
                        G_APPLICATION_DEFAULT_FLAGS, G_APPLICATION_HANDLES_OPEN,
                        NULL);
}
