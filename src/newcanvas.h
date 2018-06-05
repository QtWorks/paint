#ifndef NEWCANVAS_H
    #define NEWCANVAS_H
    #define DEFAULT_WIDTH 640
    #define DEFAULT_HEIGHT 480

    #include <QDialog>

    namespace Ui {
        class NewCanvas;
    }

    class NewCanvas : public QDialog
    {
            Q_OBJECT

        public:
            explicit NewCanvas(QWidget *parent = 0, const char * name = "New Canvas");
            int getWidth() const;
            int getHeight() const;

            ~NewCanvas();

        private:
            Ui::NewCanvas *ui;
    };

#endif // NEWCANVAS_H
