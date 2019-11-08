#include <stdio.h>
#include <stdlib.h>

int main(void){

	double score[3];
	int return_code;
	
	for(int i = 0; i < 3; i++){ 


		fflush(stdout);
		printf("Enter Score number %d\n", i + 1);
		return_code = scanf("%lg", &score[i]); 
		
		if(return_code) printf("Good\n");
	}



	if(score[0] < score[1] && score[0] < score[2]){
		
		printf("The Score is: %lg\n", (score[1] + score[2]) / 2);
	
	}else if(score[1] < score[2] && score[1] < score[0]){


		printf("The Score is: %lg\n", (score[2] + score[0]) / 2);
	}else{
	
		printf("The Score is: %lg\n", (score[1] + score[0]) / 2);
	}
	
//	for(int i = 0; i < 3; i++){
 //		if(lowest < scores[i]) lowest = i;
	
//		printf("the Scores are %lg \n", scores[i]); 
//	}


	return EXIT_SUCCESS;



}
