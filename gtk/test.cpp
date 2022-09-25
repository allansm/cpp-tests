#include <gtk/gtk.h>

int main(int argc, char ** argv){
	GtkWidget* window;
	GtkWidget* label;
	GtkWidget* entry;
	GtkWidget* button;
	
	GtkWidget* fixed;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	gtk_window_set_title(GTK_WINDOW(window), "some title");
	gtk_window_set_default_size(GTK_WINDOW(window), 185, 80);
	gtk_container_set_border_width(GTK_CONTAINER(window), 15);
	
	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);
	
	label = gtk_label_new_with_mnemonic("_Name:");
	entry = gtk_entry_new();
	button = gtk_button_new_with_mnemonic("_show");

	g_signal_connect(button, "clicked", G_CALLBACK(+[](GtkWidget *widget, gpointer ptr){
		GtkEntry* entry = (GtkEntry*)ptr;
		
		g_print(gtk_entry_get_text(entry));
		g_print("\n");
		
		gtk_entry_set_text(entry, "");
	}), entry);

	gtk_fixed_put(GTK_FIXED(fixed), label, 10, 0);
	gtk_fixed_put(GTK_FIXED(fixed), entry, 10, 25);
	gtk_fixed_put(GTK_FIXED(fixed), button, 115, 75);
	
	gtk_widget_show_all(window);

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL); 

	gtk_main();

	return 0;
}
