input & output是一切实现的基础。

- stdio：标准IO 
- sysio：系统调用IO

stdio是一套系统提供给用户的公有io api，所有操作系统都必须实现的一套io api。

sysio可以理解成是操作系统私有的io，可能每个系统的sysio都不同。

这里以stdio中的fopen函数为例，它在linux环境下依赖的sysio就是open函数，在windows中依赖的sysio则是openfile函数。



