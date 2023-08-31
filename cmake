cmake 入门教程： https://www.hahack.com/codes/cmake/#%E8%87%AA%E5%AE%9A%E4%B9%89%E7%BC%96%E8%AF%91%E9%80%89%E9%A1%B9
configure_file 使用： https://www.jianshu.com/p/2946eeec2489
cmake预定义变量： http://aikejiao.com/Article/62
option用法： https://blog.csdn.net/lhl_blog/article/details/123553686  cmake第一构建时会缓存变量到CMakeCache里，想修改要么删除CmakeCache或者 cmake . -DFFF=ON  对于同一选项，子项目值遵循主项目的定义
             对于这种主、次架构的项目来说，整个工程只有一个CMakeCache.txt，其位于主项目的编译目录下，子项目会根据次此CMakeCache.txt中选项的定义，进行子项目本身的编译CMakeCache.txt。


add_definitions(-DTEST_OPTION)  可以通过 add_definitions()定义相关的宏，已达到控制C程序条件编译流程。
