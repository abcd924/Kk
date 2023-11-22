
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct process
{
    char name[80];
    int at, bt, ct, wt, tat, tbt, pr;
} process;


process p[10];
int currenttime, i;
float totaltat, totalwt;


void sort(int n)
{
    process p1;
    int j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[j].at < p[i].at)
            {
                p1 = p[i];
                p[i] = p[j];
                p[j] = p1;
            }
        }
    }
}
void readprocess(int n)
{
    
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the process name: ");
        scanf("%s", p[i].name);
        printf("Enter the CPU Burst time: ") ;
        scanf("%d",&p[i].bt) ;
         printf("Enter pr: ") ;
        scanf("%d",&p[i].pr) ;
        printf("Enter the Arrival time: ") ;
        scanf("%d",&p[i].at) ;
        p[i].tbt = p[i].bt;
    }
}
int getprocess(int n)
{
    int i, min = 999, p1 = -1;
    for (i = 0; i < n; i++)
    {
        if (p[i].at <= currenttime && p[i].tbt != 0)
        {
            if (p[i].pr < min) 
            {
                min = p[i].pr;
                p1 = i;
            }
        }
    }
    return p1;
}
void scheduleprocess(int n)
{
    int i, count = 0;
    char cp[10], pp[10] = "NULL";//currentprocess=cp previous process=pp
    printf("\n\n GanttChart:\n");
    
    while (1)
    {
        i = getprocess(n);
        if (i == -1)
        {
            strcpy(cp, "idle");
            if (strcmp(cp, pp) != 0)
            {
                printf("%d|%d %s ", currenttime, currenttime, cp);
            }
            strcpy(pp, cp);
            currenttime++;
        }
        else
        {
            p[i].tbt--;
            strcpy(cp, p[i].name);
            if (strcmp(cp, pp) != 0)
            {

                printf("%d|%d %s ", currenttime, currenttime, cp);
            }
            currenttime++;
            if (p[i].tbt == 0)
            {
                p[i].ct = currenttime;
                p[i].tat = p[i].ct - p[i].at; // finishtime-arrival time
                p[i].wt = p[i].tat - p[i].bt; // total existence-working time
                count++;
                totaltat += p[i].tat;
                totalwt += p[i].wt;
            }
            strcpy(pp, cp);
            if (count == n)
                break;
        }
    }
    printf("%d|", currenttime);

}
void display(int n)
{
    int i;

    printf("\nprocess ArrivalTime BurstTime CPUTime TurnAroundtime WaitTime\n");

    for (i = 0; i < n; i++)
        printf("%s\t %d\t\t%d\t %d\t %d\t\t %d\n", p[i].name, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);

    printf("\n\nTotal Turn Around Time: %f", totaltat);
    printf("\nTotal Wait Time: %f", totalwt);
    printf("\n\nAverage Turn Around Time: %f", totaltat / n);
    printf("\nAverage Wait Time: %f\n", totalwt / n);
}
int main()
{
    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
   
    readprocess(n);
    sort(n);
    scheduleprocess(n);
    display(n);
    return 0;
}
