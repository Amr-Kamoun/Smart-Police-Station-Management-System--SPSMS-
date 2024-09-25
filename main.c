//
//  main.c
//  Kamoun
//
//  Created by Yehia Sharawy on 25/09/2024.
//

#include<stdio.h>
#include<string.h>
typedef    struct date
    {    int day;
            int month;
                int year;
    }DOB;
    typedef struct information
    { int id;
        char name[50];
            int rank;
                    DOB dateofbirth;
                        int experience;
                            int daysoff;
                                char station_name[50];
                                    char shift_time[50];
                                            int cases[50];
            }inf;
    
    typedef struct details
    {
        int case_number;
            char offname[50][50];
                char case_type[50];
                    DOB crdate;
                        DOB clodate;
                        int victims_id[50];
                            int suspects_id[50];
                                int closed;
    }det;
    void sort(int n,inf x[3]){
    int i,j,k;
    inf temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(x[i].rank>x[i+1].rank)
            {
                temp=x[i];
                x[i]=x[i+1];
                x[i+1]=temp;
            }
            else if(x[i].rank==x[i+1].rank)
            {
                k=strcmp(x[i].name,x[i+1].name);
                if(k<0)
                {
                temp=x[i];
                x[i]=x[i+1];
                x[i+1]=temp;
                }
            }
        }
    }
}
    
    void listofficer(int n,det y[3],inf x[3])
    {
        int i,j,k;
        for(i=0;i<n;i++)
        {
        if((strcmp(y[i].case_type,"Theft")==0))
        {
            for(j=0;j<2;j++)
            {
                for(k=0;k<3;k++){
            if(strcmp(y[i].offname[j],x[k].name)==0)
                    {
                    printf("%s  ",x[k].name);
                    printf("%d\n",x[k].rank);
                    }
                }
            }
        }
    }
}
    void cases(int n,det y[3])
    {    int i,j,k,s,t,w,victim,suspect;
        FILE *Kamoun4;
    Kamoun4=fopen("Cases.txt","r+");
        for (k=0;k<n;k++)
    {
        fscanf(Kamoun4,"%d",&y[k].case_number);
        for(s=0;s<2;s++)
        {
        fscanf(Kamoun4,"%s",y[k].offname[s]);
        }
        fscanf(Kamoun4,"%s",y[k].case_type);
        fscanf(Kamoun4,"%d %d %d",&y[k].crdate.day,&y[k].crdate.month,&y[k].crdate.year);
        fscanf(Kamoun4,"%d %d %d",&y[k].clodate.day,&y[k].clodate.month,&y[k].clodate.year);
        fscanf(Kamoun4,"%d",&victim);
        for(t=0;t<victim;t++)
        {
        fscanf(Kamoun4,"%d",&y[k].victims_id[t]);
        }
        fscanf(Kamoun4,"%d",&suspect);
        for(w=0;w<suspect;w++)
        {
        fscanf(Kamoun4,"%d",&y[w].suspects_id[w]);
        }
        fscanf(Kamoun4,"%d",&y[k].closed);
    }
        fclose(Kamoun4);
    }
    void officers(int n,inf x[3])
    {
        int i,j,k,s,t,w,victim,suspect;
        FILE *Kamoun3;
        Kamoun3=fopen("Officers.txt","r");
        for(i=0;i<n;i++)
    {
        fscanf(Kamoun3,"%s",x[i].name);
        fscanf(Kamoun3,"%d",&x[i].id);
        fscanf(Kamoun3,"%d",&x[i].rank);
            for(j=0;j<3;j++)
        {
            fscanf(Kamoun3,"%d",&x[i].cases[j]);
        }
        fscanf(Kamoun3,"%d %d %d",&x[i].dateofbirth.day,&x[i].dateofbirth.month,&x[i].dateofbirth.year);
        fscanf(Kamoun3,"%d",&x[i].experience);
        fscanf(Kamoun3,"%d",&x[i].daysoff);
        fscanf(Kamoun3,"%s",x[i].station_name);
        fscanf(Kamoun3,"%s",x[i].shift_time);
    }    fclose(Kamoun3);
    }
    void cases2(int n,det y[3])
    {
    int i,j,k,s,t,w,victim,suspect;
        FILE *Kamoun2;
        Kamoun2=fopen("Cases2.txt","w");
        for (k=0;k<n;k++)
        {
        fprintf(Kamoun2,"please enter case number:");
        fprintf(Kamoun2,"%d\n",y[k].case_number);
        for(s=0;s<2;s++)
        {
        fprintf(Kamoun2,"please enter supervised officer:");
        fprintf(Kamoun2,"%s\n",y[k].offname[s]);
        }
        fprintf(Kamoun2,"Please Enter Case Type:");
        fprintf(Kamoun2,"%s\n",y[k].case_type);
        fprintf(Kamoun2,"Please Enter Creation Date:");
        fprintf(Kamoun2,"%d %d %d\n",y[k].crdate.day,y[k].crdate.month,y[k].crdate.year);
        fprintf(Kamoun2,"Please Enter Closed Date:");
        fprintf(Kamoun2,"%d %d %d\n",y[k].clodate.day,y[k].clodate.month,y[k].clodate.year);
        fprintf(Kamoun2,"Please enter the victim numbers: ");
        fprintf(Kamoun2,"%d\n",victim);
        for(t=0;t<victim;t++)
        {
        fprintf(Kamoun2,"Please enter victims ID number %d :",t+1);
        fprintf(Kamoun2,"%d\n",y[k].victims_id[t]);
        }
        fprintf(Kamoun2,"Please enter the suspects number: ");
        fprintf(Kamoun2,"%d\n",suspect);
        for(w=0;w<suspect;w++)
        {
        fprintf(Kamoun2,"Please enter suspects ID number %d :",w+1);
        fprintf(Kamoun2,"%d\n",y[w].suspects_id[w]);
        }
        fprintf(Kamoun2,"Please Enter if case is closed or not :");
        fprintf(Kamoun2,"%d\n",y[k].closed);
    }
        fclose(Kamoun2);
    }
    void officers2(int n,inf x[3])
    {
        FILE *Kamoun;
Kamoun=fopen("Officers2.txt","w");
int i,j,k,s,t,w,victim,suspect;
    for(i=0;i<n;i++)
    {
    fprintf(Kamoun,"Officer Num");
    fprintf(Kamoun,"%d:",i+1);
    fprintf(Kamoun,"please enter name of officer:");
    fprintf(Kamoun,"%s\n",x[i].name);
        fprintf(Kamoun,"please enter officer id:");
        fprintf(Kamoun,"%d\n",x[i].id);
    fprintf(Kamoun,"please enter rank of officer\n(from 1-6)");
    fprintf(Kamoun,"%d\n",x[i].rank);
        for(j=0;j<3;j++)
        {    fprintf(Kamoun,"please enter officer cases:");
            fprintf(Kamoun,"%d\n",x[i].cases[j]);
        }
        fprintf(Kamoun,"please enter officer date of birth:");
        fprintf(Kamoun,"%d %d %d\n",x[i].dateofbirth.day,x[i].dateofbirth.month,x[i].dateofbirth.year);
        fprintf(Kamoun,"please enter officer years of experience:");
        fprintf(Kamoun,"%d\n",x[i].experience);
        fprintf(Kamoun,"please enter officer days off:");
        fprintf(Kamoun,"%d\n",x[i].daysoff);
        fprintf(Kamoun,"please enter officer station name:");
        fprintf(Kamoun,"%s\n",x[i].station_name);
        fprintf(Kamoun,"please enter officer shift time:");
        fprintf(Kamoun,"%s\n",x[i].shift_time);
    }
        fclose(Kamoun);
}
        

        
    void get(int n,det y[3])
{
    int i,maxxx=0;
        for (i=0;i<n;i++)
        {
            if((y[i].clodate.year-y[i].crdate.year)>maxxx)
            {
            maxxx=y[i].clodate.year-y[i].crdate.year;
            }
        }
            printf("%d\n",maxxx);
    }
    void scan(inf x[3],det y[3],int n)
    {
    int i,j,k,s,t,w,victim,suspect;
    for(i=0;i<n;i++)
    {
    printf("officer Num:");
    printf("%d\n",i+1);
    printf("please enter name of officer:");
    scanf("%s",x[i].name);
        printf("please enter officer id:");
        scanf("%d",&x[i].id);
    printf("please enter rank of officer\n(from 1-6)");
    scanf("%d",&x[i].rank);
        for(j=0;j<3;j++)
        {    printf("please enter officer cases:");
            scanf("%d",&x[i].cases[j]);
        }
        printf("please enter officer date of birth:");
        scanf("%d %d %d",&x[i].dateofbirth.day,&x[i].dateofbirth.month,&x[i].dateofbirth.year);
        printf("please enter officer years of experience:");
        scanf("%d",&x[i].experience);
        printf("please enter officer days off:");
        scanf("%d",&x[i].daysoff);
        printf("please enter officer station name:");
        scanf("%s",x[i].station_name);
        printf("please enter officer shift time:");
        scanf("%s",x[i].shift_time);
        }
        for (k=0;k<n;k++)
        {
        printf("please enter case number:");
        scanf("%d",&y[k].case_number);
        for(s=0;s<2;s++)
        {
        printf("please enter supervised officer:");
        scanf("%s",y[k].offname[s]);
        }
        printf("Please Enter Case Type:");
        scanf("%s",y[k].case_type);
        printf("Please Enter Creation Date:");
        scanf("%d %d %d",&y[k].crdate.day,&y[k].crdate.month,&y[k].crdate.year);
        printf("Please Enter Closed Date:");
        scanf("%d %d %d",&y[k].clodate.day,&y[k].clodate.month,&y[k].clodate.year);
        printf("Please enter the victim numbers: ");
        scanf("%d",&victim);
        for(t=0;t<victim;t++)
        {
        printf("Please enter victims ID number %d :",t+1);
        scanf("%d",&y[k].victims_id[t]);
        }
        printf("Please enter the suspects number: ");
        scanf("%d",&suspect);
        for(w=0;w<suspect;w++)
        {
        printf("Please enter suspects ID number %d :",w+1);
        scanf("%d",&y[w].suspects_id[w]);
        }
        printf("Please Enter if case is closed or not :");
        scanf("%d",&y[k].closed);
    }
    }


    int main()
    {
        int n,d,i,a,yesorno=0;
            scanf("%d",&n);
                    inf x[3];
                        det y[3];
                        while (yesorno!=1)
                        {
                            printf("1. Scan N officers and case details\n2. Get the longest time for a closed case\n3. List all case with type= ""Theft"" and print their responisble officer's name and rank.\n4. Sort officers (by Rank, if two or more officers are equal in rank, sort them alphabetically).\n5. Scan N officers and their data from a file called ""Officers.txt""\n6. Scan N cases and their data from a file called ""Cases.txt""\n7.Print N officers and their data from a file called ""Officers2.txt""\n8. Print N cases and their data from a file called ""Cases2.txt"".\n0. To end the code.\n\n Choose a number: ");
                            scanf("%d",&a);
                            switch(a)
                            {
                                case 1:scan(x,y,n);break;
                                case 2:get(n,y);break;
                                case 3:listofficer(n,y,x);break;
                                case 4:sort(n,x);
                                        for(i=0;i<n;i++)
                                        {
                                            printf("%s ",x[i].name);
                                            printf("%d\n",x[i].rank);
                                        }break;
                                case 5:officers(n,x);break;
                                case 6:cases(n,y);break;
                                case 7:officers2(n,x);break;
                                case 8:    cases2(n,y);break;
                                default:break;
                            }
                            printf("Are you finished? (yes=1 | No=0)");
                            scanf(" %d",&yesorno);
                        }
                        return 0;
                    }
