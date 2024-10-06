#include "entry.h"

#include <adwaita.h>

#include <glib/gi18n.h>
#include <locale.h>

#include "ratio.h"

#include "config.h"

/**
 * An object of this class handles the functionality of an entry.
 */
struct _CaffeineEntry {
    AdwActionRow parent;
};

G_DEFINE_TYPE(CaffeineEntry, caffeine_entry, ADW_TYPE_ACTION_ROW);

static void caffeine_entry_update(CaffeineEntry * entry);

/**
 * This function initializes a CaffeineEntry object.
 *
 * @param entry Entry to be initialized
 */
static void caffeine_entry_init(CaffeineEntry *entry)
{
    gtk_widget_init_template(GTK_WIDGET(entry));

    caffeine_entry_update(entry);
}

/**
 * This function initializes the CaffeineEntry class.
 *
 * @param class Entry class to be initialized
 */
static void caffeine_entry_class_init(CaffeineEntryClass *class)
{
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
                                                UI_RESOURCE("entry.ui"));
}

/**
 * This function creates a new CaffeineEntry object.
 *
 * @return CaffeineEntry
 */
CaffeineEntry *caffeine_entry_new()
{
    return g_object_new(CAFFEINE_TYPE_ENTRY, NULL);
}

/**
 * This function updates data of a CaffeineEntry.
 *
 * @param entry Entry to update the data of
 */
static void caffeine_entry_update(CaffeineEntry *entry)
{
}
