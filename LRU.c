#include<stdio.h>

int main(){
    int n;
    int hit=0,miss=0;
    printf("Enter Number of Entries: ");
    scanf("%d",&n);
    int entries[n];
    printf("Enter Entries: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&entries[i]);
    }
    int frames;
    printf("Enter Number of Frames: ");
    scanf("%d",&frames);
    int frame[frames];
    for(int i=0;i<frames;i++){
        frame[i] = -1;
    }
    int track = 0;
    // int k = 0;
    for(int i=0;i<frames;i++){
        frame[i] = entries[i];
        track++;
        // k++;
    }
    miss = frames;
    printf("\nTrack: %d\n",track);

    //printing frames:
    printf("\n");
    for(int i=0;i<frames;i++){
        printf("%d\t",frame[i]);
    }

    for(int i=track;i<n;i++){
        int found = 0;
        for(int j=0;j<frames;j++){
            if(entries[i]==frame[j]){
                hit++;
                printf("hit: %d\n",frame[j]);
                found = 1;
                break;
            }
        }

        //If not found:
        int track[frames];
        int index;
        for(int m=0;m<frames;m++){
            track[m]=-1;
        }
        if(found==0){
            miss++;
            for(int kd=0;kd<frames;kd++){
                int picked = frame[kd];
                for(int k=i-1;k>=0;k--){
                    if(picked==entries[k]){
                        track[kd] = k;
                        break;
                    }
                }
            }

            //finding smallest index:
            int smallest = track[0];
            index = 0;
            for(int k=1;k<frames;k++){
                if(track[k]<smallest){
                    smallest = track[k];
                    index = k;
                }
            }
            frame[index] = entries[i];
            printf("\n");
            for(int i=0;i<frames;i++){
                printf("%d\t",frame[i]);
            }
        }
    }

    printf("\n\nMiss: %d, Hit: %d",miss,hit);

    return 0;
}