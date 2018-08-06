#pragma once
//指定中文编码
#pragma execution_character_set("utf-8")
#include "QWidget"
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QChartView>
#include "QGridLayout"
QT_CHARTS_USE_NAMESPACE
typedef		struct plotset{
	QChartView				*View;//画图视图
	QChart					*Chart;//画图
	QList<QLineSeries *>	Line;//画曲线
	int						axisXMax;
	int						axisYMax;
}plotset;
class PlotWidget : public QWidget
{
	Q_OBJECT

public:
	QList<QChartView *>		mViewList;			//视图列表
	QList<plotset*>			subplt;				//
public:
	PlotWidget(QWidget *parent = 0);
	~PlotWidget();
	void					InitPlot();	//初始化模块
	plotset					*subplot(int row,int column);//绘制子图
	bool					addLine(plotset *sub);//添加曲线
	bool					updatePlot(int sub,int line, float xval, float yval);//更新曲线
signals:
	void					sendAssert(QString  Text);
private:
	QGridLayout				*m_Layout;			//绘图板
};
