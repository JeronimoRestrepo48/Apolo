# Final Workshop

## Contents
- [Running](#running)
- [Recommendations](#recommendations)
- [Authors](#authors)

## Running

1. Access APOLO in the corresponding schedule.

2. At a terminal, run the following command:
    ```
    git clone https://github.com/JeronimoRestrepo48/Final-Workshop-Apolo.git
    ```

3. Go to the directory where you cloned the project:
    ```
    cd Final-Workshop-Apolo
    ```

4. Create a `bin` directory inside the root of the project:
    ```
    mkdir bin
    ```

5. Compile the `mmm_implementation.c` file inside the bin directory:
    ```
   gcc -fopenmp -mavx -O3 -o bin/mmm mmm_implementation.c
    ```

6. Run the program:
    - In APOLO:
        ```
        sbatch job.sh
        ```

    - In you pc:
        ```
        ./bin/mmm
        ```


**NOTE:** If you have the following message or something similar
```
[1]    2460040 segmentation fault (core dumped)  ./bin/mmm
```
It is because the program uses very long arrays, and it is probably a stack overflow problem that you can solve by executing:
```
ulimit -s unlimited
```
Run the program again and it should work. If any of these solutions help you, you can always contact us!

**NOTE:** by default, the program will create random arrays from `2x2` to `5000x5000`, and perform `50` tests. If you are going to run the program on your pc or perform tests in APOLO, we recommend that you change these parameters, for example:
```
#define N 10
#define MIN_SIZE 2
#define MAX_SIZE 1000
```
When you run the final test of the program, you should recover the original values:
```
#define N 50
#define MIN_SIZE 2
#define MAX_SIZE 5000
```

## Details 
With the objective of optimizing the matrix-matrix multiplication algorithm, parallelization with OpenMP was applied as the main strategy, using the respective libraries and directly modifying the code to improve the execution time and efficiency of the loops. Later, some specific flags were used to compile the code, which help improve execution with vectorization strategies. Here are some photos of the execution tests (with a normal computer and with APOLO)

## Authors
- Jerónimo Restrepo
