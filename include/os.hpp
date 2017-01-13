#ifndef MINESWEEPER_OS_HPP_INCLUDED
#define MINESWEEPER_OS_HPP_INCLUDED

#include "def.hpp"

namespace os
{
#if defined(_WIN32)
    #include <windows.h>

    FUNCTION_NO_DUPLICATES void error(const char* const message)
    {
        MessageBox(nullptr, message, "Error", MB_ICONERROR | MB_TASKMODAL | MB_OK | MB_SETFOREGROUND);
    }

#elif defined(__linux) && !defined(__ANDROID__)
    #include <gtk/gtk.h>

    FUNCTION_NO_DUPLICATES void error(const char* const message)
    {
        if(!gtk_init_check(0, NULL))
            return Selection::None;

        GtkWidget* dialog = gtk_message_dialog_new(NULL,
                                                   GTK_DIALOG_MODAL,
                                                   GTK_MESSAGE_ERROR,
                                                   GTK_BUTTONS_OK,
                                                   "%s",
                                                   message);
        gtk_window_set_title(GTK_WINDOW(dialog), "Error");
        gtk_dialog_run(GTK_DIALOG(dialog));

        gtk_widget_destroy(GTK_WIDGET(dialog));
        while(g_main_context_iteration(NULL, false));
    }

#elifdef defined(__APPLE__)
    #import <Cocoa/Cocoa.h>

    FUNCTION_NO_DUPLICATES void error(const char* const message)
    {
        NSAlert* alert = [[NSAlert alloc] init];

        [
            alert setMessageText:
            [
                NSString stringWithCString:"Error"
                encoding:[NSString defaultCStringEncoding]
            ]
        ];

        [
            alert setInformativeText:
            [
                NSString stringWithCString:message
                encoding:[NSString defaultCStringEncoding]
            ]
        ];

        [alert setAlertStyle:NSCriticalAlertStyle];
        [alert addButtonWithTitle:@"OK"];

        [alert runModal];
        [alert release];
    }

#else
    #error Unknown OS
#endif
}

#endif
