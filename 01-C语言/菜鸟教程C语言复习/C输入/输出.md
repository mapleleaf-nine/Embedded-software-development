1. fgets()  
gets() 不安全是因为未指定缓冲区大小。可以使用 fgets()。  
```c
char* fgets(char *buf, int bufsize, FILE *stream);
```  
buf：字符型指针，指向用来存储所得数据的地址。  
bufsize：整形数据，指明缓冲区的大小，拷贝到 buf 地址的最大字符数量。  
stream：指明输入流的 FILE 对象的指针，stdin 可以作为参数，表示从标准输入读取。

