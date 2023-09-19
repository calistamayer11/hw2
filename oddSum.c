#include <stdio.h>
#include <stdlib.h>


int answers[100]; 

void reverseArray(int arr[], int length) 
{
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
	}
}

int oddSumHelp(int count, int bound, int value, int currentCount)
{
	//fill in your code below
	if (value == 0 && currentCount == count) {
		reverseArray(answers, count); 
		 for (int i = 0; i < count; i++) {
            printf("%d ", answers[i]);
        }
        return 1; 
	}

    if (value <= 0 || count <= 0 || bound <= 0 || currentCount >= count) {
        return 0; 
    } 

    if (bound % 2 == 0) {
        bound -= 1;
    }

    //try answers within the current bound 
	answers[currentCount] = bound; 

	
	if (oddSumHelp(count, bound - 2, value - bound, currentCount + 1)) {
        return 1; // Found a valid solution
    }
    
    //decrease by 2 again but don't include in answers
    if (oddSumHelp(count, bound - 2, value, currentCount)) {
        return 1;
    }
	return 0; 
}

//Do not change the code below
void oddSum(int count, int bound, int value)
{
    	if(value <= 0 || count <= 0 || bound <= 0) return;
    
    	if(bound % 2 == 0) bound -= 1;

    	if(!oddSumHelp(count, bound, value)) printf("No solutions.\n");
	else printf("\n");
}

int main(int argc, char *argv[])
{
	if(argc != 4) return -1;

	int count = atoi(argv[1]);
	int bound = atoi(argv[2]);
	int value = atoi(argv[3]);

	//oddSum(12,30,200);
	//oddSum(10,20,100);
	//oddSum(20,20,200);
	oddSum(count, bound, value);
	return 0;
}