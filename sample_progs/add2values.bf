Brainf*ck program to add and print two 1 digit numbers seperated by space (Undefined result if answer is 2 digit number)
for eg: "4 5"
Author: Siddhesh Dharme

>             C1
++++++        C1 = 6
[-<++++++++>] loop untill C0 = 48
,             C1 = input1 (ascii)
>,,           C2 = input2 (ascii)
[-<+>]        loop untill C1 = C1 (plus) C2
<<            go to C0
[->-<]        loop untill C1 = C1 (minus) 48
>.            go to C1 and print
