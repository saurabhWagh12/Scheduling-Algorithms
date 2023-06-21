#include<stdio.h>
#include<stdlib.h>

typedef struct Process{
    int burst;
    int arrival;
    int tat;
    int wt;
}P;

void initialize(P* p,int b,int a){
    p->burst = b;
    p->arrival = a;
    p->tat = 0;
    p->wt = 0;
}

int main(){
    P parr[4];
    int done[4];

    for(int i=0;i<sizeof(parr)/sizeof(parr[0]);i++){
        done[i] = 0;
    }

    //setting Up Processes data :
    for(int i=0;i<sizeof(parr)/sizeof(parr[0]);i++){
        printf("Enter Burst and Arrival for process P%d :=> ",i);
        int b,a;
        scanf("%d %d",&b,&a);
        initialize(&parr[i],b,a);
    }

   int total=0;
   int n = sizeof(parr)/sizeof(parr[0]);
   P arr[n];
   for(int i=0;i<n;i++){
    arr[i] = parr[i];
   }

   for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j].arrival>arr[j+1].arrival){
            P temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
   }

    printf("\n");
        // total = arr[0].arrival+arr[0].burst;
        for(int i=0;i<n;i++){
            printf("%d\t",arr[i].burst);
        //     if(parr[i].arrival == arr[0].arrival && parr[i].burst == arr[0].burst){
        //         parr[0].tat = total-parr[0].arrival; 
        //         parr[0].wt = parr[0].tat-parr[0].burst;
        //     }
        }

    //Actual Logic:
    printf("Gantt Chart: \n");
    // printf("P0: 0-%d\t",total); 
    int lastArrival = 0;
    // int pcount=0;
    P* moving = &arr[0];
    int movingIDX=0;

    int toReach = arr[n-1].arrival;

    while(lastArrival != toReach){

        if(lastArrival==0){
            moving->burst--;
            lastArrival++;
            total++;
        }else{
            for(int i=0;i<n;i++){
                if(done[i]!=1)
                if(lastArrival>=arr[i].arrival && moving->burst>arr[i].burst){
                    moving = &arr[i];
                    movingIDX = i;
                }
            }
            if(moving->burst!=0){
                moving->burst--;
                lastArrival++; total++;

                if(arr[movingIDX].burst==0){
                    done[movingIDX] = 1;
                    //set new moving
                    P p;
                    initialize(&p,999,0);
                    moving = &p;
                    movingIDX=-1;
                    for(int i=0;i<n;i++){
                        if(done[i]!=1 && lastArrival>=arr[i].arrival){
                            if(moving->burst>arr[i].burst){
                                moving = &arr[i];
                                movingIDX = i;
                            }
                        }
                    }
                }
            }

        }


    }

    //Remaining bursts:
    int allDone = 1;
    while(allDone){
        //Setting up allDone:
        int finding=0;
        for(int i=0;i<n;i++){
            if(done[i]==1){
                finding++;
            }
        }
        if(finding==n){
            allDone=0;
            break;
        }

        P p;
        initialize(&p,999,0);
        moving = &p;
        movingIDX=-1;
        for(int i=0;i<n;i++){
            if(done[i]!=1 && lastArrival>=arr[i].arrival){
                if(moving->burst>arr[i].burst){
                    moving = &arr[i];
                    movingIDX = i;
                }
            }
        }

        total+=moving->burst;
        moving->burst=0;
        done[movingIDX]=1;
    }


    printf("\n\n%d\n\n",total);
    // float avgTAT=0,avgWT=0;
    for(int i=0;i<n;i++){
    //     printf("for Process (%d) => TAT: %d\t, WT: %d\n",i,parr[i].tat,parr[i].wt);
    //     avgTAT+=parr[i].tat;
    //     avgWT+=parr[i].wt;
    printf("%d\n",arr[i].burst);
    }
    printf("\n%d P3 ka burst",arr[n-1].burst);

    // printf("\nAverage TAT: %.3f  and  Average WT: %.3f",avgTAT/n,avgWT/n);
  return 0;
}



// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Process {
//     int burst;
//     int arrival;
//     int tat;
//     int wt;
// } P;

// void initialize(P* p, int b, int a) {
//     p->burst = b;
//     p->arrival = a;
//     p->tat = 0;
//     p->wt = 0;
// }

// int main() {
//     P parr[4];
//     int done[4];

//     for (int i = 0; i < sizeof(parr) / sizeof(parr[0]); i++) {
//         done[i] = 0;
//     }

//     // setting Up Processes data:
//     for (int i = 0; i < sizeof(parr) / sizeof(parr[0]); i++) {
//         printf("Enter Burst and Arrival for process P%d :=> ", i);
//         int b, a;
//         scanf("%d %d", &b, &a);
//         initialize(&parr[i], b, a);
//     }

//     int total = 0;
//     int n = sizeof(parr) / sizeof(parr[0]);
//     P arr[3];
//     for (int i = 0; i < n; i++) {
//         arr[i] = parr[i];
//     }

//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j].arrival > arr[j + 1].arrival) {
//                 P temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }

//     printf("\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d\t", arr[i].burst);
//     }

//     // Actual Logic:
//     printf("Gantt Chart: \n");
//     int lastArrival = 0;
//     P* moving = &arr[0];
//     int movingIDX = 0;
//     int toReach = arr[n - 1].arrival;

//     while (lastArrival != toReach) {
//         if (lastArrival == 0) {
//             moving->burst--;
//             lastArrival++;
//             total++;
//         } else {
//             for (int i = 0; i < n; i++) {
//                 if (done[i] != 1 && lastArrival >= arr[i].arrival && moving->burst > arr[i].burst) {
//                     moving = &arr[i];
//                     movingIDX = i;
//                 }
//             }
//             if (moving->burst != 0) {
//                 moving->burst--;
//                 lastArrival++;
//                 total++;

//                 if (arr[movingIDX].burst == 0) {
//                     done[movingIDX] = 1;

//                     // Set new moving process
//                     P newMoving;
//                     initialize(&newMoving,999,0);
//                     int newMovingIdx = -1;

//                     for (int i = 0; i < n; i++) {
//                         if (done[i] != 1 && lastArrival >= arr[i].arrival) {
//                             if (arr[i].burst < newMoving.burst) {
//                                 newMoving = arr[i];
//                                 newMovingIdx = i;
//                             }
//                         }
//                     }

//                     moving = &newMoving;
//                     movingIDX = newMovingIdx;
//                 }
//             }
//         }
//     }

//     printf("\n\n%d\n\n", total);

//     for (int i = 0; i < n; i++) {
//         printf("%d\n", arr[i].burst);
//     }
//     printf("\n%d P3 ka burst\n", arr[n - 1].burst);

//     return 0;
// }
