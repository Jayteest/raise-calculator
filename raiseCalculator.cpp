/*
 Jacob St Lawrence
 This program reads a file with employee data (name, salary, and pay increase percentage)
 and calculates their new salary after the increase. It then creates a new file containing
 the employees' names and new salaries.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()  //create main
{
    //declare variables
    ifstream inFile;
    ofstream outFile;
    string firstName, lastName;
    double currentSalary, increaseRate, updatedSalary;
    
    //open files for input and output
    inFile.open("sampleEmployees.txt");
    outFile.open("newSalaries.txt");
    
    outFile << fixed << showpoint << setprecision(2);   //set precision for output
    
    while (!inFile.eof())   //create loop to run through entire list of employees
    {
        //read employee data and assign to appropriate variables
        inFile >> lastName >> firstName;
        inFile >> currentSalary >> increaseRate;
    
        updatedSalary = currentSalary * (1 + increaseRate/100); //calculate new salary
        //write result to output file
        outFile << left << setw(20) << firstName + " " + lastName << updatedSalary << endl;
    }
    //close files
    inFile.close();
    outFile.close();
    return 0;   //return 0 to exit program
}
