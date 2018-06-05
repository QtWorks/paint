#include "newcanvas.h"
#include "ui_newcanvas.h"

NewCanvas::NewCanvas(QWidget *parent, const char * name) : QDialog(parent),
                                        ui(new Ui::NewCanvas) {
    ui->setupUi(this);
    this->ui->heightSpinBox->setValue(DEFAULT_HEIGHT);
    this->ui->widthSpinBox->setValue(DEFAULT_WIDTH);
    this->setWindowTitle(name);
}

NewCanvas::~NewCanvas() {
    delete ui;
}

int NewCanvas::getWidth() const {
    return this->ui->widthSpinBox->value();
}

int NewCanvas::getHeight() const {
    return this->ui->heightSpinBox->value();
}
