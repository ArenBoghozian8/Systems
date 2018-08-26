/*******************************************************
Name: Aren Mark Boghozian
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>


char * Ham = NULL;
int Ml,Pf;//Declare the maximum length and Parity flag

void Option1 (){

    printf("Enter the maximum length:"); //User inputs length
    scanf("%d",&Ml);

    printf("Enter the parity (0=even , 1=odd):"); // User inputs parity
    scanf("%d",&Pf);

    Ham = (char*) malloc(Ml * sizeof(char)); //Allocate space for Hamming code
    return;
}


void reverse_hamming(char * hamming, int Al)
{
    char temporary;
    int i, j;

    for (i = 0, j = Al - 1; i < j; i++, j--)//for reverse
    {
        temporary = hamming[i];
        hamming[i] = hamming[j];
        hamming[j] = temporary;
    }

}

void Option2(){

    printf("Enter the Hamming code :"); // The user should enter the Hamming code;
    scanf("%s", Ham);

    int Al = strlen(Ham);
    if (Al > Ml)
    {
        printf("Error: Bad hamming code\n");
        return;
    }


    int i, j, k, result = 0;
    reverse_hamming(Ham, Al);


        for(i= 1; i <= Al;i *= 2){

            j = 0;

            for(k= i;k<= Al; k++){

                if ((k- i) % (i * 2) < i) //Ensures the correct data checking sequence for every parity
                {
                    if (Ham[k - 1] == '1')
                    {
                        j++;
                    }
                }
            }
            if (j% 2 != Pf)
            {
                result += i;
                if (result> Al)
                {
                    printf("Error: there were more than 2 errors in the code\n");
                    return;
                }
            }
        }

       if(result != 0){

                printf("There is an error in bit: %d\n",result);

                if (Ham[result - 1] == '0')
                {
                    Ham[result- 1] = '1';
                }
                else
                {
                    Ham[result - 1] = '0';
                }


                reverse_hamming(Ham, Al);
                printf("The corrected Hamming code is: %s\n", Ham);
        }

        else{
                reverse_hamming(Ham, Al);
                printf("There is no bit error.\n");
                printf("\n");
      }


      return;


}



int main (){

    int n;

    while (n != 3){

      printf("\n");
      printf("Hamming Code Checker: \n");
      printf("---------------------------------------\n");
      printf("1)Enter parameters.\n");
      printf("2)Check Hamming code.\n");
      printf("3)Quit.\n");
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

            case 3 : break;

            default : printf("Invalid option. Please try again :)\n") ;
                      break;
        }

    }
     return 0 ;

}
