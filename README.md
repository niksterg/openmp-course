## OpenMP Examples
### Prof. N. Stergioulas


The following example programs introduce the main concepts of OpenMP step by step.

### Part 1

1. [**hello-world-parallel.c**](https://github.com/niksterg/openmp-course/blob/master/hello-world-parallel.c)  (the most basic hello world executed in parallel)

2. [**hello-world-parallel-id.c**](https://github.com/niksterg/openmp-course/blob/master/hello-world-parallel-id.c) (similar to 1. but the id of each thread and the total number of threads are also printed)

3. [**hello-world-parallel-id-func.c**](https://github.com/niksterg/openmp-course/blob/master/hello-world-parallel-id-func.c) (same result as 2. but a function is called to print in inside the parallel region)

4. [**hello-world-parallel-id-scope.c**](https://github.com/niksterg/openmp-course/blob/master/hello-world-parallel-id-scope.c) (same result as 2. but data scope is used in the parallel region)

5. [**table-add1-manual.c**](https://github.com/niksterg/openmp-course/blob/master/table-add1-manual.c) (add a number to each element of a table, using manual parallelization)

6. [**table-add1.c**](https://github.com/niksterg/openmp-course/blob/master/table-add1.c) (same result as 5. but with automatic work scheduling)

7. [**table-add1-combined.c**](https://github.com/niksterg/openmp-course/blob/master/table-add1-combined.c) (same result as 6. but with combined parralel region and for construct)

8. [**table-add1-wrong.c**](https://github.com/niksterg/openmp-course/blob/master/table-add1-wrong.c) (similar to 6. and 7. but giving wrong answer - find the error in the code!)

9. [**table-implicit-notpar.c**](https://github.com/niksterg/openmp-course/blob/master/table-implicit-notpar.c) (parallel execution gives wrong answer - find out why!)

10. [**table-sum.c**](https://github.com/niksterg/openmp-course/blob/master/table-sum.c) (computing the sum of all elements in a table)

11. [**table-sum-wrong.c**](https://github.com/niksterg/openmp-course/blob/master/table-sum-wrong.c) (similar to 10. but gives wrong answer - find the error in the code!)



![Image](src)


    function fancyAlert(arg) {
      if(arg) {
        $.facebox({div:'#foo'})
      }
    }

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/niksterg/openmp-course/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.
