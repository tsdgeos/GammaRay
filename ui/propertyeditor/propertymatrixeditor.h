/*
  propertymatrixeditor.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2011-2022 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Tobias Koenig <tobias.koenig@kdab.com>

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

#ifndef GAMMARAY_PROPERTYMATRIXEDITOR_H
#define GAMMARAY_PROPERTYMATRIXEDITOR_H

#include "propertyextendededitor.h"

namespace GammaRay {
class PropertyMatrixEditor : public PropertyExtendedEditor
{
    Q_OBJECT
public:
    explicit PropertyMatrixEditor(QWidget *parent = nullptr);
    void showEditor(QWidget * parent) override;
};
}

#endif // GAMMARAY_PROPERTYMATRIXEDITOR_H
