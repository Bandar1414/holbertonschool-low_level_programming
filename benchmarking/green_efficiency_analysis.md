# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled in the same sandbox environment with the required GCC flags: `-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`. The provided algorithmic logic and input sizes were kept unchanged. Timing was measured with `clock()` and converted to seconds by dividing the difference between the ending and starting `clock_t` values by `CLOCKS_PER_SEC`.

The baseline program was executed three consecutive times. Its recorded times were 0.225340, 0.226231, and 0.225887 seconds, giving an average of 0.225819 seconds. The comparison program was also executed three times. The naive implementation recorded 2.742216, 2.747607, and 2.743731 seconds, while the single-pass implementation recorded 0.000107, 0.000106, and 0.000105 seconds. Their averages were 2.744518 seconds and 0.000106 seconds respectively.

For the controlled instrumentation experiment, measurement boundaries were placed immediately before and after each phase. The total measurement began before `build_dataset()` and ended after `reduce_checksum()`. One recorded run produced a total time of 0.000731 seconds, including 0.000287 seconds for building the data, 0.000305 seconds for processing it, and 0.000134 seconds for reducing it.

## Observed Performance Differences

The baseline results were very close. The difference between the fastest run, 0.225340 seconds, and the slowest run, 0.226231 seconds, was only 0.000891 seconds. This shows that repeated execution of the same deterministic workload can still produce small timing variation.

The algorithm comparison showed a much larger difference. Dividing the naive average of 2.744518 seconds by the single-pass average of 0.000106 seconds gives approximately 25,891.68. Therefore, in these measurements, the naive implementation was about 25,892 times slower. The recorded results were also different: the naive function returned 625025000, while the single-pass function returned 25000. This indicates that the naive version repeatedly counts values through nested loops, while the single-pass version examines each array element once.

In the instrumentation run, processing was the longest measured phase at 0.000305 seconds. Building the dataset took 0.000287 seconds, and reduction took 0.000134 seconds. The three phase measurements totaled 0.000726 seconds, which was 0.000005 seconds below the total measurement. This small difference is consistent with timing calls, assignments, and transitions between phases being included in the total interval.

## Relation Between Runtime and Energy Consumption

This experiment did not measure electrical power in watts or energy in joules. However, runtime provides a limited proxy for how long the CPU remains active for a fixed workload in the same environment. The measured difference between 2.744518 seconds and 0.000106 seconds shows that implementation choice can greatly change execution time. At larger scales or with frequent repetition, reducing unnecessary work may also reduce total processor activity.

## Limitations of the Experiment

The measurements came from one sandbox, one compiler configuration, and small numbers of runs. Background processes, operating-system scheduling, cache state, processor frequency, and the resolution of `clock()` may affect the results. The instrumentation phases were extremely short, so differences of a few microseconds should not be treated as exact hardware-level measurements. In addition, the two comparison functions returned different values and performed different quantities of work, so the timing ratio should be interpreted as a comparison of the provided implementations, not as a controlled comparison of two fully equivalent algorithms.

## Practical Engineering Takeaway

The measurements show why performance decisions should be based on repeated observations rather than assumptions. The stable baseline established expected timing variation, the comparison exposed the high cost of repeated nested-loop work, and the instrumentation identified processing as the largest phase in the measured multi-phase program. Engineers should preserve correctness, measure consistent boundaries, repeat tests, and report limitations before claiming efficiency or sustainability improvements.
