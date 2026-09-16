# Data Structures and Algorithms in C++

A structured collection of Data Structures and Algorithms problems solved in C++. This repository follows a practical, problem-solving-first approach and is suitable for learning DSA fundamentals, preparing for coding interviews, and revising common competitive-programming patterns.

## What This Repository Covers

- Fundamental data structures and their implementations
- Searching and sorting techniques
- Arrays, strings, linked lists, stacks, queues, heaps, trees, graphs, tries, and range-query structures
- Recursion, backtracking, greedy algorithms, and dynamic programming
- Interview patterns such as two pointers, sliding window, binary search on answer, monotonic stack, BFS/DFS, shortest paths, and disjoint set union
- Problems inspired by common coding-platform and Striver-style DSA sheets

## Learning Roadmap

The folders can be studied in the following order:

1. [Arrays](Arrays/) and [Strings](Strings/)
2. [Sorting](Sorting/) and [Binary Search](Binary%20Search/)
3. [Linked List](Linked%20List/), [Stack and Queue](Stack%20and%20Queue/), and [Heap](Heap/)
4. [Recursion and Backtracking](Recursion%20%26%20Backtracking/)
5. [Bit Manipulation](Bit%20Manipulation/) and [Sliding Window](Slinding%20Window/)
6. [Trees](Trees/) and [Binary Search Tree](Binary%20Search%20Tree/)
7. [Graph](Graph/) and [Binary Indexed Tree](Binary%20Indxed%20Tree/)
8. [Trie](Trie/), [Segment Tree](Segment%20Tree/), and advanced topics
9. [Dynamic Programming](Dynamic%20Programming/) and [Greedy](Greedy/)

## Topic Index

### Arrays

Problems involving array traversal, prefix/suffix techniques, subarrays, inversion counting, majority elements, Kadane's algorithm, products, and rearrangement.

- [Find largest element](Arrays/01_find_largest_element.cpp)
- [Count subarrays with a given sum](Arrays/count_all_subarray_with_given_sum.cpp)
- [Longest subarray with sum K](Arrays/longest_subarray_with_sum_k.cpp)
- [Count inversions](Arrays/count_inversion.cpp)
- [Maximum subarray sum](Arrays/maximum_subarray_sum.cpp)
- [Maximum sum circular subarray](Arrays/maximum_sum_circular_subarray.cpp)
- [Maximum product subarray](Arrays/maximum_product_subarray.cpp)
- [Majority element](Arrays/majority_element.cpp)
- [Reverse pairs](Arrays/reverse_pairs.cpp)
- [Sort an array containing 0, 1, and 2](Arrays/sort_an_array_0_1_2.cpp)

See all examples in [Arrays](Arrays/).

### Searching and Sorting

- [Binary Search](Binary%20Search/) covers lower and upper bounds, first/last occurrence, rotated arrays, peak elements, matrix searching, square roots, nth roots, and binary search on answer.
- [Sorting](Sorting/) includes bubble sort, insertion sort, selection sort, merge sort, quick sort, heap sort, and recursive variations.
- [Book allocation](Binary%20Search/22_allocate_books.cpp), painter partition, aggressive cows, shipping capacity, bouquet making, and gas-station distance minimization are included in [Binary Search](Binary%20Search/).

### Linked Lists

The [Linked List](Linked%20List/) folder covers singly, doubly, and circular linked lists; insertion and deletion; reversal; cycle detection; palindrome checks; sorting; merging; arithmetic; flattening; random pointers; and reversing nodes in groups.

- [Linked-list introduction](Linked%20List/01_introduction_to_linkedlist.cpp)
- [Detect a cycle](Linked%20List/13_detect_a_loop_in_linkedlist.cpp)
- [Find the start of a cycle](Linked%20List/14_find_starting_point_in_cyclic_linkedlist.cpp)
- [Reverse nodes in K groups](Linked%20List/28_reverse_nodes_in_k_groups.cpp)
- [Copy a list with a random pointer](Linked%20List/31_copy_list_with_ranodm_pointer.cpp)

### Stack and Queue

