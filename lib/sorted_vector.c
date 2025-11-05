/**
 * Contains functions for the sorted vector struct
 *
 * @author: Maggie Li
 * @class: CS 5008
 * @term: fall 2025
**/

#include "vector.h"
#include "movie.h"


/**
 * adds a movie to the sorted vector.
 * 
 * Based on the movie (compare_movies), it will find the correct index
 * using a linear search.
 * 
 * The moment it finds that the movie to add is greater than the
 * current movie, it will insert it at that next index calling vector_insert.
 * 
 * 
 * @param vector the vector to add the movie to
 * @param movie the movie to add
*/
void add_to_sorted_vector(SortedMovieVector * vector, Movie * movie) {
    // STUDENT TODO: implement this function
    if (vector->size == 0) {
        vector_insert(vector, movie, 0);
        return;
    }

    for (int i = 0; i < vector->size; i++) {
        if (compare_movies(movie, vector->movies[i]) < 0) {
            vector_insert(vector, movie, i);
            return;
        }
    }
    
    vector_insert(vector, movie, vector->size);
}
/**
 * Finds a movie in the sorted vector based on the title only of the movie.
 *
 * strcasecmp is used to compare the titles, so the search is case insensitive.
 *
 * For example: int cmp = strcasecmp(title, movie->title);
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one. 
 *
 * @param vector the vector to search
 * @param title the title of the movie to find
 * @return the movie if found, NULL otherwise
 */
Movie * find_in_sorted_vector(SortedMovieVector * vector, const char * title) {
    // STUDENT TODO: implement this function
    int left = 0;
    int right = vector->size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcasecmp(title, vector->movies[mid]->title);
        
        if (cmp == 0) {
            return vector->movies[mid];
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            
            left = mid + 1;
        }
    }
    // if the movie is not found, return NULL
    return NULL;
}

/**
 * Checks if the sorted vector contains a movie with the given title.
 *
 * Very similar to find_in_sorted_vector, but instead of just finding
 * the movie will call vector_remove(vector, index) to remove the movie
 * returning the resulted removed movie.
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one.
 *
 * @param vector the vector to check
 * @param title the title to check for
 * @return the movie removed, NULL otherwise
 */
Movie* sorted_vector_remove(SortedMovieVector *vector, const char *title){
    // STUDENT TODO: implement this function
    int left = 0;
    int right = vector->size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcasecmp(title, vector->movies[mid]->title);
        
        if (cmp == 0) {
            return vector_remove(vector, mid);
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return NULL; // not found
}
