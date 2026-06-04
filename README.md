# Striver A2Z DSA Sheet — Complete Analysis & 2-Hour Daily Plan

---

## What Is This Sheet?

Striver's A2Z DSA Sheet is created by Raj Vikramaditya (Striver) on takeuforward.org. It is a completely free, structured roadmap containing 474 problems organized across 18 major steps. It goes from absolute zero (basics of programming) all the way to advanced topics like Dynamic Programming, Graphs, and Tries. It is designed specifically to crack FAANG and top product-based company interviews.

The sheet is not just a random list of problems. Every step builds on the previous one. The order is intentional. Skipping steps or jumping ahead will hurt your understanding.

---

## Full Sheet Breakdown — Every Step, Every Topic

---

### STEP 1 — Learn the Basics (31 Problems)

This is the foundation. Do not rush through this. Everything else depends on it.

**1.1 Things to Know in C++ / Java / Python**
- User Input / Output
- Data Types (int, long, float, double, char, string)
- If-Else conditions
- Switch statements
- What is time complexity and why it matters
- What is space complexity

**1.2 Build-Up Logical Thinking**
- Pattern printing problems (14 patterns)
- These include triangles, pyramids, diamonds, hollow patterns
- These look boring but they build your loop thinking — do not skip them
- Example patterns: right-angled triangle, inverted triangle, number pattern, star pattern, butterfly pattern, solid rhombus, etc.

**1.3 Learn STL (Standard Template Library — C++) / Collections (Java)**
- Pairs
- Vectors / Arrays
- Lists
- Deque
- Stack
- Queue
- Priority Queue (max heap and min heap)
- Set and Multiset
- Map and Multimap
- Unordered Map, Unordered Set
- Iterators and how to use them

**1.4 Basic Maths (6 problems)**
- Count digits in a number
- Reverse a number
- Check Palindrome number
- GCD and LCM (Euclidean Algorithm — very important, comes back again and again)
- Check Armstrong number
- Print all divisors of a number
- Check Prime number

**1.5 Basic Recursion (7 problems)**
- Print 1 to N using recursion
- Print N to 1 using recursion
- Sum of first N numbers using recursion
- Factorial of N using recursion
- Reverse an array using recursion
- Check if a string is palindrome using recursion
- Fibonacci number using recursion

**1.6 Basic Hashing (4 problems)**
- Hashing theory — what is a hash map and why it is O(1) average
- Count frequency of each element in an array
- Find the highest and lowest frequency element
- Introduction to counting sort concept

**Time estimate for Step 1:** 7 to 10 days at 2 hours/day

---

### STEP 2 — Learn Important Sorting Techniques (7 Problems)

Sorting is used in nearly every other topic on this sheet. Learn each algorithm by coding it yourself, not just reading it.

**2.1 Sorting Part 1**
- Selection Sort — find minimum, place it
- Bubble Sort — compare adjacent elements, swap
- Insertion Sort — pick element, insert in correct position

**2.2 Sorting Part 2**
- Merge Sort — divide and conquer, very important for interviews
- Recursive Bubble Sort
- Recursive Insertion Sort
- Quick Sort — pivot, partition, recurse — very important

**What to focus on:** Time complexity of each sort (best, average, worst). Merge Sort is O(n log n) always. Quick Sort is O(n^2) worst case. Also understand which sort is stable and which is not.

**Time estimate for Step 2:** 3 to 4 days at 2 hours/day

---

### STEP 3 — Solve Problems on Arrays (40 Problems)

Arrays are the most heavily tested topic in any coding interview. This step goes Easy to Medium to Hard.

**3.1 Easy Array Problems (14 problems)**
- Largest element in an array
- Second largest element (without sorting)
- Check if array is sorted
- Remove duplicates from sorted array
- Left rotate an array by one place
- Left rotate an array by D places
- Move zeros to end
- Linear search
- Find union of two sorted arrays
- Find intersection of two sorted arrays
- Find missing number in an array (use sum formula or XOR)
- Maximum consecutive ones
- Find the number that appears once (XOR trick)
- Longest subarray with given sum (for positives)

**3.2 Medium Array Problems (14 problems)**
- 2 Sum problem (use HashMap)
- Sort an array of 0s, 1s, and 2s (Dutch National Flag algorithm — must know)
- Majority element (greater than n/2 times) — Boyer-Moore Voting Algorithm
- Kadane's Algorithm — Maximum subarray sum (extremely important)
- Stock buy and sell (maximum profit, one transaction)
- Rearrange array elements by sign (positives and negatives alternating)
- Next permutation
- Leaders in an array
- Longest consecutive sequence (use HashSet)
- Set matrix zeros
- Rotate matrix by 90 degrees
- Print spiral order of a matrix
- Count subarrays with given sum (prefix sum + HashMap)

**3.3 Hard Array Problems (12 problems)**
- Pascal's triangle
- Majority element (greater than n/3 times) — Extended Boyer-Moore
- 3 Sum problem
- 4 Sum problem
- Largest subarray with 0 sum
- Count number of subarrays with XOR equal to K
- Merge overlapping intervals
- Merge two sorted arrays without extra space
- Find missing and repeating number
- Count inversions in an array (using Merge Sort)
- Reverse pairs (LeetCode hard, Merge Sort based)
- Maximum product subarray

**Time estimate for Step 3:** 12 to 16 days at 2 hours/day

---

### STEP 4 — Binary Search (32 Problems)

Binary search is one of those topics that looks simple but has deep applications. This step will change how you think.

