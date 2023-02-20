#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*
AUTHOR: GUILLEMMV
*/

char matrix[50][50];
int gen = 0;

#define ROWS 20
#define COLS 50
#define LIVE_CELL '*'
#define DEAD_CELL '.'


void fillMatrix(){
	for(int i=0; i<ROWS; i++){
		for(int j=0; j<COLS; j++){
			matrix[i][j] = DEAD_CELL;
		}
	}
}

void showMatrix(){
	int j;
	gen++;
	system("clear");
	printf("GENERATION: %d\n----------\n",gen); 

	for(int i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++){
			printf("%c",matrix[i][j]);
		}
		printf("\n");
	}
	usleep(100000);
}

void generateRandomCells(){
	int upper = 50;
	int lower = 0;
	int randomCol = rand() % (upper-lower+1);
	int randomRow = rand() % (upper-lower+1);
	int randomNum = rand() % (15-1+1);
	int i;

	
	for(i=0; i<randomNum; i++){
		matrix[randomRow][randomCol] = LIVE_CELL;
		matrix[randomRow][randomCol-1] = LIVE_CELL;
		matrix[randomRow][randomCol+1] = LIVE_CELL;
		matrix[randomRow-1][randomCol] = LIVE_CELL;
		matrix[randomRow+1][randomCol] = LIVE_CELL;
	}
}

void setAliveCells(){
	
}

void getNextGeneration(){
	for(int i=0; i<ROWS; i++){
		for(int j=0; j<COLS; j++){
			
			int neighboursCount = 0;
				char neighbours[] = {matrix[i][j], matrix[i-1][j], matrix[i+1][j]
					,matrix[i][j+1],matrix[i][j-1],matrix[i-1][j-1],matrix[i+1][j+1]
					,matrix[i+1][j-1],matrix[i-1][j+1]};

			if(matrix[i][j] == LIVE_CELL){
				for(int i=0; i<=sizeof(neighbours); i++){
					if(neighbours[i]==LIVE_CELL){
						neighboursCount++;
					}
				}
				if(neighboursCount == 0 || neighboursCount >= 4 || neighboursCount == 1){
					matrix[i][j] = DEAD_CELL;
				}
			}
			else{
				for(int i=0; i<=sizeof(neighbours); i++){
					if(neighbours[i]==LIVE_CELL){
						neighboursCount++;
					}
				}
				if(neighboursCount == 3){
					matrix[i][j] = LIVE_CELL;
				}
			}
		}
	}
}

int main(){
	printf("\e[?25l");
	fillMatrix();
	generateRandomCells();
	for(;;){
		showMatrix();
		getNextGeneration();
	}
	return 0;
}
