#ifndef CANVAS_H
    #include "canvas.h"
#endif

#ifndef ERASERPROPERTIES_H
#define ERASERPROPERTIES_H

    #include <QDialog>

    namespace Ui {
        class EraserProperties;
    }

    class EraserProperties : public QDialog {
        Q_OBJECT

    public:
        explicit EraserProperties(QWidget *parent = 0);
        ~EraserProperties();
        void setThickness(int t);
        void setCanvas(Canvas * canvas);

    public slots:
        void setValue(int w);

    signals:
        void valueChnaged(int w);

    private:
        Ui::EraserProperties *ui;
        Canvas * canvas;
    };

#endif // ERASERPROPERTIES_H
