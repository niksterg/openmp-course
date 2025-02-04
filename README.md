## OpenMP Examples
### Prof. N. Stergioulas
### Aristotle University of Thessaloniki


### Example programs

The following example programs introduce the main concepts of OpenMP step by step.


1. [**hello-world-parallel.c**](https://github.com/niksterg/openmp-course/blob/master/hello-world-parallel.c)  (the most basic hello world executed in parallel)

2. [**hello-world-parallel-id.c**](https://github.com/niksterg/openmp-course/blob/master/hello-world-parallel-id.c) (similar to 1. but the id of each thread and the total number of threads are also printed)

3. [**hello-world-parallel-id-func.c**](https://github.com/niksterg/openmp-course/blob/master/hello-world-parallel-id-func.c) (same result as 2. but a function is called to print inside the parallel region)

4. [**hello-world-parallel-id-scope.c**](https://github.com/niksterg/openmp-course/blob/master/hello-world-parallel-id-scope.c) (same result as 2. but data scope is used in the parallel region)

5. [**table-add1-manual.c**](https://github.com/niksterg/openmp-course/blob/master/table-add1-manual.c) (add a number to each element of a table, using manual parallelization)

6. [**table-add1.c**](https://github.com/niksterg/openmp-course/blob/master/table-add1.c) (same result as 5. but with automatic work scheduling)

7. [**table-add1-combined.c**](https://github.com/niksterg/openmp-course/blob/master/table-add1-combined.c) (same result as 6. but with combined parallel region and for construct)

8. [**table-add1-wrong.c**](https://github.com/niksterg/openmp-course/blob/master/table-add1-wrong.c) (similar to 6. and 7. but giving wrong answer - find the error in the code!)

9. [**table-implicit-notpar.c**](https://github.com/niksterg/openmp-course/blob/master/table-implicit-notpar.c) (parallel execution gives wrong answer - find out why!)

10. [**table-sum.c**](https://github.com/niksterg/openmp-course/blob/master/table-sum.c) (computing the sum of all elements in a table)

11. [**table-sum-wrong.c**](https://github.com/niksterg/openmp-course/blob/master/table-sum-wrong.c) (similar to 10. but gives wrong answer - find the error in the code!)

### Exercises

[**2020 Homework on 2D wave equation**](https://github.com/niksterg/openmp-course/blob/master/OpenMP-set-2020.pdf)

[**2019 Homework on Poisson solvers**](https://github.com/niksterg/openmp-course/blob/master/OpenMP-set-2019.pdf) (see [this figure](https://www.researchgate.net/profile/Chhote-Shah/publication/336512640/figure/fig2/AS:922552943792128@1596965170203/Red-Black-ordering-technique-and-implementation-of-the-SOR-algorithm-a-updating-the.png)) 

[**poisson-SOR.c**](https://github.com/niksterg/openmp-course/blob/master/poisson-SOR.c) Example: ./poisson-SOR -N 400 -M 400 -a 1e-6 -o 1.9


**2023/24 Homework:**

**Set #1:** 
- Run the examples 1 - 10. 
- Find and correct the mistakes in examples 8, 9 and 11.

**Set #2:** 

- Write a code in C/C++ that calculates π using a Monte-Carlo method. Use up to 10^10 points.
- Parallelize the code using OpenMP. Run the code using 1, 2, 4, etc. threads (up to twice the physical number of cores, try at least up to 8).
- Create a Jupyter python notebook within which you automatically run the C/C++ code using different number of cores (use a list) and plot the execution time as a function of the number of cores. Alternatively, run the C/C++ code using a script, save the results in a file and load them into a Jupyter notebook to make the plot.
- In the same notebook, create a second plot of parallel speedup vs number of cores.
- Use [Amdahl's law](https://en.wikipedia.org/wiki/Amdahl%27s_law) to fit the resulting curve and find the proportion p of the code that benefits from parallelization and the maximum possible speedup in the limit of 10000 cores. (You can do the fit with e.g. spipy's curvefit.)
- Run the code for 10^2, 10^3, 10^4, ... , 10^11 points and, in a second notebook, calculate the convergence rate of your Monte-Carlo implementation. You can do this if you fit a line in a log-log- plot of the error in calculating π vs. the number of points. Try to find what the theoretical expectation is and compare your result to it.

Use logarithmic scale wherever the numerical values change by orders of magnitude!

(Bonus track: repeat with Python+Numba and/or Julia)

**2024/25**

Example code: [2D Laplace equation](https://github.com/niksterg/openmp-course/blob/master/laplace2D.c) with OpenMP

### Tutorials

1. [Tutorial by N. Trifonidis (part 1)](http://www.astro.auth.gr/~niksterg/courses/progtools/1-OpenMP-tutorial.pdf) 
2. [Tutorial by N. Trifonidis (part 2)](http://www.astro.auth.gr/~niksterg/courses/progtools/2-OpenMP-tutorial.pdf) 
3. [A brief introduction by A. Kiessling](http://www.roe.ac.uk/ifa/postgrad/pedagogy/2009_kiessling.pdf)
4. [Tutorial by S.C. Huang](https://idre.ucla.edu/sites/default/files/intro-openmp-2013-02-11.pdf)
5. [Tutorial by Texas A&M](https://people.math.umass.edu/~johnston/PHI_WG_2014/OpenMPSlides_tamu_sc.pdf)
6. [Tutorial by T. Mattson and L. Meadows](http://www.openmp.org/wp-content/uploads/omp-hands-on-SC08.pdf)
7. [Tutorial by Y. W. Li (includes Vtune examples)](https://permalink.lanl.gov/object/tr?what=info:lanl-repo/lareport/LA-UR-20-23416) 
8. [Online tutorial by B. Barney](https://computing.llnl.gov/tutorials/openMP/)
9. [Online tutorial by Y. Yliluoma](https://bisqwit.iki.fi/story/howto/openmp/)
10. [Online list of potential mistakes](https://www.viva64.com/en/a/0054/)
11. [Video tutorial by C. Terboven (part 1)](https://www.youtube.com/watch?v=6FMn7M5jxrM)
12. [Video tutorial by C. Terboven (part 2)](https://www.youtube.com/watch?v=Whq28OaPW08)
13. [Video channel by PPCES](https://www.youtube.com/channel/UCtdrEoe46tD2IvJJRs_JH1A)
14. [Additional resources](https://www.openmp.org/resources/tutorials-articles/)
15. [OpenMP 3.1 Quick Reference Card](https://www.openmp.org//wp-content/uploads/OpenMP3.1-CCard.pdf)



### License

##### Content provided under a Creative Commons Attribution license, [CC BY-NC-SA 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/); code under [MIT License](https://opensource.org/licenses/MIT). (c)2018 [Nikolaos Stergioulas](http://www.astro.auth.gr/~niksterg/)

