## Matrix Tree 定理
G 的所有不同的生成树的个数等于其基尔霍夫矩阵C[G]任何一个 n-1 阶主子式的行列式的绝对值
C[G] = D[G] - A[G];
D[G]为图的度数矩阵:
D[i] = { 0 if i != j, degree[i](点i的度数) if i == j }
A[G] 为图的邻接矩阵
