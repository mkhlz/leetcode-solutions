# What exactly are we doing over here?

The problem gives you a string and a number of rows. What we have to do is convert it to a zigzag pattern

|   /|   /|   /|
|  / |  / |  / |
| /  | /  | /  |
|/   |/   |/   |

Psudedocode

If rows are one or rows are more than size of string, then no zigzag pattern
create array of required rows
create a variable for currentRow, set it to 0
create a boolean flag to store direction
Loop thru each character, add it to current row
    change direction if top of bottom row is reached
    move up or down based on direction
combine all rows into one string and return result