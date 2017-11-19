# K-th Ordered Statistic

You are given a sequence of *n* integers. Which of these numbers are *k<sub>1</sub>*-th, (*k<sub>1</sub>*+1)-st, ..., *k<sub>2</sub>*-th in this sequence when it is sorted?

## Input

In the ﬁrst line of the input ﬁle there are three integers: *n*, the sequence size, and *k<sub>1</sub>* and *k<sub>2</sub>*, the interesting interval boundaries. (2 ≤ *n* ≤ 4⋅10<sup>7</sup>, 1 ≤ *k<sub>1</sub>* ≤ *k<sub>2</sub>* ≤ *n*, *k<sub>2</sub>*−*k<sub>1</sub>* < 200).

The second line of the input ﬁle contains integers *A*, *B*, *C*, *a<sub>1</sub>*, *a<sub>2</sub>*, which do not exceed 10<sup>9</sup> by the absolute value. You have to generate the input sequence elements, starting with the third one, using the following expression: *a<sub>i</sub>* = *A*⋅*a<sub>i-2</sub>* + *B*⋅*a<sub>i-1</sub>* + *C*. All computations should be performed in a 32-bit integer type, all overﬂows should be ignored.

Please pay attention that an array of 4⋅10<sup>7</sup> 32-bit integers takes 160 megabytes of memory!

## Output

In the ﬁrst and only line of the output ﬁle print the *k<sub>1</sub>*-th, (*k<sub>1</sub>*+1)-st, …, *k<sub>2</sub>*-th in the sorted order numbers from the sequence *a*. Separate the numbers by single white spaces.

