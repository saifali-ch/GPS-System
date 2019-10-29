
///////////////////////////////////Location Editor///////////////////////////////////////

void locationEditor(void)
{
    char locationID[10];
    printf("Enter Location ID : ");
    scanf("%s", locationID);
    FILE *fp, *op;
    fp = fopen("locations.txt","r");
    char id_check[15], title_check[10], lati_check[10], longi_check[10];
    int ready=0;
    while(fscanf(fp, "%s %s %s %s", id_check, title_check, lati_check, longi_check) != EOF)
    {
        if(strcmp(locationID,id_check)==0)
        {
            ready=1;
            break;
        }
    }
    fclose(fp);
    if(ready==1)
    {
        op = fopen("cfg.txt","w");
        fp = fopen("locations.txt","r");
        char new_Lati[15],new_longi[15],new_line[75]="";
        char id[10], title[10], lati[10], longi[10];
        while(fscanf(fp, "%s %s %s %s", id, title, lati, longi) != EOF)
        {
            if(strcmp(locationID,id)==0)
            {
                printf("Enter New Latitude Value : ");
                scanf("%s",new_Lati);
                printf("Enter New Longitude Value: ");
                scanf("%s",new_longi);
                strcat(new_line,id);
                strcat(new_line," ");
                strcat(new_line,title);
                strcat(new_line," ");
                strcat(new_line,new_Lati);
                strcat(new_line," ");
                strcat(new_line,new_longi);
                break;
            }
            fprintf(op,"%s %s %s %s\n",id,title, lati, longi);
        }
        fprintf(op, "%s", new_line);
        fclose(fp);
        fclose(op);
        op = fopen("cfg.txt","a");
        fp = fopen("locations.txt","r");
        char post_id[10], post_title[10], post_lati[15], post_longi[15];
        int start=0;
        while(fscanf(fp, "%s %s %s %s", post_id, post_title, post_lati, post_longi) != EOF)
        {
            if(stricmp(locationID, post_id)==0)
            {
                start=1;
                continue;
            }
            if(start==1)
            {
                fprintf(op, "\n%s %s %s %s", post_id, post_title, post_lati, post_longi);
            }
        }
        fprintf(op, "\n");
        fclose(fp);
        fclose(op);
        remove("locations.txt");
        rename("cfg.txt","locations.txt");
        printf("\nLocation Information Updated Successfully......\n");
        pause;
    }
    else
    {
        printf("ID Not Found!\n");
        pause;
    }
    clear;
    gpsSystemCore();
}
