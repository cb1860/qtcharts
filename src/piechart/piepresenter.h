#ifndef PIEPRESENTER_H
#define PIEPRESENTER_H

#include "chartitem_p.h"
#include "qpieseries.h"

class QGraphicsItem;
QTCOMMERCIALCHART_BEGIN_NAMESPACE
class PieSlice;

class PiePresenter : public QObject, public ChartItem
{
    Q_OBJECT

public:
    // TODO: use a generic data class instead of x and y
    PiePresenter(QGraphicsItem *parent, QPieSeries *series);
    ~PiePresenter();

public: // from QGraphicsItem
    QRectF boundingRect() const { return m_rect; }
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) {}

public:
    QRectF pieRect() const { return m_pieRect; }

public Q_SLOTS:
    void handleSeriesChanged(const PieChangeSet& changeSet);
    void handleDomainChanged(const Domain& domain);
    void handleGeometryChanged(const QRectF& rect);
    void updateGeometry();

private:
    friend class PieSlice;
    QList<PieSlice*> m_slices;
    QPieSeries *m_pieSeries;
    QRectF m_rect;
    QRectF m_pieRect;
};

QTCOMMERCIALCHART_END_NAMESPACE

#endif // PIEPRESENTER_H
