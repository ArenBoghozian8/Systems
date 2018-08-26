/*
Aren Mark Boghozian
This Program calculates average CPI, the CPU time and the MIPS
*/

#include <stdio.h>
#include <stdlib.h>

int frequency=0, instruction_class=0, instruction_cpi_total=0, instruction_total=0;
float cpi=0, cpu_time=0;

void enterParameters(){
		int cpi, instruction;
		frequency=0, instruction_class=0, instruction_cpi_total=0, instruction_total=0, cpi=0, cpu_time=0;

	while(1){
		printf("Enter the number of instruction classes: ");
		scanf("%d", &instruction_class);
		printf("Enter the frequency of the machine (MHz): ");
		scanf("%d", &frequency);

		if(instruction_class > 0 && frequency > 0)
			break;

		printf("Please enter non zero positive numbers\n\n");
	}
	
	int i=1;
	while(i<=instruction_class){
		printf("Enter CPI of class %d: ",i);
		scanf("%d", &cpi);
		printf("Enter instruction count of class %d (miliseconds): ", i);
		scanf("%d", &instruction);
		
		if(cpi<0 || instruction<0)
			continue;

		instruction_cpi_total += (cpi * instruction);
		instruction_total += instruction;		
		i++;
	}
}


void calculate_CPI(){
	if(instruction_total==0){
		printf("Division by zero not possible\n");
		return;
	}
	cpi = (1.0 * instruction_cpi_total) / instruction_total;
	printf("The average CPI of the sequence is: %.2f", cpi);

}


void calculate_cpuTime(){
	if(frequency==0){
		printf("Division by zero not possible\n");
		return;
	}
	cpu_time = (1.0 * instruction_total) * (cpi / frequency) * 1000;
	printf("The total CPU time of the sequence is: %.2f", cpu_time);
}


void calculate_mips(){
	if(cpu_time==0){
		printf("Division by zero not possible\n");
		return;
	}
	float mips;
	mips = instruction_total / cpu_time * 1000.0;
	printf("The total MIPS of the sequence is: %.2f", mips);
}

int main()
{
    int selection=1;

    while(selection != 5){
		printf("\n\n");
		printf("Menu of Options:\n");
		printf("----------------\n\n");
		printf("1) Enter Parameters\n");
		printf("2)Calculate Average CPI of a sequence of instructions\n");
		printf("3)Calculate total excexution time of a sequence pf instructions\n");
		printf("4)Calculate MIPS of a sequence of instructions\n");
		printf("5)Quit\n\n");
        printf("Enter selection: ");
        scanf("%d", &selection);

		switch(selection){
			case 1:
				enterParameters();
				break;
			case 2:
				calculate_CPI();
				break;			
			case 3:
				calculate_cpuTime();
				break;
			case 4:
				calculate_mips();
				break;
			case 5:
				printf("Good Bye\n");
				exit(0);
				break;
			default:
				printf("Wrong input, Try again\n");
		}

    }

    return 0;
}
