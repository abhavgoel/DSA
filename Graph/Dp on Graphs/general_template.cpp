//Only on DAG (Directed Acyclic Graph)
// [ Directed graph without a cycle ]

/*
Why DP is applied only on DAG?
In DP, we need to run base condition first, then the other DP values are calculated using it.
 So, order is important in DP
Eg. 
dp[0]=1
dp[n] = dp[n-1] + dp[n-2]

Almost every DP problem can be represented as DAG
- Each node would be a state
- And arrows are transition


*/

Step 1  - Topologically sort the nodes 