# Sorting

Given a sequence of integer numbers. Your task is to sort it in a non-decreasing order using the mergesort algorithm.

In order to persuade us that you really use the mergesort algorithm, we ask you, after performing a merge of a certain interval, to print the endpoint indices and endpoint values of this interval.

## Input

In the ﬁrst line of the input ﬁle there is an integer *n* (1 ≤ *n* ≤ 2⋅10<sup>5</sup>), the number of elements in the sequence. The second line contains the sequence itself: *n* integer numbers not exceeding 10<sup>9</sup> by their absolute value.

## Output

The output ﬁle consists of several lines.

In the last line of the output ﬁle print the sequence after sorting. Separate the numbers by single white spaces.

All the previous lines should describe the results of merges, one per line. Every such line should contain four numbers: *I<sub>f</sub>* *I<sub>l</sub>* *V<sub>f</sub>* *V<sub>l</sub>*, where *I<sub>f</sub>* is the starting index of the just-merged interval, *I<sub>l</sub>* is its ending index, *V<sub>f</sub>* is the value of the ﬁrst element of the interval, *V<sub>l</sub>* is the value of the last element. Indices start with one, that is, 1 ≤ *I<sub>f</sub>* ≤ *I<sub>l</sub>* ≤ *n*.

As the interval of length one is sorted by definition, you are allowed to omit merge records when *I<sub>f</sub>* = *I<sub>l</sub>*.

If you print *I<sub>f</sub>* *I<sub>l</sub>* *X* *Y*, this means you have just merged a subsequence which corresponds to the [*I<sub>f</sub>* ; *I<sub>l</sub>*] subsequence of the original sequence. In your particular implementation, the real indices for the beginning and ending of this subsequence may vary, but we nevertheless ask you to use this numbering scheme.

Let us give an example: we sort the array [9, 7, 5, 8]. The recursive part of the mergesort (the SORT(*A*, *L*, *R*) procedure, where *A* is the sorted array, *L* is the index of the beginning of the interval to merge, *R* is the index of its ending) is called with *A* = [9,7,5,8], *L* = 1, *R* = 4 and will perform the following actions:

* split the interval [1; 4] into two parts, [1; 2] and [3; 4];
* call SORT(*A*, *L*=1, *R*=2):
    * split the interval [1; 2] into two parts, [1; 1] and [2; 2];
    * these parts have size 1, will not call SORT on them;
    * perform merging, after which *A* becomes [7,9,5,8];
    * print the merge record: *I<sub>f</sub>*=*L*=1, *I<sub>l</sub>*=*R*=2, *V<sub>f</sub>*=*A<sub>L</sub>*=7, *V<sub>l</sub>*=*A<sub>R</sub>*=9.
* call SORT(*A*, *L*=3, *R*=4):
    * split the interval [3; 4] into two parts, [3; 3] and [4; 4];
    * these parts have size 1, will not call SORT on them;
    * perform merging, after which *A* becomes [7,9,5,8];
    * print the merge record: *I<sub>f</sub>* = *L* = 3, *I<sub>l</sub>* = *R* = 4, *V<sub>f</sub>* = *A<sub>L</sub>* = 5, *V<sub>l</sub>* = *A<sub>R</sub>* = 8.
* perform merging, after which *A* becomes [5,7,8,9];
* print the merge record: *I<sub>f</sub>* = L = 1, *I<sub>l</sub>* = *R* = 4, *V<sub>f</sub>* = *A<sub>L</sub>* = 5, *V<sub>l</sub>* = *A<sub>R</sub>* = 9.

The merge descriptions can go in an arbitrary order, not necessary coinciding with the order they are performed. However, to improve performance, we recommend to print these descriptions as soon as possible, not storing them in memory. This is the reason why we ask to print the resulting array at the very end.

The correctness of the sorting scenario which you printed will be performed by a special checker program. Every correct mergesort, which splits a subsequence into two smaller subsequences (not necessary equal!), will be accepted if it manages to perform sorting within time and memory limits.