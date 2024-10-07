#include "application.h"

#include <adwaita.h>
#include <glib/gi18n.h>
#include <locale.h>
#include "window.h"
#include "config.h"

/**
 * An object of this class handles the functionality of an application.
 */
struct _CaffeineApplication {
    AdwApplication parent;
};

G_DEFINE_TYPE(CaffeineApplication, caffeine_application, ADW_TYPE_APPLICATION);

/**
 * This function initializes a CaffeineApplication object.
 *
 * @param app Application to be initialized
 */
static void caffeine_application_init(CaffeineApplication *app)
{
    // Register resources
    GResource *resource = g_resource_load(GRESOURCE_FILE, NULL);
    g_resources_register(resource);
}

/**
 * This function activates a GApplication object.
 *
 * @param app Application to be activated
 */
static void caffeine_application_activate(GApplication *app)
{
    CaffeineWindow *window;

    window = caffeine_window_new(CAFFEINE_APPLICATION(app));
    gtk_window_present(GTK_WINDOW(window));
}

/**
 * This function opens a new application object.
 *
 * @param app https://docs.gtk.org/gio/signal.Application.open.html
 * @param files https://docs.gtk.org/gio/signal.Application.open.html
 * @param n_files https://docs.gtk.org/gio/signal.Application.open.html
 * @param hint https://docs.gtk.org/gio/signal.Application.open.html
 */
static void caffeine_application_open(GApplication *app, GFile **files,
                                      int n_files, const char *hint)
{
    GList *windows;
    CaffeineWindow *window;

    windows = gtk_application_get_windows(GTK_APPLICATION(app));
    if (!windows)
        window = caffeine_window_new(CAFFEINE_APPLICATION(app));
    window = CAFFEINE_WINDOW(windows->data);

    gtk_window_present(GTK_WINDOW(window));
}

/**
 * This function initializes a CaffeineApplication class.
 *
 * @param class Application class to be initialized
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

/**
 * This function shows the about dialog of an application.
 *
 * @param self https://docs.gtk.org/gtk4/signal.Button.clicked.html
 * @param window https://docs.gtk.org/gtk4/signal.Button.clicked.html
 */
void caffeine_application_show_about(GtkButton *self, GtkWindow *window)
{
    AdwAboutDialog *about = ADW_ABOUT_DIALOG(adw_about_dialog_new_from_appdata
                                             (ROOT_RESOURCE
                                              (_PROJECT_ID(".metainfo.xml")),
                                              "1.0.0"));

    // Show version suffix
    adw_about_dialog_set_version(about, PROJECT_VERSION);

    // Details
    adw_about_dialog_set_comments(about, _("Calculate your coffee"));

    // Credits
    const char *developers[] =
        { "Konstantin Tutsch <mail@konstantintutsch.com>", NULL };
    adw_about_dialog_set_developers(about, developers);
    const char *designers[] =
        { "GNOME Design Team https://welcome.gnome.org/team/design/",
        "Konstantin Tutsch <mail@konstantintutsch.com>", NULL
    };
    adw_about_dialog_set_designers(about, designers);
    adw_about_dialog_set_translator_credits(about, _("translator-credits"));
    const char *libraries[] =
        { "The GNOME Project https://www.gnome.org", NULL };
    adw_about_dialog_add_acknowledgement_section(about, _("Dependencies"),
                                                 libraries);

    // Legal
    adw_about_dialog_set_copyright(about, "© 2024 Konstantin Tutsch");

    adw_dialog_present(ADW_DIALOG(about), GTK_WIDGET(window));
}
