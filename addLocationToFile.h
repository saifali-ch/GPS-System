
////////////////////////A Simple Structure///////////////////////////
struct location
{
    char id[10];
    char title[10];
    char latitude[10];
    char longitude[10];
};
//////////////////////////////////////////////////////////////////////

////////////////////////Adding Location Information In A File///////////////////////////////////

void addLocationToFile(void)
{
    struct location loc;
    printf("Enter The Location Id : ");
    scanf("%s", loc.id);
    printf("Enter The Location Title : ");
    scanf("%s", loc.title);
    printf("Enter The Location Latitude : ");
    scanf("%s", loc.latitude);
    printf("Enter The Location Longitude : ");
    scanf("%s", loc.longitude);
    FILE *fp;
    fp = fopen("locations.txt", "a");
    fprintf(fp, "%s %s %s %s\n", loc.id, loc.title, loc.latitude, loc.longitude);
    fclose(fp);
abc:
    clear;
    int location_menu_choice;
    printf("1) Add Another Location\n");
    printf("0) Go Back\n");
    printf("\nEnter Your Choice : ");
    scanf("%d", &location_menu_choice);
    switch(location_menu_choice)
    {
    case 1:
        clear;
        addLocationToFile();
        break;
    case 0:
        clear;
        gpsSystemCore();
        break;
    default:
        printf("Invalid Choice! Please Select Correct Option\n\n");
        pause;
        goto abc;
        break;
    }
}
