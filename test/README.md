# Interval Tree

The Interval Tree project is an implementation of a data structure that efficiently stores intervals and allows for quick interval search and overlap detection.

## Tests
1. **NoOverlappingIntervals**
   - Inserts non-overlapping intervals.
   - Searches for an interval with no overlap.

2. **OverlappingIntervalFound**
   - Inserts overlapping intervals.
   - Searches for an overlapping interval.

3. **OverlappingIntervalFoundRightChild**
   - Inserts overlapping intervals with the overlapping interval on the right child.

4. **OverlappingIntervalFoundLeftChild**
   - Inserts overlapping intervals with the overlapping interval on the left child.

5. **QueryIntervalFullyContainedInOneInterval**
   - Inserts intervals with one fully containing the query interval.

6. **QueryIntervalNotFound**
   - Searches for an interval with no overlap.

7. **OverlappingIntervalsWithNegativeValues**
   - Inserts overlapping intervals with negative values.

8. **OverlappingIntervalsWithZero**
   - Inserts overlapping intervals containing zero.

9. **LargeValues**
   - Inserts overlapping intervals with large values.

10. **LargeNumberOfIntervals**
    - Inserts a large number of intervals and searches for an overlap.

11. **QueryIntervalWithNegativeValues**
    - Searches for an interval with negative values and no overlap.

12. **QueryIntervalWithLargeValues**
    - Searches for an interval with large values and no overlap.

13. **QueryIntervalWithZero**
    - Searches for an interval containing zero with no overlap.

14. **SingleInterval**
    - Inserts a single interval and searches within it.

15. **SingleIntervalQueryOutsideInterval**
    - Searches for an interval outside a single interval.

16. **SingleIntervalQueryWithNegativeValues**
    - Searches for an interval with negative values outside a single interval.

17. **SingleIntervalQueryWithLargeValues**
    - Searches for an interval with large values outside a single interval.

18. **EmptyTree**
    - Searches for an interval in an empty tree.

19. **OverlappingIntervalsWithSameLowHighValues**
    - Inserts overlapping intervals with the same low and high values.

20. **QueryIntervalWithSameLowHighValues**
    - Searches for an interval with the same low and high values and no overlap.

21. **OverlappingIntervalsOneContainingAnother**
    - Inserts overlapping intervals with one interval fully containing another.

22. **OverlappingIntervalsOneContainedWithinAnother**
    - Inserts overlapping intervals with one interval contained within another.

23. **OverlappingIntervalsWithEqualIntervals**
    - Inserts overlapping intervals with equal intervals.

24. **RandomIntervals1**
    - Inserts random overlapping intervals and searches for an overlap.

25. **RandomIntervals2**
    - Inserts additional random overlapping intervals and searches for an overlap.

