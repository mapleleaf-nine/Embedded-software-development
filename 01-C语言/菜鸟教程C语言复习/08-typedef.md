1. typedef与#define区别
- typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
- typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。
- #define可以使用其他类型说明符对宏类型名进行扩展，但对 typedef 所定义的类型名却不能这样做。例如：
```c
#define INTERGE int;
unsigned INTERGE n;  //没问题
typedef int INTERGE;
unsigned INTERGE n;  //错误，不能在 INTERGE 前面添加 unsigned
```
- 在连续定义几个变量的时候，typedef 能够保证定义的所有变量均为同一类型，而 #define 则无法保证。例如：
```c
#define PTR_INT int *
PTR_INT p1, p2;        //p1、p2 类型不相同，宏展开后变为int *p1, p2;
typedef int * PTR_INT
PTR_INT p1, p2;        //p1、p2 类型相同，它们都是指向 int 类型的指针。
```
2. #define与const  
角度1：
就定义常量说的话：
const 定义的常数是变量 也带类型， #define 定义的只是个常数 不带类型。  
角度2：
就起作用的阶段而言：
define是在编译的预处理阶段起作用，而const是在 编译、运行的时候起作用。  
角度3：
就起作用的方式而言：
define只是简单的字符串替换，没有类型检查。而const有对应的数据类型，是要进行判断的，可以避免一些低级的错误。  
正因为define只是简单的字符串替换会导致边界效应，具体举例可以参考下面代码：
```c
#define N 2+3 //我们预想的N值是5，我们这样使用N
double a = N/2;  //我们预想的a的值是2.5，可实际上a的值是3.5
```  
角度4：
就空间占用而言：
例如：
```c
#define PI 3.14     //预处理后 占用代码段空间
const float PI=3.14;    //本质上还是一个 float，占用数据段空间
```  
角度5：
从代码调试的方便程度而言：
const常量可以进行调试的，define是不能进行调试的，因为在预编译阶段就已经替换掉了。
角度6：
从是否可以再定义的角度而言：
const不足的地方，是与生俱来的，const不能重定义，而#define可以通过#undef取消某个符号的定义，再重新定义。  
角度7：
从某些特殊功能而言：
define可以用来防止头文件重复引用，而const不能，可以参看下面代码：
```c
//主要把以下代码放在头文件中，可以防止头文件被重复引用
#ifndef xxx//如果没有定义xxx
#define xxx//定义xxx

//这里是你的代码

#endif //结束如果
```  
PS： 下面说一下，头文件被重复引用的弊端：
（1） 有些头文件重复引用只是增加了编译工作的工作量，不会引起太大的问题，仅仅是编译效率低一些，但是对于大工程而言编译效率低下那将是一件多么痛苦的事情。
（2） 有些头文件重复包含，会引起错误，比如在头文件中定义了全局变量(虽然这种方式不被推荐，但确实是C规范允许的)这种会引起重复定义。  
角度8：
从某些复杂功能的实现的实现角度来看：
使用define会使得代码看起来非常简单，而const无法实现该功能
例如，MFC在实现六大核心机制中，大量使用了define  
1、MFC程序的初始化  
2、运行时类型识别（RTTI）  
3、动态创建  
4、永久保存  
5、消息映射  
6、消息传递  
比如，在实现RTTI功能的时候，定义了如下宏，代码如下：
```c
#define DECLARE_DYNCREATE(class_name) \

    DECLARE_DYNAMIC(class_name)\

    static CObject* PASCALCreateObject();
```
