#include "eraserproperties.h"
#include "ui_eraserproperties.h"

EraserProperties::EraserProperties(QWidget *parent) : QDialog(parent),
                                                    ui(new Ui::EraserProperties) {
    ui->setupUi(this);
    this->setWindowTitle("Eraser Dialog");
    connect(this->ui->thickness, SIGNAL(valueChanged(int)),
            this, SLOT(setValue(int) ) );
}

EraserProperties::~EraserProperties() {
    delete ui;
}

void EraserProperties::setThickness(int t) { this->ui->thickness->setValue(t); }

void EraserProperties::setCanvas(Canvas  * canvas) { this->canvas = canvas; }

void EraserProperties::setValue(int w) {
    this->canvas->setEraserWidth(w);
    emit valueChnaged(w);
}

