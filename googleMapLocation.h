
/////////////////////////////////Finding Location Using ID//////////////////////////////////////

void googleMapLocation(void)
{
    FILE *fp;
previous:
    clear;
    int IoT;
    printf("1) Using Location ID\n");
    printf("2) Using Location Title\n");
    printf("0) Go Back\n\n");
    printf("Enter Your Choice : ");
    scanf("%d",&IoT);
    char locationID[10];
    char searchTitle[10];
    switch(IoT)
    {
    case 1:
        clear;
        printf("Enter The Location ID : ");
        scanf("%s", locationID);
        break;
    case 2:
        clear;
        printf("Enter The Location Title : ");
        scanf("%s", searchTitle);
        break;
    case 0:
        clear;
        gpsSystemCore();
        break;
    default:
        printf("Invalid Choice! Please Select Correct Option\n");
        pause;
        googleMapLocation();
        break;
    }
    fp = fopen("locations.txt","r+");
    rewind(fp);
    int ok=0;
    char id[10], title[10], lati[10], longi[10];
    while(fscanf(fp, "%s %s %s %s", id, title, lati, longi) != EOF)
    {
        if(strcmp(locationID,id)==0||stricmp(searchTitle,title)==0)
        {
            ok=1;
            char url[80]="https://www.google.com/maps/search/?api=1&query=";
            strcat(url,lati);
            strcat(url,",");
            strcat(url,longi);
            ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
            break;
        }
    }
    fclose(fp);
    if(ok==0)
    {
        if(IoT==1)
        {
            printf("Invalid ID!");
            printf("\n");
            pause;
            goto previous;
        }
        else if(IoT==2)
        {
            printf("Title Not Found!");
            printf("\n");
            pause;
            goto previous;
        }
    }
    if(ok==1)
    {
top:
        clear;
        int search_again_choice;
        printf("1) Search Another Location\n");
        printf("0) Main Menu\n\n");
        printf("Enter Your Choice : ");
        scanf("%d", &search_again_choice);
        switch(search_again_choice)
        {
        case 1:
            googleMapLocation();
            break;
        case 0:
            clear;
            gpsSystemCore();
            break;
        default:
            printf("Invalid Choice! Please Select Correct Option\n");
            pause;
            goto top;
            break;
        }
    }
}
