# Homework 4
###  Due until 25.11., 8:30

This homework is divided into two parts. Part 1 is a very easy problem and you do
not have to submit it. Its only purpose is that you can check for yourself how
well you are doing with C++. Part 2 is a bit more tricky this week. You might need
more time than for the homework problems before.

***
### Part 1
This problem is meant as a check for yourself. Solving it requires basic concepts
we discussed in the lecture and used in the exercises so far. At this point you
should have no major problems in solving it. Your level of C++ syntax skills
should be sufficient to handle this problem without having to look up many things
in olderfiles or in the slides. This reflects the minimum C++ knowledge we expect
you to have at this point.

*Problem 1*:
Generate a static array of *N* random numbers. Fill in the numbers within an extra
function of your code, similar to the last homework. Write a second function which
finds the maximum and the minimum number stored in that array. Print the two
values from inside the `main()` function.

***

### Part 2

Assume we have discrete signal values *f[i],i=0,...,N-1* but unfortunately the
signal is very noisy. We come up with the idea of how we might reduce the noise:
We calculate g[i] = (f[i-1] + f[i] + f[i+1])/3 and thus replace every value by a
local average.

In the file **noisy.dat** there is such a signal. You can plot it in gnuplot to
see it. You will write a code that filters this signal. Files **to be submitted
are the code** for the program **and one plot** which shows your filtered result
versus the original unfiltered signal.

*Problem 2:* Write a program which reads the data from the file into an array,
filters the data according to the procedure described above and then writes the
results into a new file.

Structure your program well, in particular:
* Write a function which reads the data into an array.
  The current file has 237 lines, allocate sufficient memory *inside*
  your reading function. This requires dynamic allocation.
* Have one function which filters the data. Interpret the
  data as periodic function, i.e. f[N]=f[0]. Just like in previous
  programs, overwrite the original array and do not create a second
  array.  Note that once your code works, you can apply the filter
  function more than once to the data. It is interesting to see what
  happens to the data when you apply the filter several times.
* Write the final result inside an extra function into a file, do not
  overwrite the original data file.
* Make sure that all memory that has been allocated via `new` has
  been freed by a respective `delete`.

Once you have filtered the data, use gnuplot to compare the filtered
data and the original signal. Assuming that the filtered signal is in
`filtered.txt`, you can plot both signals via
```
gnuplot> set st data line
gnuplot> plot "noisy.txt", "filtered.txt"
```
You can save gnuplot plots into a file by the following sequence of commands:
```
gnuplot> set term png
gnuplot> set out "plot.png"
gnuplot> plot "noisy.txt", "filtered.txt"
```
This creates a file plot.png which contains your plot. Note, that after you
entered `set term png` nothing will be updated in your regular plot window.
Everything is directly sent to the .png file.


Final note: We will compile your code using the `-pedantic` flag, that is
`g++ filter.cxx -o filter -pedantic` to check that you are not using any compiler
specific C++ extensions. Hence, you should use `-pedantic` as well during the
development.
