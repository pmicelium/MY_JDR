#include "jdr.h"

static int event_levelup(t_perso *perso, int x, int y, bool cursor)
{
    // caract
    int y1 = 525;
    int y2 = 550;
    if (x > 470 && x < 495)
    {
        if ((perso->skill.exp >= perso->skill.carrure * 6) && (perso->skill.carrure < 6) && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= perso->skill.carrure * 6;
            perso->skill.carrure++;
        }
        y1 += 50;
        y2 += 50;
        if ((perso->skill.exp >= perso->skill.charisme * 6) && (perso->skill.charisme < 6) && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= perso->skill.charisme * 6;
            perso->skill.charisme++;
        }
        y1 += 50;
        y2 += 50;
        if ((perso->skill.exp >= perso->skill.coordination * 6) && (perso->skill.coordination < 6) && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= perso->skill.coordination * 6;
            perso->skill.coordination++;
        }
        y1 += 50;
        y2 += 50;
        if ((perso->skill.exp >= perso->skill.education * 6) && (perso->skill.education < 6) && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= perso->skill.education * 6;
            perso->skill.education++;
        }
        y1 += 50;
        y2 += 50;
        if ((perso->skill.exp >= perso->skill.perception * 6) && (perso->skill.perception < 6) && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= perso->skill.perception * 6;
            perso->skill.perception++;
        }
        y1 += 50;
        y2 += 50;
        if ((perso->skill.exp >= perso->skill.reflexe * 6) && (perso->skill.reflexe < 6) && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= perso->skill.reflexe * 6;
            perso->skill.reflexe++;
        }
        y1 += 50;
        y2 += 50;
        if ((perso->skill.exp >= perso->skill.sang_froid * 6) && (perso->skill.sang_froid < 6) && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= perso->skill.sang_froid * 6;
            perso->skill.sang_froid++;
        }
    }
    if (x > 1055 && x < 1080)
    {
        y1 = 85;
        y2 = 115;
        // Pilotage
        if ((perso->skill.exp >= (10 - perso->skill.vehicule_terrestre) * 2) && perso->skill.vehicule_terrestre > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.vehicule_terrestre) * 2;
            perso->skill.vehicule_terrestre--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.pilotage_Leger) * 2) && perso->skill.pilotage_Leger > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pilotage_Leger) * 2;
            perso->skill.pilotage_Leger--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.pilotage_combat) * 2) && perso->skill.pilotage_combat > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pilotage_combat) * 2;
            perso->skill.pilotage_combat--;
        }
        y1 += 40;
        y2 += 40;
        if (((perso->skill.exp >= (10 - perso->skill.pilotage_Lourd) * 2) &&
             (perso->skill.pilotage_Leger <= 6 || perso->skill.pilotage_Lourd < 9)) &&
            perso->skill.pilotage_Lourd > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pilotage_Lourd) * 2;
            perso->skill.pilotage_Lourd--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.tourelle) * 2) && perso->skill.tourelle > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.tourelle) * 2;
            perso->skill.tourelle--;
        }
        y1 = 335;
        y2 = 360;

        // physique
        if ((perso->skill.exp >= (10 - perso->skill.athle) * 2) && perso->skill.athle > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.athle) * 2;
            perso->skill.athle--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.acrobatie) * 2) && perso->skill.acrobatie > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.acrobatie) * 2;
            perso->skill.acrobatie--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.escalade) * 2) && perso->skill.escalade > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.escalade) * 2;
            perso->skill.escalade--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.endurence) * 2) && perso->skill.endurence > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.endurence) * 2;
            perso->skill.endurence--;
        }

        y1 = 545;
        y2 = 570;
        // groupe explo
        if ((perso->skill.exp >= (10 - perso->skill.discretion) * 2) && perso->skill.discretion > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.discretion) * 2;
            perso->skill.discretion--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.fouille) * 2) && perso->skill.fouille > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.fouille) * 2;
            perso->skill.fouille--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.informatique) * 2) && perso->skill.informatique > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.informatique) * 2;
            perso->skill.informatique--;
        }
        y1 += 40;
        y2 += 40;
        if (((perso->skill.exp >= (10 - perso->skill.piratage) * 2) && (perso->skill.informatique <= 6 || perso->skill.piratage < 9)) && perso->skill.piratage > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.piratage) * 2;
            perso->skill.piratage--;
        }
        y1 += 40;
        y2 += 40;
        if (((perso->skill.exp >= (10 - perso->skill.decryptage) * 2) && (perso->skill.informatique <= 6 || perso->skill.decryptage < 9)) && perso->skill.decryptage > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.decryptage) * 2;
            perso->skill.decryptage--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.premier_secour) * 2) && perso->skill.premier_secour > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.premier_secour) * 2;
            perso->skill.premier_secour--;
        }

        y1 = 835;
        y2 = 865;
        // groupe Crafting
        if ((perso->skill.exp >= (10 - perso->skill.brico) * 2) && perso->skill.brico > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.brico) * 2;
            perso->skill.brico--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.reparation) * 2) && perso->skill.reparation > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.reparation) * 2;
            perso->skill.reparation--;
        }
        y1 += 40;
        y2 += 40;
        if (((perso->skill.exp >= (10 - perso->skill.metal) * 2) && (perso->skill.brico <= 6 || perso->skill.metal < 9)) && y > y1 && y < y2 && perso->skill.metal > 2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.metal) * 2;
            perso->skill.metal--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.cuisine) * 2) && perso->skill.cuisine > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.cuisine) * 2;
            perso->skill.cuisine--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.survie) * 2) && perso->skill.survie > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.survie) * 2;
            perso->skill.survie--;
        }
    }

    if (x > 1580 && x < 1605)
    {
        y1 = 85;
        y2 = 115;
        // groupe Arme
        if ((perso->skill.exp >= (10 - perso->skill.poing) * 2) && perso->skill.poing > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.poing) * 2;
            perso->skill.poing--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.epaule) * 2) && perso->skill.epaule > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.epaule) * 2;
            perso->skill.epaule--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.pompe) * 2) && perso->skill.pompe > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pompe) * 2;
            perso->skill.pompe--;
        }
        y1 += 40;
        y2 += 40;
        if (((perso->skill.exp >= (10 - perso->skill.sniper) * 2) && (perso->skill.epaule <= 6 || perso->skill.sniper < 9)) && y > y1 && y < y2 && perso->skill.sniper > 2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.sniper) * 2;
            perso->skill.sniper--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.lourde) * 2) && perso->skill.lourde > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.lourde) * 2;
            perso->skill.lourde--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.explosif) * 2) && perso->skill.explosif > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.explosif) * 2;
            perso->skill.explosif--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.lancer) * 2) && perso->skill.lancer > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.lancer) * 2;
            perso->skill.lancer--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.CAC) * 2) && perso->skill.CAC > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.CAC) * 2;
            perso->skill.CAC--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.contact) * 2) && perso->skill.contact > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.contact) * 2;
            perso->skill.contact--;
        }

        //groupe pouvoir
        y1 = 490;
        y2 = 515;
        if ((perso->skill.pouvoir1 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir1) * 2)) && perso->skill.pouvoir1 > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pouvoir1) * 2;
            perso->skill.pouvoir1--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.pouvoir2 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir2) * 2)) && perso->skill.pouvoir2 > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pouvoir2) * 2;
            perso->skill.pouvoir2--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.pouvoir3 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir3) * 2)) && perso->skill.pouvoir3 > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pouvoir3) * 2;
            perso->skill.pouvoir3--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.pouvoir4 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir4) * 2)) && perso->skill.pouvoir4 > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pouvoir4) * 2;
            perso->skill.pouvoir4--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.pouvoir5 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir5) * 2)) && perso->skill.pouvoir5 > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pouvoir5) * 2;
            perso->skill.pouvoir5--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.pouvoir6 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir6) * 2)) && perso->skill.pouvoir6 > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pouvoir6) * 2;
            perso->skill.pouvoir6--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.pouvoir7 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir7) * 2)) && perso->skill.pouvoir7 > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pouvoir7) * 2;
            perso->skill.pouvoir7--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.pouvoir8 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir8) * 2)) && perso->skill.pouvoir8 > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pouvoir8) * 2;
            perso->skill.pouvoir8--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.pouvoir9 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir9) * 2)) && perso->skill.pouvoir9 > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.pouvoir9) * 2;
            perso->skill.pouvoir9--;
        }

        // groupe Comm
        y1 = 885;
        y2 = 915;
        if ((perso->skill.exp >= (10 - perso->skill.eloquence) * 2) && perso->skill.eloquence > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.eloquence) * 2;
            perso->skill.eloquence--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.intimidation) * 2) && perso->skill.intimidation > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.intimidation) * 2;
            perso->skill.intimidation--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.bluff) * 2) && perso->skill.bluff > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.bluff) * 2;
            perso->skill.bluff--;
        }
        y1 += 40;
        y2 += 40;
        if ((perso->skill.exp >= (10 - perso->skill.psyco) * 2) && perso->skill.psyco > 2 && y > y1 && y < y2)
        {
            if (cursor == true)
                return 1;
            perso->skill.exp -= (10 - perso->skill.psyco) * 2;
            perso->skill.psyco--;
        }
    }
    return 0;
}

void mouse_event_perso(t_perso *perso, int x, int y)
{
    if (x > 175 && x < 360 && y > 980 && y < 1005)
    {
        perso->levelup = LEVELUP_O;
    }
    if (perso->levelup == LEVELUP_O)
    {
        event_levelup(perso, x, y, false);
        if (x > 35 && x < 195 && y > 980 && y < 1005)
        {
            perso->levelup = LEVELUP;
            free_skill(&perso->skill);
            init_perso(perso);
        }
        if (x > 335 && x < 500 && y > 980 && y < 1005)
        {
            perso->levelup = LEVELUP;
            print_perso(perso);
        }
    }
}

int change_cursor_perso(t_perso *perso, int x, int y)
{
    if (perso->levelup == LEVELUP)
    {
        if (x > 175 && x < 360 && y > 980 && y < 1005)
            return 1;
    }
    if (perso->levelup == LEVELUP_O)
    {
        if (event_levelup(perso, x, y, true) == 1)
            return 1;
        if (x > 35 && x < 195 && y > 980 && y < 1005)
            return 1;
        if (x > 335 && x < 500 && y > 980 && y < 1005)
            return 1;
    }
    return 0;
}