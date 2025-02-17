/*
  networkconfigurationmodel.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2017-2022 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
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

#ifndef GAMMARAY_NETWORKCONFIGURATIONMODEL_H
#define GAMMARAY_NETWORKCONFIGURATIONMODEL_H

#include "networkconfigurationmodelroles.h"

#include <QAbstractTableModel>
#include <QNetworkConfiguration>

#include <vector>

QT_BEGIN_NAMESPACE
class QNetworkConfigurationManager;
QT_END_NAMESPACE

Q_DECLARE_METATYPE(QNetworkConfiguration::Purpose)
Q_DECLARE_METATYPE(QNetworkConfiguration::StateFlags)
Q_DECLARE_METATYPE(QNetworkConfiguration::Type)

namespace GammaRay {

class NetworkConfigurationModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit NetworkConfigurationModel(QObject *parent = nullptr);
    ~NetworkConfigurationModel() override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Qt::ItemFlags flags(const QModelIndex & index) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role) override;

private slots:
    void init();

private:
    void configurationAdded(const QNetworkConfiguration &config);
    void configurationChanged(const QNetworkConfiguration &config);
    void configurationRemoved(const QNetworkConfiguration &config);

    QNetworkConfigurationManager *m_mgr;
    std::vector<QNetworkConfiguration> m_configs;
};
}

#endif // GAMMARAY_NETWORKCONFIGURATIONMODEL_H
