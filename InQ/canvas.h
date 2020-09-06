#ifndef CANVAS_H
#define CANVAS_H

//#include <QObject>
#include <QWidget>
#include<QMouseEvent>
#include<QPainter>
#include<QFileDialog>


class Canvas : public QWidget
{
    // Declares our class as a QObject which is the base class
    // for all Qt objects
    // QObjects handle events
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas() override;

    virtual void mousePressEvent(QMouseEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    virtual void mouseReleaseEvent(QMouseEvent *e) override;
    virtual void paintEvent(QPaintEvent *e) override;        // Updates the scribble area where we are painting.
    virtual void resizeEvent(QResizeEvent *e) override;      // Makes sure the area we are drawing on remains as large as the widget.

    void init();
    bool openImage();

    QImage getImage();
    void setImage(QImage image);

    void resize(int w, int h);
    void clear();

    void setBrushWidth (int setBrushWidth);

    void setColor(QColor setColor);
    QColor getColor();

    QColor getPrevColor() const;
    void setPrevColor(const QColor &val);

    Qt::PenStyle getPenStyle() const;
    void setPenStyle(const Qt::PenStyle &val);

    Qt::PenCapStyle getCapStyle() const;
    void setCapStyle(const Qt::PenCapStyle &val);

    Qt::PenJoinStyle getJoinStyle() const;
    void setJoinStyle(const Qt::PenJoinStyle &val);

    bool getIsRectangle() const;
    void setIsRectangle(bool val);

    bool getIsCircle() const;
    void setIsCircle(bool val);

    bool getIsTriangle() const;
    void setIsTriangle(bool val);

    bool getIsStraightLine() const;
    void setIsStraightLine(bool val);

    bool getIsPentagon() const;
    void setIsPentagon(bool val);

    bool getIsHexagon() const;
    void setIsHexagon(bool val);

    bool getIsFourPointStar() const;
    void setIsFourPointStar(bool val);

    bool getIsArrow() const;
    void setIsArrow(bool val);

    bool getIsLine() const;
    void setIsLine(bool val);

    bool getIsFilling() const;
    void setIsFilling(bool val);

    QColor getFillColor() const;
    void setFillColor(const QColor &val);

    QImage getCopyDrawing() const;
    void setCopyDrawing(const QImage &val);

    void floodFill(const QPoint &floodFillStartPoint, QColor floodFillColor);

private:
    QImage canvas;
    QImage copyDrawing;
    QPoint lastPoint;
    QPoint firstPoint;
    QColor currentColor;
    QColor prevColor;
    QColor fillColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;
    int brushWidth;
    bool isDrawing;
    bool isLine;
    bool mousePressed;
    bool isRectangle;
    bool isCircle;
    bool isTriangle;
    bool isStraightLine;
    bool isPentagon;
    bool isHexagon;
    bool isFourPointStar;
    bool isArrow;
    bool isFilling;

//signals:

};

#endif // CANVAS_H
