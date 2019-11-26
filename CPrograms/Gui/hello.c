#include <gtk/gtk.h>

print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

 
int main (int argc, char **argv)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;

  gtk_init (&argc, &argv);
  GtkWidget *w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (w), "Hello World!");
  gtk_window_set_default_size (GTK_WINDOW (w), 600, 600);
  
  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (button_box), button);
//  gtk_widget_show_all (window);
	
  g_signal_connect (w, "destroy", G_CALLBACK (gtk_main_quit), NULL);
  gtk_widget_show (w);
  gtk_main ();
 
  return 0;
}
