#ifndef DSAPROJECT2_ALGORITHM_H
#define DSAPROJECT2_ALGORITHM_H
#include <vector>
#include <string>
using namespace std;


class Algorithm {
    public:
    struct Movie {
        string title;
        string genre;
        int releaseYear;
        double usBoxOffice;

        Movie ();

        Movie(string title, string genre, int releaseYear, double usBoxOffice);

    };

    void merge(vector<Algorithm::Movie>& movies, int left, int mid, int right);

    void mergeSort(vector<Algorithm::Movie>& movies, int left, int right);

    void printArray(vector<Algorithm::Movie>& movies, int size);

    void heapifyDown(int index, int size, vector<Movie>& movies);

    void heapSort(vector<Algorithm::Movie>& movies);

    vector<Movie> genreVector(string genre, vector<Movie>& movies);

    vector<Movie> yearVector(int year, vector<Movie>& movies);
};


#endif //DSAPROJECT2_ALGORITHM_H