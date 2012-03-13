#include "..\vue\vue.h"

MainWin *client_vue_create_main_win()
{
    // Ressource
    MainWin *pe = malloc(sizeof(MainWin));

    // CRéation de la fenetre
    // Allocation des différents élements...
    pe->win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    pe->vbo = gtk_vbox_new(FALSE, 1);
    pe->vpan = gtk_vpaned_new(void);
    pe->b_envoyer = gtk_button_new_from_stock(GTK_STOCK_OK);
    pe->l_prod_max_poss = gtk_label_new("Production maximale :");
    pe->l_pourcent = gtk_label_new ("Pourcentage utile :");
    pe->l_prod_atten = gtk_label_new ("Production attendu :");
    pe->l_entete = gtk_label_new ("Entete...");


    // Partie LEGO (c) ...
    // Panneau droit...
    gtk_paned_add2(pe->vpan,pe->l_prod_max_poss);
    gtk_paned_add2(pe->vpan,pe->l_prod_atten);
    gtk_paned_add2(pe->vpan,pe->l_prod_pourcent);

    // Panneau gauche...
    gtk_paned_add1(pe->vpan,pe->b_envoyer);

    //Ajout dans la box...
    gtk_container_add(pe->vbo,pe->vpan);
    gtk_container_add(pe->vbo, pe->l_entete);

    // AJout dans la fenetre
    gtk_container_add(pe->win,pe->vbo);
    return(pe);
}
