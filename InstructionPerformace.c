/*************************************
*Name: Aren Mark Boghozian
**************************************/

#include <stdlib.h>
#include <stdio.h>

int h;
struct node{
    int locale;
    int src1;
    int src2;
    int delay;
}*set=NULL;

typedef struct node totinstr;

void Option1(){
    char instr_string[9];
    printf("\n");
    printf("Enter total number of instructions: ");
    scanf("%d",&h);
    set=(totinstr*)malloc((h+1)*sizeof(totinstr));
    set[0].locale=-1;
    
    int i=1;
    for(i;i<=h;i++){
        printf("%d) ",i);
        scanf("%s", instr_string);
        set[i].locale=instr_string[1];
        set[i].src1=instr_string[4];
        set[i].src2=instr_string[7];
    }
    
}
void printthis(){
    
    int i=1;
    for(i;i<=h;i++){
        printf("%d) ",i);
        int n=1;
        for(n;n<=set[i].delay;n++){
            printf("\t");
        }
        printf("FI\tDI\tCO\tFO\tEI\tWO\t\n");
    }
}


void Option2(){
    int overlap=0;
    set[1].delay=0;
    int dep_delay;
    int total_delay;
    
    int i=2;
    for(i;i<=h;i++){
        dep_delay=0;
        if((set[i-2].locale==set[i].src1)||
           (set[i-2].locale==set[i].src2)){
            if(overlap==0){dep_delay=1;overlap=1;}
            else{dep_delay=0;overlap=0;}
        }
        
        else{
            overlap=0;
        }
        if((set[i-1].locale==set[i].src1)||
           (set[i-1].locale==set[i].src2)){
            dep_delay=2;
            overlap=1;
        }
        set[i].delay=set[i-1].delay + dep_delay+1;
    }
    total_delay= set[h].delay+6;
    printf("Total number of cycles : %d \n",total_delay);
    
    printthis();
}
void Option3(){
    int pipe_delay=1;
    int overlap1=0;
    int overlap2=0;
    int overlap3=0;
    int overlap4=0;
    int overlap5=0;
    int total_delay;
    set[1].delay=0;
    int i=2;
    for(i;i<=h;i++){
        int dep_delay=0;
        pipe_delay=1-pipe_delay;
        if(i>=5){
            if((set[i-5].locale==set[i].src1)||
               (set[i-5].locale==set[i].src2)){
                pipe_delay=1;
                if((overlap1==0)&&(overlap2==0)&&
                   (overlap3==0)&&(overlap4==0)&&(overlap5==0)){
                    overlap5=1;
                    
                    if(pipe_delay==0)
                        dep_delay=0;
                    else
                        dep_delay=0;
                }
                else
                    overlap5=0;
            }
            else
                overlap5=0;
        }
        if(i>=4)
            if((set[i-4].locale==set[i].src1)||
               (set[i-4].locale==set[i].src2)){
                if((overlap1==0)&&(overlap2==0)&&
                   (overlap3==0)&&(overlap4==0)){
                    overlap4=1;
                    if(pipe_delay==0)dep_delay=0;
                    else dep_delay=1;
                }
                else{
                    overlap4=0;
                }
            }
            else overlap4=0;
        if(i>=3)
            if((set[i-3].locale==set[i].src1)||
               (set[i-3].locale==set[i].src2)){
                if((overlap1==0)&&(overlap2==0)&&
                   (overlap3==0)){
                    overlap3=1;
                    if(pipe_delay==0)dep_delay=1;
                    else dep_delay=1;
                }
                else{
                    overlap3=0;
                }
            }
            else overlap3=0;
        if(i>=2)
            if((set[i-2].locale==set[i].src1)||
               (set[i-2].locale==set[i].src2)){
                if((overlap1==0)&&(overlap2==0)){
                    overlap2=1;
                    if(pipe_delay==0)dep_delay=1;
                    else dep_delay=2;
                    
                }
                else{
                    overlap2=0;
                }
            }
            else overlap2=0;
        if(i>=1)
            if((set[i-1].locale==set[i].src1)||
               (set[i-1].locale==set[i].src2)){
                dep_delay=2;
                overlap1=1;
                pipe_delay=1;
            }
            else overlap1=0;
        set[i].delay=set[i-1].delay+dep_delay+pipe_delay;
    }
    total_delay=set[h].delay +6;
    printf("Total number of cycles : %d \n",total_delay);
    printthis();
}

int main(){
    int choice=0;
    while(choice!=4){
        printf("\n");
        printf("Pipelined/Superscalar Instruction Performance");
        printf("\n");
        printf("---------------------------------------------");
        printf("\n");
        printf("1) Enter Instructions\n");
        printf("2) Calculate total cycle count on a 6-Stage Pipelined Architecture\n");
        printf("3) Calculate total cycle count on a 6-Stage Superscalar Architecture\n");
        printf("4) Quit\n\n");
        
        printf("Enter selection: ");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                Option1();
                break;
            case 2 :
                Option2();
                break;
            case 3:
                Option3();
                break;
            case 4:
                break;
        }
    }
    return 0;
}
