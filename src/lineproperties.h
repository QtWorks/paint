#ifndef CANVAS_H
    #include "canvas.h"
#endif

#ifndef LINEPROPERTIES_H
#define LINEPROPERTIES_H

    #include <QDialog>

    namespace Ui {
    class LineProperties;
    }

    class LineProperties : public QDialog
    {
        Q_OBJECT

    public:
        explicit LineProperties(QWidget *parent = 0);
        ~LineProperties();

        void setThickness(int t);
        void setCanvas(Canvas * canvas);
        void setCapStyle(Qt::PenCapStyle style);
        void setLineStyle(Qt::PenStyle style);
        void setLineDrawType (LineDrawType type);

    private slots:
        void setValue(int w);
        void flatSelected();
        void roundSelected();
        void squareSelected();

    signals:
        void valueChnaged(int w);

    private slots:
        void on_solid_clicked();

        void on_dashed_clicked();

        void on_dotted_clicked();

        void on_dash_dotted_clicked();

        void on_dash_dot_dotted_clicked();

        void on_single_clicked();

        void on_poly_clicked();

    private:
        Ui::LineProperties *ui;
        Canvas * canvas;
    };

#endif // LINEPROPERTIES_H
