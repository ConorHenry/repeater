//
//  main.cpp
//  repeater
//
//  Created by Conor Henry on 9/19/16.
//  Copyright © 2016 Conor Henry. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>


//rearanges elements in stickers based on array of indecies
void reorderArr(int stickers[24], int index[24]){
    int temp[24];
    for(int i=0;i<24;i++){
        temp[index[i]]=stickers[i];
    }
    for(int i=0;i<24;i++){
        stickers[i]=temp[i];
    }
    
}
//CGD code stolen from stackoverflow
int gcd(int a, int b){
    for (;;){
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}
 //LCM code stolen from stackoverflow
long long findlcm(int arr[], int n){
    long long ans = arr[0];
    for (int i=1; i<n; i++){
        ans = (((arr[i]*ans))/(gcd(arr[i], ans)));
    }
    return ans;
}

class cube{
public:
    int corners[24]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    int edges[24]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};;
    
    void turn(int n){
        reorderArr(corners, cornerTurns[n]);
        reorderArr(edges, edgeTurns[n]);

    }
private:
    int cornerTurns[12][24]={
        {3,0,1,2,7,4,5,6,11,8,9,10,12,13,14,15,16,17,18,19,20,21,22,23},//U'
        {1,2,3,0,5,6,7,4,9,10,11,8,12,13,14,15,16,17,18,19,20,21,22,23},//U
        {0,1,2,3,4,5,6,7,8,9,10,11,13,14,15,12,17,18,19,16,21,22,23,20},//D'
        {0,1,2,3,4,5,6,7,8,9,10,11,15,12,13,14,19,16,17,18,23,20,21,22},//D
        {0,6,14,3,4,10,22,7,8,2,18,11,12,5,21,15,16,1,13,19,20,9,17,23},//R'
        {0,17,9,3,4,13,1,7,8,21,5,11,12,18,2,15,16,22,10,19,20,14,6,23},//R
        {12,1,2,4,20,5,6,8,16,9,10,0,23,13,14,7,15,17,18,3,19,21,22,11},//L'
        {11,1,2,19,3,5,6,15,7,9,10,23,0,13,14,16,8,17,18,20,4,21,22,12},//L
        {0,1,7,15,4,5,11,23,8,9,3,19,12,13,6,22,16,17,2,14,20,21,10,18},//F'
        {0,1,18,10,4,5,14,2,8,9,22,6,12,13,19,3,16,17,23,11,20,21,15,7},//F
        {5,13,2,3,9,21,6,7,1,17,10,11,4,20,14,15,0,12,18,19,8,16,22,23},//B'
        {16,8,2,3,12,0,6,7,20,4,10,11,17,1,14,15,21,9,18,19,13,5,22,23} //B
    };
    int edgeTurns[12][24]={
        {3,0,1,2,7,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},//U'
        {1,2,3,0,5,6,7,4,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},//U
        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,19,16,21,22,23,20},//D'
        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,19,16,17,18,23,20,21,22},//D
        {0,10,2,3,4,14,6,7,8,5,21,11,12,1,17,15,16,9,18,19,20,13,22,23},//R'
        {0,13,2,3,4,9,6,7,8,17,1,11,12,21,5,15,16,14,18,19,20,10,22,23},//R
        {0,1,2,8,4,5,6,12,23,9,10,7,19,13,14,3,16,17,18,11,20,21,22,15},//L'
        {0,1,2,15,4,5,6,11,3,9,10,19,7,13,14,23,16,17,18,12,20,21,22,8},//L
        {0,1,11,3,4,5,15,7,8,9,6,22,12,13,2,18,16,17,10,19,20,21,14,23},//F'
        {0,1,14,3,4,5,10,7,8,9,18,2,12,13,22,6,16,17,15,19,20,21,11,23},//F
        {9,1,2,3,13,5,6,7,4,20,10,11,0,16,14,15,8,17,18,19,12,21,22,23},//B'
        {12,1,2,3,8,5,6,7,16,0,10,11,20,4,14,15,13,17,18,19,9,21,22,23},//B
    };



};

/*
 
 void algConvert(std::string alg, int result[]){
 for(int i=0,j=0;alg[i]!='\0';i+=2){
 switch(alg[i]){
 case ' ':
 break;
 case 'U':
 result[j]=1;
 j++;
 break;
 case 'D':
 result[j]=3;
 j++;
 break;
 case 'R':
 result[j]=5;
 j++;
 break;
 case 'L':
 result[j]=7;
 j++;
 break;
 case 'F':
 result[j]=9;
 j++;
 break;
 case 'B':
 result[j]=11;
 j++;
 break;
 }
 printf("%d",result[i]);
 if(alg[i+1]=='i'){
 result[i]--;
 i++;
 }
 }
 
 
 }
*/

int countCycles(std::vector<int> checkList, cube nCube, int cycles[48], int cycleNumber, int which){
    int count=0;//number of stickers involved in cycle
    int k=0;
    int *index=nCube.corners; //shitty way of switching between corners and edges
    if(which){
        index=nCube.edges;
    }
    while(0<checkList.size()){ //stickers to check
        int j=checkList[0];
        for(k=0;k<24;k++){
            if(j==index[k]){ //find first sticker in list on cube
                for(int l=0;l<checkList.size();l++){ //remove from checklist
                    if(j==checkList[l]){
                        checkList.erase(checkList.begin()+l);
                    }
                }
                if(j!=k){ //insert next sticker in cycle
                    checkList.insert(checkList.begin(),k);
                    index[k]=-1;
                    count++;
                }
                break;
            }
            else if(k==23){ //end cycle and record
                cycles[cycleNumber++]=count;
                count=0;
                checkList.erase(checkList.begin());
            }
        }
    }

    return cycleNumber;
}

int test(int size, int algorithm[size]){
    cube newCube;
    int nCycles=0;
    for(int i=0;i<size;i++){
        newCube.turn(algorithm[i]);
    }
    int i;
    int j;
    std::vector<int> cornerCheck={0,1,2,3,20,21,22,23};//test one sticker per peice
    std::vector<int> edgeCheck={0,1,2,3,8,9,10,11,20,21,22,23};
    int cycles[48]={};//number of peices involved in each cycle
    int finalCycles[48];
    nCycles=countCycles(cornerCheck, newCube, cycles, nCycles,0);
    nCycles=countCycles(edgeCheck, newCube, cycles, nCycles,1);
    for(i=0,j=0;i<48;i++){ //removes zeros
        if(cycles[i]!=0){
            finalCycles[j]=cycles[i];
            j++;
        }
    }
    return findlcm(finalCycles, j-1);
}

int main(int argc, const char * argv[]) {
    int alg[4]={5,1,4,0};
    printf("%d",test(4, alg));
    return 0;
}

