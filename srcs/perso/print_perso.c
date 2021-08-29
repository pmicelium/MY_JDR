#include "jdr.h"

void print_perso(t_perso *perso)
{
    FILE *fd;
    fopen_s(&fd, PERSO_PATH, "w");

    fprintf(fd, "// Inserer le nom de votre personage //\n\
%s\n\
\n\
// inserer vos competences //\n\
carrure                 %d\n\
charisme                %d\n\
coordination            %d\n\
eduaction               %d\n\
perception              %d\n\
reflexe                 %d\n\
sang_froid              %d\n\
vehicule_terrestre      %d\n\
pilotage_Leger          %d\n\
pilotage_combat         %d\n\
pilotage_Lourd          %d\n\
tourelle                %d\n\
discretion              %d\n\
fouille                 %d\n\
informatique            %d\n\
piratage                %d\n\
decryptage              %d\n\
premier_secour          %d\n\
athle                   %d\n\
acrobatie               %d\n\
escalade                %d\n\
endurence               %d\n\
eloquence               %d\n\
intimidation            %d\n\
bluff                   %d\n\
psyco                   %d\n\
brico                   %d\n\
metal                   %d\n\
reparation              %d\n\
cuisine                 %d\n\
survie                  %d\n\
epaule                  %d\n\
pompe                   %d\n\
sniper                  %d\n\
poing                   %d\n\
contact                 %d\n\
lourde                  %d\n\
CAC                     %d\n\
lancer                  %d\n\
explosif                %d\n\
pouvoir un              %d\n\
pouvoir deux            %d\n\
pouvoir trois           %d\n\
pouvoir quatre          %d\n\
pouvoir cinq            %d\n\
pouvoir six             %d\n\
pouvoir sept            %d\n\
pouvoir huit            %d\n\
pouvoir neuf            %d\n\
\n\
Point d'experience      %d\n\
\n\
// inserer les noms de vos pouvoirs (si vide, laissez (vide)) //\n\
// les characteres unicode ne sont pas aceptes, donc eviter les accents. //\n\
// attention a bien respecter l'orde au dessus //\n\
%s\n\
%s\n\
%s\n\
%s\n\
%s\n\
%s\n\
%s\n\
%s\n\
%s\n\
// merci //", perso->name, perso->skill.carrure, perso->skill.charisme, \
perso->skill.coordination, perso->skill.education, perso->skill.perception, \
perso->skill.reflexe, perso->skill.sang_froid, perso->skill.vehicule_terrestre, \
perso->skill.pilotage_Leger, perso->skill.pilotage_combat, perso->skill.pilotage_Lourd, \
perso->skill.tourelle, perso->skill.discretion, perso->skill.fouille, perso->skill.informatique, \
perso->skill.piratage, perso->skill.decryptage, perso->skill.premier_secour, perso->skill.athle, \
perso->skill.acrobatie, perso->skill.escalade, perso->skill.endurence, perso->skill.eloquence, \
perso->skill.intimidation, perso->skill.bluff, perso->skill.psyco, perso->skill.brico, perso->skill.metal, \
perso->skill.reparation, perso->skill.cuisine, perso->skill.survie, perso->skill.epaule, \
perso->skill.pompe, perso->skill.sniper, perso->skill.poing, perso->skill.contact, perso->skill.lourde, \
perso->skill.CAC, perso->skill.lancer, perso->skill.explosif, perso->skill.pouvoir1, perso->skill.pouvoir2, \
perso->skill.pouvoir3, perso->skill.pouvoir4, perso->skill.pouvoir5, perso->skill.pouvoir6, \
perso->skill.pouvoir7, perso->skill.pouvoir8, perso->skill.pouvoir9, perso->skill.exp, \
perso->skill.power1, perso->skill.power2, perso->skill.power3, perso->skill.power4, perso->skill.power5, \
perso->skill.power6, perso->skill.power7, perso->skill.power8, perso->skill.power9);
fclose(fd);
return ;
}