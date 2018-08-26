#include <stdio.h>
#include <stdlib.h>

/*  Aren Mark Boghozian
*/

int mm, pz , rp, ne;


struct node {

    int vp;
    int pf;
            }*pt = NULL;


typedef struct node row;


void Option1(){


    printf("Enter main memory size (words):");
    scanf("%d",&mm);

    printf("Enter page size(words/page):");
    scanf("%d", &pz);

    printf("Enter replacement policy(0=LRU , 1=FIFO):");
    scanf("%d" , &rp);

    /* calculate number the entires in page table */
    /*  ne= number the entires */

    ne = (mm)/(pz);

    pt = (row*)malloc(ne * sizeof(row)); /* Allocate spave for page table */

    int i;

    for(i=0 ; i<=ne-1 ; i++){            

        pt[i].vp = -1;
    }
}


void Option2(){

    int vm,pf,i;

        printf("Enter virtual memory address to access :");
        scanf("%d",&vm);

        int vp = (vm)/(pz);

        int offset = (vm) % (pz);

    /* Check for virtual page entry in page table */

    int index =0;

        while((index < ne ) && (pt[index].vp!=-1) && (pt[index].vp!=vp)){
            index ++;
        }

        int Tpf = pt[0].pf;

        if(index == ne){


          for(i=0; i<=ne-2 ; i++){

            pt[i] = pt[i+1];

            }

            pt[ne-1].vp = vp;
            pt[ne-1].pf = Tpf;


            printf("Page fault!\n");
        }

        else if (pt[index].vp==-1){
            pt[index].vp=vp;
            pt[index].pf=index;

            printf("Page fault!\n");

        }



        else {


            int Tpf = pt[index].pf;

            if(rp == 0){
                int i;
                for (i= index ; i<= (ne-2); i++){
                    if(pt[i].vp==-1) break;

                    pt[i]=pt[i+1];
                }

                pt[i].vp = vp;
                pt[i].pf = Tpf;
        }

        int Pa = Tpf * pz + offset;

        printf("Virtual address %d maps to physical address %d \n",vm,Pa);

    }

    int x;
    for(x=0 ; x<=ne-1;x++){

     	if(pt[x].vp == -1){
			break;		
		}
			printf(" VP %d --> PF %d \n", pt[x].vp, pt[x].pf);     	

        }


}


int main(){


int n;

    while (n !=4 ){

      printf("\n");
      printf("Virtual address mapping: \n");
      printf("------------------------\n");
      printf("1)Enter parameters.\n");
      printf("2)Map virtual address.\n");
      printf("3)Quit\n");
      printf("\n");
      printf("\n");
      printf("Enter selection : ");
      scanf("%d",&n);
      printf("\n");



        switch(n){

            case 1 : Option1();
                     break;

            case 2 : Option2();
                     break;

            case 3 : exit(0);
 					

            default : printf("Invalid option. Please try again :)\n") ;
                      break;
        }

    }
     return 0 ;

}


