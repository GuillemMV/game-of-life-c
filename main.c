#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*
AUTHOR: GUILLEMMV
*/

char matrix[50][50];
int rows = 20;
int cols = 50;
int gen = 0;

void fillMatrix(){
	int i, j;
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			matrix[i][j] = '.';
		}
	}
}

void showMatrix(){
	int i, j;
	gen++;
	system("clear");
	printf("GENERATION: %d\n----------\n",gen); 

	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			printf("%c",matrix[i][j]);
		}
		printf("\n");
	}
	sleep(1);
}

void generateRandomCells(){
	int upper = 50;
	int lower = 0;
	int randomCol = rand() % (upper-lower+1);
	int randomRow = rand() % (upper-lower+1);
	int randomNum = rand() % (15-1+1);
	int i;

	for(i=0; i<randomNum; i++){
		matrix[randomRow][randomCol] = '0';
	}
}

int main(){
	fillMatrix();
	for(;;){
		generateRandomCells();
		showMatrix();
		generateRandomCells();
		if(gen==10){
			break;
		}
	}
	return 0;
}
