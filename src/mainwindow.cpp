#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("HW3 Painter");
    this->canvas = new Canvas(this);
    setCentralWidget(this->canvas);
    this->pen_properties = NULL;
    this->eraser_properties = NULL;
    this->line_properties = NULL;

}

MainWindow::~MainWindow() {
    delete ui;
    delete canvas;
    delete pen_properties;
    delete line_properties;
}

void MainWindow::on_actionLoad_image_triggered() {
    QString s = QFileDialog::getOpenFileName(this, tr("Open File"), "/home",
                                                   tr("Images (*.bmp)"));
    if (! s.isEmpty()) {
        this->canvas->openImage(s);
    }
}

void MainWindow::on_actionNew_Image_triggered() {
    NewCanvas dialog;
    dialog.setModal(true);
    dialog.exec();
    // If the dialog is accepted
    if (dialog.result() == 1) {
        this->canvas->newImage(dialog.getWidth(), dialog.getHeight());
    }
}

void MainWindow::on_actionSave_Image_triggered() {
    QString s = QFileDialog::getSaveFileName(this, tr("Save File"), "/home",
                                                   tr("Images (*.bmp)"));
    if (! s.isNull()) {
        this->canvas->saveImage(s, "BMP");
    }
}

void MainWindow::on_actionResize_Canvas_triggered() {
    NewCanvas dialog(0, "Resize Canvas");
    dialog.setModal(true);
    dialog.exec();
    // If the dialog is accepted
    if (dialog.result() == 1) {
        this->canvas->resizeCanvas(dialog.getWidth(), dialog.getHeight());
    }
}

void MainWindow::on_actionLine_triggered()          { this->canvas->setTool(LINE); }
void MainWindow::on_actionPen_triggered()           { this->canvas->setTool(PEN); }
void MainWindow::on_actionEraser_triggered()        { this->canvas->setTool(ERASER); }
void MainWindow::on_actionUndo_triggered()          { this->canvas->revert(); }
void MainWindow::on_actionRedo_triggered()          { this->canvas->revert(); }
void MainWindow::on_actionClear_Canvas_triggered()  { this->canvas->clearImage(); }
void MainWindow::on_actionQuit_triggered()          { close(); }

void MainWindow::on_actionForeground_Color_triggered() {
    QColor newColor = QColorDialog::getColor(this->canvas->foregroundColor());
    if (newColor.isValid()) {
        this->canvas->setForegroundColor(newColor);
    }
}

void MainWindow::on_actionBackground_Color_triggered() {
    QColor newColor = QColorDialog::getColor(this->canvas->backgroundColor());
    if (newColor.isValid()) {
        this->canvas->setBackgroundColor(newColor);
    }
}

void MainWindow::on_actionEraser_Properties_triggered() {
    if (this->eraser_properties == NULL) {
        this->eraser_properties = new EraserProperties(this);
    }
    this->eraser_properties->setCanvas(this->canvas);
    this->eraser_properties->show();
    this->eraser_properties->setThickness(this->canvas->erasorWidth());
}

void MainWindow::on_actionPen_Properties_triggered() {
    if (this->pen_properties == NULL) {
        this->pen_properties = new PenProperties(this);
    }
    this->pen_properties->setCanvas(this->canvas);
    this->pen_properties->show();
    this->pen_properties->setThickness(this->canvas->penWidth());
    this->pen_properties->setCapStyle(this->canvas->penCapStyle());
}

void MainWindow::on_actionLine_Properties_triggered() {
    if (this->line_properties == NULL) {
        this->line_properties = new LineProperties(this);
    }
    this->line_properties->setCanvas(this->canvas);
    this->line_properties->show();
    this->line_properties->setThickness(this->canvas->lineWidth());
    this->line_properties->setCapStyle(this->canvas->lineCapStyle());
    this->line_properties->setLineStyle(this->canvas->lineStyle());
    this->line_properties->setLineDrawType(this->canvas->lineDrawType());
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        switch(this->canvas->currentTool()) {
        case ERASER:
            if ((this->eraser_properties != NULL) && this->eraser_properties->isVisible()) {
                return;
            }
            on_actionEraser_Properties_triggered();
            break;
        case PEN:
            if ((this->pen_properties != NULL) && this->pen_properties->isVisible()) {
                return;
            }
            on_actionPen_Properties_triggered();
            break;
        case LINE:
            if ((this->line_properties != NULL) && this->line_properties->isVisible()) {
                return;
            }
            on_actionLine_Properties_triggered();
            break;
        }
    }
}
