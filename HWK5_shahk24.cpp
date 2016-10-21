/*
Name:  Kunal Shah
MacID: shahk24
Student Number:  1419350
Description:  C++ program that takes as input N values and prints 
their average and standard deviation. The last input value is marked by #.
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using  namespace std;

// Function to calculate the mean of given array
// Input: array, array lenght.

// Method:
// Sum of all numbers
// Divide sum by number of numbers
double getMean(double data[],int dataLength)
{
	double sum = 0; //sum of all the numbers in array
	double avg; // mean value
	// Summation of all valuse in array
	for (int i=0; i< dataLength; i++)
	{
		sum += data[i];
	}
	// mean = total of sum divided by number of numbers
	avg = sum/dataLength;
	return avg;
}

// Function to calculate the mean of given array
// Input: array, array lenght.

// Method: Population Standard Deviation
// Get mean
// square the result of data value subtract the Mean 
// sum result of squares
// Sample variance = Divide sum of squares by number of numbers
// Standard deviation = square root of Sample variance
double getStdDiv(double data[],int dataLength)
{
	double mean = getMean(data,dataLength); // geting mean value 
	double sqrSum = 0;
	for (int i=0; i< dataLength; i++)
	{
		// reset result of data value subtract the Mean to zero
		double value = 0;
		// data value subtract the Mean 
		value = data[i] - mean;
		// value squared
		sqrSum += value * value;
	}
	// sampleVariance =  squared value divide by number of numbers
	double sampleVariance = sqrSum/(dataLength);
	// square root of sampleVariance
	double stdDiv = sqrt(sampleVariance);

	return stdDiv;
}

int main ()
{
	string user_input;
	vector<string> input_str;
	
	// Takeing user input. Storing in string vector: input_str
	// last input is # to stop taking more input.
	int counter = 1;
	bool run = true;
	while (run)
	{
		cout << "Enter value " << counter << ":   ";
		cin >> user_input;
		input_str.push_back(user_input);
		
		// end input colection when # symbol is detected
		if (input_str[counter-1]=="#")
		{
			run = false;
		}
		counter++;
	}
	// Converting string vector to double array.
	int dataLength = input_str.size() - 1; // onless than input_str lenght to remove # end character
	double inputData [dataLength];
	
	// converting string to double and storing in array
	for (int i=0; i< dataLength; i++)
	{
		inputData[i]=stod(input_str[i]);
	}
	// Calculating and printing mean avarage and standard deviation
	// rounding to 2 decimal places
	cout << "The average is " << roundf(getMean(inputData,dataLength)*100)/100 << "\n";
	cout << "The standard deviation is " << roundf(getStdDiv(inputData,dataLength)*100)/100 << "\n";


	return 0;
}