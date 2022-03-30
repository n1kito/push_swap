#!/bin/bash

# Usage: ./push_swap_tester.sh $ARGUMENT 
# > $ARGUMENT is the number of tests you want done.

# If your push_swap program is not in the parent directory, change the PROGRAM_PATH variable.
# And if for some mysterious reason your program is not named "push_swap", change the PROGRAM variable.

# -TODO JE NE VERIFIE QUE LA STRING "Error" et pas "Error\n" pour les tests d'erreur, si je mets le \n ca marche pas. Je préfèrerais que ca teste ca aussi.
# -TODO J'ARRIVE PAS A FAIRE MARCHER LE TEST 6 (et les tests avec des double quotes) il me met erreur mais je pige pas pourquoi
# -TODO Pour les tests ou il ne doit rien renvoyer je dois check le stderr et le std out. Pareil pour les tests ou il doit renvoyer quelque chose, je dois rien avoir en stderr.

################################################################################
##                             USEFUL VARIABLES                               ##
################################################################################

NUMBER_OF_TESTS=$1
PROGRAM_PATH=".." # LOCATION OF THE PROGRAM
PROGRAM="push_swap"

ERROR="Error\n"

TEST_COUNT=0
TEST_PASSED=0

## COLORS
################################################################################

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

## TITLE
################################################################################

TITLE="
 ██▓███   █    ██   ██████  ██░ ██              ██████  █     █░ ▄▄▄       ██▓███
