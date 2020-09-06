#ifndef MAGNIFIER_H
#define MAGNIFIER_H

#include <QIntValidator>
#include <QDialog>

namespace Ui {
class Magnifier;
}

class Magnifier : public QDialog
{
    Q_OBJECT

public:
    explicit Magnifier(QWidget *parent = nullptr);//for explicit keyword, Magnifier() becomes conversion constructor because
                                                  // it allows conversion of the single argument (QWidget *parent) to the Magnifier class.
    ~Magnifier();
    int getZoom() const;

private:
    Ui::Magnifier *ui;
    int zoom;
};

#endif // MAGNIFIER_H
