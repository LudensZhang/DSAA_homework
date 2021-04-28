# <center> 图作业 </center>
#### <p align="Right"> 登峰1901 张皓鸿 </p>
#### 7.1

|顶点编号|1|2|3|4|5|6|
|------|---|---|---|---|---|---|
|入度|3|2|1|1|2|2|2|
|出度|0|2|2|3|1|3


邻接矩阵如下
$$
\begin{array}{c|cc}
    & 1 & 2 & 3 & 4 & 5 & 6 \\ \hline
  1 & \infty & \infty & \infty & \infty & \infty & \infty \\
  2 & 1 & \infty & \infty & 1 & \infty & \infty \\
  3 & \infty & 1 & \infty & \infty & \infty & 1 \\
  4 & \infty & \infty & 1 & \infty & 1 & 1 \\
  5 & 1 & \infty & \infty & \infty & \infty & \infty \\
  6 & 1 & 1 & \infty & \infty & 1 & \infty \\
\end{array}
$$

邻接表如下

![](1_1.jpg)

逆邻接表如下

![](1_2.jpg)

强连通分量为{2，3，4，6}，{1}，{5}

#### 7.3
