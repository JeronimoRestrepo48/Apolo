# Final Workshop

## Contents
- [Running](#running)
- [Recommendations](#recommendations)
- [Authors](#authors)

## Running

1. Access APOLO in the corresponding schedule.

2. Create your own directory with your name in capital letter.

3. At a terminal, run the following command:
    ```
    git clone https://github.com/JeronimoRestrepo48/Final-Workshop-Apolo.git
    ```
4. Go to the directory where you cloned the project:
    ```
    cd Final-Workshop-Apolo
    ```
5. Copy the `job.sh` file to your directory with the following command:
   ```
   cp job.sh DIRECTORY'S_NAME/
    ```
6. Create a `bin` directory inside the root of the project:
    ```
    mkdir bin
    ```
7. Compile the `mmm_implementation.c` file inside the bin directory:
    ```
   gcc -fopenmp -mavx -O3 -o bin/mmm mmm_implementation.c
    ```
8. In the `job.sh` file modify the `dir` word with the name of the directory where it is located the executable file of the 
   `mmm_implementation.c` file.
    
9. Run the program:
    - In APOLO:
        ```
        sbatch job.sh
        ```
        - After that a new job is created with an ID number, so it's important to check if the job is running correctly in your queue 
          with the command:
          ```
          smyqueue
          ```
        - When the job is finally executed you can see in the files inside your main directory two new files with the extensions `.err` 
          and `.out`, therefore you need to execute first the `.err` file to check if there aren't any errors in the compilation and 
          execution with the command:
          ```
          cat MMM_SCAR_JOB_ID.err 
          ```
          Then, if there is no error we can proceed to run the `.out` file to obtain the results with the following command:
          ```
          cat MMM_SCAR_JOB_ID.out 
          ```
          **NOTE:** Replace the `JOB_ID` with your job's ID.
    - In your pc:
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
With the objective of optimizing the matrix-matrix multiplication algorithm, parallelization with OpenMP was applied as the main strategy, using the respective libraries and directly modifying the code to improve the execution time and efficiency of the loops. Later, some specific flags were used to compile the code, which help improve execution with vectorization strategies. 

## Simulations
Here are some screenshots of the execution tests in APOLO.

In the pictures it's shown the execution of the matrix-matrix multiplication algorithm, as we can evidence in the first one, the running time for it, is about 105 seconds per iteration (50 times) with arrays of 1872 x 1872.

![image](https://github.com/user-attachments/assets/debf4c1f-9ec3-459f-8edf-27d878b4cf6c)


## Authors
- Jerónimo Restrepo
