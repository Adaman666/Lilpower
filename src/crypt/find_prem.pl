#!/usr/bin/perl -w
#######################################################################
##
##	Script de recherche de nombres premier sur un interval donn� et d'�criture de ces dernier
##	dans le fichier demand� du projet Lilpower.
##
##	Propri�t� de Lo�c Dalloz, Alexandre Brand, Jean-Charles Blind, Arthur declerq et Romain Brewee
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
print "\n\n\tBienvenue dans l'asistant de recherche de nombres premiers.\nCet outil cr�e un fichier contenant tous les nombres premiers entre les bornes donn� par l'utilisateur.\n\n";

#saisie des variables
print "Choisissez le nom de fichier (ATTENTION : si le fichier est existant, il sera d�truit) : \n>>> ";
$file = <stdin>;
chomp $file;
open (WRITE, "> ".$file) or die "impossible d'ouvrir le fichier.\n";
print "\n ouverture r�ussie.\n\n";
print "Saisissez la valeur de d�part : \n>>> ";
$min = <stdin>;
chomp $min;
print "\nSaisissez la valeur de fin : \n>>> ";
$max = <stdin>;
chomp $max;
print "\n\n\nD�but des calculs :\n";

#calcul des nombres premiers :
$percent = 0;
for($i=$min; $i<=$max; $i++)
{
	$temp = 0;
	for($k=1; $k<=$i; $k++){if($i%$k == 0){$temp++;}}
	#si nous sommes en pr�sence d'un nombre premier :
	if($temp == 2){print WRITE $i."\n";}
		
	#affichage du pourcentage :
	if(int((($i-$min)*100)/($max-$min)) != $percent){
		$percent = int((($i-$min)*100)/($max-$min));
		print $percent."%\n";}
	
}
print "Done.\n\n";

#fermeture du fichier
close WRITE;