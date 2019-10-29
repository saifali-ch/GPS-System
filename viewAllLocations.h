
////////////////////////////////View All Locations From File////////////////////////////////////

int gobackdisplay=0;
void viewAllLocations(void)
{
    FILE *fp;
    int all_location_menu_choice;
    char ch;
    fp = fopen("locations.txt", "r");
    ch = fgetc(fp);
    while(ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);

    if(gobackdisplay==0)
    {
        printf("\n\n0) Go Back\n");
        gobackdisplay++;
    }
    else
    {
        printf("\n0) Go Back\n");
    }
    printf("\nEnter Your Choice : ");
    scanf("%d", &all_location_menu_choice);
    if(all_location_menu_choice == 0)
    {
        clear;
        gpsSystemCore();
    }
    else
    {
        printf("Invalid Choice! Please Select Correct Option\n");
        pause;
        clear;
        viewAllLocations();
    }
}
