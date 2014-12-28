#include "toolpathwidget.h"
#include <QPainter>
#include <QPoint>
#include <QPen>
#include <iostream>
#include "Tool.h"
#include "Toolchain.h"
#include "Workpoint.h"
#include <list>


void computeBorders(const std::vector<Workpoint> & workpoint, double & minX, double & maxX, double & minY, double & maxY);

ToolPathWidget::ToolPathWidget(QWidget *parent) :
    QWidget(parent)
{
}

void ToolPathWidget::setCurrentTool(int i) {
    currentTool = i;
}

void ToolPathWidget::paintEvent(QPaintEvent *event) {

    if (GUIDataObject.getWorkpoint().size() == 0)
        return;

    auto workpoint = GUIDataObject.getWorkpoint();
    double maxX, maxY, minX, minY;

    QPainter * painter = new QPainter(this);
    computeBorders(workpoint, minX, maxX, minY, maxY);
    painter->translate(0, 0);
    scaleCoordinates(workpoint);

    QPen pen;
    pen.setColor(Qt::blue);
    pen.setStyle(Qt::DashLine);
    painter->setPen(pen);
    printLines(painter, workpoint, currentTool);

    QFont font;
    font.setPixelSize(18);
    font.setBold(true);
    painter->setFont(font);
    pen.setColor(Qt::red);
    painter->setPen(pen);
    printPoints(painter);

}

void ToolPathWidget::scaleCoordinates(const std::vector<Workpoint> & workpoint) {
    double maxX, maxY, minX, minY;
    computeBorders(workpoint, minX, maxX, minY, maxY);
    scaledCoordinates.clear();
    for (auto it = workpoint.begin(); it != workpoint.end(); ++it) {
        double x = (*it).getPoint().getX()* 100000;
        double y = (*it).getPoint().getY()* 100000;
        x *= width() / maxX;
        y *= height() / maxY;
        scaledCoordinates.push_back(Point(x, y));
    }
}

void ToolPathWidget::printPoints(QPainter * painter) {
    int counter = 0;
    for (auto it = scaledCoordinates.begin(); it != scaledCoordinates.end(); ++it, counter++) {
        double x  = (*it).getX();
        double y  = (*it).getY();
        QString name = QString::fromStdString(std::to_string(counter));
        painter->drawText(x, y, name);
    }
}

void ToolPathWidget::printLines(QPainter * painter, std::vector<Workpoint> & workpoint, int toolIndex) {
    int prevX, prevY;
    prevX = prevY = -1;

    for (auto it = solution.begin(); it != solution.end(); ++it) {
        if ( workpoint[*it].popTool() == toolIndex and it != solution.begin() ) {
            int x, y;
            x = scaledCoordinates[*it].getX();
            y = scaledCoordinates[*it].getY();
            if (prevX != -1)
                painter->drawLine(prevX, prevY, x, y);
            prevX = x;
            prevY = y;
        }
    }
}

void computeBorders(const std::vector<Workpoint> & workpoint,
                    double & minX, double & maxX,
                    double & minY, double & maxY) {
    minX = maxX = workpoint[0].getPoint().getX();
    minY = maxY = workpoint[0].getPoint().getY();

    for (auto it = workpoint.begin(); it != workpoint.end(); ++it ) {
        double x = (*it).getPoint().getX();
        if (x > maxX) maxX = x;
        if (x < minX) minX = x;
        double y = (*it).getPoint().getY();
        if (y > maxY) maxY = y;
        if (y < minY) minY = y;
    }

    maxX += 1;
    maxY += 1;
    maxX *= 100000;
    minX *= 100000;
    maxY *= 100000;
    minY *= 100000;
}
