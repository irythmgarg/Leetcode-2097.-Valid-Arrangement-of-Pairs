# Leetcode-2097.-Valid-Arrangement-of-Pairs
# Valid Arrangement of Pairs

## 🧩 Problem Statement

You are given a list of pairs where for every adjacent pair `(a, b)` and `(c, d)` in the output, `b` should equal `c`. Your task is to reorder the pairs such that this condition holds true.
This is equivalent to finding an **Eulerian path** in a directed graph where each edge is a pair `(u, v)`.

---

## 💡 Approach

We use **Hierholzer’s Algorithm** to find the Eulerian path:

1. **Graph Representation:**
   - Each pair is treated as a directed edge `u -> v`.
   - We build an adjacency list and track in-degrees and out-degrees of each node.

2. **Determine Starting Node:**
   - If a node has `out-degree - in-degree == 1`, it's the starting point.
   - Otherwise, we start from the first node of the first pair.

3. **Build the Path:**
   - Use a stack to simulate Hierholzer’s algorithm and construct the path.
   - The path is reversed at the end since we backtrack during the DFS.

4. **Form the Result:**
   - Convert the list of visited nodes into pair format.

---

## 🛠️ Example

### Input
```cpp
pairs = {{5,1},{4,5},{11,9},{9,4}}

🧠 Time and Space Complexity
Time: O(N) — where N is the number of pairs.

Space: O(N) — for the graph and stack.

🚀 Topics Covered
Graph traversal
Eulerian path
Hierholzer’s algorithm
Stack-based DFS
