# Algorithmic Efficiency Comparison Metrics

## Run 1

```text
Naive algorithm result: 625025000
Naive algorithm time: 2.742216 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000107 seconds
```

## Run 2

```text
Naive algorithm result: 625025000
Naive algorithm time: 2.747607 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000106 seconds
```

## Run 3

```text
Naive algorithm result: 625025000
Naive algorithm time: 2.743731 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000105 seconds
```

## Average Execution Times

The average execution time of the naive algorithm was calculated as follows:

```text
(2.742216 + 2.747607 + 2.743731) / 3
= 2.744518 seconds
```

The average execution time of the single-pass algorithm was calculated as follows:

```text
(0.000107 + 0.000106 + 0.000105) / 3
= 0.000106 seconds
```

## Relative Difference

The relative performance difference was calculated by dividing the average
execution time of the naive algorithm by the average execution time of the
single-pass algorithm:

```text
2.744518 / 0.000106
= 25891.679245
```

Based on the recorded measurements, the naive algorithm was approximately
25,892 times slower than the single-pass algorithm.
