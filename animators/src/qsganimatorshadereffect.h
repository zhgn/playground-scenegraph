/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the plugins of %MODULE%.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSGANIMATORSHADEREFFECT_H
#define QSGANIMATORSHADEREFFECT_H

#include <QSGNode>
#include <QtQuick/private/qquickshadereffect_p.h>
#include <QtQuick/private/qquickshadereffectnode_p.h>
#include "qsganimatorcontroller.h"
#include "qsganimatorhost.h"

class QSGShaderEffectAnimatorNode;

class QSGAnimatorShaderEffect : public QQuickShaderEffect, public QSGAnimatorHost
{
    Q_OBJECT
public:
    QSGAnimatorShaderEffect(QQuickItem *parent = 0);
    ~QSGAnimatorShaderEffect();

    virtual void registerAnimation(QSGAbstractAnimation *);

protected:
    virtual QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

private:
    QList<QSGAbstractAnimation*> m_pendingAnimations;
    QList<QSGAbstractAnimation*> m_registeredAnimations;
    QQuickShaderEffectNode *m_shaderEffectNode;
    QSGShaderEffectAnimatorNode *m_animatorNode;
    Q_DISABLE_COPY(QSGAnimatorShaderEffect)
};

#endif // QSGANIMATORSHADEREFFECT_H
