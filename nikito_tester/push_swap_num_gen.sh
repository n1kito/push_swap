#!/bin/bash

# Usage: ./push_swap_num_gen $ARGUMENT
# > $ARGUMENT is how many numbers you want generated.

# This script generates an array of numbers, as long as the parameter passed during script call.
# The array will have no duplicates but might already be sorted, especially for very small arrays like 2 or 3.
# > In my Push_swap_tester script, the cases where lists are already sorted are ignored.
# For very long lists (500), this script takes a while and makes the tester pretty time consuming on slow computers. But it works ! :).

# Note: This script will never generate MIN_INT, I will fix this but my push_swap_tester already checks that MIN_INT is accepted and sorted, so I'm not loosing sleep over it.

for (( i = 0; i < $1; i++ ))
do
  echo $(( ( RANDOM % 2147483647 ) )) >> numbers # adds $1 random numbers to 'numbers' file, between 0 and INT_MAX.
done

paste -d'-\n' /dev/null - - < numbers > numberswithneg # adds '-' to every other number in 'numbers' and exports to 'numberswithneg'. Allows me to have negative numbers and lessens the chances of having duplicates.
cat numberswithneg > numbers # replaces content of 'numbers' with 'contentwithneg'.
sort numbers | uniq > numbersnoduplicates # removes duplicates from 'numbers' and outputs new list in 'numbersnoduplicates'.
cat numbersnoduplicates > numbers # replaces content of 'numbers' with 'numbers no duplicates'.

# now my numbers file might be less than what I need, if duplicates where removed I need to add some back.
len=$(cat numbers | wc -l)
while [ $len -lt $1 ] # while my file is less than $1ARGUMENT lines.
do
  echo $(( ( RANDOM % 2147483647 ) )) >> numbers # append numbers file with new number.
  sort numbers | uniq > numbersnoduplicates # sortes numbers file and mmoves all numbers that are not duplicates into numbersnoduplicates file.
  cat numbersnoduplicates > numbers # moves these back to numbers file.
  len=$(cat numbers | wc -l) # update len variable with new len before going back into the loop.
done

sort -R numbers > numbersrandom # puts my lines in a random order
cat numbersrandom | grep . > numbers # and moves all of that back to my main file, removing any blank lines with grep (I think some are added with the paste commande used to add '-' signs

# Remove unnecessary work files
rm numbersnoduplicates
rm numbersrandom
rm numberswithneg

cat numbers | perl -pe 'chomp if eof' | tr "\n" " " # formats the 'numbers' file into a line, the very last new line is removed and then all new lines are replaced by a space

rm numbers #removes numbers file as it's no longer in use
