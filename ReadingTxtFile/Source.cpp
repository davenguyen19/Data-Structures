
/*
In this program we are readinmg a .txt file that has the number of students that took a 
survey. The survey contains the numbers of movies each astudent has watched in the month.
With this data we are then instructed to find the mean, median, and mode of the data. 
After, these values are calculated we are writting it into an outfile that states
all of these values. 
*/



#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

double calcMean(int *array, int numStudents);
double calcMedian(int *array, int numStudents);
int calcMode(int *array, int numStudents);
void selectionSort(int *array, int numStudents);


int main() {
	int *numMovies;
	int numStudents = 0;
	int mode;
	double average, median;

	numMovies = new int[numStudents];

	ifstream inFile;
	ofstream outFile;

	inFile.open("movieStatStudents.txt");
	outFile.open("movieStatStudents2.txt");

	if (!inFile) { //for opening input file failure
		cout << "File did not open correctly" << endl;
		return 1;
	}
	if (!outFile) {	//opening output file failure
		cout << "file not found" << endl;
		cout << "Program ending" << endl;
		return 1;
	}


	while (inFile.eof() != true) {
		inFile >> numStudents;
		for (int i = 0; i < numStudents; i++) {
			inFile >> numMovies[i];
		}
	}

	selectionSort(numMovies, numStudents);
	average = calcMean(numMovies, numStudents);
	median = calcMedian(numMovies, numStudents);
	mode = calcMode(numMovies, numStudents);

	outFile << "Statistics for Movie Viewing of College Students" << endl;
	outFile << "February 2018" << endl;
	outFile << "Number of Students Surveyed: " << numStudents << endl;
	outFile << "Average is: " << average << endl;
	outFile << "Median is: " << median << endl;
	outFile << "Mode is: " << mode << endl;

	delete[] numMovies;

	inFile.close();
	outFile.close();

	return 0;
}



double calcMean(int *array, int numStudents){ // calculates the mean of the data
	
		double sum = 0;
		double average;
		for (int i = 0; i < numStudents; i++) {

			sum += array[i];
			average = sum / numStudents;
			
		}
		return average;
}




double calcMedian(int *array, int numStudents){	//calculates the median of the data
		double median = 0;
		if (numStudents % 2 == 0){
				median = (array[numStudents / 2] + array[(numStudents / 2) + 1]) / 2;
		}else
			median = array[numStudents / 2];
		return median;
}



int calcMode(int *array, int numStudents){	//calculates the mode of the data
	int mode = 0;
	int mostNums = 0;
	int count;
		for (int i = 0; i < numStudents; i++) {
			if (*(array + i) == *(array + (i + 1))) {
				count++;
				if (mode > mostNums) {
					mode = *(array + i);
					mostNums = count;
				}
			}
			count = 0;
		}
				return mode;
}



void selectionSort(int *array, int numStudents) { // sorts the numbers from lowest to highest
	int startScan;
	int minIndex;
	int minValue;
	
	for (startScan = 0; startScan < (numStudents - 1); startScan++) {
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < 20; index++) {
			if (array[index] < minValue) {
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
	
}
