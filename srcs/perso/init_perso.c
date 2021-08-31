#include "jdr.h"

/*
// initialisation du personnage
*/

void    free_skill(t_skill *skill)
{
    if (skill->power1)
        free(skill->power1);
    if (skill->power2)
        free(skill->power2);
    if (skill->power3)
        free(skill->power3);
    if (skill->power4)
        free(skill->power4);
    if (skill->power5)
        free(skill->power5);
    if (skill->power6)
        free(skill->power6);
    if (skill->power7)
        free(skill->power7);
    if (skill->power8)
        free(skill->power8);
    if (skill->power9)
        free(skill->power9);
}

t_skill copy_skill(t_skill *old)
{
    t_skill new;

    // caracteristique
    new.carrure = old->carrure;
    new.charisme = old->charisme;
    new.coordination = old->coordination;
    new.education = old->education;
    new.perception = old->perception;
    new.reflexe = old->reflexe;
    new.sang_froid = old->sang_froid;
    // Pilote
    new.vehicule_terrestre = old->vehicule_terrestre;
    new.pilotage_Leger = old->pilotage_Leger;
    new.pilotage_combat = old->pilotage_combat;
    new.pilotage_Leger = old->pilotage_Lourd;
    new.tourelle = old->tourelle;
    // explo
    new.discretion = old->discretion;
    new.fouille = old->fouille;
    new.informatique = old->informatique;
    new.piratage = old->piratage;
    new.decryptage = old->decryptage;
    new.premier_secour = old->premier_secour;
    // phyisque 
    new.athle = old->athle;
    new.acrobatie = old->acrobatie;
    new.escalade = old->escalade;
    new.endurence = old->endurence;
    // com
    new.eloquence = old->eloquence;
    new.intimidation = old->intimidation;
    new.bluff = old->bluff;
    new.psyco = old->psyco;
    // craft
    new.brico = old->brico;
    new.metal = old->metal;
    new.reparation = old->reparation;
    new.cuisine = old->cuisine;
    new.survie = old->cuisine;
    // Arme
    new.epaule = old->epaule;
    new.pompe = old->pompe;
    new.sniper = old->sniper;
    new.poing = old->poing;
    new.contact = old->contact;
    new.lourde = old->lourde;
    new.CAC = old->CAC;
    new.lancer = old->lancer;
    new.explosif = old->explosif;
    new.exp = old->exp;
    // Pouvoir
    new.pouvoir1 = old->pouvoir1;
    new.pouvoir2 = old->pouvoir2; 
    new.pouvoir3 = old->pouvoir3; 
    new.pouvoir4 = old->pouvoir4; 
    new.pouvoir5 = old->pouvoir5; 
    new.pouvoir6 = old->pouvoir6; 
    new.pouvoir7 = old->pouvoir7; 
    new.pouvoir8 = old->pouvoir8; 
    new.pouvoir9 = old->pouvoir9;  
    
    new.power1 = ft_strdup(old->power1);
    new.power2 = ft_strdup(old->power2);
    new.power3 = ft_strdup(old->power3);
    new.power4 = ft_strdup(old->power4);
    new.power5 = ft_strdup(old->power5);
    new.power6 = ft_strdup(old->power6);
    new.power7 = ft_strdup(old->power7);
    new.power8 = ft_strdup(old->power8);
    new.power9 = ft_strdup(old->power9);
    return new;
}