**4.1 Binary Search on 1D Arrays (13 problems)**
- Binary search basics — iterative and recursive
- Implement lower bound and upper bound
- Search insert position
- Floor and ceil in sorted array
- First and last occurrence of element in sorted array
- Count occurrences of element in sorted array
- Search in rotated sorted array (no duplicates)
- Search in rotated sorted array (with duplicates)
- Find minimum in rotated sorted array
- Find rotation count
- Single element in a sorted array (every other appears twice)
- Find peak element

**4.2 Binary Search on Answers / Search Space (11 problems)**
- This is the advanced and most important part of binary search
- Find square root of a number using binary search
- Find Nth root of a number
- Koko eating bananas (find minimum eating speed)
- Minimum days to make M bouquets
- Find the smallest divisor given a threshold
- Capacity to ship packages within D days
- Kth missing positive number
- Aggressive cows (classic — minimize the maximum)
- Book allocation problem (maximize the minimum)
- Split array — largest sum
- Minimize maximum distance between gas stations
- Median of two sorted arrays (hard — O(log min(m,n)))

**4.3 Binary Search on 2D Arrays (8 problems)**
- Find row with maximum number of 1s
- Search in a row-wise and column-wise sorted matrix
- Find peak element in a 2D matrix
- Matrix median

**Time estimate for Step 4:** 10 to 14 days at 2 hours/day

---

### STEP 5 — Strings (15 Problems)

**5.1 Basic String Problems**
- Remove outermost parentheses
- Reverse words in a string
- Largest odd number in a string
- Longest common prefix
- Isomorphic strings
- Check if strings are rotations of each other
- Check if two strings are anagrams

**5.2 Medium String Problems**
- Sort characters by frequency
- Maximum nesting depth of parentheses
- Roman to Integer
- Integer to Roman
- Implement Atoi (string to integer, handle edge cases carefully)
- Count and say
- Longest palindromic substring

**Time estimate for Step 5:** 5 to 6 days at 2 hours/day

---

### STEP 6 — Linked Lists (31 Problems)

Linked lists are pointer-heavy. Draw diagrams while solving. Never solve blind.

**6.1 Learning — Single Linked List (6 problems)**
- Introduction to Linked List
- Inserting a node (at head, tail, Kth position)
- Deleting a node (head, tail, Kth position, given value)
- Finding length of a Linked List
- Searching in a Linked List

**6.2 Learning — Doubly Linked List (5 problems)**
- Introduction to Doubly Linked List
- Insert a node in DLL
- Delete a node in DLL
- Reverse a DLL

