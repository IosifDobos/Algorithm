/**
 * Algorithm and Problem Solving Assignment #1 Part 4
 * Implement the algorithm derived in part 1, 2, and 3 in C.
 * This program is created using diferent algorithms, Merge sort, Insertion sort, linear search and binary search
 * used to sorted 3 different lists of student into one sorted list.
 *
 * Program created by Iosif Dobos, C16735789 @copyright all rights are reserved
 *
 * DUE Date: 24/04/2017
 *
 * Compiler used: JetBrain CLion 2017.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declare my symbolic names
#define EU_SIZE 20
#define NON_EU_SIZE 6
#define INT_SIZE 10
#define MAX 21

//declare my structure template
struct students_list
{
    char first_name[MAX];
    char surname[MAX];
    char student_number[MAX];
    char student_class[MAX];
};
typedef struct students_list students;

//declare my function prototype
void merge_sort(students[], int, int);
void insertion_sort(students[], int);
void merge(students[], int, int, int);
void search_for_Internationals(students[], int );
void search_by_surname( students[], char[], int, int );

//start of main() function
int main()
{
    //declare my structure variables
    students NON_founded[NON_EU_SIZE];
    students students_combined[EU_SIZE + INT_SIZE];
    students my_DT228[EU_SIZE + NON_EU_SIZE + INT_SIZE];

    //declare my index variables
    int i = 0;
    int j = 0;
    int k = 0;

    //declare my pointers FILE
    FILE *fp1, *fp2, *fp3, *my_sorted_list;

    //Open the funded EU students for reading
    fp1 = fopen("founded_EU_students.bin", "rb");

    //create an if statement to check if file was opened successfully
    if ((fp1 = fopen("founded_EU_students.bin", "rb")) == NULL )
    {
        printf("\nError opening the file!!!");
    }
    //Open the non_founded_students to read from the file and create an if
    //statement to check if file open successfully
    fp2 = fopen("non_founded_students.bin", "rb");
    if ((fp2 = fopen("non_founded_students.bin", "rb")) == NULL )
    {
        printf("\nError opening the file!!!");
    }
    //Open the international_students to read from the file and create an if
    //statement to check if file open successfully
    fp3 = fopen("international_students.bin", "rb");
    if ((fp3 = fopen("international_students.bin", "rb")) == NULL )
    {
        printf("\nError opening the file!!!");
    }//end if

    //If files open successfully copy the founded_EU students and International students into a temporary array
    fseek(fp1, 0, SEEK_SET);
    for ( i = 0; i < EU_SIZE; ++i)
    {
        fread( &students_combined[i],sizeof(students), 1, fp1);
    }//end for loop

    fseek(fp3, 0, SEEK_SET);
    for ( i = EU_SIZE; i < EU_SIZE + INT_SIZE; ++i)
    {
        fread( &students_combined[i],sizeof(students), 1, fp3);
    }//end for loop

    //copy the non-founded EU students(2nd file) into an array
    fseek(fp2, 0, SEEK_SET);
    for ( i = 0; i < NON_EU_SIZE ; ++i)
    {
        fread( &NON_founded[i],sizeof(students), 1, fp2);
    }//end for loop

    //close the three files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    //display the content of the temporary array from EU_founded and International students
    printf("\n********** DISPLAY THE UNSORTED LIST OF STUDENTS **********\n");
    printf("\nStudent number\tSurname\t\t First name\t Student number\t Class\n");
    //create a lop that will display the students name from the array
    for ( i = 0; i < EU_SIZE + INT_SIZE; ++i)
    {
        printf("%d\t %s\t %s\t %s\t %s", i+1, students_combined[i].surname, students_combined[i].first_name,
               students_combined[i].student_number, students_combined[i].student_class );
        printf("\n");
    }

    //display the list of non-founded students

    for( i = 0; i < NON_EU_SIZE; i++)
    {
        printf("   %d ", i+31);
        printf("\t%s \t%s \t%s %s", NON_founded[i].surname, NON_founded[i].first_name, NON_founded[i].student_number,
                    NON_founded[i].student_class);


        printf("\n");
    }

    /**
     * Call function from question one, the merge sort algorithm, and sort the student list
     */
     merge_sort( students_combined, 0, EU_SIZE + INT_SIZE - 1);

    //call function insertion sort, and sort the non-founded list using the insertion sort algorithm
    insertion_sort( NON_founded, NON_EU_SIZE);

    //combine the 2 sorted list founded EU students and International students into a sorted DT228[] array
    //create a while loop and run true it goes to the end of the list
    while( i < (EU_SIZE + INT_SIZE ) && j < NON_EU_SIZE)
    {
        if( strcmp( students_combined[i].surname, NON_founded[j].surname) < 0)
        {
            my_DT228[k++] = students_combined[i++];
        }
        else
        {
            my_DT228[k++] = NON_founded[j++];
        }
    }//end while loop

    while ( j < NON_EU_SIZE)
    {
        my_DT228[k++] = students_combined[j++];
    }//end while loop

    //print all the student surname from the lists
    printf("\n*************** This is the sorted list of students by surname **************\n");
    printf("\nNumber\tSurname\tFirst name\tStudent number\tClass\n");
    for ( i = 0; i < EU_SIZE + INT_SIZE + NON_EU_SIZE; ++i)
    {
        printf("\t%d\t%s \t%s \t%s\t%s", i+1, my_DT228[i].surname,  my_DT228[i].first_name, my_DT228[i].student_number,
                    my_DT228[i].student_class);
        printf("\n");
    }

    //create a new file for writing and write the new list of students into this list
    my_sorted_list = fopen("sorted_list_of_students", "wb");

    fwrite( &my_DT228,sizeof(students), EU_SIZE + INT_SIZE + NON_EU_SIZE, my_sorted_list);

    fclose( my_sorted_list);

    /**
     * Part 2 of the assignment, Search for all international students
     */
    //call function search for all international students
    search_for_Internationals( my_DT228, EU_SIZE + INT_SIZE + NON_EU_SIZE);

    //Implement part 3 of the assignment
    //declare my string variable
    char search_surname[MAX];

    /**
     * Implement part 3 of the assignment search a student by surname
     */
    //asking user to enter the student surname wish to find
    printf("\n\nPlease enter student surname you want to look for: ");
    scanf("%s", search_surname);

    //implement function search for a specific surname
    search_by_surname( my_DT228, search_surname, 0, EU_SIZE + INT_SIZE + NON_EU_SIZE - 1);

    return 0;
}//end main() function
////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Implement function merge_sort algorithm
 * Purpose: This function will take to list of students founded EU students and International students and
 * sort the two list and store into a temporary variable
 */
