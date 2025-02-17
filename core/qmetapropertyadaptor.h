/*
  qmetapropertyadaptor.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2015-2022 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAMMARAY_QMETAPROPERTYADAPTOR_H
#define GAMMARAY_QMETAPROPERTYADAPTOR_H

#include "propertyadaptor.h"
#include "objectinstance.h"

namespace GammaRay {
/** Property adaptor for QMetaProperty/Object-based property access. */
class QMetaPropertyAdaptor : public PropertyAdaptor
{
    Q_OBJECT
public:
    explicit QMetaPropertyAdaptor(QObject *parent = nullptr);
    ~QMetaPropertyAdaptor() override;

    int count() const override;
    PropertyData propertyData(int index) const override;
    void writeProperty(int index, const QVariant &value) override;
    void resetProperty(int index) override;

protected:
    void doSetObject(const ObjectInstance &oi) override;

private:
    QString detailString(const QMetaProperty &prop) const;
    PropertyData propertyMetaData(int index) const;

private slots:
    void propertyUpdated();

private:
    QHash<int, int> m_notifyToRowMap;
    QVector<int> m_rowToPropertyIndex;
    mutable bool m_notifyGuard;
};
}

#endif // GAMMARAY_QMETAPROPERTYADAPTOR_H
