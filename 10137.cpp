#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {

	int numberofstudents;
	double *studentcontibutions;

	while (scanf("%i\n", &numberofstudents) && numberofstudents != 0) {
		double average = 0;
		double contribution = 0;
		double posresult = 0;
		double negresult = 0;
		double result = 0;
		studentcontibutions = new double[numberofstudents];
		for (int i = 0; i < numberofstudents; i++) {
			scanf("%lf\n", &studentcontibutions[i]);
			contribution += studentcontibutions[i];
		}
		average = contribution / numberofstudents;

		for (int i = 0; i < numberofstudents; i++) {
			double difference = (studentcontibutions[i] - average);
			double diff = trunc(100 * difference) / 100;
			if (diff < 0) {
				negresult += diff;
			} else {
				posresult += diff;
			}
		}
		if (negresult != 0) {
			negresult = -negresult;
		}
		if (posresult > negresult) {
			result = posresult;
		} else {
			result = negresult;
		}
		printf("$%.2f\n", result);
	}
	delete studentcontibutions;
	return 0;
}
