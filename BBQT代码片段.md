BBQT

QT学习总结：

1.VS+QT，QT中文乱码问题:

在确保VS中cpp，h文件的保存格式为utf-8,在文件开头添加下面代码，只对当前文本起作用

    //指定编码格式为utf-8
    #pragma execution_character_set("utf-8")


