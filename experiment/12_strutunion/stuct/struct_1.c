#include<stdio.h>

int main(int argc,char **argv)
{
	struct results
	{
		float interim_results;
		float end_results;
		float average_scores;
	}student;

	printf("Input interim_results:");
	scanf("%f",&student.interim_results);
	printf("Input end_results:");
	scanf("%f",&student.end_results);

	student.average_scores = (student.interim_results + student.end_results)/2;

	printf("%.2f\n",student.average_scores);

	return 0;
}
