#ifndef CANVAS_H
#define CANVAS_H

    #include <QColor>
    #include <QImage>
    #include <QPoint>
    #include <QWidget>
    #include <QMouseEvent>
    #include <QPainter>
    #include <QFileDialog>
    #include <QColorDialog>
    #include <QApplication>

    enum Mode { PEN, LINE, ERASER };
    enum LineDrawType { SINGLE, POLY };


    namespace Ui {
        class Canvas;
    }

    class Canvas : public QWidget {
        Q_OBJECT

    public:

        explicit Canvas(QWidget *parent = 0);

        bool openImage(const QString &filename);
        bool saveImage(const QString &filename, const char * format);
        bool newImage(int w, int h);

        void setLineDrawType(LineDrawType type);

        LineDrawType lineDrawType();

        void revert();
        void resizeCanvas(int w, int h);

        void setBackgroundColor (const QColor & color);
        void setForegroundColor (const QColor & color);

        void setTool(Mode mode);
        Mode currentTool()                     const;

        Qt::PenCapStyle penCapStyle()   const;
        int penWidth()                  const;

        Qt::PenStyle lineStyle()        const;
        Qt::PenCapStyle lineCapStyle()  const;
        int lineWidth()                 const;

        int erasorWidth()               const;

        QColor backgroundColor()    const;
        QColor foregroundColor()    const;

        void clearImage();

        void setPenWidth(int width);
        void setPenCapStyle(Qt::PenCapStyle style);

        void setLineStyle(Qt::PenStyle style);
        void setLineCapStyle(Qt::PenCapStyle style);
        void setLineWidth (int width);

        void setEraserWidth (int width);


        void mousePressEvent(QMouseEvent * event) ;
        void mouseMoveEvent(QMouseEvent * event) ;
        void mouseReleaseEvent(QMouseEvent *event) ;
        void paintEvent(QPaintEvent * event);
        void mouseDoubleClickEvent(QMouseEvent *event);

    private:
        void drawLineTo(const QPoint & endPoint);
        void resizeImage(QImage * im, const QSize & size);
        bool modified;
        QImage image, previous_image, forLine;
        QPoint lastPoint;
        Mode mode;
        QColor background;
        QPen pen, line, erasor;
        LineDrawType polyLineMode;
        QPen * tool;
        bool polyLineTerminated;
    };

#endif // CANVAS_H
