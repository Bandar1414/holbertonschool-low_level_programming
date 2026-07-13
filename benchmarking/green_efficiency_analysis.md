# Green Efficiency Analysis

## Measurement Methodology

I used the same sandbox environment for all tests. I compiled the C files with the required GCC flags and did not change the algorithm logic or the input size. The programs used `clock()` from `<time.h>` to measure CPU time, and the results were converted to seconds using `CLOCKS_PER_SEC`.

For the baseline test, I ran the program three times. The times were 0.225340 seconds, 0.226231 seconds, and 0.225887 seconds. For the algorithm comparison, I also ran the program three times. The naive algorithm times were 2.742216 seconds, 2.747607 seconds, and 2.743731 seconds. The single-pass algorithm times were 0.000107 seconds, 0.000106 seconds, and 0.000105 seconds.

For the instrumentation test, I measured the total time and the time of each phase. The total time was measured from before `build_dataset()` until after `reduce_checksum()`. I also measured the build, process, and reduce phases separately.

## Observed Performance Differences

The baseline results were very close to each other. The fastest result was 0.225340 seconds and the slowest result was 0.226231 seconds. The difference was only 0.000891 seconds. This shows that even when the program does the same work, the execution time can change a little between runs.

The average time of the naive algorithm was 2.744518 seconds. The average time of the single-pass algorithm was 0.000106 seconds. Based on these averages, the naive algorithm was about 25,892 times slower than the single-pass algorithm.

The reason is clear from the code. The naive algorithm uses nested loops and repeats the counting work many times. The single-pass algorithm checks each array element only once. The results of the two functions were also different. The naive algorithm returned 625025000, while the single-pass algorithm returned 25000. This means they do not perform the same amount of work.

In the instrumentation test, the total time was 0.000731 seconds. Building the data took 0.000287 seconds, processing took 0.000305 seconds, and reducing the data took 0.000134 seconds. The process phase was the longest phase. The three phase times added together were 0.000726 seconds, which was very close to the total time.

## Relation Between Runtime and Energy Consumption

This project did not measure real electrical power or energy use. It only measured runtime. However, a program that runs for less time usually keeps the CPU busy for less time in the same environment. Because of this, runtime can give a simple idea about efficiency.

The large difference between the naive and single-pass algorithms shows that better code can greatly reduce CPU work. Still, I cannot say the exact energy saving because I did not measure watts or joules.

## Limitations of the Experiment

There are several limitations. The tests were done in one sandbox only, and each program was run a small number of times. Other processes in the background may affect the results. The operating system, CPU speed, cache, and timer accuracy may also cause small changes.

The instrumentation times were very small, so a difference of a few microseconds may not be fully accurate. Also, the two comparison algorithms returned different results and did different amounts of work. Because of this, the ratio should be understood as a comparison of the provided code, not as a perfect comparison between two equal algorithms.

## Practical Engineering Takeaway

The main lesson is that performance should be measured, not guessed. Running the same test more than once helps show normal timing changes. Measuring each program phase also helps find where most of the time is spent.

In this project, the process phase took the most time in the instrumentation test, and the nested-loop algorithm was much slower than the single-pass algorithm. Good algorithm choices can save a large amount of runtime. However, energy claims should only be made when real power-measurement tools are used.
