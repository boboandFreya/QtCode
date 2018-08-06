#include "PlotWidget.h"

//************************************
// Method:    Plot
// FullName:  Plot::Plot
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: QWidget * parent
//************************************
PlotWidget::PlotWidget(QWidget *parent)
{
	m_Layout = new QGridLayout;
	setLayout(m_Layout);
}

//************************************
// Method:    ~Plot
// FullName:  Plot::~Plot
// Access:    public 
// Returns:   
// Qualifier:
//************************************
PlotWidget::~PlotWidget()
{

}

//************************************
// Method:    InitMoudle
// FullName:  Plot::InitMoudle
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void PlotWidget::InitPlot()
{

}

//************************************
// Method:    subplot
// FullName:  Plot::subplot
// Access:    public 
// Returns:   QT_CHARTS_NAMESPACE::QChart*
// Qualifier:
//************************************
plotset*  PlotWidget::subplot(int row, int column)
{
	QChart			*tmpplot;
	QLineSeries		*tmpseries, *tmpseries1;
	QChartView		*tmpView;
	plotset			*tmpplt;
	//开辟空间
	tmpplt = new plotset;
	tmpView = new QChartView;
	tmpplot = new QChart;
	tmpseries = new QLineSeries;
	tmpseries1 = new QLineSeries;

	//子图操作
	tmpplot->addSeries(tmpseries);
	tmpplot->addSeries(tmpseries1);
	tmpplot->createDefaultAxes();
 	tmpplot->axisX()->setRange(0, 100);
 	tmpplot->axisY()->setRange(0, 110);
	tmpplot->setTitle("Simple line chart example");
	//曲线操作
	tmpseries->setUseOpenGL(true);//使用opengl加速
	//视图操作
	tmpView->setRubberBand(QChartView::RectangleRubberBand);//设置曲线可缩放
	tmpView->setChart(tmpplot);
	tmpView->setRenderHint(QPainter::Antialiasing);

	//添加到布局中去
	m_Layout->addWidget(tmpView,row,column);
	//存入列表中去
	tmpplt->View = tmpView;
	tmpplt->Chart = tmpplot;
	tmpplt->Line.append(tmpseries);
	tmpplt->Line.append(tmpseries1);
	tmpplt->axisXMax = 100;
	tmpplt->axisYMax = 100;
	subplt.append(tmpplt);
	return	tmpplt;
}

bool	 PlotWidget::addLine(plotset *sub)
{
	if (!(sub->Chart==NULL))
	{
		QLineSeries		*tmpseries;
		tmpseries = new QLineSeries;
		sub->Chart->addSeries(tmpseries);
		//曲线操作
		tmpseries->setUseOpenGL(true);//使用opengl加速
		sub->Line.append(tmpseries);
		return true;
	}
	return		false;
}

//************************************
// Method:    updatePlot
// FullName:  PlotWidget::updatePlot
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: int sub 子图的索引值(视图中第几个子图)
// Parameter: int line 子图中曲线的索引值(子图中第几根曲线)
// Parameter: float xval x值（坐标）
// Parameter: float yval y值（坐标）
//************************************
bool PlotWidget::updatePlot(int sub, int line, float xval, float yval)
{
	int subcnt;
	int linecnt;
	plotset			*tmpplt;
	QList<QLineSeries *>	LineList;
	subcnt = subplt.count();
	if (sub<subcnt)
	{
		tmpplt = subplt.at(sub);
		LineList = tmpplt->Line;
		linecnt = LineList.count();
		if (line<linecnt)
		{
			QLineSeries				*TempLine;

			TempLine = LineList.at(line);
			if (xval>= tmpplt->axisXMax)
			{
				tmpplt->axisXMax += xval;
				tmpplt->Chart->axisX()->setMax(tmpplt->axisXMax);
			}
			if (yval>= tmpplt->axisYMax)
			{
				tmpplt->axisYMax += yval;
				tmpplt->Chart->axisY()->setMax(tmpplt->axisYMax);
			}
			*TempLine << QPointF(xval, yval);
			return  true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

