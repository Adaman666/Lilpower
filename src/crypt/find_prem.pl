#!/usr/bin/perl -w
#######################################################################
##
##	Script de recherche de nombres premier sur un interval donné et d'écriture de ces dernier
##	dans le fichier demandé du projet Lilpower.
##
##	Propriété de Loïc Dalloz, Alexandre Brand, Jean-Charles Blind, Arthur declerq et Romain Brewee
##
#######################################################################

use strict;

#ressources
my $file;
my $i;
my $k;
my $min;
my $max;
my $percent;
my $temp;

#message de bienvenue
print "\n\n\tBienvenue dans l'asistant de recherche de nombres premiers.\nCet outil crée un fichier contenant tous les nombres premiers entre les bornes donné par l'utilisateur.\n\n";

#saisie des variables
print "Choisissez le nom de fichier (ATTENTION : si le fichier est existant, il sera détruit) : \n>>> ";
$file = <stdin>;
chomp $file;
open (WRITE, "> ".$file) or die "impossible d'ouvrir le fichier.\n";
print "\n ouverture réussie.\n\n";
print "Saisissez la valeur de départ : \n>>> ";
$min = <stdin>;
chomp $min;
print "\nSaisissez la valeur de fin : \n>>> ";
$max = <stdin>;
chomp $max;
print "\n\n\nDébut des calculs :\n";

#calcul des nombres premiers :
$percent = 0;
for($i=$min; $i<=$max; $i++)
{
	$temp = 0;
	for($k=1; $k<=$i; $k++){if($i%$k == 0){$temp++;}}
	#si nous sommes en présence d'un nombre premier :
	if($temp == 2){print WRITE $i."\n";}
		
	#affichage du pourcentage :
	if(int((($i-$min)*100)/($max-$min)) != $percent){
		$percent = int((($i-$min)*100)/($max-$min));
		print $percent."%\n";}
	
}
print "Done.\n\n";

#fermeture du fichier
close WRITE;