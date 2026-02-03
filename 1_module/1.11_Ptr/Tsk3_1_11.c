//
// Created by NandanRaj on 25-01-2026.
//
#include <stdio.h>
#include <stdlib.h>
// take input of no, of innings, score of each inning, avg of all and highest of all
void inputScore(int* innigsScores,int numGames);
double calculateAverage(const int* scoresPtr, int size);
int findHighest(const int* scoresPtr, int size);
int main() {
    int numGames=0;
    do {
        printf("Enter the total number of innings played (must be positive): ");
        if (scanf("%d",&numGames)!=1) {
            printf("Invalid input\n");
            while (getchar()!='\n');
        }
        if (numGames<=0) {
            printf("No. of innings must be positive.\n");
        }
    }while (numGames<=0);
    int *innigsScores=(int*)calloc(numGames,sizeof(int));
    if (innigsScores==NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    inputScore(innigsScores,numGames);
    double average=calculateAverage(innigsScores,numGames);
    if (average>0) {
        printf("The average of each innings is %.2f\n",average);
    }
    int highest=findHighest(innigsScores,numGames);
    printf("The highest of each innings is %d\n",highest);
    free(innigsScores);
    innigsScores=NULL;
    return 0;

}
void inputScore(int *innigsScores,int numGames) {
    if (innigsScores==NULL) {
        printf("There is no memeory to get input of scores\n");
        return;
    }
    int i=0;
    while (i<numGames) {
        printf("Enter score of Game%d:",i+1);
        scanf("%d",innigsScores+i);
        if (innigsScores[i]<0) {
            printf("Invalid input.\nEnter again\n");
            i--;
        }
        i++;
    }
    printf("Input of score of each innings successful\n");
}

double calculateAverage(const int* scoresPtr, int size) {
    if (size==0) {
        printf("Can't calculate average of zero innings as size=0\n");
        return 0.0;
    }
    int sum=0;
    double average=0;
    for (int i=0;i<size;i++) {
        sum+=scoresPtr[i];
    }
    average=(double)sum/size;

    return average;
}
int findHighest(const int* scoresPtr, int size) {
    int highest=0;
    for (int i=0;i<size;i++) {
        if (scoresPtr[i]>highest) {
            highest=scoresPtr[i];
        }
    }
    return highest;
}