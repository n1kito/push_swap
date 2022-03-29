<p align="center">

<img src="img/Push_swap.png" alt="Push_swap">

</p>

---

<details><summary>see todo list</summary>

#### Gestion des cas d'erreur dans le parsing
- [x] Attention `./push_swap` sans arg ne renvoie rien il semblerait (**voir avec le checker**). Moi je renvoie une erreur.
  - C'est bon je ne renvoie rien. Pas d'arguments = liste triée wesh.
- [x] Int passé > `int max` ou < `int min`
- [x] Argument n'est pas un int
- [x] Plusieurs chiffres dans un string ""
- [x] Apparemment " " doit renvoyer Error, et " " 5 4 aussi.
- [x] Mais est-ce que "4 " 3 2 1 doit renvoyer 0 aussi ? Chez moi oui.
- [x] Int en double
  - Au lieu de faire une fonction séparée qui vérifiera ma liste une fois toutes les valeurs parsées, c'est ma fonction de parsing qui devra checker ça au fur et à mesure.
- [x] Créer une fonction ft_is_sorted qui verifie si la liste est deja triee et si c'est le cas je renvoie 0 puisqu'il m'y a rien a faire.

#### Détails techniques généraux
- [ ] Bien verifier que mes operations ne font rien quand elles ne sont pas censees (genre swap ou rotate une liste de 1)
- [ ] Attention, si je change un truc dans la libft et que je make avec mon makefile principal ca remake pas la libft. Il faut que je rajoute le make -C libft dans la make principal je pense.
- [ ] Faire les unit tests pour mes operations (push, rotate etc... Surtout avec les double linked lists)
- [ ] Idem pour lstlen
- [ ] Je crois que j'ai rien free du tout là. Mais normalement je perds rien donc je peux tout free à la fin.
  - Il faudra que je free: stack_b (?), la linked list the coûts dans chaque maillon de stack_a, et stack_a.
- [ ] Push_swap utils: too many functions in file
- [ ] J'ai un peu fait le fou dans ma fonction set_stack_as_sorted, verifier que ca fonctionne bien.
- [ ] Renomer ft_set_stack_as_sorted
- [x] Virer toutes les fonctions de la libft que je n'utilise pas !
- [ ] Virer le -g flag du makefile
</details>

---

# Introduction

The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted.  
You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

Write a program in C called push_swap which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts the integer arguments received.

This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions.

To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

---
# Rules & Requirements

<details>
<summary>Rules <i>(click to open)</i></summary>

The game is composed of **2 stacks** named `stack_a` and `stack_b`. 

