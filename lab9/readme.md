CS105 - Lab 9 - 17/03/2023

problem1
Write a C program that takes two integer inputs from the user and swaps their values using pointers.
The program should declare two integer variables and two integer pointers. The pointers should
point to the addresses of the two integer variables, and the program should use pointer arithmetic to
swap the values of the two variables. Finally, the program should print out the values of the two
integers after they have been swapped.

problem2
Write a C program that takes a string input from the user and reverses it using pointers. The
program should declare a char array and a char pointer. The pointer should point to the first element
of the array, and the program should use pointer arithmetic to traverse the array from both ends,
swapping the values at each position until the entire string has been reversed. Finally, the program
should print out the reversed string. There should be a user-defined function which does the task of
reversing the string.

problem3
Write a C program that takes an integer array input from the user and finds the largest and smallest
elements using pointers. The program should declare an integer array and two integer pointers. The
first pointer should point to the first element of the array, and the second pointer should point to the
last element of the array. The program should then use pointer arithmetic to traverse the array,
comparing each element to the current values of the largest and smallest integers, and updating the
pointers accordingly. Finally, the program should print out the largest and smallest integers. Use the
concept of user-defined functions to pass the relevant arguments to the function which is handling
the task of finding the largest and smallest elements of the array.

problem4
Write a C program that takes the length and width of a rectangle as input from the user and
calculates its area and perimeter using structures. Your program should define a struct called
"Rectangle" that contains two float fields called "length" and "width". The program should then
declare a variable of type Rectangle, initialize its fields with the user input, and calculate its area
and perimeter using those fields. Finally, the program should print out the area and perimeter.

problem5
Write a C program that stores and displays the details of employees using structures. The program
should define a struct called "Employee" that contains fields for the employee's name, ID,
department, and salary. The program should then declare an array of Employee structs and allow the
user to enter details for each employee. Finally, the program should display the details of all
employees in a formatted table.

problem6
Write a C program that takes the temperature and rainfall data for each day of a month as input from
the user and calculates the average temperature and rainfall using structures. The program should
define a struct called "DayData" that contains fields for the temperature and rainfall for a single day.
The program should then declare an array of DayData structs and allow the user to enter data for
each day. Finally, the program should calculate the average temperature and rainfall for the month
and print out the results.