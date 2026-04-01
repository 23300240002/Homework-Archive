# 02 傅里叶分析

## 一、知识点讲解

### 1. 信号空间与正交分解

在信号处理中，常常把信号看作**向量**，但这里的向量不是三维空间中的箭头，而是无穷维空间中的一个点。每个时刻的取值对应一个“坐标”，因此连续时间信号 $x(t)$ 可以视为无穷维向量，离散序列 $x[n]$ 则可视为可数无穷维向量。

#### 1.1 内积与范数

- **内积**（Inner Product）衡量两个信号的“相似程度”或一个信号在另一个信号上的投影大小。
  - 连续时间：$\langle x(t), y(t) \rangle = \int_{-\infty}^{\infty} x(t) y^{*}(t) \, dt$
  - 离散时间：$\langle x[n], y[n] \rangle = \sum_{n=-\infty}^{\infty} x[n] y^{*}[n]$
  - 其中 $y^{*}(t)$ 表示复共轭。若信号为实信号，则共轭可省略。

- **范数**（Norm）表示信号的长度或能量：
  - $\|x(t)\| = \sqrt{\langle x(t), x(t) \rangle} = \sqrt{\int_{-\infty}^{\infty} |x(t)|^{2} dt}$
  - 这就是信号**能量**的平方根。

#### 1.2 正交与正交基

- 若两个信号的内积为零，即 $\langle x, y \rangle = 0$，则称它们**正交**（orthogonal）。
- **正交函数集**：一组函数 $\{\phi_1(t), \phi_2(t), \dots, \phi_n(t)\}$，其中任意两个不同的函数正交。
- **完备正交函数集**：如果该函数集中函数个数趋于无穷时，能够用来**精确表示**任何满足一定条件的信号（例如均方收敛），则称该函数集是完备的。
  - 常用的完备正交函数集：三角函数集 $\{1, \cos\omega t, \cos2\omega t, \dots, \sin\omega t, \sin2\omega t, \dots\}$，在区间 $[t_0, t_0+T]$ 上（$T=2\pi/\omega$）是完备的。
  - 另一个重要完备集：复指数函数集 $\{e^{j n\omega t}\}$。

#### 1.3 正交分解与傅里叶级数的思想

任意信号 $f(t)$ 在区间 $[t_1, t_2]$ 上可以用一组正交函数 $\{\phi_k(t)\}$ 的线性组合近似：

$$
f(t) \approx \sum_{k=1}^{n} c_k \phi_k(t)
$$

在最小均方误差意义下，系数为：

$$
c_k = \frac{\langle f(t), \phi_k(t) \rangle}{\langle \phi_k(t), \phi_k(t) \rangle} = \frac{\int_{t_1}^{t_2} f(t) \phi_k^{*}(t) dt}{\int_{t_1}^{t_2} |\phi_k(t)|^{2} dt}
$$

当 $n\to\infty$ 且函数集完备时，上式成为精确等式，这就是**正交分解**。傅里叶级数正是用三角函数（或复指数）作正交分解的结果。

---

### 2. 傅里叶级数（周期信号）

#### 2.1 三角形式傅里叶级数

设周期信号 $f(t)$ 周期为 $T$，角频率 $\omega = \frac{2\pi}{T}$。在满足狄利克雷条件（一个周期内绝对可积、有限个极值点、有限个间断点）时，可以展开为：

$$
f(t) = a_0 + \sum_{n=1}^{\infty} \left[ a_n \cos(n\omega t) + b_n \sin(n\omega t) \right]
$$

系数计算公式：

$$
\begin{aligned}
a_0 &= \frac{1}{T} \int_{0}^{T} f(t) \, dt \\[4pt]
a_n &= \frac{2}{T} \int_{0}^{T} f(t) \cos(n\omega t) \, dt \\[4pt]
b_n &= \frac{2}{T} \int_{0}^{T} f(t) \sin(n\omega t) \, dt
\end{aligned}
$$

（积分区间也可取任意一个周期，如 $[-T/2, T/2]$。）

