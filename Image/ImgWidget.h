#pragma once
//制定中文编码
#pragma execution_character_set("utf-8")
#include "QWidget"
#include "QPainter"
#include "QImage"

class ImgWidget:public QWidget
{
	QOBJECT_H
public:
	//公共成员变量
public:
	//公共成员函数
	ImgWidget(QWidget *parent = 0);
	~ImgWidget();
	//成员函数
	void	setImage(QString  imgFilePath);//设置图片
	bool	isImageEmpty();//判断是否有图片文件（true有，false没有）
public slots:
	//公共槽函数

protected:
	//事件函数
	void		paintEvent(QPaintEvent *event);
private:
	//私有成员变量
	QImage		*image;
private:
	//私有成员函数
	bool		isEmptyFlag;//是否有图片文件标志（true有，false没有）
signals:
	//信号
private slots:
	//私有槽函数
};

