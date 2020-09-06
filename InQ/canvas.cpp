#include "canvas.h"
#include <QImage>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QQueue>


#define x1 firstPoint.x()
#define y1 firstPoint.y()
#define x2 lastPoint.x()
#define y2 lastPoint.y()



Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    init();
}

Canvas::~Canvas() {}

void Canvas::init()
{
    canvas=QImage(this->size(),QImage::Format_RGB32);
    canvas.fill(Qt::white);
    setColor(Qt::black);
    setFillColor(Qt::blue);
    setBrushWidth(1);
    setPenStyle(Qt::SolidLine);
    setCapStyle(Qt::RoundCap);
    setJoinStyle(Qt::RoundJoin);
    setIsLine(true);
    setIsCircle(false);
    setIsTriangle(false);
    setIsRectangle(false);
    setIsStraightLine(false);
    setIsPentagon(false);
    setIsHexagon(false);
    setIsFourPointStar(false);
    setIsFilling(false);
    setIsArrow(false);
    mousePressed = false;
}

bool Canvas::openImage()
{
    QString openImageLocation = QFileDialog::getOpenFileName(this, tr("Open image"), "", tr("PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)" ));
    if(!openImageLocation.isEmpty())
    {
        canvas.load(openImageLocation);
        return true;
    }
    else
    {
        return false;
    }
}

void Canvas::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        firstPoint = e->pos();
        lastPoint = e->pos();

        isDrawing = true;
        mousePressed = true;
        QColor clr=canvas.pixelColor(lastPoint);
        //clr.fromRgb(canvas.pixel(lastPoint));
        if(isFilling)
        {
            floodFill(lastPoint,clr);
        }
    }
    update();
}

void Canvas::mouseMoveEvent(QMouseEvent *e)
{
    if ((e->buttons() & Qt::LeftButton) && isDrawing)
    {
        lastPoint = e->pos();
    }
    update();
}

void Canvas::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton && isDrawing)
    {
        isDrawing = false;
        mousePressed = false;
    }
    update();
}

