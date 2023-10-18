# C - Sorting algorithms & Big O

## Background Context

## Resources

**Read or watch**:

-   [Sorting algorithm](https://intranet.alxswe.com/rltoken/-j5MKLBlzZAC2RfJ5DTBIg "Sorting algorithm")
-   [Big O notation](https://intranet.alxswe.com/rltoken/WRvrE2BaNVQFssHiUATTrw "Big O notation")
-   [Sorting algorithms animations](https://intranet.alxswe.com/rltoken/ol0P7NbYVb5R31iOv4Q40A "Sorting algorithms animations")
-   [15 sorting algorithms in 6 minutes](https://intranet.alxswe.com/rltoken/_I0aEvhfJ66Xyob6dd9Utw "15 sorting algorithms in 6 minutes") (_**WARNING**: The following video can trigger seizure/epilepsy. It is not required for the project, as it is only a funny visualization of different sorting algorithms_)
-   [CS50 Algorithms explanation in detail by David Malan](https://intranet.alxswe.com/rltoken/Ea93HeEYuNkOL7sGb6zzGg "CS50 Algorithms explanation in detail by David Malan")
-   [All about sorting algorithms](https://intranet.alxswe.com/rltoken/21X_eaj5RGcLIL9mZv2sqw "All about sorting algorithms")

## Learning Objectives

At the end of this project, you are expected to be able to [explain to anyone](https://intranet.alxswe.com/rltoken/b-QhraVUoSGmQ1C4QfNoFw "explain to anyone"), **without the help of Google**:

### General

-   At least four different sorting algorithms
-   What is the Big O notation, and how to evaluate the time complexity of an algorithm
-   How to select the best sorting algorithm for a given input
-   What is a stable sorting algorithm

## Requirements

### General

-   Allowed editors: `vi`, `vim`, `emacs`
-   All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
-   You are not allowed to use global variables
-   No more than 5 functions per file
-   Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like _printf, puts, …_ is totally forbidden.
-   In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
-   The prototypes of all your functions should be included in your header file called `sort.h`
-   Don’t forget to push your header file
-   All your header files should be include guarded
-   A list/array does not need to be sorted if its size is less than 2.

### Data Structure and Functions

-   For this project you are given the following `print_array`, and `print_list` functions:

```
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```

```
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```

-   Our files `print_array.c` and `print_list.c` (containing the `print_array` and `print_list` functions) will be compiled with your functions during the correction.
-   Please declare the prototype of the functions `print_array` and `print_list` in your `sort.h` header file
-   Please use the following data structure for doubly linked list:

```
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

Please, note this format is used for Quiz and Task questions.

-   `O(1)`
-   `O(n)`
-   `O(n!)`
-   n square -> `O(n^2)`
-   log(n) -> `O(log(n))`
-   n \* log(n) -> `O(nlog(n))`
-   n + k -> `O(n+k)`
-   …

Please use the “short” notation (don’t use constants). Example: `O(nk)` or `O(wn)` should be written `O(n)`. If an answer is required within a file, all your answers files must have a newline at the end.

### Tests

Here is a quick tip to help you test your sorting algorithms with big sets of random integers: [Random.org](https://intranet.alxswe.com/rltoken/YR-VWQbICB59wZs1eAaI3w "Random.org")


#### Question #0

What is the time complexity of searching for an element in an unsorted array of size n?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #1

What is the time complexity of removing at index n from an unsorted Python 3 list?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #2

What is the time complexity of inserting at index n on an unsorted array?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #3

What is the time complexity of accessing the nth element of a singly linked list?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #4

What is the time complexity of accessing the nth element of a doubly linked list?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #5

Assuming you have a pointer to the node to remove, what is the time complexity of removing the nth element of a doubly linked list?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #6

What is the time complexity of removing the nth element of a singly linked list? (Assuming you have a pointer to the node to remove)

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #7

What is the best case time complexity searching for an element in a hash table with the implementation you used during the previous Hash Table C project (chaining)?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #8

What is the time complexity of searching for an element in a doubly linked list of size n?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #9

What is the time complexity of this function / algorithm?

```
foreach($numbers as $number)
{
    echo $number;
}
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #10

What is the time complexity of searching for an element - worst case - in a hash table with the implementation you used during the previous Hash Table C project (chaining)?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #11

What is the time complexity of accessing the nth element on an unsorted array?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #12

What is the time complexity of inserting into an unsorted Python 3 list at index n?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #13

What is the time complexity of worst case deletion from a hash table with the implementation you used during the previous Hash Table C project (chaining)?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #14

What is the time complexity of inserting after the nth element of a singly linked list? (Assuming you have a pointer to the node to insert)

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #15

What is the time complexity of this function / algorithm?

```
int Fibonacci(int number)
{
    if (number <= 1) return number;

    return Fibonacci(number - 2) + Fibonacci(number - 1);
}
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #16

What is the time complexity of “pushing” an element into a queue if you are given a pointer to both the head and the tail of the queue?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #17

What is the time complexity of this function / algorithm?

```
void f(int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (j = 1; j < n; j = j * 2)
            {
                printf("[%d] [%d]\n", i, j);
            }
        }
        else
        {
            for (j = 0; j < n; j = j + 2)
            {
                printf("[%d] [%d]\n", i, j);
            }
        }
    }
}
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #18

What is the time complexity of “popping” an element in a queue if you are given a pointer to both the head and the tail of the queue?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(log(n))
    
-   O(2^n)
    
-   O(nlog(n))
    

#### Question #19

What is the time complexity of this function / algorithm?

```
var factorial = function(n) {
    if(n == 0) {
        return 1
    } else {
        return n * factorial(n - 1);
    }
}
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #20

What is the time complexity of searching for an element in a stack of size n?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #21

What is the time complexity of setting a value at index n in an unsorted array?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #22

Assuming you have a pointer to the node to set the value of, what is the time complexity of setting the value of the nth element in a doubly linked list?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #23

What is the worst case time complexity of insertion in a hash table with the implementation you used during the previous Hash Table C project (chaining)?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #24

What is the time complexity of the “push” operation onto a stack?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #25

Assuming you have a pointer to the node to insert, what is the time complexity of inserting after the nth element of a doubly linked list?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #26

What is the time complexity of best case deletion from a hash table with the implementation you used during the previous Hash Table C project (chaining)?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #27

What is the time complexity of this function / algorithm?

```
void f(unsigned int n)
{
    int i;

    for (i = 1; i < n; i = i * 2)
    {
        printf("[%d]\n", i);
    }
}
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #28

What is the time complexity of searching for an element in an unsorted Python 3 list of size n?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #29

What is the time complexity of the “pop” operation onto a stack?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #30

What is the time complexity of this function / algorithm?

```
def func(n):
    a=5
    b=6
    c=10
    for i in range(n):
        for j in range(n):
            x = i * i
            y = j * j
            z = i * j
    for k in range(n):
        w = a*k + 45
        v = b*b
    d = 33
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #31

What is the best case time complexity of insertion in a hash table with the implementation you used during the previous Hash Table C project (chaining)?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #32

What is the time complexity of setting value at index n in an unsorted Python 3 list?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #33

What is the time complexity accessing the nth element in an unsorted Python 3 list?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #34

What is the time complexity of setting the value of the nth element in a singly linked list? (Assuming you have a pointer to the node to set the value of)

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #35

What is the time complexity of this function / algorithm?

```
void f(int n)
{
    printf("n = %d\n", n);
}
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #36

What is the time complexity of this function / algorithm?

```
void f(unsigned int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n; j = j * 2)
        {
            printf("[%d] [%d]\n", i, j);
        }
    }
}
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #37

What is the time complexity of this function / algorithm?

```
void f(int n)
{
    int i;

    for (i = 0; i < n; i += 98)
    {
        printf("[%d]\n", i);
    }
}
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #38

What is the time complexity of this function / algorithm?

```
void f(int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("[%d]\n", i);
    }
}
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #39

What is the time complexity of searching for an element in a singly linked list of size n?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #40

What is the time complexity of searching for an element in a queue of size n if you are given a pointer to both the head and the tail of the queue?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #41

What is the time complexity of removing at index n in an unsorted array?

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

#### Question #42

What is the time complexity of this function / algorithm?

```
void f(int n)
{
     int i;
     int j;

     for (i = 0; i < n; i++)
     {
          for (j = i + 1; j < n; j++)
          {
               printf("[%d] [%d]\n", i, j);
          }
     }
}
```

-   O(1)
    
-   O(n!)
    
-   O(n)
    
-   O(n^2)
    
-   O(nlog(n))
    
-   O(log(n))
    
-   O(2^n)
    

## Tasks

### 0\. Bubble sort

mandatory

<iframe width="560" height="315" src="https://www.youtube.com/embed/lyZQPjUT5B4" frameborder="0" allowfullscreen=""></iframe>  
  

Write a function that sorts an array of integers in ascending order using the [Bubble sort](https://intranet.alxswe.com/rltoken/awhP8BhtkGi-lwmMc2-KAw "Bubble sort") algorithm

-   Prototype: `void bubble_sort(int *array, size_t size);`
-   You’re expected to print the `array` after each time you swap two elements (See example below)

Write in the file `0-O`, the big O notations of the time complexity of the Bubble sort algorithm, with 1 notation per line:

-   in the best case
-   in the average case
-   in the worst case

```
alex@/tmp/sort$ cat 0-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 0-bubble_sort.c 0-main.c print_array.c -o bubble
alex@/tmp/sort$ ./bubble
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 71, 99, 13, 52, 96, 73, 86, 7
19, 48, 71, 13, 99, 52, 96, 73, 86, 7
19, 48, 71, 13, 52, 99, 96, 73, 86, 7
19, 48, 71, 13, 52, 96, 99, 73, 86, 7
19, 48, 71, 13, 52, 96, 73, 99, 86, 7
19, 48, 71, 13, 52, 96, 73, 86, 99, 7
19, 48, 71, 13, 52, 96, 73, 86, 7, 99
19, 48, 13, 71, 52, 96, 73, 86, 7, 99
19, 48, 13, 52, 71, 96, 73, 86, 7, 99
19, 48, 13, 52, 71, 73, 96, 86, 7, 99
19, 48, 13, 52, 71, 73, 86, 96, 7, 99
19, 48, 13, 52, 71, 73, 86, 7, 96, 99
19, 13, 48, 52, 71, 73, 86, 7, 96, 99
19, 13, 48, 52, 71, 73, 7, 86, 96, 99
13, 19, 48, 52, 71, 73, 7, 86, 96, 99
13, 19, 48, 52, 71, 7, 73, 86, 96, 99
13, 19, 48, 52, 7, 71, 73, 86, 96, 99
13, 19, 48, 7, 52, 71, 73, 86, 96, 99
13, 19, 7, 48, 52, 71, 73, 86, 96, 99
13, 7, 19, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$ 
```

**Repo:**

-   GitHub repository: `sorting_algorithms`
-   File: `0-bubble_sort.c, 0-O`

Done?! Help

×

#### Learners who are done with "0. Bubble sort"

### 1\. Insertion sort

mandatory

<iframe width="560" height="315" src="https://www.youtube.com/embed/ROalU379l3U" frameborder="0" allowfullscreen=""></iframe>  
  

Write a function that sorts a doubly linked list of integers in ascending order using the [Insertion sort](https://intranet.alxswe.com/rltoken/GocxRKbPdsmERXeOHMCO2w "Insertion sort") algorithm

-   Prototype: `void insertion_sort_list(listint_t **list);`
-   You are not allowed to modify the integer `n` of a node. You have to swap the nodes themselves.
-   You’re expected to print the `list` after each time you swap two elements (See example below)

Write in the file `1-O`, the big O notations of the time complexity of the Insertion sort algorithm, with 1 notation per line:

-   in the best case
-   in the average case
-   in the worst case

```
alex@/tmp/sort$ cat 1-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 1-main.c 1-insertion_sort_list.c print_list.c -o insertion
alex@/tmp/sort$ ./insertion
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 71, 99, 13, 52, 96, 73, 86, 7
19, 48, 71, 13, 99, 52, 96, 73, 86, 7
19, 48, 13, 71, 99, 52, 96, 73, 86, 7
19, 13, 48, 71, 99, 52, 96, 73, 86, 7
13, 19, 48, 71, 99, 52, 96, 73, 86, 7
13, 19, 48, 71, 52, 99, 96, 73, 86, 7
13, 19, 48, 52, 71, 99, 96, 73, 86, 7
13, 19, 48, 52, 71, 96, 99, 73, 86, 7
13, 19, 48, 52, 71, 96, 73, 99, 86, 7
13, 19, 48, 52, 71, 73, 96, 99, 86, 7
13, 19, 48, 52, 71, 73, 96, 86, 99, 7
13, 19, 48, 52, 71, 73, 86, 96, 99, 7
13, 19, 48, 52, 71, 73, 86, 96, 7, 99
13, 19, 48, 52, 71, 73, 86, 7, 96, 99
13, 19, 48, 52, 71, 73, 7, 86, 96, 99
13, 19, 48, 52, 71, 7, 73, 86, 96, 99
13, 19, 48, 52, 7, 71, 73, 86, 96, 99
13, 19, 48, 7, 52, 71, 73, 86, 96, 99
13, 19, 7, 48, 52, 71, 73, 86, 96, 99
13, 7, 19, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$
```

**Repo:**

-   GitHub repository: `sorting_algorithms`
-   File: `1-insertion_sort_list.c, 1-O`

Done?! Help

×

#### Learners who are done with "1. Insertion sort"

### 2\. Selection sort

mandatory

<iframe width="560" height="315" src="https://www.youtube.com/embed/Ns4TPTC8whw" frameborder="0" allowfullscreen=""></iframe>  
  

Write a function that sorts an array of integers in ascending order using the [Selection sort](https://intranet.alxswe.com/rltoken/SEbg0fBEraioQcl-igvUSw "Selection sort") algorithm

-   Prototype: `void selection_sort(int *array, size_t size);`
-   You’re expected to print the `array` after each time you swap two elements (See example below)

Write in the file `2-O`, the big O notations of the time complexity of the Selection sort algorithm, with 1 notation per line:

-   in the best case
-   in the average case
-   in the worst case

```
alex@/tmp/sort$ cat 2-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    selection_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 
2-main.c 2-selection_sort.c print_array.c -o select
alex@/tmp/sort$ ./select
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

7, 48, 99, 71, 13, 52, 96, 73, 86, 19
7, 13, 99, 71, 48, 52, 96, 73, 86, 19
7, 13, 19, 71, 48, 52, 96, 73, 86, 99
7, 13, 19, 48, 71, 52, 96, 73, 86, 99
7, 13, 19, 48, 52, 71, 96, 73, 86, 99
7, 13, 19, 48, 52, 71, 73, 96, 86, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$
```

**Repo:**

-   GitHub repository: `sorting_algorithms`
-   File: `2-selection_sort.c, 2-O`

Done?! Help

×

#### Learners who are done with "2. Selection sort"

### 3\. Quick sort

mandatory

<iframe width="560" height="315" src="https://www.youtube.com/embed/ywWBy6J5gz8" frameborder="0" allowfullscreen=""></iframe>  
  

Write a function that sorts an array of integers in ascending order using the [Quick sort](https://intranet.alxswe.com/rltoken/_pBTrH0Xyo4BRmQn4CtnMg "Quick sort") algorithm

-   Prototype: `void quick_sort(int *array, size_t size);`
-   You must implement the `Lomuto` partition scheme.
-   The pivot should always be the last element of the partition being sorted.
-   You’re expected to print the `array` after each time you swap two elements (See example below)

Write in the file `3-O`, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:

-   in the best case
-   in the average case
-   in the worst case

```
alex@/tmp/sort$ cat 3-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 3-main.c 3-quick_sort.c print_array.c -o quick
alex@/tmp/sort$ ./quick
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

7, 48, 99, 71, 13, 52, 96, 73, 86, 19
7, 13, 99, 71, 48, 52, 96, 73, 86, 19
7, 13, 19, 71, 48, 52, 96, 73, 86, 99
7, 13, 19, 71, 48, 52, 73, 96, 86, 99
7, 13, 19, 71, 48, 52, 73, 86, 96, 99
7, 13, 19, 48, 71, 52, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$
```

**Repo:**

-   GitHub repository: `sorting_algorithms`
-   File: `3-quick_sort.c, 3-O`

Done?! Help

×

#### Learners who are done with "3. Quick sort"
