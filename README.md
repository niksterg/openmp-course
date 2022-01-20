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

