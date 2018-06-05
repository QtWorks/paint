#ifndef CANVAS_H
    #include "canvas.h"
#endif

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setAttribute(Qt::WA_StaticContents);
    this->modified = this->polyLineTerminated = false;
    this->mode = PEN;
    this->background = Qt::white;
    this->pen = QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    this->erasor = QPen(this->background, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    this->line = this->pen;
    this->polyLineMode = SINGLE;
    this->tool = &this->pen;
}

bool Canvas::openImage(const QString &filename) {
    QImage loadedImage;
    if (! loadedImage.load(filename)) {
        return false;
    }

    resizeImage(&loadedImage, loadedImage.size());
    this->image = loadedImage;
    this->modified = false;
    this->update();
    return true;
}

bool Canvas::newImage(int w, int h) {
    resizeImage(&this->image, QSize(w, h));
    this->erasor.setColor(this->background);
    this->clearImage();
    this->update();
    return true;
}

bool Canvas::saveImage(const QString &filename, const char *format){
    QImage currentImage = this->image;
    resizeImage(&currentImage, this->size());
    if (currentImage.save(filename, format)) {
        this->modified = false;
        return true;
    }
    return false;
}

void Canvas::clearImage() {
    this->previous_image = this->image;
    this->image.fill(this->background);
    this->forLine.fill(this->background);
    this->modified = true;
    this->update();
}

void Canvas::mousePressEvent(QMouseEvent *event)  {
    if (event->button() == Qt::LeftButton) {
        this->previous_image = this->image;
        if (this->mode == LINE) {
            this->forLine = this->image;
            if (this->polyLineMode == POLY) {
                return;
            }
        }
        this->lastPoint = event->pos();
    }
    QApplication::sendEvent(this->parent(), event);
}

void Canvas::mouseMoveEvent(QMouseEvent *event)  {
    if ((event->buttons() & Qt::LeftButton) ) {
        drawLineTo(event->pos());
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawLineTo(event->pos());
        if (this->mode == LINE) {
            this->image = this->forLine;
            this->lastPoint = event->pos();
        }
    }
}

void Canvas::mouseDoubleClickEvent(QMouseEvent * event) { }

void Canvas::paintEvent(QPaintEvent *event)  {
    QPainter painter(this);
    QRect rect = event->rect();
    if (this->mode == PEN || this->mode == ERASER) {
        painter.drawImage(rect, this->image, rect);
    }
    else if (this->mode == LINE) {
        painter.drawImage(rect, this->forLine, rect);
        this->forLine = this->image;
    }
    painter.end();
}

void Canvas::drawLineTo(const QPoint &endPoint) {
    if (this->image.isNull()) { return; }

    QPainter painter;
    if (this->mode == LINE)    { painter.begin(&this->forLine); }
    else                       { painter.begin(&this->image);   }

    painter.setPen(*this->tool);
    painter.drawLine(this->lastPoint, endPoint);
    this->modified = true;
    this->update();

    if (this->mode == PEN || this->mode == ERASER)  { this->lastPoint = endPoint; }
    else if (this->mode == LINE)    { }
    painter.end();
}

void Canvas::resizeImage(QImage *im, const QSize &size) {
    if (this->image.size() == size) { return; }

    QImage newImage(size, QImage::Format_RGB32);
    newImage.fill(this->background);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *im);
    *im = newImage;
}

void Canvas::revert() {
    QImage temp = this->image;
    this->image = this->previous_image;
    this->previous_image = temp;

    if (this->mode == LINE) { this->forLine = this->image; }
    this->update();
}

void Canvas::resizeCanvas(int w, int h) {
    if (this->image.isNull()) { return; }
    this->previous_image = this->image;
    this->modified = true;
    this->image = this->image.scaledToHeight(h);
    this->image = this->image.scaledToWidth(w);
    update();
}

void Canvas::setBackgroundColor(const QColor &color) {
    this->background = color;
    this->erasor.setColor(color);
}

void Canvas::setForegroundColor(const QColor &color) {
    this->pen.setColor(color);
    this->line.setColor(color);
}

void Canvas::setPenCapStyle(Qt::PenCapStyle style)  { this->pen.setCapStyle(style); }
void Canvas::setPenWidth(int width)                 { this->pen.setWidth(width); }
void Canvas::setLineStyle(Qt::PenStyle style)       { this->line.setStyle(style); }
void Canvas::setLineCapStyle(Qt::PenCapStyle style) { this->line.setCapStyle(style); }
void Canvas::setLineWidth(int width)                { this->line.setWidth(width); }
void Canvas::setEraserWidth(int width)              { this->erasor.setWidth(width); }
void Canvas::setTool(Mode mode) {
    this->mode = mode;
    switch (mode) {
    case PEN:
        this->tool = &this->pen;
        break;
    case LINE:
        this->tool = &this->line;
        break;
    case ERASER:
        this->tool = &this->erasor;
        break;
    default:
        break;
    }
}

Mode Canvas::currentTool()              const { return this->mode; }
Qt::PenStyle Canvas::lineStyle()        const { return this->line.style(); }
Qt::PenCapStyle Canvas::lineCapStyle()  const { return this->line.capStyle(); }
int Canvas::lineWidth()                 const { return this->line.width(); }
int Canvas::erasorWidth()               const { return this->erasor.width(); }
Qt::PenCapStyle Canvas::penCapStyle()   const { return this->pen.capStyle(); }
int Canvas::penWidth()                  const { return this->pen.width(); }
QColor Canvas::backgroundColor()        const { return this->background;  }
QColor Canvas::foregroundColor()        const { return this->pen.color(); }

void Canvas::setLineDrawType(LineDrawType type) { this->polyLineMode = type; }
LineDrawType Canvas::lineDrawType() { return this->polyLineMode; }
