#ifndef CANVAS_H
    #include "canvas.h"
#endif

#ifndef PENPROPERTIES_H
#define PENPROPERTIES_H

#include <QDialog>

namespace Ui {
class PenProperties;
}

class PenProperties : public QDialog
{
    Q_OBJECT

public:
    explicit PenProperties(QWidget *parent = 0);
    ~PenProperties();   
    void setThickness(int t);
    void setCanvas(Canvas * canvas);
    void setCapStyle(Qt::PenCapStyle style);

public slots:
    void setValue(int w);
    void flatSelected();
    void roundSelected();
    void squareSelected();

signals:
    void valueChnaged(int w);

private:
    Ui::PenProperties *ui;
    Canvas * canvas;
};

#endif // PENPROPERTIES_H