**物理意义**：周期信号可以分解为直流分量 $a_0$ 和一系列正弦、余弦谐波分量之和。

#### 2.2 复指数形式傅里叶级数

利用欧拉公式 $\cos\theta = \frac{e^{j\theta}+e^{-j\theta}}{2}$，$\sin\theta = \frac{e^{j\theta}-e^{-j\theta}}{2j}$，可将三角形式合并为更简洁的复指数形式：

$$
f(t) = \sum_{n=-\infty}^{\infty} F_n \, e^{j n \omega t}
$$

其中傅里叶系数为：

$$
F_n = \frac{1}{T} \int_{0}^{T} f(t) \, e^{-j n \omega t} dt
$$

与三角形式系数的关系：

$$
F_0 = a_0, \quad F_n = \frac{a_n - j b_n}{2}, \quad F_{-n} = \frac{a_n + j b_n}{2} \quad (n>0)
$$

复指数形式在数学上更简洁，且便于与傅里叶变换衔接。

---

### 3. 傅里叶变换（非周期信号）

#### 3.1 从傅里叶级数到傅里叶变换

当周期 $T\to\infty$ 时，周期信号变为非周期信号，谱线间隔 $\omega_0 = \frac{2\pi}{T}\to 0$，离散谱变成连续谱。但各频率分量的幅度趋于无穷小，因此引入**频谱密度函数** $F(\omega)$，定义为：

$$
F(\omega) = \int_{-\infty}^{\infty} f(t) \, e^{-j\omega t} dt
$$

这一运算称为**傅里叶变换**（Fourier Transform）。其逆变换为：

$$
f(t) = \frac{1}{2\pi} \int_{-\infty}^{\infty} F(\omega) \, e^{j\omega t} d\omega
$$

通常记作 $f(t) \leftrightarrow F(\omega)$。

**物理意义**：$F(\omega)$ 表示信号中频率为 $\omega$ 的复指数分量的**密度**；$|F(\omega)|$ 是幅度谱，$\angle F(\omega)$ 是相位谱。

#### 3.2 常见信号的傅里叶变换

- **矩形脉冲**：$f(t) = \operatorname{rect}\left(\frac{t}{\tau}\right) = \begin{cases} 1, & |t|<\tau/2 \\ 0, & \text{其他} \end{cases}$  
  $$F(\omega) = \tau \cdot \operatorname{sinc}\left(\frac{\omega\tau}{2}\right) = \frac{2\sin(\omega\tau/2)}{\omega}$$
  其中 $\operatorname{sinc}(x)=\sin x/x$。

- **升余弦信号**：$f(t) = \frac{1}{2}\left[1+\cos\left(\frac{2\pi t}{\tau}\right)\right] \operatorname{rect}\left(\frac{t}{\tau}\right)$ 等，其频谱比矩形脉冲更集中在低频区域。

- **直流信号** $f(t)=1$：  
  $$F(\omega) = 2\pi \delta(\omega)$$

- **余弦信号** $\cos(\omega_0 t)$：  
  $$F(\omega) = \pi \left[ \delta(\omega-\omega_0) + \delta(\omega+\omega_0) \right]$$

- **符号函数** $\operatorname{sgn}(t) = \begin{cases} 1, & t>0 \\ -1, & t<0 \end{cases}$：  
  $$F(\omega) = \frac{2}{j\omega}$$

#### 3.3 傅里叶变换的基本性质

1. **线性**：$a f_1(t) + b f_2(t) \leftrightarrow a F_1(\omega) + b F_2(\omega)$

2. **时移**：$f(t-t_0) \leftrightarrow e^{-j\omega t_0} F(\omega)$

3. **频移**：$f(t) e^{j\omega_0 t} \leftrightarrow F(\omega - \omega_0)$

4. **尺度变换**：$f(at) \leftrightarrow \frac{1}{|a|} F\left(\frac{\omega}{a}\right)$

