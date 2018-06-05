#include "penproperties.h"
#include "ui_penproperties.h"

PenProperties::PenProperties(QWidget *parent) : QDialog(parent),
    ui(new Ui::PenProperties)
{
    ui->setupUi(this);
    connect(this->ui->thickness, SIGNAL(valueChanged(int)),
            this, SLOT(setValue(int) ) );
    connect(this->ui->flat, SIGNAL(clicked(bool)), this, SLOT(flatSelected()));
    connect(this->ui->round, SIGNAL(clicked(bool)), this, SLOT(roundSelected()));
    connect(this->ui->square, SIGNAL(clicked(bool)), this, SLOT(squareSelected()));

}

PenProperties::~PenProperties() { delete ui; }

void PenProperties::setThickness(int t) { this->ui->thickness->setValue(t); }

void PenProperties::setCanvas(Canvas  * canvas) { this->canvas = canvas; }

void PenProperties::setValue(int w) {
    this->canvas->setPenWidth(w);
    emit valueChnaged(w);
}

void PenProperties::setCapStyle(Qt::PenCapStyle style) {
    switch(style) {
    case Qt::RoundCap:
        this->ui->round->click();
        break;
    case Qt::SquareCap:
        this->ui->square->click();
        break;
    case Qt::FlatCap:
        this->ui->flat->click();
        break;
    default:
        break;
    }
}

void PenProperties::flatSelected() { this->canvas->setPenCapStyle(Qt::FlatCap); }
void PenProperties::roundSelected() { this->canvas->setPenCapStyle(Qt::RoundCap); }
void PenProperties::squareSelected() { this->canvas->setPenCapStyle(Qt::SquareCap); }