**6.3 Medium LL Problems (14 problems)**
- Middle of a Linked List (fast and slow pointer — must know)
- Reverse a Linked List (iterative and recursive)
- Detect a cycle in a Linked List (Floyd's cycle detection)
- Find starting point of loop in Linked List
- Length of cycle in a Linked List
- Check if Linked List is palindrome
- Segregate odd and even nodes
- Remove Nth node from end
- Delete middle node of Linked List
- Sort Linked List (Merge Sort on LL)
- Sort a LL of 0s, 1s, and 2s
- Add 1 to a number represented as a Linked List
- Add two numbers represented as Linked Lists
- Intersection point of two Linked Lists (Floyd / length difference method)

**6.4 Hard LL Problems (6 problems)**
- Reverse a Linked List in groups of K
- Rotate a Linked List by K
- Flattening a Linked List
- Clone a Linked List with random pointer
- Find pairs with given sum in a DLL
- Remove duplicates from sorted DLL

**Time estimate for Step 6:** 10 to 14 days at 2 hours/day

---

### STEP 7 — Recursion (25 Problems)

Recursion is the hardest mindset shift. Go slow. Understand the call stack. Draw the recursion tree for every problem.

**7.1 Get a Strong Hold (6 problems)**
- Recursive implementation of Atoi
- Pow(x, n) — fast power using recursion
- Count good numbers
- Sort a stack using recursion
- Reverse a stack using recursion
- K-th symbol in grammar

**7.2 Subsequences Pattern (8 problems)**
- Generate all binary strings without consecutive 1s
- Generate parentheses
- Print all subsequences of a string
- Print subsequence whose sum equals K
- Count all subsequences with sum K
- Check if subset with given sum exists
- Combination sum 1 (elements can repeat, pick or not pick)
- Combination sum 2 (elements cannot repeat)
- Subset sum 1 (sorted order of all subsets)
- Subset sum 2 (no duplicates in output)

**7.3 Trying Out All Combos / Hard (11 problems)**
- Combination sum 3 (K numbers summing to N)
- Letter combinations of a phone number
- Palindrome partitioning
- Word search in a 2D grid (backtracking)
- N-Queens problem (most classic backtracking)
- Rat in a maze
- Word break 1 (can string be split into dictionary words)
- M-coloring problem
- Sudoku solver

**Time estimate for Step 7:** 10 to 13 days at 2 hours/day

---

### STEP 8 — Bit Manipulation (18 Problems)

**8.1 Concepts (6 problems)**
- Introduction to Bit Manipulation (AND, OR, XOR, NOT, left shift, right shift)
- Check if the i-th bit is set
- Set the i-th bit
- Clear the i-th bit
- Toggle the i-th bit
- Remove the last set bit (n & (n-1) trick)
- Check if a number is a power of 2
- Count number of set bits (Brian Kernighan's algorithm)
- Find minimum bit flips to convert number

**8.2 Interview Problems (12 problems)**
- Find the number that appears once (XOR — classic)
- Find two numbers that appear odd times (XOR split technique)
- Power set of an array
- Find XOR of numbers from L to R (XOR prefix trick)
- Find the Nth magic number
- Divide two integers without division operator
- Reverse bits of a number
- Single number 3

**Time estimate for Step 8:** 5 to 7 days at 2 hours/day

---

### STEP 9 — Stack and Queues (30 Problems)

Stack and Queue together form one of the most important topics for interview problems.

**9.1 Learning (9 problems)**
- Implement Stack using Arrays
- Implement Queue using Arrays
- Implement Stack using Queue
- Implement Queue using Stack
- Implement Stack using Linked List
- Implement Queue using Linked List
- Check for balanced parentheses
- Implement Min Stack (return minimum in O(1))

**9.2 Prefix, Infix, Postfix (5 problems)**
- Infix to Postfix conversion
- Infix to Prefix conversion
- Postfix to Infix conversion
- Prefix to Infix conversion
- Evaluate Postfix expression

**9.3 Monotonic Stack — Very Important (10 problems)**
- Next greater element 1
- Next greater element 2 (circular array)
- Next smaller element
- Previous greater element
- Previous smaller element
- Stock span problem
- Asteroid collision
- Sum of subarray ranges
- Remove K digits (make smallest number)
- Largest rectangle in histogram (very important hard problem)
- Maximal rectangle in a binary matrix

**9.4 Implementation Problems (6 problems)**
- Sliding window maximum (Deque)
- LRU Cache (HashMap + Doubly Linked List)
- LFU Cache
- Largest rectangle in histogram using Stack
- Celebrity problem
- The stock span problem revisited

**Time estimate for Step 9:** 10 to 13 days at 2 hours/day

---

### STEP 10 — Sliding Window and Two Pointers (12 Problems)

These two techniques are often used together. They are pattern-recognition heavy.

**10.1 Medium Problems (6 problems)**
- Longest subarray with at most K zeros
- Fruit into baskets (at most 2 distinct elements)
- Number of substrings containing all three characters
- Maximum points from cards (slide from both ends)
- Longest repeating character replacement
- Binary subarrays with sum

**10.2 Hard Problems (6 problems)**
- Longest substring without repeating characters (classic)
- Minimum window substring (hard — two pointer + map)
- Maximum consecutive ones 3
- Subarrays with K different integers
- Minimum window substring (variation)
- Count number of nice subarrays

**Time estimate for Step 10:** 5 to 7 days at 2 hours/day

---

### STEP 11 — Heaps (17 Problems)

Heaps are underrated. Many hard problems become easy once you know how to use a heap.

**11.1 Learning (5 problems)**
- Introduction to heap — max heap and min heap
- Min heap implementation
- Max heap implementation
- Priority queue in STL / Java
- Heap sort algorithm

**11.2 Medium Problems (8 problems)**
- Kth largest element in an array
- Kth smallest element in an array
- Sort a K-sorted array (nearly sorted)
- Merge K sorted lists
- Replace each element with its rank
- Task scheduler (cool down problem)
- Hands of straights
- Find K closest elements to a given number

**11.3 Hard Problems (4 problems)**
- Maximum sum combination (K pairs)
- Find median from a data stream (two heaps trick — very important)
- K most frequent elements
- Top K frequent words

**Time estimate for Step 11:** 6 to 8 days at 2 hours/day

---

### STEP 12 — Greedy Algorithms (15 Problems)

Greedy is about trusting the locally optimal choice. The hard part is knowing when greedy works and when it does not.

**12.1 Easy Greedy (9 problems)**
- Assign cookies (maximize number of children with cookies)
- Fractional knapsack
- Greedy algorithm to find minimum number of coins
- Lemonade change
- Valid parenthesis string
- Jump game 1 (can you reach the end?)
- Jump game 2 (minimum jumps to reach end)
- Job sequencing problem
- N meetings in one room

**12.2 Medium and Hard Greedy (6 problems)**
- Minimum number of platforms required at a railway station
- Buy and sell stocks with unlimited transactions (greedy)
- Insert intervals
- Merge intervals (revisit from arrays)
- Non-overlapping intervals
- Candy distribution problem

**Time estimate for Step 12:** 5 to 7 days at 2 hours/day

---

### STEP 13 — Binary Trees (38 Problems)

Trees are massive. This is the biggest conceptual jump in the sheet. Think recursively for every problem.

**13.1 Traversals (14 problems)**
- Introduction to Trees
- Binary tree representation
- Level order traversal (BFS using Queue)
- Pre-order traversal (recursive and iterative)
- In-order traversal (recursive and iterative)
- Post-order traversal (recursive and iterative)
- Pre, In, Post order in a single traversal
- Height of a binary tree
- Check if a tree is balanced
- Diameter of a binary tree (tricky — don't pass through root assumption)
- Maximum path sum in binary tree (very important hard problem)
- Count total nodes in a complete binary tree
- Check if two trees are identical

**13.2 Medium Binary Tree Problems (17 problems)**
- Zigzag level order traversal
- Boundary traversal
- Vertical order traversal
- Top view of binary tree
- Bottom view of binary tree
- Right view of binary tree
- Left view of binary tree
- Symmetric binary tree
- Print all paths from root to leaf
- LCA (Lowest Common Ancestor — very important)
- Maximum width of binary tree
- Print all nodes at distance K from a given node
- Minimum time to burn an entire tree from a node
- Count nodes in complete binary tree
- Requirements needed to construct unique binary tree
- Construct binary tree from inorder and preorder
- Construct binary tree from inorder and postorder

**13.3 Hard Binary Tree Problems (7 problems)**
- Flatten a binary tree to linked list (in-place)
- Find median in a row-wise sorted matrix
- Morris inorder traversal
- Morris preorder traversal
- Serialize and deserialize a binary tree (very important for interviews)
- Recover BST with two nodes swapped (covered in BST)

**Time estimate for Step 13:** 14 to 18 days at 2 hours/day

---

### STEP 14 — Binary Search Trees (16 Problems)

BST problems leverage the ordering property. In-order of a BST is always sorted — this is the key insight for most problems.

**14.1 Concepts and Problems (9 problems)**
- Introduction to BST — properties and structure
- Search in a BST
- Find minimum and maximum in a BST
- Floor in a BST
- Ceil in a BST
- Insert a node in a BST
- Delete a node in a BST (tricky — three cases)
- Kth smallest element in a BST (in-order traversal)
- Kth largest element in a BST
- Validate a BST (don't just check child, use range)
- LCA in a BST
- Construct BST from a preorder traversal

**14.2 Hard BST Problems (7 problems)**
- Two sum in a BST (BST iterator + two pointer)
- Recover BST (two nodes swapped, find and fix)
- Largest BST in a binary tree (hard)
- BST iterator implementation
- Count BSTs with N nodes (Catalan numbers)

**Time estimate for Step 14:** 6 to 8 days at 2 hours/day

---

### STEP 15 — Graphs (53 Problems)

Graphs are the largest topic. This is also the most frequently asked topic in FAANG interviews. It is layered — BFS, DFS, then algorithms built on top.

**15.1 Learning (5 problems)**
- Graph representation — adjacency matrix and adjacency list
- BFS traversal of graph
- DFS traversal of graph
- Count connected components
- Number of provinces

**15.2 Problems on BFS and DFS (10 problems)**
- Detect cycle in undirected graph (using BFS and DFS)
- Detect cycle in directed graph (using DFS + visited + path)
- Flood fill algorithm
- Rotten oranges (multi-source BFS)
- 01 Matrix (BFS from all zeros)
- Surrounded regions (boundary DFS)
- Number of enclaves
- Bipartite graph check (2-coloring using BFS)
- Detect cycle in directed graph using Kahn's algorithm

**15.3 Topological Sort and Problems (6 problems)**
- Topological sort — DFS method
- Topological sort — Kahn's algorithm (BFS with in-degree)
- Detect cycle in directed graph using Kahn's
- Course schedule 1 and 2
- Find eventual safe states
- Alien dictionary (very important interview problem)

**15.4 Shortest Path Algorithms (12 problems)**
- Dijkstra's algorithm (using priority queue — must know perfectly)
- Bellman-Ford algorithm (handles negative weights)
- Floyd-Warshall algorithm (all pairs shortest path)
- Shortest path in undirected graph with unit weights (BFS)
- Shortest path in DAG (using topological sort)
- Network delay time
- Cheapest flights with at most K stops
- Number of ways to arrive at destination
- Minimum multiplications to reach end
- Path with minimum effort (modified Dijkstra)
- Path with maximum probability

**15.5 Minimum Spanning Tree (5 problems)**
- Prim's algorithm
- Kruskal's algorithm + Union-Find (DSU)
- Number of operations to make network connected
- Most stones removed with same row or column
- Accounts merge (DSU — very commonly asked)

**15.6 Other Graph Algorithms (15 problems)**
- Disjoint Set Union (DSU) — union by rank, path compression (separate focus)
- Number of islands (classic DFS/BFS)
- Making a large island (expand with DSU)
- Swim in rising water
- Strongly Connected Components — Kosaraju's algorithm
- Bridges in a graph (Tarjan's algorithm)
- Articulation points in a graph
- Word ladder 1 (BFS shortest transformation — hard)
- Word ladder 2 (all shortest transformations — very hard)

**Time estimate for Step 15:** 18 to 24 days at 2 hours/day

---

### STEP 16 — Dynamic Programming (55 Problems)

DP is the most dreaded topic. But Striver's approach of breaking it into patterns makes it learnable. The key insight: DP = recursion + memoization + (optionally) tabulation.

**16.1 Introduction to DP (4 problems)**
- Memoization vs Tabulation — understand both thoroughly
- Fibonacci using recursion, memoization, and tabulation
- Climbing stairs
- Frog jump (minimum energy to reach end)

**16.2 1D DP (5 problems)**
- Frog jump with K distances
- Maximum sum of non-adjacent elements (House robber)
- House robber 2 (circular array)
- Ninja training
- Count ways to climb stairs

**16.3 2D DP / Grid Problems (9 problems)**
- Grid unique paths (count paths from top-left to bottom-right)
- Grid unique paths 2 (with obstacles)
- Minimum path sum in a grid
- Minimum falling path sum
- Ninja and his friends (3D DP)
- Gold mine problem
- Triangle — minimum path sum from top to bottom
- Cherry pickup 2

**16.4 DP on Subsequences (11 problems)**
- Subset sum equals target (0/1 knapsack basis)
- Partition equal subset sum
- Partition a set into two subsets with minimum absolute difference
- Count of subsets with given sum
- Count partitions with given difference
- 0/1 Knapsack — the classic (must know perfectly)
- Unbounded knapsack
- Rod cutting problem
- Coin change 1 (minimum coins)
- Coin change 2 (count ways)
- Minimum number of elements to sum to target

**16.5 DP on Strings (10 problems)**
- Longest Common Subsequence (LCS — master this)
- Longest Common Substring
- Longest Palindromic Subsequence
- Edit distance (very famous — Levenshtein distance)
- Wildcard matching
- Regex pattern matching
- Count distinct subsequences
- Minimum insertion to make a string palindrome
- Minimum insertion/deletion to convert string A to B
- Shortest Common Supersequence

**16.6 DP on Stocks (6 problems)**
- Buy and sell stocks 1 (one transaction)
- Buy and sell stocks 2 (unlimited transactions)
- Buy and sell stocks 3 (at most 2 transactions)
- Buy and sell stocks 4 (at most K transactions)
- Buy and sell stocks with cooldown
- Buy and sell stocks with transaction fee

**16.7 DP on Longest Increasing Subsequence (5 problems)**
- Longest Increasing Subsequence (LIS) — O(n^2) and O(n log n) both
- Print the actual LIS
- Largest divisible subset
- Longest String chain
- Longest bitonic subsequence

**16.8 DP on Partitions (5 problems)**
- Matrix chain multiplication (classic DP on intervals)
- Minimum cost to cut a stick
- Burst balloons
- Evaluate boolean expression to true
- Palindrome partitioning 2

**Time estimate for Step 16:** 18 to 24 days at 2 hours/day

---

### STEP 17 — Tries (7 Problems)

**17.1 Theory and Problems**
- Introduction to Trie data structure
- Implement a Trie (insert, search, startsWith)
- Implement a Trie 2 (count insertions, prefix count)
- Longest string with all prefixes (complete string)
- Count distinct substrings (using Trie)
- Maximum XOR of two numbers in an array (Trie + bits)
- Maximum XOR with an element from an array

**Time estimate for Step 17:** 3 to 5 days at 2 hours/day

---

### STEP 18 — Advanced Strings (9 Problems)

**18.1 String Algorithms**
- Z-algorithm for pattern matching
- KMP algorithm — constructing the failure function (lps array)
- KMP algorithm — using it for searching
- Minimum characters to add in front to make a string palindrome
- Rabin-Karp algorithm for pattern matching (hashing based)
- Count occurrences of an anagram (sliding window + character count)
- Minimum window substring (revisit)
- String matching using Z-algorithm
- Repeated string match

**Time estimate for Step 18:** 4 to 5 days at 2 hours/day

---

## TIME ESTIMATE SUMMARY

Here is a topic-wise breakdown of days needed at 2 hours per day.

Step 1 — Basics: 8 days
Step 2 — Sorting: 4 days
Step 3 — Arrays: 14 days
Step 4 — Binary Search: 12 days
Step 5 — Strings: 6 days
Step 6 — Linked Lists: 12 days
Step 7 — Recursion: 12 days
Step 8 — Bit Manipulation: 6 days
Step 9 — Stack and Queue: 12 days
Step 10 — Sliding Window: 6 days
Step 11 — Heaps: 7 days
Step 12 — Greedy: 6 days
Step 13 — Binary Trees: 16 days
Step 14 — BST: 7 days
Step 15 — Graphs: 21 days
Step 16 — Dynamic Programming: 21 days
Step 17 — Tries: 4 days
Step 18 — Advanced Strings: 5 days

TOTAL: approximately 179 days at 2 hours/day — roughly 6 months

With dedicated effort, realistic completion is 5 to 6 months.

---

## YOUR DAY-BY-DAY PLAN (Week by Week)

Each day is 2 hours. Budget your time as: 40 minutes reading/watching concept + 80 minutes solving.

---

### PHASE 1 — FOUNDATION (Days 1–28)

**Week 1 — Days 1–7: Basics Part 1**
Day 1: I/O, data types, if-else, switch, time complexity theory
Day 2: Pattern printing — right triangle, inverted triangle, number pattern
Day 3: Pattern printing — star pyramid, inverted pyramid, diamond, hollow patterns
Day 4: STL / Collections — vectors, pairs, arrays, lists
Day 5: STL / Collections — stack, queue, priority queue, set, map
Day 6: Basic Maths — count digits, reverse number, palindrome, GCD, LCM
Day 7: Basic Maths — Armstrong, print divisors, prime check + REVISION of week

**Week 2 — Days 8–14: Basics Part 2 + Sorting**
Day 8: Basic Recursion — print 1 to N, N to 1, sum, factorial
Day 9: Basic Recursion — reverse array, palindrome check, Fibonacci
Day 10: Basic Hashing — frequency counting, highest/lowest frequency, hash map theory
Day 11: Revision of Step 1 completely
Day 12: Sorting — Selection Sort, Bubble Sort, Insertion Sort
Day 13: Sorting — Merge Sort (code it completely with recursion)
Day 14: Sorting — Quick Sort, Recursive Bubble and Insertion Sort + revision

**Week 3–4 — Days 15–28: Arrays Easy and Medium**
Day 15: Largest element, second largest, check if sorted, remove duplicates from sorted array
Day 16: Left rotate by 1, left rotate by D, move zeros to end, linear search
Day 17: Union and intersection of sorted arrays
Day 18: Missing number, max consecutive ones, single number using XOR
Day 19: Longest subarray with given sum
Day 20: REVISION — all easy array problems
Day 21: 2 Sum problem (HashMap approach)
Day 22: Sort 0s, 1s, 2s (Dutch National Flag), Majority Element (Boyer-Moore)
Day 23: Kadane's Algorithm (max subarray sum) — very important
Day 24: Stock buy and sell, rearrange by sign
Day 25: Next permutation (understand the algorithm step by step)
Day 26: Leaders in array, longest consecutive sequence
Day 27: Set matrix zeros, rotate matrix, spiral order
Day 28: Count subarrays with given sum + REVISION of medium arrays

---

### PHASE 2 — CORE DATA STRUCTURES (Days 29–84)

**Days 29–42: Arrays Hard + Binary Search**
Day 29: Pascal's triangle, Majority element (n/3)
Day 30: 3 Sum problem (two pointer after sorting)
Day 31: 4 Sum problem
Day 32: Largest subarray with 0 sum, count subarrays with XOR = K
Day 33: Merge overlapping intervals
Day 34: Merge two sorted arrays without extra space
Day 35: Find missing and repeating, count inversions (Merge Sort)
Day 36: Reverse pairs, maximum product subarray + REVISION of hard arrays
Day 37: Binary search basics — iterative, recursive, lower bound, upper bound
Day 38: Search insert position, floor and ceil, first and last occurrence
Day 39: Count occurrences, search in rotated sorted array (no duplicates)
Day 40: Search in rotated sorted array (duplicates), find minimum in rotated array
Day 41: Single element in sorted array, find peak element
Day 42: REVISION of 1D Binary Search problems

**Days 43–56: Binary Search on Answers + Strings + Linked List start**
Day 43: Square root, Nth root using binary search
Day 44: Koko bananas, minimum days for bouquets
Day 45: Smallest divisor, capacity to ship packages
Day 46: Kth missing positive, aggressive cows, book allocation
Day 47: Split array largest sum, median of two sorted arrays
Day 48: Binary search on 2D matrix problems + REVISION
Day 49: Strings — remove outermost parentheses, reverse words, largest odd number
Day 50: Strings — longest common prefix, isomorphic strings, rotation check, anagram check
Day 51: Strings — sort by frequency, nesting depth, Roman to Integer
Day 52: Strings — Integer to Roman, Atoi, count and say, longest palindromic substring + revision
Day 53: Linked List — introduction, insertion at head/tail/Kth position
Day 54: Linked List — deletion operations, find length, search

**Days 57–70: Linked List + Recursion**
Day 55: Doubly Linked List — introduction, insert, delete, reverse
Day 56: LL Medium — middle of LL (fast/slow pointer), reverse LL
Day 57: LL Medium — detect cycle (Floyd's), find start of loop, length of cycle
Day 58: LL Medium — palindrome LL, segregate odd and even
Day 59: LL Medium — remove Nth from end, delete middle node
Day 60: LL Medium — sort LL, sort 0s 1s 2s in LL, add 1 to number
Day 61: LL Medium — add two numbers, intersection point of two LLs
Day 62: LL Hard — reverse in groups of K, rotate LL
Day 63: LL Hard — flatten LL, clone with random pointer, pairs in DLL, remove duplicates DLL
Day 64: REVISION of all Linked List problems
Day 65: Recursion — Atoi, Pow(x,n), count good numbers, sort a stack
Day 66: Recursion — reverse a stack, K-th symbol in grammar
Day 67: Recursion — generate binary strings, generate parentheses, print subsequences
Day 68: Recursion — subset sum, combination sum 1 and 2
Day 69: Recursion — subset sum 2, combination sum 3, letter combinations phone number
Day 70: Recursion — palindrome partitioning, word search, N-Queens + revision

**Days 71–84: Recursion Hard + Bit Manipulation + Stack and Queue**
Day 71: Recursion — rat in a maze, word break, M-coloring, Sudoku solver
Day 72: REVISION of all recursion problems — draw recursion trees again
Day 73: Bit Manipulation — theory, check/set/clear/toggle bit, remove last set bit
Day 74: Bit Manipulation — power of 2, count set bits, minimum flips
Day 75: Bit Manipulation — single number (XOR), two odd occurrences, power set
Day 76: Bit Manipulation — XOR from L to R, Nth magic number, divide without division, reverse bits
Day 77: Stack and Queue — implement using arrays and LLs, balanced parentheses, Min Stack
Day 78: Stack and Queue — implement Stack using Queue, Queue using Stack
Day 79: Prefix/Infix/Postfix — infix to postfix, infix to prefix, evaluate postfix
Day 80: Monotonic Stack — next greater element 1 and 2, next smaller, previous greater
Day 81: Monotonic Stack — previous smaller, stock span, asteroid collision
Day 82: Monotonic Stack — sum of subarray ranges, remove K digits
Day 83: Monotonic Stack — largest rectangle in histogram (very important)
Day 84: Stack Hard — sliding window max, LRU Cache + REVISION

---

### PHASE 3 — ADVANCED TOPICS (Days 85–140)

**Days 85–91: Sliding Window + Heaps**
Day 85: Sliding Window Medium — at most K zeros, fruit baskets, all three chars
Day 86: Sliding Window Medium — max points from cards, char replacement, binary subarrays
Day 87: Sliding Window Hard — longest without repeating, minimum window substring
Day 88: Sliding Window Hard — max consecutive ones 3, K different integers, nice subarrays
Day 89: Heaps — introduction, min/max heap, heap sort, priority queue
Day 90: Heaps Medium — Kth largest, Kth smallest, sort K-sorted array, merge K sorted lists
Day 91: Heaps Medium/Hard — rank elements, task scheduler, K closest, find median + REVISION

**Days 92–98: Greedy + Binary Trees start**
Day 92: Greedy Easy — assign cookies, fractional knapsack, minimum coins
Day 93: Greedy Easy — lemonade change, valid parenthesis string, jump game 1 and 2
Day 94: Greedy Medium — job sequencing, N meetings in one room, minimum platforms
Day 95: Greedy Medium/Hard — unlimited stocks greedy, insert intervals, non-overlapping intervals, candy
Day 96: REVISION of Greedy
Day 97: Binary Trees — introduction, representation, level order traversal
Day 98: Binary Trees — preorder, inorder, postorder (recursive and iterative)

**Days 99–117: Binary Trees**
Day 99: Binary Trees — preorder/inorder/postorder in single traversal
Day 100: Binary Trees — height, balance check, diameter
Day 101: Binary Trees — maximum path sum (hard, crucial)
Day 102: Binary Trees — count nodes, check identical trees
Day 103: Binary Trees Medium — zigzag traversal, boundary traversal
Day 104: Binary Trees Medium — vertical order traversal
Day 105: Binary Trees Medium — top view, bottom view
Day 106: Binary Trees Medium — right view, left view, symmetric tree
Day 107: Binary Trees Medium — all paths root to leaf, LCA
Day 108: Binary Trees Medium — maximum width, nodes at distance K
Day 109: Binary Trees Medium — minimum time to burn tree, count complete tree nodes
Day 110: Binary Trees Medium — construct from inorder+preorder
Day 111: Binary Trees Medium — construct from inorder+postorder + revision of medium
Day 112: Binary Trees Hard — flatten to linked list, Morris inorder traversal
Day 113: Binary Trees Hard — Morris preorder, serialize and deserialize
Day 114: REVISION of all Binary Tree problems
Day 115: BST — introduction, search, min/max, floor and ceil
Day 116: BST — insert, delete (3 cases), Kth smallest, Kth largest
Day 117: BST — validate BST, LCA in BST, construct BST from preorder

**Days 118–124: BST + Graphs start**
Day 118: BST Hard — two sum in BST, recover BST, largest BST in tree, BST iterator
Day 119: REVISION of BST
Day 120: Graphs — representation, BFS traversal
Day 121: Graphs — DFS traversal, connected components, number of provinces
Day 122: Graphs — detect cycle undirected BFS, detect cycle undirected DFS
Day 123: Graphs — detect cycle directed DFS, flood fill, rotten oranges
Day 124: Graphs — 01 matrix, surrounded regions, number of enclaves, bipartite check

---

### PHASE 4 — GRAPHS + DP (Days 125–179)

**Days 125–140: Graphs continued**
Day 125: Topological sort DFS and Kahn's algorithm
Day 126: Detect cycle in directed graph using Kahn's, course schedule 1 and 2
Day 127: Find eventual safe states, Alien dictionary
Day 128: Dijkstra's algorithm — understand and implement from scratch
Day 129: Dijkstra problems — network delay, cheapest flights, number of ways
Day 130: Dijkstra problems continued — minimum effort, maximum probability
Day 131: Bellman-Ford, Floyd-Warshall
Day 132: Shortest path in unweighted graph, shortest path in DAG
Day 133: Prim's algorithm for MST
Day 134: Kruskal's algorithm + Union-Find (DSU — very important to learn)
Day 135: DSU problems — make network connected, stones removed, accounts merge
Day 136: Graphs — number of islands, making large island
Day 137: SCC — Kosaraju's algorithm
Day 138: Bridges and articulation points (Tarjan's algorithm)
Day 139: Word ladder 1
Day 140: Word ladder 2 + REVISION of all Graphs

**Days 141–179: Dynamic Programming**
Day 141: DP Introduction — memoization vs tabulation, Fibonacci both ways
Day 142: DP 1D — climbing stairs, frog jump
Day 143: DP 1D — frog jump K distances, house robber 1 and 2, ninja training
Day 144: DP 2D Grid — unique paths 1 and 2
Day 145: DP 2D Grid — minimum path sum, minimum falling path sum
Day 146: DP 2D Grid — ninja and friends (3D DP), gold mine, triangle
Day 147: DP Subsequences — subset sum = target, partition equal subset
Day 148: DP Subsequences — min absolute difference partition, count subsets with sum
Day 149: DP Subsequences — 0/1 Knapsack (master this completely)
Day 150: DP Subsequences — unbounded knapsack, rod cutting
Day 151: DP Subsequences — coin change 1 and 2, minimum elements to sum
Day 152: DP Strings — LCS (master this)
Day 153: DP Strings — longest common substring, longest palindromic subsequence
Day 154: DP Strings — edit distance (master this)
Day 155: DP Strings — wildcard matching, regex matching
Day 156: DP Strings — count distinct subsequences, min insertion to make palindrome
Day 157: DP Strings — min insert/delete to convert, shortest common supersequence
Day 158: REVISION of DP on strings
Day 159: DP Stocks — buy sell 1 and 2
Day 160: DP Stocks — buy sell 3 (at most 2 transactions), buy sell 4 (K transactions)
Day 161: DP Stocks — buy sell with cooldown, buy sell with fee
Day 162: DP LIS — longest increasing subsequence O(n^2) and O(n log n)
Day 163: DP LIS — print LIS, largest divisible subset, longest string chain
Day 164: DP LIS — longest bitonic subsequence
Day 165: DP Partitions — matrix chain multiplication
Day 166: DP Partitions — min cost to cut stick, burst balloons
Day 167: DP Partitions — evaluate boolean expression, palindrome partitioning 2
Day 168: GRAND REVISION of all DP
Day 169: Tries — introduction, implement Trie (insert, search, startsWith)
Day 170: Tries — implement Trie 2, longest string with all prefixes
Day 171: Tries — count distinct substrings, max XOR of two numbers, max XOR with element
Day 172: Advanced Strings — Z-algorithm
Day 173: Advanced Strings — KMP failure function, KMP search
Day 174: Advanced Strings — min chars to make palindrome, Rabin-Karp
Day 175: Advanced Strings — count anagram occurrences, min window substring, string match
Day 176: REVISION of Tries and Advanced Strings
Day 177: GRAND REVISION — Basics to Binary Search
Day 178: GRAND REVISION — LL, Recursion, Bit Manipulation, Stack and Queue
Day 179: GRAND REVISION — Trees, Graphs, DP

---

## DAILY ROUTINE (2 Hours)

The way to split your 2 hours every day:

First 10 minutes: Briefly review what you solved yesterday. Just glance at the code and the logic.

Next 40 minutes: Watch Striver's video for the new concept or problem. Pause frequently. Don't watch passively. Have a code editor or notebook open.

Next 70 minutes: Solve the problems yourself. Close the solution. Try completely on your own first for at least 20 minutes. If stuck, re-watch the relevant part and try again.

---

## RULES TO FOLLOW

Rule 1: Never copy paste code. Type every solution yourself. This builds muscle memory.

Rule 2: For every problem, understand at least two approaches — the brute force and the optimal. Know why the brute force is slow.

Rule 3: Time yourself only after you've fully understood a topic. Not during learning phase.

Rule 4: If you can't solve a problem in 30 minutes, watch the hint or editorial, understand it, close it, and code from scratch yourself. This is more important than blindly not watching.

Rule 5: Write the time complexity and space complexity for every single problem you solve. This is what interviewers ask first.

Rule 6: Revise at the end of every week. Spend 30 minutes of your 2-hour slot on Friday or Saturday going back over the week's problems.

Rule 7: Don't skip problems. Every problem in Striver's sheet is there for a reason. Even if it looks easy.

Rule 8: Prefer Striver's explanations over random YouTube videos. The sheet and his videos are designed together.

---

## MOST IMPORTANT PROBLEMS (Must Know for Interviews)

If you are doing the sheet for interview prep specifically, these are the 25 problems that appear most frequently in FAANG and top company interviews:

1. Kadane's Algorithm
2. Median of Two Sorted Arrays
3. LRU Cache
4. Trapping Rainwater (related to histogram)
5. Largest Rectangle in Histogram
6. Word Ladder
7. Serialize and Deserialize Binary Tree
8. LCA of Binary Tree
9. Maximum Path Sum in Binary Tree
10. Flatten Binary Tree to Linked List
11. Edit Distance
12. Longest Common Subsequence
13. 0/1 Knapsack
14. Coin Change
15. Buy and Sell Stocks (all variants)
16. Merge K Sorted Lists
17. Course Schedule (Topological Sort)
18. Dijkstra's Algorithm
19. Union-Find (DSU)
20. Minimum Window Substring
21. Longest Increasing Subsequence
22. Matrix Chain Multiplication
23. N-Queens
24. Word Search
25. Accounts Merge

---

## TIPS FOR DIFFERENT DIFFICULTY LEVELS

For Easy problems: These should take 10–20 minutes. If they take more than 30 minutes, your foundations need more time. Don't rush to medium.

For Medium problems: Budget 30–45 minutes. First attempt on your own, then look at hints if stuck. These form the bulk of actual interview questions.

For Hard problems: Budget 45–60 minutes. For hard problems, watching the explanation first and then coding is perfectly fine. Understanding the pattern is more important than struggling blindly.

---

## WHAT NOT TO DO

Do not do this sheet in parallel with another DSA sheet. This one is comprehensive enough.

Do not try to do more than 2–3 new problems a day during heavy topics like DP or Graphs. Depth beats breadth.

Do not skip the video for medium and hard problems. Striver explains the intuition that is hard to get from text alone.

Do not measure progress only by problem count. Measure it by how confidently you can explain the solution to someone else.

Do not ignore time complexity. If you can't tell the interviewer the complexity of your solution, the solution doesn't count.

---

## FINAL SUMMARY TABLE

Topic                    | Problems | Days (2hrs/day)
-------------------------|----------|----------------
Step 1: Basics           | 31       | 8
Step 2: Sorting          | 7        | 4
Step 3: Arrays           | 40       | 14
Step 4: Binary Search    | 32       | 12
Step 5: Strings          | 15       | 6
Step 6: Linked List      | 31       | 12
Step 7: Recursion        | 25       | 12
Step 8: Bit Manipulation | 18       | 6
Step 9: Stack and Queue  | 30       | 12
Step 10: Sliding Window  | 12       | 6
Step 11: Heaps           | 17       | 7
Step 12: Greedy          | 15       | 6
Step 13: Binary Trees    | 38       | 16
Step 14: BST             | 16       | 7
Step 15: Graphs          | 53       | 21
Step 16: DP              | 55       | 21
Step 17: Tries           | 7        | 4
Step 18: Adv Strings     | 9        | 5
-------------------------|----------|----------------
TOTAL                    | 474      | ~179 days

At 2 hours per day with consistency, you will complete the sheet in approximately 6 months. With weekend buffer and revision days built in, plan for 7 months to be safe.

Start date: Day 1
Target end date: ~7 months from start

Good luck. The sheet is hard. It is supposed to be hard. Every problem you solve compounds your understanding. The people who finish it are not smarter — they are more consistent.
