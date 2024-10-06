#ifndef ENTRY_H
#define ENTRY_H

#include <adwaita.h>

#define CAFFEINE_TYPE_ENTRY (caffeine_entry_get_type())

G_DECLARE_FINAL_TYPE(CaffeineEntry, caffeine_entry, CAFFEINE, ENTRY,
                     AdwActionRow);

CaffeineEntry *caffeine_entry_new();

#endif // ENTRY_H