To start with:
+ `stack_a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
+ `stack_b` is empty 

The **goal** is to sort in ascending order numbers into `stack_a`.

To do this you have the following **operations** at your disposal:
<br><br>

|       | Operation        | Description                                                                                      |
|-------|------------------|--------------------------------------------------------------------------------------------------|
| `sa`  | swap a           | swap the first 2 elements at the top of `stack_a`. Do nothing if there is only one or no elements) |
| `sb`  | swap b           | swap the first 2 elements at the top of `stack_b`. Do nothing if there is only one or no elements) |
| `ss`  | sa & sb          | at the same time.                                                                                |
| `pa`  | push a           | take the first element at the top of b and put it at the top of `stack_a`. Do nothing if `stack_b` is empty.     |
| `pb`  | push b           | take the first element at the top of `stack_a` and put it at the top of `stack_b`. Do nothing if `stack_a` is empty.     |
| `ra`  | rotate a         | shift up all elements of `stack_a` by 1. The first element becomes the last one.                   |
| `rb`  | rotate b         | shift up all elements of `stack_b` by 1. The first element becomes the last one.                   |
| `rr`  | `ra` & `rb`      | at the same time.                                                                                |
| `rra` | reverse rotate a | shift down all elements of `stack_a` by 1. The last element becomes the first one.                 |
| `rrb` | reverse rotate b | shift down all elements of `stack_b` by 1. The last element becomes the first one.                 |
| `rrr` | `rra` & `rrb`    | at the same time.                                                                                |

### Error handling

In case of error, you must display `Error` followed by a `\n` on the standard error.

**Errors include for example:**
- [x] some arguments aren’t integers
- [x] some arguments are bigger than an integer
- [x] there are duplicates.

</details>

<details>
<summary>Requirements <i>(click to open)</i></summary>

| Item                | Requirement                                                                                                                                                                                      |
|:--------------------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Files to submit** | This project will only be corrected by actual human beings.<br/>You are therefore free to organize and name your files as you wish, although you need to respect some requirements listed below. |
| Makefile            | The Makefile needs to compile the project and must contain the usual rules.<br/>It can only recompile the program if necessary.                                                                  |
| Libft allowed       | Yes                                                                                                                                                                                              |
| Functions allowed   | write, read, malloc, free, exit                                                                                                                                                                  |
| Learning objectives | Rigor<br/>Use of C<br/>Use of basic algorithms                                                                                                                                                   |
</details>

---
# My Approach

I divided my code into several algorithms depending on how many numbers are added to `stack_a`.

### For lists of `2`

A function just swaps the numbers.

### For lists of `3`

I treat all cases possible here, there are only 5 so one function is enough.

| #1 	 |     #2 	     | #3 	| #4 	| #5 	| #6 	|
|:----:|:------------:|:---:	|:---:	|:---:	|:---:	|
| 1 	  |     3 	      | 2 	| 3 	| 1 	| 2 	|
| 2 	  |     2 	      | 1 	| 1 	| 3 	| 3 	|
| 3 	  |     1 	      | 3 	| 2 	| 2 	| 1 	|
| ⭐	  |`sa`<br>`rra` 	 | `sa` 	| `ra` 	| `sa`<br>`ra` 	| `rra` 	|


### For longer lists

<p align="center">
(<b>List</b>: 100 – <b>Operations</b>: 551)
<br><br>
<img src="img/push_swap_100_551ops(fast).gif" alt="Push_swap 100 numbers 551 operations">
</p>

My algorithm is based on cost calculation mixed with a selection sort.  

I will use the cost calculation sort until `stack_a` is down to the 10 biggest numbers in the range, then I will selection sort these 10 numbers before pushing everything back from `stack_b` to `stack_a`.

Here is how it works:
+ Push one number to `stack_b` (that is _not_ in the 10 biggest numbers of the range)
+ While `stack_a->len` > 10, use a `push_cheapest()` function:
  + If `number` is in the 10 biggest of `stack_a`, I attribute it a very high cost so it won't be moved.
  + Otherwise, I calculate the cost not only to push it from `stack_a` to `stack_b`, but also to prepare `stack_b` to receive it.
    + For `stack_b` to be prepared to receive a number from `stack_a` and have it be sorted, the **last** number in `stack_b` has to be the one that is directly bigger than the number we're trying to push. **Unless** the number I'm trying to push is the highest number of the stack, then I need the last number in `stack_b` to be its smallest number.
  + I then push the cheapest one of those numbers until `stack_a` has a len of 10 && `stack_b` is sorted from biggest to smallest.
+ Since `stack_a` now only has 10 numbers, I use selection sort to sort them from biggest to smallest in `stack_a`
+ Finally, I push everything back to `stack_a`.

**Why use selection sort when `stack_a` is <= 10 ?**  
Because when `stack_b` is very big, the cost to prepare it to receive numbers from `stack_a` is very high.  
Using selection sort in that case allowed be to use less operations.



# Algorithm Efficiency

<table><thead><tr><th rowspan="3">List length<br></th><th colspan="4">Operations</th></tr><tr><th rowspan="2">Max allowed<br> to get bonus</th><th colspan="3">My algorithm<br/>(10.000 tests)</th></tr><tr><th>Average</th><th>Min</th><th>Max</th></tr></thead><tbody><tr><td><b>3</b></td><td>3</td><td>1</td><td>0</td><td>2</td></tr><tr><td><b>5</b></td><td>12</td><td>6</td><td>0</td></td><td>10</td></tr><tr><td><b>100</b></td><td>700</td><td>584</td><td>497</td><td>686</td></tr><tr><td><b>500</b></td><td>5500</td><td>5228</td><td>4847</td><td>5636</td></tr></tbody></table>

### Possible improvements

#### Speed

For the cost calculation function that runs after every push from `stack_a` to `stack_b`, I might want to only calculate cost on the first & last _n_ numbers in the stack, the ones close*ish* to the top/bottom of the list and easiest to push to `stack_b`.  
I might be able to assume that a number right in the middle of a `stack_a` of 500 numbers will **never** be the cheapest to push.  
But that would only improve runtime and not the number of operations used to sort the stacks.

---

# Error Handling

<details><summary>Argument parsing</summary>

-1 (ok)  
+1 (ok)  
+2147483647 (ok)  
-2147483648 (ok)  
+2147483648 (error car > max int)  
-2147483649 (error car < min int)  
-/+ seuls (doit renvoyer une erreur)  
123432b (error)  
"1 3 4354j" (error)  
"" (pas d'erreur, ne renvoie rien)  
" " (pas d'erreur, ne renvoie rien)  
1 2 3 4 3 (error)  
1 2 3 "4 5 6" (ok)  
1 2 3 "4 5 6 1" (error)  
1 2 3 -4 (ok)  
1 2 3-4 (error)  
"-4 4" 5 4 (error)  
" " 5 4 (ok)
"  " 5 4 (ok)   
"  4" 3 2 (ok)
</details>

---

# Useful testers


⭐⭐ [Quickly runs many tests with goal number of operations, precision, and uses checkers](https://github.com/SimonCROS/push_swap_tester)  
⭐ [Test aussi l'input des arguments](https://github.com/ael-bekk/push_swap_tester)  
[Tests using checker](https://github.com/izenynn/push_swap_tester)  
[42_Corrections](https://github.com/Binary-Hackers/42_Corrections)

🌈 [Push_Swap visualizer](https://github.com/o-reo/push_swap_visualizer.git)

## Checking for leaks on Mac_OS

```C
// add this line in main function, right before return:
system("leaks push_swap");
```
If you have leaks and want to track their origin(s):
```shell
# in the terminal:
export MallocStackLogging=1

# j'ai pas encore pigé comment désactiver l'option, quand je refais avec =0 bah ça continue.
```

---

<p align="center">
<br />
<img src="https://forthebadge.com/images/badges/made-with-c.svg" alt="Made with CSS badge"/>
</p>
