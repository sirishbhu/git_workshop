#include <iostream>
using namespace std;

int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j,p[20],pos,temp;
    cout<<"Enter total number of processes:\n";
    cin>>n;
    cout<<"Enter a process: \n"<<"1. FCFS\n"<<"2. SJF\n"<<"3. Priority\n"<<"4. Round Robin\n";
    int x;
    cin>>x;
    switch(x)
    {
        case 1:
            cout<<"Enter Process Burst Time\n";
            for(i=0;i<n;i++)
            {
                cout<<i+1<<": ";
                cin>>bt[i];
            }
            wt[0]=0;
            for(i=1;i<n;i++)
            {
                wt[i]=0;
                for(j=0;j<i;j++)
                    wt[i]+=bt[j];
            }
            cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
            for(i=0;i<n;i++)
            {
                tat[i]=bt[i]+wt[i];
                avwt+=wt[i];
                avtat+=tat[i];
                cout<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
            }
            avwt/=n;
            avtat/=n;
            cout<<"\nAverage Waiting Time: " <<avwt<<"\n";
            cout<<"Average Turnaround Time: " <<avtat;

            break;
        case 2:
            cout<<"Enter Process Burst Time\n";
            for(i=0;i<n;i++)
            {
                cout<<i+1<<": ";
                cin>>bt[i];
                p[i]=i+1;
            }
            for(i=0;i<n;i++)
            {
                pos=i;
                for(j=i+1;j<n;j++)
                {
                    if(bt[j]<bt[pos])
                        pos=j;
                }
                temp=bt[i];
                bt[i]=bt[pos];
                bt[pos]=temp;
                temp=p[i];
                p[i]=p[pos];
                p[pos]=temp;
            }
            wt[0]=0;
            for(i=1;i<n;i++)
            {
                wt[i]=0;
                for(j=0;j<i;j++)
                    wt[i]+=bt[j];
            }
            cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
            for(i=0;i<n;i++)
            {
                tat[i]=bt[i]+wt[i];
                avwt+=wt[i];
                avtat+=tat[i];
                cout<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
            }
            avwt/=n;
            avtat/=n;
            cout<<"\nAverage Waiting Time: " <<avwt<<"\n";
            cout<<"Average Turnaround Time: " <<avtat;

            break;
        case 3:
            int pr[20];
            cout<<"Enter Process Burst Time and Priority\n";
            for(i=0;i<n;i++)
            {
                cout<<i+1<<": ";
                cin>>bt[i]>>pr[i];
                p[i]=i+1;
            }
            for (i=0;i<n;i++)
            {
                pos=i;
                for (j=i+ 1 ;j<n;j++)
                {
                    if (pr[j]<pr[pos])
                        pos=j;
                }
                temp=pr[i];
                pr[i]=pr[pos];
                pr[pos]=temp;
                temp=bt[i];
                bt[i]=bt[pos];
                bt[pos]=temp;
                temp=p[i];
                p[i]=p[pos];
                p[pos]=temp;
            }
            wt[0]=0;
            for(i=1;i<n;i++)
            {
                wt[i]=0;
                for(j=0;j<i;j++)
                    wt[i]+=bt[j];
            }
            cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
            for(i=0;i<n;i++)
            {
                tat[i]=bt[i]+wt[i];
                avwt+=wt[i];
                avtat+=tat[i];
                cout<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
            }
            avwt/=n;
            avtat/=n;
            cout<<"\nAverage Waiting Time: " <<avwt<<"\n";
            cout<<"Average Turnaround Time: " <<avtat;
            break;
        case 4:
            int count,j,time,remain,flag=0,quantum, min= 0,start=0;
            int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
            remain=n;
            count=0;
            while(count<n)
            {
                cout<<"Enter Arrival Time and Burst Time for Process " <<count+1<<": ";
                cin>>at[count];
                cin>>bt[count];
                rt[count]=bt[count];
                count++;
            }
            cout<<"Enter Time Quantum: ";
            cin>>quantum;
            cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
            min=at[0];
            for(i=1;i<n;i++)
            {
                if (at[i]<=min)
                {
                    min=at[i];
                    start=i;
                }
            }
            for(time=min,count=start;remain!=0;)
            {
                if(rt[count]<=quantum && rt[count]> 0 )
                {
                    time+=rt[count];
                    rt[count]= 0;
                    flag=1;
                }
                else if(rt[count]>0)
                {
                    rt[count]-=quantum;
                    time+=quantum;
                }
                if(rt[count]==0&&flag==1)
                {
                    remain--;
                    cout<<count+ 1<<"\t\t"<<bt[count]<<"\t\t"<< time-at[count]-bt[count]<<"\t\t"<< time-at[count]<<"\n";
                    wait_time+=time-at[count]-bt[count];
                    turnaround_time+=time-at[count];
                    flag= 0 ;
                }
                if (count==n-1)
                    count= 0;
                else if(at[count+1]<=time)
                    count++;
                else
                    count= 0;
            }
            cout<<"\nAverage Waiting Time= " <<wait_time/n;
            cout<< "\nAvg Turnaround Time = " <<turnaround_time/n;
            break;
    }
    return 0;
}
