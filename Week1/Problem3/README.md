# Three-bonacci

This problem is about a funny extension of the well-known Fibonacci numbers, called Three-bonacci numbers. We define them as follows:

*T<sub>i</sub>* = *A<sub>0</sub>* if *i* = 0

*T<sub>i</sub>* = *A<sub>1</sub>* if *i* = 1

*T<sub>i</sub>* = *A<sub>2</sub>* if *i* = 2

*T<sub>i</sub>* = *T<sub>i-1</sub>* + *T<sub>i-2</sub>* - *T<sub>i-3</sub>* otherwise

We give you *A<sub>0</sub>*, *A<sub>1</sub>*, *A<sub>2</sub>* and *n*. Your task is to calculate T<sub>n</sub>.

## Input

The input file contains one line with four integer numbers, *A<sub>0</sub>*, *A<sub>1</sub>*, *A<sub>2</sub>*, and *n*. For these numbers, it holds that −10<sup>3</sup> ≤ *A<sub>0</sub>*, *A<sub>1</sub>*, *A<sub>2</sub>* ≤ 10<sup>3</sup> and 0 ≤ *n* ≤ 105.

## Output

Output T<sub>n</sub> in the first and only line of the output file.