▓██░  ██▒ ██  ▓██▒▒██    ▒ ▓██░ ██▒▒           ██    ▒ ▓█░ █ ░█░▒████▄    ▓██░  ██▒
▓██░ ██▓▒▓██  ▒██░░ ▓██▄   ▒██▀▀██░░            ▓██▄   ▒█░ █ ░█ ▒██  ▀█▄  ▓██░ ██▓▒
▒██▄█▓▒ ▒▓▓█  ░██░  ▒   ██▒░██ ░██              ▒   ██▒░█░ █ ░█ ░██▄▄▄▄██ ▒██▄█▓▒ ▒
▒██▒ ░  ░▒▒█████▓ ▒██████▒▒░▓█▒░██▓▒ ▓▒█████░▓ ██████▒▒░░██▒██▓  ▓█   ▓██▒▒██▒ ░  ░
▒▓▒░ ░  ░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒▒ ▒▓▒ ▒▓▒  ▒ ░░ ▓░▒ ▒   ▒▒   ▓▒█░▒▓▒░ ░  ░
░▒ ░     ░░▒░ ░ ░ ░ ░▒  ░ ░ ▒ ░▒░ ░░ ░▒  ░▒░  ░ ░  ▒ ░ ░    ▒   ▒▒ ░░▒ ░
░░        ░░░ ░ ░ ░  ░  ░   ░  ░░ ░░  ░   ░   ░    ░   ░    ░   ▒   ░░
            ░           ░   ░  ░  ░       ░   ░      ░          ░  ░
                               \e[2m(tester by nikito)\e[22m
"

################################################################################
##                                   TESTS                                    ##
################################################################################

## TESTS THAT SHOULD RETURN NOTHING
################################################################################
TEST_NO_RETURN[0]="1" # List is sorted, nothing happens
TEST_NO_RETURN[1]="1 2 3" # List is sorted, nothing happens
TEST_NO_RETURN[2]="-1" # List is sorted, nothing happens
TEST_NO_RETURN[3]="+1" # List is sorted, nothing happens
TEST_NO_RETURN[4]="+2147483647" # INT_MAX, nothing happens
TEST_NO_RETURN[5]="-2147483648" # INT_MIN, nothing happens
#TEST_NO_RETURN[6]="1 2 3 \"4 5 6\"" # List is sorted, nothing happens <- This one does not work

## TESTS THAT SHOULD LAUNCH PUSH_SWAP AND RETURN OPERATIONS
################################################################################
TEST_RETURNS_OPERATIONS[0]="1 2 3 -4" # List it not sorted
TEST_RETURNS_OPERATIONS[1]="-4 0 5 3" # List it not sorted
TEST_RETURNS_OPERATIONS[2]="4 3 \"2 1\"" # Arguments in quotes
#TEST_RETURNS_OPERATIONS[3]="4 3 \" 2 1 \"" # Arguments in quotes with extra spaces
#TEST_RETURNS_OPERATIONS[4]="4 3 \"4 0001\"" # Arguments in quotes with extra zeros
#TEST_RETURNS_OPERATIONS[5]="4 3 \"2      1\"" # Arguments in quotes with extra extra spaces

## TESTS THAT SHOULD RETURN AN ERROR
################################################################################
TEST_RETURNS_ERROR[0]="+2147483648" # > INT_MAX, returns Error
TEST_RETURNS_ERROR[1]="-2147483649" # < INT_MIN, returns Error
TEST_RETURNS_ERROR[2]="-" # Char, returns error
TEST_RETURNS_ERROR[3]="+" # Char, returns error
TEST_RETURNS_ERROR[4]="1234b" # Char, returns error
TEST_RETURNS_ERROR[5]="1 2 34b" # Char, returns error
TEST_RETURNS_ERROR[6]="\"\"" # Devrait me mettre une erreur puisaue le test suivant m'en met une
TEST_RETURNS_ERROR[7]="1 2 3 4 3" # Duplicate, returns error
TEST_RETURNS_ERROR[8]="1 2 3 \"4 5 6 1\"" # Duplicate, returns error
TEST_RETURNS_ERROR[9]="1 2 3-4" # Formating error, returns error
TEST_RETURNS_ERROR[10]="\"--4 4\" 5 3" # Double negative sign, returns error
TEST_RETURNS_ERROR[11]="\"-4 4\" 5 4" # Duplicate, returns error

################################################################################
##                                  HEADER                                    ##
################################################################################

# CHECK IF PROGRAM EXISTS, RUN MAKE IF IT DOES NOT
#if ! command -v ${PROGRAM_PATH}/${PROGRAM} >/dev/null;
#then
#  printf "push_swap not found in parent folder.\nCompiling push_swap..."
  make -C ${PROGRAM_PATH}
#fi

## DISPLAY TITLE
clear -x # clears screen, equals to CTRL + L in Terminal
printf "${TITLE}"

################################################################################
##                           ARGUMENT PARSING TESTS                           ##
################################################################################

echo
printf "###################################################################################"
echo
printf "#                               ARGUMENT PARSING TESTS                            #"
echo
printf "###################################################################################"

printf "\n\e[4mArgument parsing:\e[24m\n"

## TESTS THAT SHOULD RETURN NOTHING
################################################################################

printf "\nshould return nothing: "
for i in "${!TEST_NO_RETURN[@]}";
do
  RESULT=$(${PROGRAM_PATH}/${PROGRAM} "${TEST_NO_RETURN[$i]}") # SETS TEST RESULT TO VARIABLE $RESULT
    if [ -z "$RESULT" ] # CHECKS IF VARIABLE IS EMPTY
    then
          printf "${GREEN}OK${NC} " # IF VARIABLE IS EMPTY, MEANS PROGRAM DID NOT RETURN ANYTHING AND IS OK
         (( TEST_PASSED++ ))
         (( TEST_COUNT++ ))
    else
         printf "${RED}Error${NC} (Test %s <%s> returned <%s>) " "$i" "${TEST_NO_RETURN[$i]}" "${RESULT}" # IF PROGRAM RETURNED SOMETHING, TEST FAILS AND SHOWS WHAT WAS TESTED
         (( TEST_COUNT++ ))
    fi
done

## TESTS THAT SHOULD LAUNCH PUSH_SWAP AND RETURN OPERATIONS
################################################################################

printf "\nshould return operations: "
for j in "${!TEST_RETURNS_OPERATIONS[@]}"
do
  RESULT=$(${PROGRAM_PATH}/${PROGRAM} "${TEST_RETURNS_OPERATIONS[$j]}") # SETS TEST RESULT TO VARIABLE $RESULT
    if [ "$RESULT" != "Error" ] || [ -z "$RESULT" ] # CHECKS IF VARIABLE IS EMPTY OR RETURNED AN ERROR
    then
          printf "${GREEN}OK${NC} " # IF VARIABLE IS EMPTY, MEANS PROGRAM DID NOT RETURN ANYTHING AND IS OK
         (( TEST_PASSED++ ))
         (( TEST_COUNT++ ))
    else
          printf "${RED}Error${NC} (Test %s <%s> returned <%s>) " "$j" "${TEST_RETURNS_OPERATIONS[$j]}" "${RESULT}" # IF PROGRAM RETURNED SOMETHING, TEST FAILS AND SHOWS WHAT WAS TESTED
         (( TEST_COUNT++ ))
    fi
done

## TESTS THAT SHOULD RETURN AN ERROR
################################################################################

printf "\nshould return error: "
for k in "${!TEST_RETURNS_ERROR[@]}"
do
  RESULT=$(${PROGRAM_PATH}/${PROGRAM} "${TEST_RETURNS_ERROR[$k]}" 2>&1 >/dev/null ) # SETS TEST RESULT TO VARIABLE $RESULT
    if [ "$RESULT" = "Error" ] # CHECKS THAT VARIABLE IS "ERROR"
    then
          printf "${GREEN}OK${NC} " # IF VARIABLE IS EMPTY, MEANS PROGRAM DID NOT RETURN ANYTHING AND IS OK
         (( TEST_PASSED++ ))
         (( TEST_COUNT++ ))
    else
          printf "${RED}Error !!${NC} (Test %s <%s> returned <%s>) " "$k" "${TEST_RETURNS_ERROR[$k]}" "${RESULT}" # IF PROGRAM RETURNED SOMETHING ELSE, TEST FAILS AND SHOWS WHAT WAS TESTED
         (( TEST_COUNT++ ))
    fi
done

echo
echo

printf "\e[4mTests passed:\e[24m\n"
if [ ${TEST_PASSED} -eq ${TEST_COUNT} ]
then
  printf "${GREEN}${TEST_PASSED}/${TEST_COUNT}${NC}"
else
  printf "${RED}${TEST_PASSED}${NC}/${TEST_COUNT}"
fi
echo
echo

################################################################################
##                               SORTING TESTS                                ##
################################################################################

printf "###################################################################################"
echo
printf "#                                   SORTING TESTS                                 #"
echo
printf "###################################################################################"

echo
echo

function test_push_swap
{
  parameter=$(./push_swap_num_gen.sh $1) # calls my num gen script using the first argument of this function call
  ../push_swap $parameter > results
  cat results | wc -l
}

function test_loop {
  for (( i = 1; i <= NUMBER_OF_TESTS; i++ ))
  do
    RESULT[$i]=$(test_push_swap $1)
	if [ "${RESULT[$i]}" -eq 0 ] # if the test returned zero means my list was already sorted so I'm decrementing my index so the test does not count
	then
		(( i-- )) # decrements index
	else
		printf "\e[2m> %s / %s\e[22m\r" "$i" "${NUMBER_OF_TESTS}" # else I'm printing the test number and total number of tests ran
	fi
  done
 echo
 MIN=0
 MAX=0
 AV=0
  for i in "${RESULT[@]}"; do
     (( $i > MAX || MAX == 0)) && MAX=$i
     (( $i < MIN || MIN == 0)) && MIN=$i
     if [ "i" > "0" ]
     then
       AV=$(((AV+i)/2))
     fi
 done

 echo "# Min = $MIN"
 echo "# Max = $MAX"
 echo "# Av. = $AV"
 echo
}

function launch_test {
	printf "\e[4mTesting %s numbers\e[24m\n" "$1";
	test_loop $1
}

#launch_test 2 # This might be a bit of an overkill.
launch_test 3
launch_test 5
launch_test 10
launch_test 100
launch_test 500

printf "All tests done :)\n"
printf '\7'

# Remove unnecessary files
# rm numbers
rm results
