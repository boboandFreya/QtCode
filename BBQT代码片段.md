BBQT

QT学习总结：

1.VS+QT，QT中文乱码问题:

    //在确保VS中cpp，h文件的保存格式为utf-8,在文件开头添加下面代码，只对当前文本起作用
    //指定编码格式为utf-8
    #pragma execution_character_set("utf-8")

2.Windows方法调用外部dll文件

    #include "windows.h"
    m_hModule = LoadLibrary(L"serial.dll");

3.Windows下阻止Windows系统睡眠造成程序停止运行

    //在main文件里添加下面代码
    #include <Windows.h>
    //在main函数里添加下面代码
    SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);





