#ifndef CANVASDIMENSION_H
#define CANVASDIMENSION_H

#include <QDialog>
#include <QIntValidator>


namespace Ui
{
class CanvasDimension;
}

class CanvasDimension : public QDialog
{
    Q_OBJECT

public:
    explicit CanvasDimension(QWidget *parent = nullptr);
    ~CanvasDimension();
    int getWidth() const;
    int getHeight() const;

    void setWidth(int value);
    void setHeight(int value);

private:
    Ui::CanvasDimension *ui;
    int width;
    int height;
};

#endif // CANVASDIMENSION_H
