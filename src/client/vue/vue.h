/**
 *   Notes :
 *      Fichier Header, description des fonctions de graphismes
 *
 *      propri�t� de Lo�c Dalloz, Alexandre Brand, Jean-Charles Blind, Arthur Declerq et Romain Brewee
 *
 *   Last build 9/3/12
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <gtk/gtk.h>

#ifndef VUE_H
#define VUE_H

/// STRUCTURES
typedef struct tt
{
    GtkWidget *vbox;
    GtkWidget *table;
    GtkWidget **label;
    GtkWidget *bout;
    int number_data;
}lilclient_spec;

typedef struct t
{
    // Donn�es graphiques
    GtkWidget * win;
    GtkWidget *vbox;
    GtkWidget *table;
    GtkWidget *vpan;

    // Donn�es sp�cifiques - solaire (stirling + photovolta�que)
    lilclient_spec * sol;
    // Donn�es sp�cifiques - houlometrique
    lilcient_spec *houl;
    // Donn�es sp�cifiques - eolien
    lilclient_spec *eol;
}lilclient_view;

/// Prototypes

/// Creation et gestion de fenetres
lilclient_view *client_vue_create_main_win();
int client_destroy_main_win();
void client_modify_main_win(int type, lilclient_view *pe);

#endif


