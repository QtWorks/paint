#ifndef CANVAS_H
    #include "canvas.h"
#endif

#ifndef MAINWINDOW_H
    #define MAINWINDOW_H
    #include <QMainWindow>

    #include "eraserproperties.h"
    #include "newcanvas.h"
    #include "penproperties.h"
    #include "lineproperties.h"


    namespace Ui {
        class MainWindow;
    }

    class MainWindow : public QMainWindow {
        Q_OBJECT

        public:
            explicit MainWindow(QWidget *parent = 0);
            ~MainWindow();

        private slots:
                void on_actionLoad_image_triggered();

                void on_actionQuit_triggered();

                void on_actionNew_Image_triggered();

                void on_actionSave_Image_triggered();

                void on_actionUndo_triggered();

                void on_actionRedo_triggered();

                void on_actionClear_Canvas_triggered();

                void on_actionResize_Canvas_triggered();

                void on_actionLine_triggered();

                void on_actionPen_triggered();

                void on_actionEraser_triggered();

                void on_actionForeground_Color_triggered();

                void on_actionBackground_Color_triggered();

                void on_actionEraser_Properties_triggered();

                void on_actionPen_Properties_triggered();

                void on_actionLine_Properties_triggered();


        protected:
                void mousePressEvent(QMouseEvent * event);

        private:
                Ui::MainWindow *ui;
                Canvas * canvas;
                PenProperties * pen_properties;
                EraserProperties * eraser_properties;
                LineProperties * line_properties;

    };
#endif // MAINWINDOW_H
