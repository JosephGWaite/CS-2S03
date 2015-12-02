/* 
Name: Joseph Waite
MacID: waitejg
Student Number: 001403712 
Description: prints avg and std deviation of input values
*/ 

//these allow us to do things
#include <iostream> // for cout and cin 
#include <cmath> //for pow and sqrt 
#include <vector> //for a mutible list/arrary
#include <string> //for user input 

//this allows us us to do things without std::whatever
using namespace std; //We don't want to prepend std:: to all our calls

double listAverage(vector<int> & list) //takes a list of numbers and returns the 
{
	//AVG = SUM OF VALUES / NUM OF VALUES

	double sum = 0; //Initialse our sum
	for(int i=0; i<list.size(); i++) //for every value in a list
	{
		sum += list[i]; //add up values 
	}
	return sum / list.size(); //return the average
}

double stdDeviation(vector<int> & list, double average) //Values, and the average of those values
{	
	// 1/(n) * Σ(x- avg)^2
	double sum = 0; //init the sum
	for(int i=0; i< list.size(); i++)//for every value in a list
	{	
		sum += pow((list[i] - average), 2); //See standard deviation formula. 
	}
	double stdDev = pow(sum / (list.size()), 0.5); // x^0.5 === sqrt(x)
	return stdDev; // return the standard deviation
}

int main()
{
	//Declare and initalise
	double average = 0; 
	double stdDev  = 0;
	string i; 
	vector<int> v1; //vector, so we can push new values during input 

	int counter = 1; //for a dynamic UI experience
	while(true){ //Loop for ever and ever and ever, until we break out.
		cout << "Enter value " << counter << ":  "; //user prompt
		counter++; //increment counter
		cin >> i; //take input 
		if (i=="#") break; //if #, exit loop. 
		v1.push_back(stod(i)); //Push the input to a vector
	}

	average = listAverage(v1); //Call our average function
	stdDev  = stdDeviation(v1, average); //Call our stdDev function 
	cout.precision(2); //For the formating required
	cout << " \nThe average is " << average << "\n";  //print avg

	cout << fixed;// ""	
	cout << "The standard deviation is " << stdDev << "\n";	//print stdDev
	return 0; //SOP
}
