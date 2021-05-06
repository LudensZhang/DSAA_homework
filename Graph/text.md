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
邻接多重表如下

![](3.png)
* 深度优先遍历
    * 顶点序列：$V_1,V_2,V_3,V_4,V_5,V_6$  
    * 边序列：$(V_1,V_2),(V_2,V_3),(V_3,V_4),(V_4,V_5),(V_5,V_6)$
* 广度优先遍历
    * 顶点序列：$V_1,V_2,V_3,V_5,V_6,V_4$
    * 边序列：$(V_1,V_2),(V_1,V_3),(V_1,V_5),(V_1,V_6),(V_2,V_4)$

#### 7.7
* 邻接矩阵如下
$$
\begin{array}{c|cc}
    & a & b & c & d & e & f & g & h \\ \hline
  a & \infty & 4 & 3 & \infty & \infty & \infty & \infty & \infty \\
  b & 4 & \infty & 5 & 5 & 9 & \infty & \infty & \infty\\
  c & 3 & 5 & \infty & 5 & \infty & \infty & \infty & \infty \\
  d & \infty & 5 & 5 & \infty & 7 & 6 & 5 & 4 \\
  e & \infty & 9 & \infty & 7 & \infty & 3 & \infty & \infty \\
  f & \infty & \infty & \infty & 6 & 3 & \infty & 2 & \infty \\
  g & \infty & \infty & \infty & 5 & \infty & 2 & \infty & 6 \\
  h & \infty & \infty & \infty & 4 & \infty & \infty & 6 & \infty \\
\end{array}
$$

* 邻接表如下
![](7_1.png)
* 最小生成树如下
![](7_2.png)

#### 7.10

|顶点|ve|vl|弧|e|l|
|---|---|---|---|---|---|
|a|0|0|a-A|||
|A|1|11|a-B|||
|B|6|15|a-D|||
|C|17|17|a-F|||
|D|3|10|a-G|||
|E|34|34|a-I|||
|F|4|8|A-C|||
|G|3|3|B-C|||
|H|13|13|D-C|||
|I|1|7|D-E|||
|J|31|32|D-J|||
|K|22|22|F-E|||
|ω|44|44|F-H|||
||||G-ω|||
||||G-H|||
||||I-H|||
||||C-E|||
||||H-C|||
||||H-J|||
||||H-K|||
||||E-ω|||
||||J-ω|||
