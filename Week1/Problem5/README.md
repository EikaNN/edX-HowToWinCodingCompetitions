# Create a Team!

When you create a team to participate in programming competitions, not only a particular set of people plays an important role, but also how exactly the roles in the team are distributed among these people. For example, if one of the teammates knows algorithms very well, but is not perfect in programming, it is not wise for him/her to write most of the programs in the team.

Andrew decided to create a team to participate in programming competitions. He invited his classmates, Peter and Paul. Now they have a question of role distribution. Andrew thinks that there are three roles in the team: a "coder", a "mathematician", and a "tester". The ﬁrst of them should write programs, the second one should invent algorithms, and the third one should create tests for algorithms and programs.

As the guys know each other very well, it didn't take much time for them to determine, how good is every person in every role. Now, they have a 3x3 table, where the first row is for Andrew, the second row is for Peter, and the third one is for Paul. The columns correspond to the roles: first to a "coder", second to a "mathematician", third to a "tester". As an example, the number in the third column of the second row shows how good is Peter as a "tester".

How the guys want to distribute the roles in such a way that the team performs in a most efficient way. Of course, every person can take exactly one role, and every role should be occupied by exactly one person. The efficiency of the assignment where Andrew performs with the efficiency of *A*, Peter performs with the efficiency of *B* and Paul with *C*, is equal to √(*A<sup>2</sup>* + *B<sup>2</sup>* + *C<sup>2</sup>*).

Help Andrew, Peter and Paul to ﬁnd the role distribution with the maximum efficiency.

## Input

The input file contains three lines, each containing three integer numbers – the table which the guys constructed. All numbers are positive and do not exceed 1000.

## Output

Output one number – the maximum efficiency which this team may achieve by optimal role distribution. Any answer, which is different from the correct one by no more than 10<sup>−6</sup>, is accepted.

