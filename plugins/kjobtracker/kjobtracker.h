/*
  kjobtracker.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2012-2022 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
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

#ifndef GAMMARAY_KJOBTRACKER_KJOBTRACKER_H
#define GAMMARAY_KJOBTRACKER_KJOBTRACKER_H

#include <core/toolfactory.h>

#include <KJob>

class KJob;
namespace GammaRay {
class KJobModel;

class KJobTracker : public QObject
{
    Q_OBJECT
public:
    explicit KJobTracker(Probe *probe, QObject *parent = nullptr);
    ~KJobTracker() override;

private:
    KJobModel *m_jobModel;
};

class KJobTrackerFactory : public QObject, public StandardToolFactory<KJob, KJobTracker>
{
    Q_OBJECT
    Q_INTERFACES(GammaRay::ToolFactory)
    Q_PLUGIN_METADATA(IID "com.kdab.GammaRay.ToolFactory" FILE "gammaray_kjobtracker.json")

public:
    explicit KJobTrackerFactory(QObject *parent = nullptr)
        : QObject(parent)
    {
    }
};
}

#endif // GAMMARAY_KJOBTRACKER_H