The [Stack and Queue](Stack%20and%20Queue/) folder includes implementations using arrays, linked lists, stacks, and queues, plus expression conversion and monotonic-stack problems.

- [Stack implementation](Stack%20and%20Queue/01_stack_implementation_using_arrays.cpp)
- [Valid parentheses](Stack%20and%20Queue/07_valid_parentheses.cpp)
- [Minimum stack](Stack%20and%20Queue/08_implement_min_stack.cpp)
- [Next greater element](Stack%20and%20Queue/14_next_greater_element_i.cpp)
- [Trapping rain water](Stack%20and%20Queue/18_trapping_rain_water.cpp)
- [Largest rectangle in a histogram](Stack%20and%20Queue/23_largest_area_in_histogram.cpp)
- [Stock span problem](Stack%20and%20Queue/26_stock_span_problem.cpp)

### Recursion and Backtracking

[Recursion and Backtracking](Recursion%20%26%20Backtracking/) contains power calculation, subsequences, subsets, combinations, partitioning, word search, maze solving, N-Queens, and Sudoku.

- [Generate all subsequences](Recursion%20%26%20Backtracking/08_print_all_subsequences.cpp)
- [Combination Sum](Recursion%20%26%20Backtracking/12_combination_sum.cpp)
- [Palindrome partitioning](Recursion%20%26%20Backtracking/18_palindrome_partationing.cpp)
- [N-Queens](Recursion%20%26%20Backtracking/N_queen_problem.cpp)
- [Sudoku solver](Recursion%20%26%20Backtracking/sudoku_solver.cpp)

### Trees and Binary Search Trees

- [Trees](Trees/) covers binary-tree construction, recursive and iterative traversals, level order, views, boundary traversal, height, balance, diameter, maximum path sum, lowest common ancestor, serialization, Morris traversal, and flattening.
- [Binary Search Tree](Binary%20Search%20Tree/) covers search, minimum, ceil/floor, insertion, deletion, validation, construction, successor, two-sum, recovery, and largest BST problems.

Useful starting points:

- [Binary-tree traversals](Trees/03_tree_traversal.cpp)
- [Iterative traversals](Trees/13_pre_in_post_traversal.cpp)
- [Lowest common ancestor](Trees/27_lowest_common_ansester_in_binary_tree.cpp)
- [Serialize and deserialize a binary tree](Trees/36_serialize_and_deserialize_a_binary_tree.cpp)
- [Validate a BST](Binary%20Search%20Tree/09_validate_bst.cpp)

### Graphs

[Graph](Graph/) contains graph construction, BFS, DFS, connected components, islands, flood fill, cycle detection, bipartite checking, topological sorting, course scheduling, shortest paths, minimum spanning trees, DSU, strongly connected components, bridges, and articulation points.

