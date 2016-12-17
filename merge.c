/**
 * Implements a merge sort for a list of 25,000 items.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Exits on error with the parameterized message. 
 * @param message a message to print upon exit
 */
void exitOnError( char const *message )
{
	printf( "%s\n", message );
	exit( EXIT_FAILURE );
}

/**
 * Reads a list from standard input.
 * @param list a pointer to the list created
 * @return the length of the list
 */
int readList( int *list )
{
	int len;
	if ( scanf( "%d", &len ) != 1 )
		exitOnError( "Can't read input length" );

	for ( int i = 0; i < len; i++ )
		if ( scanf( "%d", list + i ) != 1 )
			exitOnError( "Can't read list item" );

	return len;
}

/**
 * Performs the merge sort. Function splits the list in half
 * recursively sorts each half.
 * @param list a pointer to the list to be sorted
 * @param len the length of the list
 */
void sortList( int *list, int len )
{
	// A list with one is already sorted.
	if ( len <= 1 )
		return;

	// Splits the list into two smaller lists.
	int alen = ( len + 1 ) / 2;
	int blen = len / 2;

	int a[ alen ];
	int b[ blen ];

	int pos = 0; 

	// Copies the first half (alen elements) of list[] to a[].
	for (int i = 0; i < alen; i++) {
		a[i] = list[i];
	}

	// Copies the rest of list[] (the remaining blen elements) to b[].
	for (int i = alen; i < len; i++) {
		b[i - alen] = list[i];
	}

	// Recursively sorts the two smaller lists.
	sortList( a, alen );
	sortList( b, blen );

	pos = 0;
	int apos = 0;
	int bpos = 0;

	// Repeatedly takes the next item from a[] or b[], copying it to the next position in list[]

	int i = 0;
	while (apos < alen && bpos < blen) {
		if (a[apos] <= b[bpos]) {
			list[i] = a[apos];
			apos++;
			i++;
		} else {
			list[i] = b[bpos];
			bpos++;
			i++;
		}
	}

	while (apos < alen) {
		list[i] = a[apos];
		apos++;
		i++;
	}

	while (bpos < blen) {
		list[i] = b[bpos];
		bpos++;
		i++;
	}
}



/**
 * Prints a sorted list.
 * @param list the sorted list to print
 * @param len the length of the list
 */
void printList( int *list, int len )
{
	for ( int i = 0; i < len; i++ ) {
		printf( "%d", list[ i ] );
		// Fencepost behavior.
		if ( i + 1 < len )
			printf( " " );
	}
	printf( "\n" );
}

/**
 * Starts and runs the program.
 */
int main()
{
	
	//Consider changing this behavior. Hard-coding should be avoided.
	int list[ 25000 ];

	int len = readList( list );
	sortList( list, len );
	printList( list, len );

	return 0;
}
