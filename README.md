# Network-Programming
Write a simple TCP iterative server and client to evaluate arithmetic expressions. The
client-server system has the following functionalities:
a. The client asks for an arithmetic expression from the user. The user enters an
arithmetic expression containing only positive integers and the binary operators +, -,
*, and /. The arithmetic expression can be at most 100 characters long. There is no spaces before and after the operators. For example, all of the following
are valid expressions to enter: “13+42*5”, “10+2/4”, “5+6-3”. Assume that all
operators have the same precedence and are left-associative.
b. The client sends the expression to the server. You should send only the
number of bytes needed to send the expression properly and not send the complete
buffer if not needed.
c. The server computes the expression and sends the integer back to the client.
d. The client displays the result on the screen. It then prompts the user to enter
the next expression.
e. The client terminates when the user enters a –1.
