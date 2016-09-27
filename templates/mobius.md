# Mobius
Mobius反演的精髓在于根据题意构造两个函数f(n)和F(n),其中F(n)有显式表达式，并且有
$$F(n) = \sum_{d|n}f(d)$$

根据mobius反演可以得到
$$f(n) = \sum_{d|n} \mu (d)F(\frac{n}{d})$$

mobius反演还有另外一种写法:
$$ f(n) = \sum_{n|d}\mu(\frac{d}{n}) F(d)$$

$\mu(d)$成为mobius函数。定义为
> 若$d=1$，则$μ(d)=1$
> 若$d=p1×p2×p3×⋯×pk$， $pi$均为互异质数，则$μ(d)=(−1)^k$
> 否则，$μ(d)=0$

可以通过Euler筛法以O(nlogn)的时间求出mobius函数。