5. **奇偶性**：若 $f(t)$ 为实函数，则 $F(\omega)$ 的实部为偶函数、虚部为奇函数；若 $f(t)$ 为偶函数，则 $F(\omega)$ 为实偶函数；若 $f(t)$ 为奇函数，则 $F(\omega)$ 为虚奇函数。

6. **时域微分**：$\frac{d^n f(t)}{dt^n} \leftrightarrow (j\omega)^n F(\omega)$

7. **时域积分**：$\int_{-\infty}^{t} f(\tau) d\tau \leftrightarrow \frac{F(\omega)}{j\omega} + \pi F(0) \delta(\omega)$

8. **卷积定理**：
   - 时域卷积：$f_1(t) * f_2(t) \leftrightarrow F_1(\omega) F_2(\omega)$
   - 频域卷积：$f_1(t) f_2(t) \leftrightarrow \frac{1}{2\pi} F_1(\omega) * F_2(\omega)$

---

### 4. 变换的本质

傅里叶变换本质上是一种**坐标变换**：将时域信号变换到频域坐标系中。在频域中，卷积运算变成了乘法，许多复杂问题得以简化。就像在笛卡尔坐标系中圆的方程是二次的，而在极坐标系中圆的方程是线性的 $r = r_0$；傅里叶变换让我们能够从“频率”的角度更清晰地观察信号的结构。

---

## 二、例题讲解

### 例题1：周期信号的傅里叶级数

**题目**  
设周期信号 $f(t) = \begin{cases} 1, & 0 \le t < 1 \\ -1, & 1 \le t < 2 \end{cases}$，周期 $T=2$。求其三角形式傅里叶级数，并写出前三次谐波的表达式。

**参考答案**

周期 $T=2$，角频率 $\omega = \frac{2\pi}{T} = \pi$。计算系数：

- 直流分量：
  $$a_0 = \frac{1}{T} \int_{0}^{T} f(t) dt = \frac{1}{2} \left( \int_{0}^{1} 1 \, dt + \int_{1}^{2} (-1) \, dt \right) = \frac{1}{2} (1 - 1) = 0$$

- $a_n$：
  $$a_n = \frac{2}{T} \int_{0}^{T} f(t) \cos(n\omega t) dt = \int_{0}^{1} \cos(n\pi t) dt + \int_{1}^{2} (-\cos(n\pi t)) dt$$
  由于 $\cos(n\pi t)$ 在 $[0,2]$ 上的对称性，可直接计算：
  $$\int_{0}^{1} \cos(n\pi t) dt = \left.\frac{\sin(n\pi t)}{n\pi}\right|_{0}^{1} = \frac{\sin(n\pi)}{n\pi} = 0$$
  $$\int_{1}^{2} \cos(n\pi t) dt = \left.\frac{\sin(n\pi t)}{n\pi}\right|_{1}^{2} = \frac{\sin(2n\pi)-\sin(n\pi)}{n\pi} = 0$$
  故 $a_n = 0$。

- $b_n$：
  $$b_n = \int_{0}^{1} \sin(n\pi t) dt + \int_{1}^{2} (-\sin(n\pi t)) dt$$
  $$\int_{0}^{1} \sin(n\pi t) dt = \left.-\frac{\cos(n\pi t)}{n\pi}\right|_{0}^{1} = \frac{1-\cos(n\pi)}{n\pi} = \frac{1-(-1)^n}{n\pi}$$
  $$\int_{1}^{2} \sin(n\pi t) dt = \left.-\frac{\cos(n\pi t)}{n\pi}\right|_{1}^{2} = \frac{-\cos(2n\pi)+\cos(n\pi)}{n\pi} = \frac{-1+(-1)^n}{n\pi}$$
  所以第二项取负号后为 $-\int_{1}^{2} \sin(n\pi t) dt = \frac{1-(-1)^n}{n\pi}$。两者相加：
  $$b_n = \frac{2[1-(-1)^n]}{n\pi} = \begin{cases} 0, & n \text{ 偶数} \\ \dfrac{4}{n\pi}, & n \text{ 奇数} \end{cases}$$

