#include "Algorithm.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

Algorithm::Movie::Movie() {}

Algorithm::Movie::Movie(string title, string genre, int releaseYear, double usBoxOffice) {
    this->title = title;
    this->genre = genre;
    this->releaseYear = releaseYear;
    this->usBoxOffice = usBoxOffice;
};

// the following merge sort functions are from the Graphs Lecture
// https://www.onlinegdb.com/HJT6FfMlv#

void Algorithm::merge(vector<Algorithm::Movie>& movies, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Movie> X(n1);
    vector<Movie> Y(n2);

    for (int i = 0; i < n1; i++)
        X[i] = movies[left + i];
    for (int j = 0; j < n2; j++)
        Y[j] = movies[mid + 1 + j];


    int i, j, k;
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (X[i].usBoxOffice <= Y[j].usBoxOffice)
        {
            movies[k] = X[i];
            i++;
        }
        else
        {
            movies[k] = Y[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        movies[k] = X[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        movies[k] = Y[j];
        j++;
        k++;
    }
}


void Algorithm::mergeSort(vector<Algorithm::Movie>& movies, int left, int right)
{
    if (left < right)
    {

        int mid = left + (right - left) / 2;

        mergeSort(movies, left, mid);
        mergeSort(movies, mid + 1, right);

        merge(movies, left, mid, right);
    }
}

void Algorithm::printArray(vector<Algorithm::Movie>& movies, int size)
{
    for (int i = 0; i < size; i++)
        cout << movies[i].title << ": $" << movies[i].usBoxOffice << endl;
}

// using psuedocode from the Heaps lecture slide 47

void Algorithm::heapifyDown(int index, int size, vector<Algorithm::Movie>& movies){
    int max = index;
    int left = 2 * index + 1;
    int right = 2 *index + 2;
    if(left < size && movies[left].usBoxOffice > movies[max].usBoxOffice){
        max = left;
    }
    if (right < size && movies[right].usBoxOffice > movies[max].usBoxOffice){
        max = right;
    }
    if (max != index){
        swap(movies[index], movies[max]);
        heapifyDown(max, size, movies);
    }
}

void Algorithm::heapSort(vector<Algorithm::Movie>& movies)
{
    for (int i = (movies.size() / 2) - 1; i >= 0; i--)
    {
        heapifyDown(i, movies.size(), movies);
    }

    for (int i = movies.size() - 1; i > 0; i--)
    {
        swap(movies[0], movies[i]);
        heapifyDown(0, i, movies);
    }
}

vector<Algorithm::Movie> Algorithm::genreVector(string genre, vector<Algorithm::Movie>& movies)
{
    vector<Algorithm::Movie> genre_movies;
    for (int i=0; i<movies.size(); i++)
    {
        if (movies[i].genre == genre)
        {
            genre_movies.push_back(movies[i]);
        }
    }
    return genre_movies;
}

vector<Algorithm::Movie> Algorithm::yearVector(int year, vector<Algorithm::Movie>& movies)
{
    vector<Algorithm::Movie> year_movies;
    for (int i=0; i<movies.size(); i++)
    {
        if (movies[i].releaseYear == year)
        {
            year_movies.push_back(movies[i]);
        }
    }
    return year_movies;
}