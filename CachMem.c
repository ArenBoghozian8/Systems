/*********************************************************************************
Name: Aren Mark Boghozian
Date: 03/5/2017
*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

    int mms=0, cchs=0, blks=0, nrows=0;
    int *mm = NULL ;

struct Node {
	int tag;
	int *block;
}*cch = NULL;

    typedef struct Node  node;


void Option1() {
		
        printf("Enter main memory size (words):");
        scanf("%d" , &mms);

        printf("Enter cache size (words):");
        scanf("%d" , &cchs);

        printf("Enter block size (words/block):");
        scanf("%d" , &blks);

        nrows = (cchs)/(blks);

        mm = (int *) malloc(mms * sizeof (int));
        int i, j;
        for( i=0 ; i< mms ; i++){
            mm [i]  = mms-i;
        }

        cch = (node*) malloc(nrows * sizeof(node));
        for(i=0 ; i<nrows ; i++){
            cch[i].tag = -1;
            cch[i].block = (int *)malloc(blks * sizeof(int));
            for (j = 0; j < blks; j++)
            {
                cch[i].block[j] = 0;
            }
        }

}

void Option2(){

    int tg, blk , word, n, mmaddr, vw=0, base, i;
	
	while(1){

		printf("Select read (0) or write (1) : " );
		scanf("%d", &n);
		
		if(n==0 || n==1)
			break;
	
		printf("Number must be 0 or 1 \n");
	}

	if(n==1){
	    printf("Enter main memory address to write to:");
	}
	else{
	    printf("Enter main memory address to read from:");
	}
    scanf("%d", &mmaddr);

    if (n == 1)
    {
        printf("Enter value to write:");
        scanf("%d", &vw);
        printf("Write ");
    }
    else{
        printf("Read ");
    }

    tg = mmaddr / cchs;
    blk = (mmaddr % cchs) / blks;
    word = mmaddr % blks;
    base = (mmaddr / blks ) * blks;

    if (cch[blk].tag == tg)
    {
        printf("hit!\n");
    }
    else{
        printf("miss!\n");
        cch[blk].tag = tg;
        for (i = 0; i < blks; i++)
        {
            cch[blk].block[i] = mm[base + i];
        }
    }

    if (n == 1)
    {
        cch[blk].block[word] = vw;
        mm[mmaddr] = vw;
    }

	printf("------------------------------------------\n");
	printf("| Tag: %d |  Block: %d | Word: %d (%d) |\n", tg, blk, word, cch[blk].block[word]);
	printf("------------------------------------------\n");
}




int main (){

	int n;
    while (1){

      printf("\n");
      printf("Cache memory allocation and mapping: \n");
      printf("---------------------------------------\n");
      printf("1)Enter parameters.\n");
      printf("2)Access cache for reading / writing and transfer data .\n");
      printf("3)Quit.\n");
      printf("\n");
      printf("\n");
      printf("Enter selection : ");
      scanf("%d",&n);
      printf("\n");



        switch(n){

            case 1 :
					 Option1();
                     break;

            case 2 :
					 Option2();
                     break;

            case 3 :
					 exit(0);
					 break;

            default : printf("Invalid option. Please try again :)\n") ;
                      break;
        }

    }
     return 0 ;

}
