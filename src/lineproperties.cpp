#include "lineproperties.h"
#include "ui_lineproperties.h"

LineProperties::LineProperties(QWidget *parent) : QDialog(parent),
    ui(new Ui::LineProperties)
{
    ui->setupUi(this);

    this->setWindowTitle("Line Dialog");
    connect(this->ui->thickness, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));

    connect(this->ui->flat, SIGNAL(clicked(bool)), this, SLOT(flatSelected()));
    connect(this->ui->round, SIGNAL(clicked(bool)), this, SLOT(roundSelected()));
    connect(this->ui->square, SIGNAL(clicked(bool)), this, SLOT(squareSelected()));

    connect(this->ui->dashed, SIGNAL(clicked(bool)), this, SLOT(on_dashed_clicked()));
    connect(this->ui->solid, SIGNAL(clicked(bool)), this, SLOT(on_solid_clicked()));
    connect(this->ui->dash_dotted, SIGNAL(clicked(bool)), this, SLOT(on_dash_dotted_clicked()));
    connect(this->ui->dash_dot_dotted, SIGNAL(clicked(bool)), this, SLOT(on_dash_dot_dotted_clicked()));
    connect(this->ui->dotted, SIGNAL(clicked(bool)), this, SLOT(on_dotted_clicked()));
}

LineProperties::~LineProperties() { delete ui; }
void LineProperties::setThickness(int t) { this->ui->thickness->setValue(t); }
void LineProperties::setCanvas(Canvas  * canvas) { this->canvas = canvas; }

void LineProperties::setValue(int w) {
    this->canvas->setLineWidth(w);
    emit valueChnaged(w);
}

void LineProperties::setCapStyle(Qt::PenCapStyle style) {
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

void LineProperties::setLineStyle(Qt::PenStyle style) {
    switch(style) {
    case Qt::SolidLine:
        this->ui->solid->click();
        break;
    case Qt::DashLine:
        this->ui->dashed->click();
        break;
    case Qt::DotLine:
        this->ui->dotted->click();
        break;

    case Qt::DashDotLine:
        this->ui->dash_dotted->click();
        break;
    case Qt::DashDotDotLine:
        this->ui->dash_dot_dotted->click();
        break;
    default:
        break;
    }
}

void LineProperties::setLineDrawType(LineDrawType type) {
    switch (type) {
    case SINGLE:
        this->ui->single->click();
        break;
    case POLY:
        this->ui->poly->click();
        break;
    default:
        break;
    }
}

void LineProperties::flatSelected() { this->canvas->setLineCapStyle(Qt::FlatCap); }
void LineProperties::roundSelected() { this->canvas->setLineCapStyle(Qt::RoundCap); }
void LineProperties::squareSelected() { this->canvas->setLineCapStyle(Qt::SquareCap); }

void LineProperties::on_solid_clicked() { this->canvas->setLineStyle(Qt::SolidLine); }
void LineProperties::on_dashed_clicked() { this->canvas->setLineStyle(Qt::DashLine); }
void LineProperties::on_dotted_clicked() { this->canvas->setLineStyle(Qt::DotLine); }
void LineProperties::on_dash_dotted_clicked() { this->canvas->setLineStyle(Qt::DashDotLine); }
void LineProperties::on_dash_dot_dotted_clicked() { this->canvas->setLineStyle(Qt::DashDotDotLine); }

void LineProperties::on_single_clicked() { this->canvas->setLineDrawType(SINGLE); }
void LineProperties::on_poly_clicked() { this->canvas->setLineDrawType(POLY); }
