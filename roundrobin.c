
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct PROCESS
{
    char name[80];
    int at, bt, ct, wt, tat, tbt;
    
}PROCESS;


PROCESS p[10];
int i, q, tq, x;
float totaltat, totalwt;



void sort(int n)
{
    PROCESS p1;
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
void readProcess(int n)
{
 
    printf("\nEnter time quantum:");
    scanf("%d", &q);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the process name: ");
        scanf("%s", p[i].name);
        printf("Enter the CPU Burst time: ");
        scanf("%d", &p[i].bt);
        printf("Enter the Arrival time: ");
        scanf("%d", &p[i].at);
        p[i].tbt = p[i].bt;
    }
}

int getProcess(int n)
{
    int p1;
    if (x == n)
    x = 0;
    p1 = x;
    x++;
    return p1;
}
void scheduleProcess(int n)
{
    int i, count = 0, time = 0;
    char cp[10], pp[10] = "NULL";
    printf("\n\n GanttChart:\n");

    while (1)
    {
        tq = 0;
        i = getProcess(n);
        if (p[i].tbt == 0)
            tq = q;       
        while (tq != q)   
        {
            p[i].tbt--;
            strcpy(cp, p[i].name);
            if (strcmp(cp, pp) != 0)
            {
                printf("%d|%d %s ", time, time, cp);
            }
            time++;
            if (p[i].tbt == 0)
            {
                p[i].ct = time;
                p[i].tat = time - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
                count++;
                totaltat += p[i].tat;
                totalwt += p[i].wt;
            }
            strcpy(pp, cp);
            if (p[i].tbt == 0 && tq != q)
                break;

            tq++;
        }
        if (count == n)
            break;
    }
    printf("%d|", time);

 
}
void display(int n)
{
    printf("\nProcess ArrivalTime BurstTime CPUTime TurnAroundtime WaitTime\n");

    for (i = 0; i < n; i++)
        printf("%s\t %d\t\t%d\t %d\t %d\t\t%d\n", p[i].name, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);

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
     readProcess(n);
     sort(n);     
    getProcess(n);
    scheduleProcess(n);
    display(n);
    return 0;
}
