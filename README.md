# bank_account
Calculate the amount earned in interest for different account types.

2 types of account are supported, one with interest only and the other with regular savings.

## Summarize the project and what problem it was solving.

The program was designed to produce a table of the amount in a bank account, taking into account
the APR (annual percentage rate), and number of years, and initial deposit. A second type of account, assumes 
a monthly deposit in addition to the initial amount.

## What did you do particularly well?

The amount of code to support and extra type is very small, with a virtual method. So a fee based account could also
be added, when an annual fee is charged if the account has less than a certain amount.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

Adding factory methods to create different types of account, and only using them to input the additional parameters.

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The initial code was developed to match the test cases, and then merging the code between the 2 different classes.

## What skills from this project will be particularly transferable to other projects or course work?

Refactoring code to eliminate code reuse.

## How did you make this program maintainable, readable, and adaptable?

The same code is used for each instance, with a virtual method providing monthly updates.
