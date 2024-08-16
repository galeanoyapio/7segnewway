#include "MKL25Z4.h"

int sieteseg[7]={8,9,10,11,0,1,2};
    int nums[10][7]={
    {1,1,1,1,1,1,0}, //0
    {0,1,1,0,0,0,0}, //1
    {1,1,0,1,1,0,1}, //2
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1} //9
    };

int main(){
    SIM->SCGC5|=SIM_SCGC5_PORTB_MASK;

    PORTB->PCR [8]|=(1<<8);
    PORTB->PCR [9]|=(1<<8);
    PORTB->PCR [10]|=(1<<8);
    PORTB->PCR [11]|=(1<<8);
    PORTB->PCR [0]|=(1<<8);
    PORTB->PCR [1]|=(1<<8);
    PORTB->PCR [2]|=(1<<8);

    PTB->PDDR|=(1<<8);
    PTB->PDDR|=(1<<9);
    PTB->PDDR|=(1<<10);
    PTB->PDDR|=(1<<11);
    PTB->PDDR|=(1<<0);
    PTB->PDDR|=(1<<1);
    PTB->PDDR|=(1<<2);



    while(1){
        for(int i=0;i<10;i++){
            for(int x=0;x<7;x++){
                if(nums[i][x]==1) PTB->PSOR|=(1<<sieteseg[x]); //para que quede un 1
                else PTB->PCOR|=(1<<sieteseg[x]); //para que quede un 0 y no un 1 porque el |= suma 1 con 0 = 1
            }
            for(int t=3000000;t>0;t--);
        }
    }
    return 0;
}
