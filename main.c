#include <gtk/gtk.h>

// signal handler for a button
static void
click_cb (GtkButton *btn, GtkWindow *win) {
    g_print ("Clicked.\n");

    gtk_window_destroy (win);
}

// signal handler of the window
static void app_activate (GApplication *app, gpointer user_data) {
    // creates the window
    GtkWidget *win;
    // creates a new widget
    GtkWidget *lab;
    // creates a new button
    GtkWidget *btn;

    // defines the window for the application
    win = gtk_application_window_new (GTK_APPLICATION (app));
    // sets the title of the application
    gtk_window_set_title (GTK_WINDOW (win), "GTK Test Application");
    // sets the size of the window
    gtk_window_set_default_size (GTK_WINDOW (win), 400, 300);

    // adds a text widget
    lab = gtk_label_new ("Hello.");
    gtk_window_set_child (GTK_WINDOW (win), lab);

    // adds a new button
    btn = gtk_button_new_with_label ("Close");
    gtk_window_set_child (GTK_WINDOW (win), btn);
    g_signal_connect (btn, "clicked", G_CALLBACK (click_cb), win);  // win is passed to the handler

    // shows the window (top-level-widget default visibility is off (widgets usually have it on))
    gtk_window_present (GTK_WINDOW (win));
}

void
activate (
        GApplication* self,
        gpointer user_data
);

int
main (int argc, char **argv) {
    //pointer to the widget that is in the application window
    GtkApplication *app;
    //used for storing the application with its data
    int stat;

    //creating the app
    app = gtk_application_new ("com.github.ToshioCP.pr2", G_APPLICATION_DEFAULT_FLAGS);
    //connecting the signal to the app (instance to which the signal belongs ,"name of the signal", G_CALLBACK(function that provides the signal handler), Data to pass to the handler (NULL if no data is passed))
    g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
    // g_application_run runs the application
    stat =g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return stat;
}