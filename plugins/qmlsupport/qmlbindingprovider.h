/*
  qmlbindingprovider.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2017-2022 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Anton Kreuzkamp <anton.kreuzkamp@kdab.com>

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

#ifndef GAMMARAY_QMLBINDINGPROVIDER_H
#define GAMMARAY_QMLBINDINGPROVIDER_H

// Own
#include <common/sourcelocation.h>
#include <core/abstractbindingprovider.h>

// Qt
#include <QQmlProperty>

// Std
#include <memory>
#include <vector>

QT_BEGIN_NAMESPACE
class QQmlAbstractBinding;
class QQmlBinding;
QT_END_NAMESPACE

namespace GammaRay {

class QmlBindingProvider : public AbstractBindingProvider
{
public:
    std::vector<std::unique_ptr<BindingNode>> findBindingsFor(QObject * obj) const override;
    std::vector<std::unique_ptr<BindingNode>> findDependenciesFor(GammaRay::BindingNode * binding) const override;
    bool canProvideBindingsFor(QObject *object) const override;

private:
    std::unique_ptr<BindingNode> bindingNodeFromQmlProperty(QQmlProperty property, BindingNode *parent) const;
    BindingNode *bindingNodeFromBinding(QQmlAbstractBinding *binding) const;
    static void fetchSourceLocationFor(BindingNode *node, QQmlBinding *binding) ;
    static QQmlAbstractBinding *bindingForProperty(QObject *obj, int propertyIndex) ;
};

}

#endif // GAMMARAY_QMLBINDINGPROVIDER_H