int init_perso(t_perso *perso)
{
    int     fd;
    char*   line;

    if ((fd = open(PERSO_PATH, O_RDONLY)) < 0)
        return exit_char("cannot open perso_skill", -1);
    int     i = 1;

    perso->levelup = LEVELUP;
    
    while ((gnl(fd, &line) > 0))
    {
        // ft_putendl(line);

        if (i == 2)
            perso->name = strdup(line);    
        if(i == 5)
            perso->skill.carrure = ft_atoi(line);
        if(i == 6)
            perso->skill.charisme = ft_atoi(line);    
        if(i == 7)
            perso->skill.coordination = ft_atoi(line); 
        if(i == 8)
            perso->skill.education = ft_atoi(line);
        if(i == 9)
            perso->skill.perception = ft_atoi(line);
        if(i == 10)
            perso->skill.reflexe = ft_atoi(line);
        if(i == 11)
            perso->skill.sang_froid = ft_atoi(line);
        if(i == 12)
            perso->skill.vehicule_terrestre = ft_atoi(line);
        if(i == 13)
            perso->skill.pilotage_Leger = ft_atoi(line);
        if(i == 14)
            perso->skill.pilotage_combat = ft_atoi(line);
        if(i == 15)
            perso->skill.pilotage_Lourd = ft_atoi(line);
        if(i == 16)
            perso->skill.tourelle = ft_atoi(line);
        if(i == 17)
            perso->skill.discretion = ft_atoi(line);
        if(i == 18)
            perso->skill.fouille = ft_atoi(line);
        if(i == 19)
            perso->skill.informatique = ft_atoi(line);
        if(i == 20)
            perso->skill.piratage = ft_atoi(line);
        if(i == 21)
            perso->skill.decryptage = ft_atoi(line);
        if(i == 22)
            perso->skill.premier_secour = ft_atoi(line);
        if(i == 23)
            perso->skill.athle = ft_atoi(line);
        if(i == 24)
            perso->skill.acrobatie = ft_atoi(line);
        if(i == 25)
            perso->skill.escalade = ft_atoi(line);
        if(i == 26)
            perso->skill.endurence = ft_atoi(line);
        if(i == 27)
            perso->skill.eloquence = ft_atoi(line);
        if(i == 28)
            perso->skill.intimidation = ft_atoi(line);
        if(i == 29)
            perso->skill.bluff = ft_atoi(line);
        if(i == 30)
            perso->skill.psyco = ft_atoi(line);
        if(i == 31)
            perso->skill.brico = ft_atoi(line);
        if(i == 32)
            perso->skill.metal = ft_atoi(line);
        if(i == 33)
            perso->skill.reparation = ft_atoi(line);
        if(i == 34)
            perso->skill.cuisine = ft_atoi(line);
        if(i == 35)
            perso->skill.survie = ft_atoi(line);
        if(i == 36)
            perso->skill.epaule = ft_atoi(line);
        if(i == 37)
            perso->skill.pompe = ft_atoi(line);
        if(i == 38)
            perso->skill.sniper = ft_atoi(line);
        if(i == 39)
            perso->skill.poing = ft_atoi(line);
        if(i == 40)
            perso->skill.contact = ft_atoi(line);
        if(i == 41)
            perso->skill.lourde = ft_atoi(line);
        if(i == 42)
            perso->skill.CAC = ft_atoi(line);
        if(i == 43)
            perso->skill.lancer = ft_atoi(line);
        if(i == 44)
            perso->skill.explosif = ft_atoi(line);
        if(i == 45)
            perso->skill.pouvoir1 = ft_atoi(line); 
        if(i == 46)
            perso->skill.pouvoir2 = ft_atoi(line);
        if(i == 47)
            perso->skill.pouvoir3 = ft_atoi(line);
        if(i == 48)
            perso->skill.pouvoir4 = ft_atoi(line);
        if(i == 49)
            perso->skill.pouvoir5 = ft_atoi(line);
        if(i == 50)
            perso->skill.pouvoir6 = ft_atoi(line);
        if(i == 51)
            perso->skill.pouvoir7 = ft_atoi(line);
        if(i == 52)
            perso->skill.pouvoir8 = ft_atoi(line);
        if(i == 53)
            perso->skill.pouvoir9 = ft_atoi(line);
        if(i == 55)
            perso->skill.exp = ft_atoi(line);
        if(i == 60)
            perso->skill.power1 = strdup(line);
        if(i == 61)
            perso->skill.power2 = strdup(line);
        if(i == 62)
            perso->skill.power3 = strdup(line);
        if(i == 63)
            perso->skill.power4 = strdup(line);
        if(i == 64)
            perso->skill.power5 = strdup(line);
        if(i == 65)
            perso->skill.power6 = strdup(line);
        if(i == 66)
            perso->skill.power7 = strdup(line);
        if(i == 67)
            perso->skill.power8 = strdup(line);
        if(i == 68)
            perso->skill.power9 = strdup(line);
        i++;
    }
    //  test print_perso
    // ft_putstr("carrure init : ");
    // ft_putstr(ft_atoi(perso->skill.carrure));
    // perso->skill.carrure = 9;
    close(fd);
    // print_perso(perso);
    return 0;
}

void destroy_perso(t_perso *perso)
{
    free(perso->name);
    free(perso->skill.power1);
    free(perso->skill.power2);
    free(perso->skill.power3);
    free(perso->skill.power4);
    free(perso->skill.power5);
    free(perso->skill.power6);
    free(perso->skill.power7);
    free(perso->skill.power8);
    free(perso->skill.power9);
}