- [Graph using an adjacency list](Graph/graph_creation_using_adjecencylist.cpp)
- [BFS traversal](Graph/graph_5_BFS_traversal.cpp)
- [DFS traversal](Graph/graph_6_DFS_traversal.cpp)
- [Cycle detection](Graph/graph_11_cycle_dedection_undirected.cpp)
- [Topological sort](Graph/graph_20_topological-sort.cpp)
- [Dijkstra's algorithm](Graph/graph_27_dijkstra_algorithm.cpp)
- [Bellman-Ford algorithm](Graph/graph_35_bellmen-ford-algorithm.cpp)
- [Floyd-Warshall algorithm](Graph/graph_36_floyd-warshall.cpp)
- [Minimum spanning tree with Kruskal's algorithm](Graph/graph_42_kruskal_algo_to_find_mst.cpp)
- [Strongly connected components](Graph/graph_54_strongly-connected-components-kosarajus-algo.cpp)
- [Critical connections](Graph/graph_55_critical_connection_in_a_graph.cpp)

### Dynamic Programming

[Dynamic Programming](Dynamic%20Programming/) progresses from one-dimensional DP to grids, subsequences, knapsack, partition DP, string DP, stock problems, interval DP, and optimization techniques.

- [Climbing stairs](Dynamic%20Programming/dp_02_count-ways-to-reach-nth-stairs.cpp)
- [Frog jump](Dynamic%20Programming/dp_03_frog_jump.cpp)
- [0/1 Knapsack](Dynamic%20Programming/dp_19_0-1_knapsack.cpp)
- [Coin Change](Dynamic%20Programming/dp_20_minimum_elements_coin_change.cpp)
- [Longest common subsequence](Dynamic%20Programming/dp_25_longest_commom_subsequence.cpp)
- [Edit distance](Dynamic%20Programming/dp_33_edit_distance.cpp)
- [Best time to buy and sell stock](Dynamic%20Programming/dp_35_best_time_to_buy_or_sell_stock.cpp)
- [Longest increasing subsequence](Dynamic%20Programming/dp_41_42_longest_increasing_subsequence.cpp)
- [Matrix chain multiplication](Dynamic%20Programming/dp_48_matrix_cahin_multiplication.cpp)
- [Burst balloons](Dynamic%20Programming/dp_51_burst_ballons.cpp)

### Greedy and Heap

- [Greedy](Greedy/) includes activity selection, fractional knapsack, coin change, interval scheduling, jump game, job sequencing, candy distribution, page replacement, and worker-cost optimization.
- [Heap](Heap/) includes priority queue implementation, heap conversion, Kth smallest/largest elements, merging sorted lists, task scheduling, running median, top-K problems, and greedy heap applications.

### Bit Manipulation and Number Theory

[Bit Manipulation](Bit%20Manipulation/) covers bit checks, powers of two, set bits, XOR, bit flips, swapping, division, subsets, prime factors, sieves, divisors, and bitwise string/array problems.

- [Check whether the ith bit is set](Bit%20Manipulation/02_check_whether_ith_bit_set_or_not.cpp)
- [Count set bits](Bit%20Manipulation/05_count_total_set_bits.cpp)
- [XOR from L to R](Bit%20Manipulation/10_L_to_R_xor.cpp)
- [Generate subsets with bit manipulation](Bit%20Manipulation/generate_all_subset_using_bit_manipulation.cpp)

### Sliding Window and Two Pointers

[Sliding Window](Slinding%20Window/) includes fixed-size and variable-size windows, distinct-character problems, anagrams, maximum/minimum windows, binary arrays, and subarray counting.

- [Longest substring without repeating characters](Slinding%20Window/01_longest_substring_without_repeting_char.cpp)
- [Maximum consecutive ones](Slinding%20Window/02_maximum_consicutive_ones_iii.cpp)
- [Fruit into baskets](Slinding%20Window/03_fruits_in_baskets.cpp)
- [Minimum window substring](Slinding%20Window/11_minimum_window_substring.cpp)
- [Maximum of every window](Slinding%20Window/maximum_of_all_subarray_of_size_k.cpp)

### Advanced Structures and Other Topics

- [Binary Indexed Tree](Binary%20Indxed%20Tree/) includes Fenwick tree operations, counting smaller elements, and sorted-array construction.
- [Segment Tree](Segment%20Tree/) includes range sum/minimum queries, mutable and immutable queries, lazy propagation, peaks, and LIS-related queries.
- [Trie](Trie/) includes Trie I/II, distinct substring counting, and maximum XOR queries.
- [Other topics](other%20topics/) includes convex hull and gas-station problems.
- [Multiset](multiset/) includes the Skyline problem.
- [Striver sheet](striver%20sheet/) is reserved for additional structured practice.

## How to Use This Repository

1. Choose a topic from the roadmap.
2. Read the problem statement and understand the expected input/output.
3. Study the implementation and identify the algorithmic pattern.
4. Compile and run the file with your own test cases.
5. Write the time and space complexity beside the solution as revision notes.

## Compile and Run a Solution

From the repository root, use MinGW g++:

```bash
g++ -std=c++17 -Wall -Wextra "Arrays/maximum_subarray_sum.cpp" -o solution.exe
solution.exe
```

On Windows PowerShell, run the generated executable with:

```powershell
./solution.exe
```

## Goal

Build strong DSA fundamentals by understanding the pattern behind each solution, not only by memorizing individual implementations.
