/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the either Technology Preview License Agreement or the
** Beta Release License Agreement.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://www.qtsoftware.com/contact.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QGESTURE_H
#define QGESTURE_H

#include "qobject.h"
#include "qlist.h"
#include "qdatetime.h"
#include "qpoint.h"
#include "qrect.h"
#include "qmetatype.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Gui)

class QGraphicsItem;
class QGesturePrivate;
class Q_GUI_EXPORT QGesture : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QGesture)

    Q_PROPERTY(Qt::GestureState state READ state)

    Q_PROPERTY(QPoint startPos READ startPos WRITE setStartPos)
    Q_PROPERTY(QPoint lastPos READ lastPos WRITE setLastPos)
    Q_PROPERTY(QPoint pos READ pos WRITE setPos)

public:
    explicit QGesture(QObject *parent = 0);
    ~QGesture();

    virtual bool filterEvent(QEvent *event) = 0;

    void setGraphicsItem(QGraphicsItem *);
    QGraphicsItem *graphicsItem() const;

    virtual void reset();

    Qt::GestureState state() const;
    void setState(Qt::GestureState state);

    QPoint startPos() const;
    void setStartPos(const QPoint &point);
    QPoint lastPos() const;
    void setLastPos(const QPoint &point);
    QPoint pos() const;
    void setPos(const QPoint &point);

protected:
    QGesture(QGesturePrivate &dd, QObject *parent);
    bool eventFilter(QObject*, QEvent*);

Q_SIGNALS:
    void started();
    void triggered();
    void finished();
    void cancelled();

private:
    friend class QWidget;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QGESTURE_H