void Canvas::paintEvent(QPaintEvent *e)
{
    static bool wasMousePressed=false;
    QRect dirtyRect=e->rect();
    QPainter painter(this);
    painter.drawImage(dirtyRect,canvas,dirtyRect);
    if(mousePressed)
    {
        wasMousePressed=true;
        if(getIsCircle())
        {
            QRect circle=QRect(firstPoint,lastPoint);
            QPainter circlePainter(this);
            circlePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            circlePainter.drawEllipse(circle);
            if(isFilling)
            {
                QBrush fillBrush(fillColor);
                QPainterPath path;
                path.addEllipse(circle);
                painter.fillPath(path,fillBrush);
            }
        }
        else if (getIsRectangle())
        {
            QRect rect = QRect(firstPoint, lastPoint);
            QPainter rectanglePainter(this);
            rectanglePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            rectanglePainter.drawRect(rect);
            if (isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addRoundedRect(rect,brushWidth, brushWidth);
                painter.fillPath(path,fillbrush);
            }
        }
        else if (getIsTriangle())
        {
            QPainter trianglePainter(this);
            trianglePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            //QPoint *points = new QPoint[3];
            QVector<QPoint>points(3);
            points[0] = QPoint(x1, y2);
            points[1] = QPoint(((x1 + x2) / 2), y1);
            points[2] = QPoint(x2,y2);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2];
            trianglePainter.drawPolygon(polygon);
            if (isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if(getIsPentagon())
        {
            QPainter pentagonPainter(this);
            pentagonPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QVector<QPoint>points(5);
            points[0]=QPoint(x1,((3*y1+2*y2)/5));
            points[4]=QPoint(((x1 + x2) / 2), y1);
            points[1]=QPoint(((3*x1)+x2)/4,y2);
            points[3]=QPoint(x2,((3*y1+2*y2)/5));
            points[2]=QPoint((x1+(3*x2))/4,y2);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2]<<points[3]<<points[4];
            pentagonPainter.drawPolygon(polygon);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if(getIsHexagon())
        {
            QPainter hexagonPainter(this);
            hexagonPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QVector<QPoint>points(6);
            points[0]=QPoint(x1,y1-((y1-y2)/4));
            points[1]=QPoint(x1,y1-(3*(y1-y2)/4));
            points[2]=QPoint(x1+((x2-x1)/2),y2);
            points[3]=QPoint(x2,y1-(3*(y1-y2)/4));
            points[4]=QPoint(x2,y1-((y1-y2)/4));
            points[5]=QPoint(x1+((x2-x1)/2),y1);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2]<<points[3]<<points[4]<<points[5];
            hexagonPainter.drawPolygon(polygon);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if(getIsFourPointStar())
        {
            QPainter fourpointstarPainter(this);
            fourpointstarPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QVector<QPoint>points(8);
            points[0]=QPoint(x1,y1-((y1-y2)/2));
            points[1]=QPoint(x1+(4*(x2-x1))/10,y1-(6*(y1-y2))/10);
            points[2]=QPoint(x1+((x2-x1)/2),y2);
            points[3]=QPoint(x1+(6*(x2-x1))/10,y1-(6*(y1-y2))/10);
            points[4]=QPoint(x2,y1-((y1-y2)/2));
            points[5]=QPoint(x1+(6*(x2-x1))/10,y1-(4*(y1-y2))/10);
            points[6]=QPoint(x1+((x2-x1)/2),y1);
            points[7]=QPoint(x1+(4*(x2-x1))/10,y1-(4*(y1-y2))/10);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2]<<points[3]<<points[4]<<points[5]<<points[6]<<points[7];
            fourpointstarPainter.drawPolygon(polygon);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if(getIsStraightLine())
        {
            QPainter straightlinePainter(this);
            straightlinePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QVector<QPoint>points(2);
            points[0]=QPoint(firstPoint);
            points[1]=QPoint(lastPoint);

            QPolygon polygon;
            polygon<<points[0]<<points[1];
            straightlinePainter.drawPolygon(polygon);
        }
        else if(getIsArrow())
        {
            QPainter ArrowPainter(this);
            ArrowPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QVector<QPoint>points(7);
            points[0]=QPoint(x1,y1-((y1-y2)/4));
            points[1]=QPoint(x1+(x2-x1)/2,y1-(y1-y2)/4);
            points[2]=QPoint(x1+((x2-x1)/2),y1);
            points[3]=QPoint(x2,y1-(y1-y2)/2);
            points[4]=QPoint(x1+(x2-x1)/2,y2);
            points[5]=QPoint(x1+(x2-x1)/2,y1-(3*(y1-y2))/4);
            points[6]=QPoint(x1,y1-(3*(y1-y2))/4);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2]<<points[3]<<points[4]<<points[5]<<points[6];
            ArrowPainter.drawPolygon(polygon);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else
        {
            QPainter pencilPainter(&canvas);
            pencilPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            pencilPainter.drawLine(lastPoint,firstPoint);
            firstPoint=lastPoint;
        }
    }
    else if(wasMousePressed)
    {
        QPainter painter(&canvas);
        painter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
        if (getIsCircle())
        {
            QRect circle = QRect(firstPoint, lastPoint);
            painter.drawEllipse(circle);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addEllipse(circle);
                painter.fillPath(path, fillbrush);
            }
        }
        else if (getIsRectangle())
        {
            QRect rect = QRect(firstPoint, lastPoint);
            painter.drawRect(rect);
            if (isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addRoundedRect(rect,brushWidth, brushWidth);
                painter.fillPath(path,fillbrush);
            }
        }
        else if (getIsTriangle())
        {
            QPoint *points = new QPoint[3];
            points[0] = QPoint(firstPoint.x(), lastPoint.y());
            points[1] = QPoint(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
            points[2] = QPoint(lastPoint);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2];
            painter.drawPolygon(polygon);
            if (isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if(getIsPentagon())
        {
            //QPainter pentagonPainter(this);
            //pentagonPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QVector<QPoint>points(5);
            points[0]=QPoint(firstPoint.x(),((3*firstPoint.y()+2*lastPoint.y())/5));
            points[4]=QPoint(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
            points[1]=QPoint(((3*firstPoint.x())+lastPoint.x())/4,lastPoint.y());
            points[3]=QPoint(lastPoint.x(),((3*firstPoint.y()+2*lastPoint.y())/5));
            points[2]=QPoint((firstPoint.x()+(3*lastPoint.x()))/4,lastPoint.y());

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2]<<points[3]<<points[4];
            painter.drawPolygon(polygon);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if(getIsHexagon())
        {
            //QPainter hexagonPainter(this);
            //hexagonPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QVector<QPoint>points(6);
            points[0]=QPoint(firstPoint.x(),firstPoint.y()-((firstPoint.y()-lastPoint.y())/4));
            points[1]=QPoint(firstPoint.x(),firstPoint.y()-(3*(firstPoint.y()-lastPoint.y())/4));
            points[2]=QPoint(firstPoint.x()+((lastPoint.x()-firstPoint.x())/2),lastPoint.y());
            points[3]=QPoint(lastPoint.x(),firstPoint.y()-(3*(firstPoint.y()-lastPoint.y())/4));
            points[4]=QPoint(lastPoint.x(),firstPoint.y()-((firstPoint.y()-lastPoint.y())/4));
            points[5]=QPoint(firstPoint.x()+((lastPoint.x()-firstPoint.x())/2),firstPoint.y());

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2]<<points[3]<<points[4]<<points[5];
            painter.drawPolygon(polygon);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if(getIsFourPointStar())
        {
            //QPainter fourpointstarPainter(this);
            //fourpointstarPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QVector<QPoint>points(8);
            points[0]=QPoint(x1,y1-((y1-y2)/2));
            points[1]=QPoint(x1+(4*(x2-x1))/10,y1-(6*(y1-y2))/10);
            points[2]=QPoint(x1+((x2-x1)/2),y2);
            points[3]=QPoint(x1+(6*(x2-x1))/10,y1-(6*(y1-y2))/10);
            points[4]=QPoint(x2,y1-((y1-y2)/2));
            points[5]=QPoint(x1+(6*(x2-x1))/10,y1-(4*(y1-y2))/10);
            points[6]=QPoint(x1+((x2-x1)/2),y1);
            points[7]=QPoint(x1+(4*(x2-x1))/10,y1-(4*(y1-y2))/10);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2]<<points[3]<<points[4]<<points[5]<<points[6]<<points[7];
            painter.drawPolygon(polygon);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if(getIsArrow())
        {
            //QPainter ArrowPainter(this);
            //ArrowPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QVector<QPoint>points(7);
            points[0]=QPoint(x1,y1-((y1-y2)/4));
            points[1]=QPoint(x1+(x2-x1)/2,y1-(y1-y2)/4);
            points[2]=QPoint(x1+((x2-x1)/2),y1);
            points[3]=QPoint(x2,y1-(y1-y2)/2);
            points[4]=QPoint(x1+(x2-x1)/2,y2);
            points[5]=QPoint(x1+(x2-x1)/2,y1-(3*(y1-y2))/4);
            points[6]=QPoint(x1,y1-(3*(y1-y2))/4);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2]<<points[3]<<points[4]<<points[5]<<points[6];
            painter.drawPolygon(polygon);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if(getIsStraightLine())
        {
            //QPainter straightlinePainter(this);
            //straightlinePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QVector<QPoint>points(2);
            points[0]=QPoint(firstPoint);
            points[1]=QPoint(lastPoint);

            QPolygon polygon;
            polygon<<points[0]<<points[1];
            painter.drawPolygon(polygon);
        }
        else
        {
            painter.drawImage(dirtyRect,canvas,dirtyRect);
        }
        wasMousePressed=false;
    }
    update();
}

void Canvas::resizeEvent(QResizeEvent *e)
{
    if (width() != canvas.width() || height() != canvas.height())
    {
        int nWidth, nHeight;

        if (width() > canvas.width())
            nWidth = qMax(width(),canvas.width());
        if (width() <= canvas.width())
            nWidth = canvas.width();
        if (height() > canvas.height())
            nHeight = qMax(height(),canvas.height());
        if (height() <= canvas.height())
            nHeight = canvas.height();

        resize(nWidth,nHeight);
    }
    QWidget::resizeEvent(e);
}

QImage Canvas::getImage()
{
    return canvas;
}
void Canvas::setImage(QImage image)
{
    canvas=image;
}
void Canvas::resize(int w, int h)
{
    QPixmap newImage(QSize(w, h));
    newImage.fill(Qt::white);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), canvas);
    setImage(newImage.toImage());
    update();
}
void Canvas::clear()
{
    canvas.fill(Qt::white);
    update();
}
QColor Canvas::getPrevColor() const
{
    return prevColor;
}
void Canvas::setPrevColor(const QColor &val)
{
    prevColor=val;
}
Qt::PenStyle Canvas::getPenStyle() const
{
    return penStyle;
}

void Canvas::setPenStyle(const Qt::PenStyle &val)
{
    penStyle = val;
}

Qt::PenCapStyle Canvas::getCapStyle() const
{
    return capStyle;
}

void Canvas::setCapStyle(const Qt::PenCapStyle &val)
{
    capStyle = val;
}

Qt::PenJoinStyle Canvas::getJoinStyle() const
{
    return joinStyle;
}

void Canvas::setJoinStyle(const Qt::PenJoinStyle &val)
{
    joinStyle = val;
}
bool Canvas::getIsRectangle() const
{
    return isRectangle;
}

void Canvas::setIsRectangle(bool val)
{
    isRectangle = val;
}

bool Canvas::getIsCircle() const
{
    return isCircle;
}

void Canvas::setIsCircle(bool val)
{
    isCircle = val;
}

bool Canvas::getIsTriangle() const
{
    return isTriangle;
}

void Canvas::setIsTriangle(bool val)
{
    isTriangle = val;
}

bool Canvas::getIsStraightLine() const
{
    return isStraightLine;
}

void Canvas::setIsStraightLine(bool val)
{
    isStraightLine = val;
}

bool Canvas::getIsPentagon() const
{
    return isPentagon;
}

void Canvas::setIsPentagon(bool val)
{
    isPentagon = val;
}

bool Canvas::getIsHexagon() const
{
    return isHexagon;
}

void Canvas::setIsHexagon(bool val)
{
    isHexagon = val;
}

bool Canvas::getIsFourPointStar() const
{
    return isFourPointStar;
}

void Canvas::setIsFourPointStar(bool val)
{
    isFourPointStar = val;
}

bool Canvas::getIsLine() const
{
    return isLine;
}

void Canvas::setIsLine(bool val)
{
    isLine = val;
}

bool Canvas::getIsArrow() const
{
    return isArrow;
}

void Canvas::setIsArrow(bool val)
{
    isArrow = val;
}

bool Canvas::getIsFilling() const
{
    return isFilling;
}

void Canvas::setIsFilling(bool val)
{
    isFilling = val;
}

QColor Canvas::getFillColor() const
{
    return fillColor;
}

void Canvas::setFillColor(const QColor &val)
{
    fillColor = val;
}

QImage Canvas::getCopyDrawing() const
{
    return copyDrawing;
}
void Canvas::setCopyDrawing(const QImage &val)
{
    copyDrawing = val;
}
void Canvas::setColor(QColor setColor)
{
    currentColor = setColor;
}

void Canvas::setBrushWidth(int setBrushWidth)
{
    brushWidth = setBrushWidth;
}

QColor Canvas::getColor()
{
    return currentColor;
}


void Canvas::floodFill(const QPoint &floodFillStartPoint, QColor floodFillColor)
{
    QPainter painter(&canvas);
    QPen floodFillPen(fillColor);
    floodFillPen.setWidth(1);
    painter.setPen(floodFillPen);

    QQueue<QPoint>pixels;
    if(canvas.pixelColor(floodFillStartPoint)!=fillColor)
    {
        pixels.enqueue(floodFillStartPoint);
        painter.drawPoint(floodFillStartPoint);
        update();
    }
    while(!pixels.isEmpty())
    {
        QPoint newPoint=pixels.dequeue();

        QColor actual=canvas.pixelColor(newPoint);


            QPoint left((newPoint.x()-1), newPoint.y());
            if(left.x() >0 && left.x() < canvas.width() && canvas.pixelColor(left) != actual && canvas.pixelColor(left)==floodFillColor)
            {
                pixels.enqueue(left);
                painter.drawPoint(left);
                //update();
            }

            QPoint right((newPoint.x()+1), newPoint.y());
            if(right.x() > 0 && right.x() < canvas.width() &&  canvas.pixelColor(right) != actual && canvas.pixelColor(right)==floodFillColor)
            {
                pixels.enqueue(right);
                painter.drawPoint(right);
                update();
            }

            QPoint up((newPoint.x()), (newPoint.y()-1));
            if(up.y() > 0 && up.y() < canvas.height() &&  canvas.pixelColor(up) != actual && canvas.pixelColor(up)==floodFillColor)
            {
                pixels.enqueue(up);
                painter.drawPoint(up);
                update();
            }

            QPoint down((newPoint.x()), (newPoint.y()+1));
            if(down.y() > 0 && down.y() < canvas.height() &&  canvas.pixelColor(down) != actual && canvas.pixelColor(down)==floodFillColor)
            {
                pixels.enqueue(down);
                painter.drawPoint(down);
                update();
            }
    }
}
