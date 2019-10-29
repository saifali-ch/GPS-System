#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define pause system("pause")
#define clear system("cls")
#include "addLocationToFile.h"
#include "viewAllLocations.h"
#include "googleMapLocation.h"
#include "locationEditor.h"

// "A Project To Add Locations To A File, View Them From File, Edit Them and Display A Particular Location On Google Maps"

int main(void)
{
    FILE *exist;
    if((exist = fopen("locations.txt","r")))
    {
        fclose(exist);
    }
    else
    {
        exist = fopen("locations.txt","w");
        char put[]={""};
        fputs(put,exist);
        fclose(exist);
    }
    gpsSystemCore();
}

///////////////////////////Main Menu//////////////////////////////////
void gpsSystemCore(void)
{
    printf("                <<==============Welcome To GPS System==============>>\n");
    printf("                <<=================================================>>\n");
    printf("                |Project Name : GPS System v1.0.0                   |\n");
    printf("                |Developed By : Saif Ali                            |\n");
    printf("                |Reg #        : SP19-BSE-036                        |\n");
    printf("                |Version      : 1.0.0                               |\n");
    printf("                <<=================================================>>\n\n");
    printf("v1.0 GPS System                       Main Menu  \n");
    printf("<==========><==========><==========><==========><==========><==========><==========>\n");
    printf("1) Add A New Location\n");
    printf("2) View All Locations\n");
    printf("3) View Specific Location On Google Maps Using Location ID Or Title\n");
    printf("4) Edit Specific Location Using Location ID\n");
    printf("0) Quit The Program\n\n");

    int main_menu_choice;
    printf("Enter Your Choice : ");
    scanf("%d", &main_menu_choice);
    switch(main_menu_choice)
    {
    case 1:
        clear;
        addLocationToFile();
        break;
    case 2:
        clear;
        viewAllLocations();
        break;
    case 3:
        clear;
        googleMapLocation();
        break;
    case 4:
        clear;
        locationEditor();
        break;
    case 0:
        printf("Quiting The Program...............\n");
        pause;
        break;
    default:
        printf("Invalid Choice! Quiting The Program...............\n");
        pause;
        break;
    }
}
