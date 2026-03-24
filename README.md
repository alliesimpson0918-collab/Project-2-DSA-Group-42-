# Project-2-DSA-Group-42-
Allie Simpson, Brooke Mosrie, Frances Van Looveren DSA Project 2

Project Overview:
Sorting through a large movie dataset by box office revenue to determine how successful they were financially based off of the year they were released in or genre they belong to. We are looking to find the most efficient sorting method out of heap sort and merge sort when using a data set with one million rows.

There are Three files in the repository. 

1. Algorithm.h: The header file for our implementations of the sorting functions and the filtering of the dataset. This contains the Algorithm class and the movie struct.
2. Algorithm.cpp: The source code for our implementations of the sorting functions and the filtering of the dataset.
3. main.cpp: The file that should be run. It allows users to interact with the terminal to choose how to filter and sort the data.

Features:

1. Filters the movies by genre and release year.
2. Sorts the filtered results using both heap and merge sort
3. Lists the amount of time both heap and merge sort took as well as saying which algorithm is quicker.

How to Run:
First download the dataset - 
You can download it from:
https://www.kaggle.com/datasets/mjshubham21/movie-dataset-for-analytics-and-visualization

After downloading, place the file `movies_dataset.csv` in the same directory as the source files before running the program.
