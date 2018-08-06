#include "ImgWidget.h"

//************************************
// Method:    ImgWidget
// FullName:  ImgWidget::ImgWidget
// Access:    public 
// Returns:   
// Qualifier:
//************************************
ImgWidget::ImgWidget(QWidget *parent)
{
	image = new QImage;
	isEmptyFlag = false;
}


//************************************
// Method:    ~ImgWidget
// FullName:  ImgWidget::~ImgWidget
// Access:    public 
// Returns:   
// Qualifier:
//************************************
ImgWidget::~ImgWidget()
{
}

//************************************
// Method:    setImage
// FullName:  ImgWidget::setImage
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void ImgWidget::setImage(QString  imgFilePath)
{
	image->load(imgFilePath);
	isEmptyFlag = true;
}

//************************************
// Method:    isImageEmpty
// FullName:  ImgWidget::isImageEmpty
// Access:    public 
// Returns:   bool
// Qualifier:
//************************************
bool ImgWidget::isImageEmpty()
{
	return isEmptyFlag;
}

//************************************
// Method:    paintEvent
// FullName:  ImgWidget::paintEvent
// Access:    protected 
// Returns:   void
// Qualifier:
// Parameter: QPaintEvent * event
//************************************
void ImgWidget::paintEvent(QPaintEvent *event)
{
	QPainter     painter(this);
	painter.begin(this);
	if (isEmptyFlag)
	{
		painter.drawImage(0, 0, *image);
	}

}
