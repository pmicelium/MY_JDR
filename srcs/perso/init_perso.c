#include "jdr.h"

/*
// initialisation du personnage
*/

int init_perso(t_perso *perso)
{
    int     fd;
    char*   line;

    if ((fd = open(PERSO_PATH, O_RDONLY)) < 0)
        return exit_char("cannot open perso_skill", -1);
    int     i = 1;

    while ((gnl(fd, &line) > 0))
    {
        ft_putendl(line);

        if (i == 2)
            perso->name = strdup(line);    
        if(i == 5)
            perso->skill.carrure = atoi(line);
        if(i == 6)
            perso->skill.charisme = atoi(line);    
        if(i == 7)
            perso->skill.coordination = atoi(line); 
        if(i == 8)
            perso->skill.education = atoi(line);
        if(i == 9)
            perso->skill.perception = atoi(line);
        if(i == 10)
            perso->skill.reflexe = atoi(line);
        if(i == 11)
            perso->skill.sang_froid = atoi(line);
        if(i == 12)
            perso->skill.vehicule_terrestre = atoi(line);
        if(i == 13)
            perso->skill.pilotage_Leger = atoi(line);
        if(i == 14)
            perso->skill.pilotage_combat = atoi(line);
        if(i == 15)
            perso->skill.pilotage_Lourd = atoi(line);
        if(i == 16)
            perso->skill.tourelle = atoi(line);
        if(i == 17)
            perso->skill.discretion = atoi(line);
        if(i == 18)
            perso->skill.fouille = atoi(line);
        if(i == 19)
            perso->skill.informatique = atoi(line);
        if(i == 20)
            perso->skill.piratage = atoi(line);
        if(i == 21)
            perso->skill.decryptage = atoi(line);
        if(i == 22)
            perso->skill.premier_secour = atoi(line);
        if(i == 23)
            perso->skill.athle = atoi(line);
        if(i == 24)
            perso->skill.acrobatie = atoi(line);
        if(i == 25)
            perso->skill.escalade = atoi(line);
        if(i == 26)
            perso->skill.endurence = atoi(line);
        if(i == 27)
            perso->skill.eloquence = atoi(line);
        if(i == 28)
            perso->skill.intimidation = atoi(line);
        if(i == 29)
            perso->skill.bluff = atoi(line);
        if(i == 30)
            perso->skill.psyco = atoi(line);
        if(i == 31)
            perso->skill.brico = atoi(line);
        if(i == 32)
            perso->skill.metal = atoi(line);
        if(i == 33)
            perso->skill.reparation = atoi(line);
        if(i == 34)
            perso->skill.cuisine = atoi(line);
        if(i == 35)
            perso->skill.survie = atoi(line);
        if(i == 36)
            perso->skill.epaule = atoi(line);
        if(i == 37)
            perso->skill.pompe = atoi(line);
        if(i == 38)
            perso->skill.sniper = atoi(line);
        if(i == 39)
            perso->skill.poing = atoi(line);
        if(i == 40)
            perso->skill.contact = atoi(line);
        if(i == 41)
            perso->skill.lourde = atoi(line);
        if(i == 42)
            perso->skill.CAC = atoi(line);
        if(i == 43)
            perso->skill.lancer = atoi(line);
        if(i == 44)
            perso->skill.explosif = atoi(line);
        if(i == 45)
            perso->skill.pouvoir1 = atoi(line); 
        if(i == 46)
            perso->skill.pouvoir2 = atoi(line);
        if(i == 47)
            perso->skill.pouvoir3 = atoi(line);
        if(i == 48)
            perso->skill.pouvoir4 = atoi(line);
        if(i == 49)
            perso->skill.pouvoir5 = atoi(line);
        if(i == 50)
            perso->skill.pouvoir6 = atoi(line);
        if(i == 51)
            perso->skill.pouvoir7 = atoi(line);
        if(i == 52)
            perso->skill.pouvoir8 = atoi(line);
        if(i == 53)
            perso->skill.pouvoir9 = atoi(line);
        if(i == 55)
            perso->skill.exp = atoi(line);
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
           printf("honK 4\n");
     ft_putstr("exp init : ");
     ft_putnbr_endl(perso->skill.exp);
    perso->skill.carrure = 9;
    close(fd);
    print_perso(perso);
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