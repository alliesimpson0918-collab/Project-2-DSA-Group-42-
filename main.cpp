#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Algorithm.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {

    // create an algorithm object
    Algorithm algo;

    cout <<"We will be sorting movies based on certain years and genres!" << endl
    <<"Getting Movie Data..." << endl << endl;

    // for guidance on creating an array of objects
    // https://www.geeksforgeeks.org/cpp/array-of-objects-in-c-with-examples/

    ifstream file("movies_dataset.csv");

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int rows = 999999;
    string line;
    int row = 0;

    // initialize a vector of movies
    vector<Algorithm::Movie> movies;
    getline(file, line); // skip the header

    // loops through each row (Movie) in the movies csv
    while (getline(file, line) && row <rows) {
        stringstream ss(line);
        string cell;
        vector<string> row_elements;

        // put each element of a movie into a mini array
        while (getline(ss, cell, ',')) {
            row_elements.push_back(cell);
        }

        // saves a movie obj for the row
        Algorithm::Movie movieObj(row_elements[1], row_elements[2], stoi(row_elements[3]), stod(row_elements[7]));
        movies.push_back(movieObj);
        row++;
    }

    bool endProgram = false;

    while (endProgram == false)
    {
        // creating a copy of the vector so user can do multiple sorts
        vector<Algorithm::Movie> moviesVector = movies;

        // filter the data by genre
        cout << "Choose a genre number to filter the data by:" << endl;
        cout << "1. Action" << endl << "2. Comedy" << endl << "3. Documentary" <<
            endl << "4. Drama"<< endl << "5. Horror" << endl << "6. Sci-Fi"
            << endl << "7. Thriller" << endl << "8. Romance" << endl;

        int inputGenre;

        // see if user input is valid
        if (!(cin >> inputGenre)){
            cout << "Invalid Input!" << endl << endl;
            // to clear the current input so user can start over
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // check the input is valid
        if (inputGenre >= 1 && inputGenre <= 8) {

            string genre;

            if (inputGenre == 1){
                genre = "Action";
            } else if (inputGenre == 2){
                genre = "Comedy";
            } else if (inputGenre == 3){
                genre = "Documentary";
            } else if (inputGenre == 4){
                genre = "Drama";
            } else if (inputGenre == 5){
                genre = "Horror";
            } else if (inputGenre == 6){
                genre = "Sci-Fi";
            } else if (inputGenre == 7){
                genre = "Thriller";
            } else if (inputGenre == 8)
            {
                genre = "Romance";
            }

            moviesVector = algo.genreVector(genre, moviesVector);
        } else {
            cout << "Invalid Input!" << endl << endl;
            continue;
        }

        cout << "Choose a year between 1950 and 2025 to filter by: " << endl;
        int inputYear;

        if (!(cin >> inputYear)){
            cout << "Invalid Input!" << endl << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (inputYear >= 1950 && inputYear <= 2025){

            moviesVector = algo.yearVector(inputYear, moviesVector);
        } else {
            cout << "Invalid Input!" << endl << endl;
            continue;
        }

        vector<Algorithm::Movie> mergeSortVector = moviesVector;
        vector<Algorithm::Movie> heapSortVector = moviesVector;

        // for help using chronos to time our sort functions
        // https://www.geeksforgeeks.org/cpp/measure-execution-time-function-cpp/

        // call merge sort and time it
        auto start = high_resolution_clock::now();
        algo.mergeSort(mergeSortVector, 0, mergeSortVector.size() - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        auto durationMerge = duration.count();

        // call heap sort and time it
        start = high_resolution_clock::now();
        algo.heapSort(heapSortVector);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        auto durationHeap = duration.count();


        cout << "Box Office Sales sorted by..." << endl << endl;
        cout << "Merge Sort: " << endl;
        cout << "----------" << endl << endl << endl;
        algo.printArray(mergeSortVector, mergeSortVector.size());

        cout << "Box Office Sales sorted by..." << endl << endl;
        cout << "Heap Sort: " << endl;
        cout << "----------" << endl << endl;
        algo.printArray(heapSortVector, heapSortVector.size());

        cout << endl << endl;

        // compare duration times
        cout << "Time to merge sort: " << durationMerge << " microseconds" << endl;
        cout << "Time to heap sort: " << durationHeap << " microseconds" << endl;

        if (durationMerge > durationHeap){
            cout << "Heap sort is quicker!" << endl << endl;
        } else {
            cout << "Merge sort is quicker!" << endl << endl;
        }


        // ask the user if they want to do it again
        cout << "Choose an option:" << endl;
        cout << "1. Continue" << endl << "2. End" << endl;
        string ifEndProgram;
        cin >> ifEndProgram;

        if (ifEndProgram == "2"){
            endProgram = true;
            cout << "Thanks for sorting with us!";
            cout << endl;
        }

    }

    return 0;
}