因此三角形式傅里叶级数为：
$$f(t) = \sum_{k=0}^{\infty} \frac{4}{(2k+1)\pi} \sin\big((2k+1)\pi t\big)$$

前三次谐波（$k=0,1,2$）：
$$f(t) \approx \frac{4}{\pi} \sin(\pi t) + \frac{4}{3\pi} \sin(3\pi t) + \frac{4}{5\pi} \sin(5\pi t)$$

---

### 例题2：矩形脉冲的傅里叶变换

**题目**  
已知矩形脉冲信号 $f(t) = \begin{cases} 1, & |t| \le \tau/2 \\ 0, & \text{其他} \end{cases}$，求其傅里叶变换 $F(\omega)$，并画出幅度谱草图。

**参考答案**

由定义：
$$F(\omega) = \int_{-\infty}^{\infty} f(t) e^{-j\omega t} dt = \int_{-\tau/2}^{\tau/2} e^{-j\omega t} dt = \left. \frac{e^{-j\omega t}}{-j\omega} \right|_{-\tau/2}^{\tau/2} = \frac{e^{-j\omega \tau/2} - e^{j\omega \tau/2}}{-j\omega} = \frac{2\sin(\omega\tau/2)}{\omega}$$

通常写成 $F(\omega) = \tau \cdot \operatorname{sinc}\left(\frac{\omega\tau}{2}\right)$，其中 $\operatorname{sinc}(x) = \sin x / x$。

幅度谱 $|F(\omega)| = \tau \left|\operatorname{sinc}\left(\frac{\omega\tau}{2}\right)\right|$，在 $\omega=0$ 处 $|F(0)| = \tau$；第一零点位于 $\frac{\omega\tau}{2} = \pi$，即 $\omega = \frac{2\pi}{\tau}$。主瓣宽度为 $\frac{4\pi}{\tau}$。相位谱在 $\frac{\omega\tau}{2}$ 过零点处发生 $\pi$ 跳变。

---

### 例题3：利用傅里叶变换性质求频谱

**题目**  
已知 $f(t) = \operatorname{sinc}(t) = \frac{\sin t}{t}$，利用傅里叶变换的对称性和已知变换，求 $f(t)$ 的傅里叶变换。

**参考答案**

已知矩形脉冲 $g(t) = \begin{cases} 1, & |t| \le 1 \\ 0, & \text{其他} \end{cases}$ 的傅里叶变换为 $G(\omega) = \frac{2\sin\omega}{\omega} = 2\operatorname{sinc}(\omega)$。

根据傅里叶变换的对称性（对偶性）：若 $f(t) \leftrightarrow F(\omega)$，则 $F(t) \leftrightarrow 2\pi f(-\omega)$。

取 $g(t)$ 的傅里叶变换为 $G(\omega) = 2\operatorname{sinc}(\omega)$，则 $G(t) = 2\operatorname{sinc}(t)$ 的傅里叶变换应为 $2\pi g(-\omega) = 2\pi \cdot \begin{cases} 1, & |-\omega| \le 1 \\ 0, & \text{其他} \end{cases} = \begin{cases} 2\pi, & |\omega| \le 1 \\ 0, & \text{其他} \end{cases}$。

因此 $\operatorname{sinc}(t) \leftrightarrow \pi \cdot \begin{cases} 1, & |\omega| \le 1 \\ 0, & \text{其他} \end{cases}$。即 $\frac{\sin t}{t}$ 的傅里叶变换是频域上的矩形脉冲，幅度为 $\pi$，宽度为 $2$。

（也可用定义直接计算，但利用对称性更简洁。）

---

**补充说明**：欧拉公式 $e^{j\theta} = \cos\theta + j\sin\theta$ 是连接三角形式和复指数形式的关键；$\operatorname{sinc}$ 函数在信号处理中广泛出现，其形状为 $\sin x/x$；升余弦信号（如 $\frac{1}{2}[1+\cos(\pi t/\tau)]\operatorname{rect}(t/\tau)$）的频谱能量更集中，常用于通信中的脉冲成形。