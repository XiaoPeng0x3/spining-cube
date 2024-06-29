# 旋转ASCII字符立方体

## 0 由来
最近心血来潮,恰好刷到了一个有关旋转ASCII立方体的视频,于是乎我打算重新学习一下计算机图形学,所以打算借这个项目练手一下,主要用到了一些线性代数的知识，包括坐标轴的旋转、点的旋转。

## 1 原理

## 1.1 二维平面中的坐标旋转

在二维平面中，描述一个点可以使用$(x,y)$来进行描述。现在规定绕原点进行逆时针旋转的方向为正方向。那么一个点$P(x_1,y_1)$经过旋转后，假设它旋转到了$P'(x_2,y_2)$这个点，那么可以根据这些点之间的几何关系来表达出来$P$和$P'$之间的关系。

![deduction1](C:\Users\13481\Desktop\spining-cube\Theory\deduction1.jpg)

![deduction2](C:\Users\13481\Desktop\spining-cube\Theory\deduction2.jpg)

![deduction3](C:\Users\13481\Desktop\spining-cube\Theory\deduction3.jpg)

因此，可以得到变换矩阵为：


$$
\begin{bmatrix}
cos(b) & -sin(b)\\
sin(b) & cos(b)
\end{bmatrix}
$$
这里$b$是我们旋转后的角度，所以对于二维平面上任意一个点，我们都可以根据公式得到旋转后的坐标。



## 1.2 三维空间中的旋转坐标

在三维空间里面，我们可以简化讨论整个旋转过程，因为这样可以使用在二维平面里面得到的公式推论。请设想，假设我们只在$$yz$$平面上进行旋转，那么$x$轴的坐标其实是不发生变换的，所以，这样就可以使用我们得到的二维旋转公式了。对三个平面来说，每次只需要分别计算即可。

那么我们假设对点$P(i,j,k)$来说，当绕$x$轴发生转动时，$x$坐标的值不发生变化，那么我们就可以得到绕$x$轴的矩阵为
$$
R(x) = \begin{bmatrix}
	1 & 0 & 0 \\
	0 & cos(b) & -sin(b)\\
	0 & sin(b) & cos(b)
	\end{bmatrix}
$$
同理也可以得到绕$y$轴和$z$轴的旋转矩阵
$$
R(y) = \begin{bmatrix}
cos(b) & 0 & -sin(b)\\
0 & 1 & 0\\
sin(b) & 0 & cos(b)
\end{bmatrix}
$$

$$
R(z) = \begin{bmatrix}

cos(b) & -sin(b) & 0\\
sin(b) & cos(b) & 0\\
0 & 0 & 1

\end{bmatrix}
$$

