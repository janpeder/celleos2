#include <gtk/gtk.h>
#include <glib/gstdio.h>

char *get_product_name_factory(GtkListItem *item){
  gpointer obj = gtk_list_item_get_item(item);
  if (!GTK_IS_STRING_LIST(obj)) {
    //g_warning("get_product_name_factory: Element is not a GtkStringList");
    return g_strdup("Unknown");
  }
  GtkStringList *sl = GTK_STRING_LIST(obj);
  return g_strdup(gtk_string_list_get_string(sl, 0));
}

char *get_serial_factory(GtkListItem *item){
  gpointer obj = gtk_list_item_get_item(item);
  if (!GTK_IS_STRING_LIST(obj)) {
    //g_warning("get_serial_factory: Element is not a GtkStringList");
    return g_strdup("Unknown");
  }
  GtkStringList *sl = GTK_STRING_LIST(obj);
  return g_strdup(gtk_string_list_get_string(sl, 1));
}


static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void
quit_cb (GtkWindow *window)
{
  gtk_window_close (window);
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  /* Construct a GtkBuilder instance and load our UI description */
  GtkBuilder *builder = gtk_builder_new_from_resource ("/com/github/janpeder/tilkoblingssperre/resources/tilkoblingssperre.ui");
  //gtk_builder_add_from_file (builder, "tilkoblingssperre.ui", NULL);
  //  gtk_builder_new_from_resource(builder, , NULL)
  
  /* Connect signal handlers to the constructed widgets. */
  GObject *window = gtk_builder_get_object (builder, "window");
  gtk_window_set_application (GTK_WINDOW (window), app);

  GObject *button = gtk_builder_get_object (builder, "button1");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "button2");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "quit");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (quit_cb), window);

  gtk_widget_set_visible (GTK_WIDGET (window), TRUE);

  GListStore *liststore1 = G_LIST_STORE(gtk_builder_get_object (builder, "liststore1"));
  // Får vi nå utfordringer med at liststore1 ikke har satt typen på elementene?
  GtkStringList *enhet1 = gtk_string_list_new(NULL);
  gtk_string_list_append(enhet1, "ting1");
  gtk_string_list_append(enhet1, "45623189");
  g_list_store_append(liststore1, enhet1);
  GtkStringList *enhet2 = gtk_string_list_new(NULL);
  gtk_string_list_append(enhet2, "ting12");
  gtk_string_list_append(enhet2, "321654");
  g_list_store_append(liststore1, enhet2);
  
  /* We do not need the builder any more */
  g_object_unref (builder);
}

int
main (int   argc,
      char *argv[])
{
#ifdef GTK_SRCDIR
  g_chdir (GTK_SRCDIR);
#endif

  GtkApplication *app = gtk_application_new ("com.github.janpeder.tilkoblingssperre", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  int status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