void merge_sort( students temporary_students[], int low, int high)
{
    int mid; //create a variable mid ( middle )

    if ( low < high )
    {
        mid = ( low + high ) / 2;

        merge_sort( temporary_students, low, mid);

        merge_sort( temporary_students, mid + 1, high);

        merge( temporary_students, low, mid, high);
    }//end if statement

}//end merge_sort() function

/**
 * Implement function merge() used for the function merge_sort()
 */
void merge( students temporary_students[], int low, int mid, int high )
{
    //declare my variables used within this function
    int i;
    int num1 = low;
    int num2 = mid + 1;
    int k = low;

    //create my structure array
    students temp_array[EU_SIZE + INT_SIZE + NON_EU_SIZE];

    while( num1 <= mid && num2 <= high)
    {

        if(strcmp( temporary_students[num1].surname , temporary_students[num2].surname) < 0)
        {
            temp_array[k++] = temporary_students[num1++];
        }
        else
        {
            temp_array[k++] = temporary_students[num2++];
        }

    }//end while

    //Copy the rest of element left in one of the arrays after merging
    if(num1 == mid + 1)
    {
        while(num2 <= high )
        {
            temp_array[k++] = temporary_students[num2++];
        }
    }//end if statement
    else
    {
        while(num1 <= mid)
        {
            temp_array[k++] = temporary_students[num1++];
        }
    }//end else statement

    for(i = low; i <= high; i++)
    {
        temporary_students[i] = temp_array[i];
    }//end for loop

}//end merge() function

//Implement insertion sort
void insertion_sort( students NON_EU_students[], int size)
{
    int i, j;
    students temporary;

    for(i = 1; i < size; i++)
    {
        temporary = NON_EU_students[i]; //assign the element of i to a temporary variable
        j = i;

        while (strcmp (temporary.surname, NON_EU_students[j - 1].surname) < 0 ) {
            NON_EU_students[j] = NON_EU_students[j-1];
            j = j - 1;
        }
        NON_EU_students[j] = temporary;

    }//end for

}//end insertion_Sort()


/**
 * implement function search_for_Internationals() students
 */
void search_for_Internationals( students search[], int size_search)
{
    //declare my index variables
    int i = 0;
    int j = 1;

    //display the international students from the sorted list
    printf("\n\nThe international students are : \n");
    for(i = 0; i < size_search; i++)
    {
        if(strcmp(search[i].student_class, "International") == 0 )
        {
            printf("\n%d %15s  %15s    %10s     %10s", j++, search[i].surname, search[i].first_name,
                   search[i].student_number, search[i].student_class);
        }//end if statement
    }//end for loop

}//end search_for_Internationals() function


/**
 * Implement function search_by_surname() in this function user is ask to enter the surname student
 * want to search for
 */
void search_by_surname(students search_surname[], char find_surname[], int lower, int high)
{
    int middle;
    //int error_checking = 0;
    middle = (lower + high) / 2;


    if( lower > high )
    {
        printf("\nSorry cannot find student on the list");
        return;
    }


    //Compare strings
    if (strcasecmp(find_surname, search_surname[middle].surname) == 0)
    {
        //error_checking = 1;  //error checking
        printf("\n\nStudent found at position %d", middle+1);
        printf("\n %s   %s          %s       %s ", search_surname[middle].surname, search_surname[middle].first_name,
               search_surname[middle].student_number, 	search_surname[middle].student_class);

        return;

    }//end if


    if (strcasecmp(find_surname, search_surname[middle].surname) > 0)
    {
        lower = middle + 1;
        search_by_surname(search_surname,find_surname,lower , high);
    }

    if (strcasecmp(find_surname, search_surname[middle].surname) < 0)
    {
        high = middle - 1;
        search_by_surname(search_surname,find_surname,lower , high);
    }

}//end search_by_surname() function